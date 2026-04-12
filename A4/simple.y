%{
/*
 * simple.y  —  Parser & IR Generator for the "Simple" language
 * CS327 Compilers — Lab Assignment #4
 *
 * Three-Address Code, Quadruple format: (op, arg1, arg2, result)
 * Dragon Book (Aho, Lam, Sethi, Ullman) §6.2–6.7  SDT + back-patching
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

extern int   yylineno;
extern char *yytext;
int  yylex(void);
void yyerror(const char *s);

/* ═══════════════════════════════════════════════════════
   ERROR BUFFER  —  Option A design
   All semantic / lex / parse errors are collected here.
   Nothing is printed to stderr during parsing.
   At the end, main decides: errors? print only error
   report. Clean? print full IR output.
   ═══════════════════════════════════════════════════════ */
#define MAX_ERRORS 512
typedef struct { char msg[256]; } ErrEntry;
static ErrEntry ERR[MAX_ERRORS];
static int      err_cnt = 0;
static int      suppress_ir = 0;  /* set to 1 on first error */

void add_error(const char *fmt, ...)
{
    if (err_cnt >= MAX_ERRORS) return;
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(ERR[err_cnt++].msg, 256, fmt, ap);
    va_end(ap);
    suppress_ir = 1;
}

static void print_errors(void)
{
    printf("\n=== ERRORS DETECTED (%d) =====================================\n", err_cnt);
    for (int i = 0; i < err_cnt; i++)
        printf("  %s\n", ERR[i].msg);
    printf("======================================================================\n");
}

/* ═══════════════════════════════════════════════════════
   SOURCE LINE TABLE
   ═══════════════════════════════════════════════════════ */
#define MAX_SRC 4096
static char *src_lines[MAX_SRC];
static int   src_cnt = 0;

/* ═══════════════════════════════════════════════════════
   QUADRUPLE TABLE
   ═══════════════════════════════════════════════════════ */
#define MAX_Q 8192
typedef struct {
    char op[64], arg1[64], arg2[64], result[64];
    int  line;
} Quad;

static Quad Q[MAX_Q];
static int  qn = 0;

static int emit_q(const char *op, const char *a1,
                  const char *a2, const char *r)
{
    if (qn >= MAX_Q) { fprintf(stderr,"Fatal: quad overflow\n"); exit(1); }
    Quad *q = &Q[qn];
    snprintf(q->op,    64, "%s", op ? op : "-");
    snprintf(q->arg1,  64, "%s", a1 ? a1 : "-");
    snprintf(q->arg2,  64, "%s", a2 ? a2 : "-");
    snprintf(q->result,64, "%s", r  ? r  : "-");
    q->line = yylineno;
    return qn++;
}

static void bp_res (int i, const char *v) { snprintf(Q[i].result,64,"%s",v); }
static void bp_arg1(int i, const char *v) { snprintf(Q[i].arg1,  64,"%s",v); }

/* ═══════════════════════════════════════════════════════
   TEMPORARIES AND LABELS
   ═══════════════════════════════════════════════════════ */
static int tc = 0, lc = 0;
static char *temp_types[8192];
static char *nt(void){char *b=malloc(16);snprintf(b,16,"t%d",++tc);return b;}
static char *nl(void){char *b=malloc(16);snprintf(b,16,"L%d",++lc);return b;}

static int temp_index(const char *t)
{
    if (!t || t[0] != 't') return -1;
    if (!isdigit((unsigned char)t[1])) return -1;
    int v = 0;
    for (int i = 1; t[i]; i++) {
        if (!isdigit((unsigned char)t[i])) break;
        v = (v * 10) + (t[i] - '0');
    }
    return v;
}

static void set_temp_type(const char *t, const char *ty)
{
    int idx = temp_index(t);
    if (idx <= 0 || idx >= 8192) return;
    if (temp_types[idx]) free(temp_types[idx]);
    temp_types[idx] = strdup(ty);
}

static const char *get_temp_type(const char *t)
{
    int idx = temp_index(t);
    if (idx <= 0 || idx >= 8192) return NULL;
    return temp_types[idx];
}

static char *nt_of_type(const char *ty)
{
    char *b = nt();
    set_temp_type(b, ty);
    return b;
}

/* ═══════════════════════════════════════════════════════
   SYMBOL TABLE
   ═══════════════════════════════════════════════════════ */
#define MAX_S 2048
typedef struct {
    char name[64], type[16], value[64];
    int  scope, init, decl, end, active;
} Sym;

static Sym ST[MAX_S];
static int  sn = 0, dep = 0;

static void scope_open(void) { dep++; }

static void scope_close(void)
{
    for (int i = 0; i < sn; i++)
        if (ST[i].active && ST[i].scope == dep)
            { ST[i].active = 0; ST[i].end = yylineno; }
    dep--;
}

static Sym *sym_decl(const char *nm, const char *ty)
{
    for (int i = 0; i < sn; i++)
        if (ST[i].active && ST[i].scope == dep &&
            strcmp(ST[i].name, nm) == 0)
        {
            add_error("[Semantic Error] Line %d: '%s' already declared in this scope (first declared at line %d)",
                yylineno, nm, ST[i].decl);
            return NULL;
        }
    if (sn >= MAX_S) { fprintf(stderr,"Fatal: symbol table full\n"); exit(1); }
    Sym *s = &ST[sn++];
    snprintf(s->name, 64, "%s", nm);
    snprintf(s->type, 16, "%s", ty);
    snprintf(s->value,64, "?");
    s->scope = dep; s->init = 0; s->decl = yylineno;
    s->end = -1; s->active = 1;
    return s;
}

static Sym *sym_look(const char *nm)
{
    for (int i = sn-1; i >= 0; i--)
        if (ST[i].active && strcmp(ST[i].name, nm) == 0)
            return &ST[i];
    return NULL;
}

static void sym_sv(const char *nm, const char *v)
{
    Sym *s = sym_look(nm);
    if (s) { s->init = 1; snprintf(s->value, 64, "%s", v); }
}

static void sym_mk(const char *nm)
{
    Sym *s = sym_look(nm);
    if (s) s->init = 1;
}

static int is_float_literal(const char *s)
{
    if (!s) return 0;
    for (const char *p = s; *p; p++)
        if (*p == '.' || *p == 'e' || *p == 'E') return 1;
    return 0;
}

static const char *type_of_place(const char *p)
{
    const char *t = get_temp_type(p);
    if (t) return t;
    Sym *s = sym_look(p);
    if (s) return s->type;
    return is_float_literal(p) ? "float" : "int";
}

static char *cast_place(const char *p, const char *from, const char *to)
{
    if (!p || !from || !to) return (char *)p;
    if (strcmp(from, to) == 0) return (char *)p;
    if (strcmp(from, "int") == 0 && strcmp(to, "float") == 0) {
        char *t = nt_of_type("float");
        emit_q("itof", p, "-", t);
        return t;
    }
    if (strcmp(from, "float") == 0 && strcmp(to, "int") == 0) {
        char *t = nt_of_type("int");
        emit_q("ftoi", p, "-", t);
        return t;
    }
    return (char *)p;
}

static const char *common_numeric_type(const char *t1, const char *t2)
{
    if (!t1 || !t2) return "int";
    if (strcmp(t1, "float") == 0 || strcmp(t2, "float") == 0) return "float";
    return "int";
}

/* ═══════════════════════════════════════════════════════
   DISPLAY
   ═══════════════════════════════════════════════════════ */
static void show_quads(int from)
{
    if (suppress_ir) return;
    if (from >= qn) { printf("  (no IR quads generated)\n"); return; }
    printf("  +---------+---------------------------+---------------+---------------+---------------+---------------+\n");
    printf("  |   No    |        expr               |      op       |     arg1      |     arg2      |    result     |\n");
    printf("  +---------+---------------------------+---------------+---------------+---------------+---------------+\n");
    for (int i = from; i < qn; i++) {
        char expr[128];
        const Quad *q = &Q[i];
        if (strcmp(q->op, "=") == 0)
            snprintf(expr, sizeof expr, "%s=%s", q->result, q->arg1);
        else if (strcmp(q->op, "minus") == 0 || strcmp(q->op, "!") == 0 || strcmp(q->op, "~") == 0)
            snprintf(expr, sizeof expr, "%s= %s %s", q->result, q->op, q->arg1);
        else if (strcmp(q->op, "itof") == 0 || strcmp(q->op, "ftoi") == 0)
            snprintf(expr, sizeof expr, "%s= %s(%s)", q->result, q->op, q->arg1);
        else if (strcmp(q->op, "+") == 0 || strcmp(q->op, "-") == 0 || strcmp(q->op, "*") == 0 ||
                 strcmp(q->op, "/") == 0 || strcmp(q->op, "%") == 0 || strcmp(q->op, "<") == 0 ||
                 strcmp(q->op, ">") == 0 || strcmp(q->op, "<=") == 0 || strcmp(q->op, ">=") == 0 ||
                 strcmp(q->op, "==") == 0 || strcmp(q->op, "!=") == 0 || strcmp(q->op, "&&") == 0 ||
                 strcmp(q->op, "||") == 0)
            snprintf(expr, sizeof expr, "%s=%s%s%s", q->result, q->arg1, q->op, q->arg2);
        else if (strcmp(q->op, "ifFalse") == 0)
            snprintf(expr, sizeof expr, "ifFalse %s goto %s", q->arg1, q->result);
        else if (strcmp(q->op, "goto") == 0)
            snprintf(expr, sizeof expr, "goto %s", q->arg1);
        else if (strcmp(q->op, "label") == 0)
            snprintf(expr, sizeof expr, "label %s", q->arg1);
        else if (strcmp(q->op, "return") == 0) {
            if (strcmp(q->arg1, "-") == 0) snprintf(expr, sizeof expr, "return");
            else snprintf(expr, sizeof expr, "return %s", q->arg1);
        }
        else
            snprintf(expr, sizeof expr, "%s %s %s %s", q->op, q->arg1, q->arg2, q->result);

        printf("  | %5d   | %-25s | %-13s | %-13s | %-13s | %-13s |\n",
               i+1, expr, q->op, q->arg1, q->arg2, q->result);
    }
    printf("  +---------+---------------------------+---------------+---------------+---------------+---------------+\n");
}

static void show_sym(void)
{
    if (suppress_ir) return;
    printf("  +------------------+---------+-------+-------------+--------------+---------+--------------+\n");
    printf("  |      Name        |  Type   | Scope | Decl Line   |  Live Until  |  Init?  |    Value     |\n");
    printf("  +------------------+---------+-------+-------------+--------------+---------+--------------+\n");
    int any = 0;
    for (int i = 0; i < sn; i++) {
        Sym *s = &ST[i];
        char e[20];
        if (s->end == -1) snprintf(e,20,"active      ");
        else              snprintf(e,20,"line %-7d", s->end);
        printf("  |%s%-17s| %-7s |   %d   | line %-5d  | %-12s | %-7s | %-12s |\n",
               s->active ? ">" : " ",
               s->name, s->type, s->scope, s->decl,
               e, s->init ? "yes" : "no", s->value);
        any = 1;
    }
    if (!any)
        printf("  |                         (symbol table empty)                                        |\n");
    printf("  +------------------+---------+-------+-------------+--------------+---------+--------------+\n");
    printf("  (> = currently in scope)\n");
}

static void show_stmt(int line, int q0)
{
    if (suppress_ir) return;
    printf("\n");
    printf("  ================================================================\n");
    if (line >= 1 && line <= src_cnt)
        printf("  Source [line %3d]:  %s\n", line, src_lines[line-1]);
    else
        printf("  Source [line %3d]:  <control flow>\n", line);
    printf("  ================================================================\n");
    printf("\n  -- IR Quads Generated -----------------------------------------\n");
    show_quads(q0);
    printf("\n  -- Symbol Table State -----------------------------------------\n");
    show_sym();
}

/* ═══════════════════════════════════════════════════════
   BREAK / CONTINUE STACKS
   ═══════════════════════════════════════════════════════ */
#define MAXNEST 64

static int  brk_buf[MAXNEST][128];
static int  brk_cnt[MAXNEST];
static int  brk_top = -1;

static void brk_enter(void) { ++brk_top; brk_cnt[brk_top] = 0; }
static void brk_add(int idx)
{
    if (brk_top >= 0) brk_buf[brk_top][brk_cnt[brk_top]++] = idx;
}
static void brk_patch(const char *lend)
{
    for (int i = 0; i < brk_cnt[brk_top]; i++)
        bp_arg1(brk_buf[brk_top][i], lend);
    brk_top--;
}

static char *cnt_lbl[MAXNEST];
static int   cnt_top = -1;

static void cnt_enter(const char *l) { cnt_lbl[++cnt_top] = strdup(l); }
static void cnt_exit(void)           { free(cnt_lbl[cnt_top--]); }

/* ═══════════════════════════════════════════════════════
   FOR-LOOP GLOBAL: carries goto-Lbody quad index across
   mid-rule action boundaries (one slot can't hold both
   a char* and an int simultaneously).
   ═══════════════════════════════════════════════════════ */
static int for_gbody = -1;   /* for-loop: goto Lbody quad index */

/* ─── if-else goto stack ───────────────────────────────────────────────
   When we nest  if-else  inside another  if-else  the ELSE clause's
   "goto Lend" quad index must survive while the inner if-else runs.
   A single global would be overwritten by the inner if-else before the
   outer rule's closing action reads it.  We use a small stack instead.
   ─────────────────────────────────────────────────────────────────────*/
#define MAX_IF_NEST 128
static int if_goto_stack[MAX_IF_NEST];
static int if_goto_top = -1;

static void if_goto_push(int idx) { if_goto_stack[++if_goto_top] = idx; }
static int  if_goto_pop(void)     { return if_goto_stack[if_goto_top--]; }

/* ═══════════════════════════════════════════════════════
   FINAL SUMMARY
   ═══════════════════════════════════════════════════════ */
static void print_summary(void)
{
    printf("\n");
    printf("+======+===========================+===============+===============+===============+===============+=============+\n");
    printf("|  No  |           expr            |      op       |     arg1      |     arg2      |    result     |  Src Line   |\n");
    printf("+======+===========================+===============+===============+===============+===============+=============+\n");
    for (int i = 0; i < qn; i++) {
        char expr[128];
        const Quad *q = &Q[i];
        if (strcmp(q->op, "=") == 0)
            snprintf(expr, sizeof expr, "%s=%s", q->result, q->arg1);
        else if (strcmp(q->op, "minus") == 0 || strcmp(q->op, "!") == 0 || strcmp(q->op, "~") == 0)
            snprintf(expr, sizeof expr, "%s= %s %s", q->result, q->op, q->arg1);
        else if (strcmp(q->op, "itof") == 0 || strcmp(q->op, "ftoi") == 0)
            snprintf(expr, sizeof expr, "%s= %s(%s)", q->result, q->op, q->arg1);
        else if (strcmp(q->op, "+") == 0 || strcmp(q->op, "-") == 0 || strcmp(q->op, "*") == 0 ||
                 strcmp(q->op, "/") == 0 || strcmp(q->op, "%") == 0 || strcmp(q->op, "<") == 0 ||
                 strcmp(q->op, ">") == 0 || strcmp(q->op, "<=") == 0 || strcmp(q->op, ">=") == 0 ||
                 strcmp(q->op, "==") == 0 || strcmp(q->op, "!=") == 0 || strcmp(q->op, "&&") == 0 ||
                 strcmp(q->op, "||") == 0)
            snprintf(expr, sizeof expr, "%s=%s%s%s", q->result, q->arg1, q->op, q->arg2);
        else if (strcmp(q->op, "ifFalse") == 0)
            snprintf(expr, sizeof expr, "ifFalse %s goto %s", q->arg1, q->result);
        else if (strcmp(q->op, "goto") == 0)
            snprintf(expr, sizeof expr, "goto %s", q->arg1);
        else if (strcmp(q->op, "label") == 0)
            snprintf(expr, sizeof expr, "label %s", q->arg1);
        else if (strcmp(q->op, "return") == 0) {
            if (strcmp(q->arg1, "-") == 0) snprintf(expr, sizeof expr, "return");
            else snprintf(expr, sizeof expr, "return %s", q->arg1);
        }
        else
            snprintf(expr, sizeof expr, "%s %s %s %s", q->op, q->arg1, q->arg2, q->result);

        printf("| %4d | %-25s | %-13s | %-13s | %-13s | %-13s | line %-5d  |\n",
               i+1, expr, q->op, q->arg1, q->arg2, q->result, q->line);
    }
    printf("+------+---------------------------+---------------+---------------+---------------+---------------+-------------+\n");

    printf("\n");
    printf("+==================+=========+=======+=============+==============+=========+==============+=========+\n");
    printf("|      Name        |  Type   | Scope | Decl Line   |  Live Until  |  Init?  |    Value     | Active? |\n");
    printf("+==================+=========+=======+=============+==============+=========+==============+=========+\n");
    for (int i = 0; i < sn; i++) {
        Sym *s = &ST[i];
        char e[20];
        if (s->end == -1) snprintf(e,20,"end-of-prog");
        else              snprintf(e,20,"line %-6d", s->end);
        printf("| %-16s | %-7s |   %d   | line %-5d  | %-12s | %-7s | %-12s | %-7s |\n",
               s->name, s->type, s->scope, s->decl,
               e, s->init ? "yes" : "no", s->value,
               s->active ? "active" : "gone");
    }
    printf("+------------------+---------+-------+-------------+--------------+---------+--------------+---------+\n");
}

%}

/* ═══════════════════════════════════════════════════════
   BISON DECLARATIONS
   ═══════════════════════════════════════════════════════ */
%define parse.error verbose

%union { char *sval; int ival; }

%token <sval> IDENTIFIER I_CONSTANT F_CONSTANT
%token IF ELSE WHILE FOR RETURN BREAK CONTINUE
%token INT FLOAT VOID
%token INC_OP DEC_OP AND_OP OR_OP
%token LE_OP GE_OP EQ_OP NE_OP
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN

%type <sval> expression assignment_expression
%type <sval> logical_or_expression logical_and_expression
%type <sval> equality_expression relational_expression
%type <sval> additive_expression multiplicative_expression
%type <sval> unary_expression postfix_expression primary_expression
%type <sval> type_specifier

/*
 * if_prefix: handles "IF '(' expression ')'" and emits the
 * ifFalse quad.  Returns the index of that quad (ival) so
 * the closing rules can back-patch it.
 * Using a named non-terminal (instead of inline mid-rule
 * action) avoids the duplicate-prefix reduce/reduce conflicts
 * that arise when both if and if-else rules start identically.
 */
%type <ival> if_prefix

/* for_cond: optional condition in a for loop.
   Returns the ifFalse quad index, or -1 if absent. */
%type <ival> for_cond

/* Dangling-else handled by bison's default shift preference.
   We only need to declare ELSE so bison knows its token class. */
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%start program

%%

/* ─────────────────────────────────────────────────────
   TOP-LEVEL
   ───────────────────────────────────────────────────── */

program : statement_list ;

statement_list
    : /* empty */
    | statement_list statement
    ;

/* ─────────────────────────────────────────────────────
   STATEMENTS
   ───────────────────────────────────────────────────── */

statement
    : declaration_statement
    | expression_statement
    | compound_statement
    | selection_statement
    | iteration_statement
    | jump_statement
    ;

compound_statement
    : '{' { scope_open(); } statement_list '}' { scope_close(); }
    ;

type_specifier
    : INT    { $$ = strdup("int");    }
    | FLOAT  { $$ = strdup("float");  }
    | VOID   { $$ = strdup("void");   }
    ;

/* ═══════════════════════════════════════════════════════
   DECLARATIONS
   ═══════════════════════════════════════════════════════
   int x;        → symbol table entry only; no quad emitted
   int x = E;    → symbol table entry + quad ( = , E , - , x )
   ═══════════════════════════════════════════════════════ */

declaration_statement
    : type_specifier IDENTIFIER ';'
        {
            int q0 = qn, ln = yylineno;
            sym_decl($2, $1);
            show_stmt(ln, q0);
            free($1); free($2);
        }
    | type_specifier IDENTIFIER '=' expression ';'
        {
            int q0 = qn, ln = yylineno;
            Sym *s = sym_decl($2, $1);
            if (s) {
                if (strcmp(s->type, "void") == 0)
                    add_error("[Semantic Error] Line %d: void variable '%s' cannot be initialized", yylineno, $2);
                else {
                    const char *rt = type_of_place($4);
                    if (strcmp(rt, "void") == 0)
                        add_error("[Semantic Error] Line %d: void value used in initialization of '%s'", yylineno, $2);
                    else {
                        char *rhs = cast_place($4, rt, s->type);
                        emit_q("=", rhs, "-", $2);
                        sym_sv($2, rhs);
                    }
                }
            }
            show_stmt(ln, q0);
            free($1); free($2); free($4);
        }
    ;

/* ═══════════════════════════════════════════════════════
   EXPRESSION STATEMENT
   ═══════════════════════════════════════════════════════ */

expression_statement
    : ';'
    | expression ';'
        {
            if (!suppress_ir) { printf("\n  -- Symbol Table (after expression statement) --------\n"); show_sym(); }
            free($1);
        }
    ;

/* ═══════════════════════════════════════════════════════
   SELECTION STATEMENTS  (if / if-else)
   ═══════════════════════════════════════════════════════
   Dragon Book §6.6 back-patching.

   KEY DESIGN DECISION:
   Both if and if-else share the same prefix:
       IF '(' expression ')'
   If we write two full rules with that prefix, bison sees
   22 reduce/reduce conflicts because it can't decide which
   rule to use until it sees ELSE.

   SOLUTION: factor the common prefix into a named non-terminal
   `if_prefix` that handles the prefix AND emits the ifFalse
   quad.  Then:
       if (C) S       → if_prefix  statement
       if (C) S else  → if_prefix  statement  ELSE  statement

   Bison resolves the dangling-else shift/reduce by preferring
   shift (correct default), so we only get 1 s/r conflict which
   is expected and harmless.

   QUAD LAYOUT:
   if (C) S:
       ifFalse  C  goto  ??       ← index = if_prefix.ival
       [ S ]
       label    Lf                ← Lf back-patched into ifFalse.result

   if (C) S else S1:
       ifFalse  C  goto  ??       ← index = if_prefix.ival
       [ S ]
       goto     ??                ← index = goto_idx
       label    Lf                ← back-patch ifFalse.result
       [ S1 ]
       label    Lend              ← back-patch goto.arg1
   ═══════════════════════════════════════════════════════ */

if_prefix
    : IF '(' expression ')'
        {
            /* Emit the conditional jump with placeholder target.
               Return the quad index so the outer rule can back-patch it. */
            const char *ct = type_of_place($3);
            if (strcmp(ct, "void") == 0)
                add_error("[Semantic Error] Line %d: void expression used in if-condition", yylineno);
            char *cond = (strcmp(ct, "float") == 0) ? cast_place($3, "float", "int") : $3;
            $$ = emit_q("ifFalse", cond, "goto", "??");
            free($3);
        }
    ;

selection_statement
    /* ── if (C) S ── */
    : if_prefix statement %prec LOWER_THAN_ELSE
        {
            /* $1 = ifFalse quad index */
            char *lf = nl();
            bp_res($1, lf);                    /* ifFalse ... goto Lf */
            emit_q("label", lf, "-", "-");
            free(lf);
        }

    /* ── if (C) S else S1 ── */
    | if_prefix statement ELSE
        {
            /* Emit goto past else body; push its index onto the if-goto
               stack so nested if-else rules can't clobber it.
               Then emit Lf and back-patch the ifFalse. */
            if_goto_push(emit_q("goto", "??", "-", "-"));
            char *lf = nl();
            bp_res($1, lf);
            emit_q("label", lf, "-", "-");
            free(lf);
        }
      statement
        {
            /* Pop our goto index — guaranteed to be ours even if the
               else-body contained nested if-else statements. */
            char *lend = nl();
            bp_arg1(if_goto_pop(), lend);
            emit_q("label", lend, "-", "-");
            free(lend);
        }
    ;

/* ═══════════════════════════════════════════════════════
   ITERATION STATEMENTS  (while / for)
   ═══════════════════════════════════════════════════════

   ── while (C) S ───────────────────────────────────────
       Ls:   label
       [C -> t]
       ifFalse t goto ??     (ifi)
       [S]
       goto Ls
       Lend: label           bp ifi.result <- Lend

   RHS with mid-rule actions:
     WHILE '(' {mra_Ls} expression ')' {mra_if} statement
     $1    $2  $3        $4        $5  $6        $7

   mra_Ls ($3): emit Ls; push continue; return Ls string
   mra_if ($6): emit ifFalse; return quad index

   ── for (init ; cond ; update) S ─────────────────────
       [init]
       Ltest:   label
       ifFalse cond goto ??   (ifi, -1 if absent)
       goto Lbody              (for_gbody global)
       Lupdate: label
       [update]
       goto Ltest
       Lbody:   label         bp for_gbody.arg1 <- Lbody
       [S]
       goto Lupdate
       Lend:    label         bp ifi.result <- Lend
   ═══════════════════════════════════════════════════════ */

iteration_statement

    /* ── while ── */
    : WHILE '('
        {
            char *ls = nl();
            emit_q("label", ls, "-", "-");
            cnt_enter(ls);
            brk_enter();
            $<sval>$ = ls;          /* slot $3 = Ls */
        }
      expression ')'
        {
            /* slot $6 = ifFalse quad index */
            const char *ct = type_of_place($4);
            if (strcmp(ct, "void") == 0)
                add_error("[Semantic Error] Line %d: void expression used in while-condition", yylineno);
            char *cond = (strcmp(ct, "float") == 0) ? cast_place($4, "float", "int") : $4;
            $<ival>$ = emit_q("ifFalse", cond, "goto", "??");
            free($4);
        }
      statement
        {
            char *ls  = $<sval>3;
            int   ifi = $<ival>6;
            emit_q("goto", ls, "-", "-");
            char *lend = nl();
            bp_res(ifi, lend);
            emit_q("label", lend, "-", "-");
            brk_patch(lend);
            cnt_exit();
            free(ls); free(lend);
        }

    /* ── for ── */
    | FOR '('
        for_init ';'
        {
            /* emit Ltest; slot $5 = Ltest string */
            char *lt = nl();
            emit_q("label", lt, "-", "-");
            $<sval>$ = lt;
        }
        for_cond ';'
        {
            /* $6 = ifFalse quad index from for_cond (or -1)      */
            /* emit goto Lbody (forward ref); save in for_gbody   */
            for_gbody = emit_q("goto", "??", "-", "-");
            /* emit Lupdate; slot $8 = Lupdate string             */
            char *lu = nl();
            emit_q("label", lu, "-", "-");
            cnt_enter(lu);
            brk_enter();
            $<sval>$ = lu;
        }
        for_update ')'
        {
            /* after update: goto Ltest; emit Lbody               */
            char *lt = $<sval>5;
            char *lu = $<sval>8;
            emit_q("goto", lt, "-", "-");
            char *lb = nl();
            bp_arg1(for_gbody, lb);           /* goto ?? -> goto Lbody */
            emit_q("label", lb, "-", "-");
            $<sval>$ = lb;                    /* slot $10 = Lbody */
        }
        statement
        {
            /* close the loop */
            char *lu   = $<sval>8;
            char *lb   = $<sval>10;
            int   ifi  = $<ival>6;
            emit_q("goto", lu, "-", "-");
            char *lend = nl();
            if (ifi >= 0) bp_res(ifi, lend);
            emit_q("label", lend, "-", "-");
            brk_patch(lend);
            cnt_exit();
            free($<sval>5); free(lu); free(lb); free(lend);
        }
    ;

for_init
    : /* empty */
    | expression                                { free($1); }
    | type_specifier IDENTIFIER '=' expression
        {
            Sym *s = sym_decl($2, $1);
            if (s) {
                if (strcmp(s->type, "void") == 0)
                    add_error("[Semantic Error] Line %d: void variable '%s' cannot be initialized", yylineno, $2);
                else {
                    const char *rt = type_of_place($4);
                    if (strcmp(rt, "void") == 0)
                        add_error("[Semantic Error] Line %d: void value used in initialization of '%s'", yylineno, $2);
                    else {
                        char *rhs = cast_place($4, rt, s->type);
                        emit_q("=", rhs, "-", $2);
                        sym_sv($2, rhs);
                    }
                }
            }
            free($1); free($2); free($4);
        }
    | type_specifier IDENTIFIER
        { sym_decl($2, $1); free($1); free($2); }
    ;

for_cond
    : /* empty */   { $$ = -1; }
    | expression
        {
            const char *ct = type_of_place($1);
            if (strcmp(ct, "void") == 0)
                add_error("[Semantic Error] Line %d: void expression used in for-condition", yylineno);
            char *cond = (strcmp(ct, "float") == 0) ? cast_place($1, "float", "int") : $1;
            $$ = emit_q("ifFalse", cond, "goto", "??");
            free($1);
        }
    ;

for_update
    : /* empty */
    | expression    { free($1); }
    ;

/* ═══════════════════════════════════════════════════════
   JUMP STATEMENTS
   ═══════════════════════════════════════════════════════ */

jump_statement
    : BREAK ';'
        {
            if (brk_top < 0)
                add_error("[Semantic Error] Line %d: 'break' outside a loop", yylineno);
            else { int idx = emit_q("goto","??","-","-"); brk_add(idx); }
        }
    | CONTINUE ';'
        {
            if (cnt_top < 0)
                add_error("[Semantic Error] Line %d: 'continue' outside a loop", yylineno);
            else
                emit_q("goto", cnt_lbl[cnt_top], "-", "-");
        }
    | RETURN ';'
        { emit_q("return", "-", "-", "-"); }
    | RETURN expression ';'
        { emit_q("return", $2, "-", "-"); free($2); }
    ;

/* ═══════════════════════════════════════════════════════
   EXPRESSIONS — Dragon Book §6.2–6.4 SDT
   $$ = "place" holding the computed value
       (temp name t1, t2… or variable name or literal)
   ═══════════════════════════════════════════════════════ */

expression
    : assignment_expression { $$ = $1; }
    ;

/* ── Assignment ─────────────────────────────────────────
   x = E        →  ( = ,  E ,  - , x )
   x += E       →  ( + ,  x ,  E , t )  ( = , t , - , x )
   x -= E       →  ( - ,  x ,  E , t )  ( = , t , - , x )
   x *= E       →  ( * ,  x ,  E , t )  ( = , t , - , x )
   x /= E       →  ( / ,  x ,  E , t )  ( = , t , - , x )
   ────────────────────────────────────────────────────── */

assignment_expression
    : logical_or_expression { $$ = $1; }

    | IDENTIFIER '=' assignment_expression
        {
            Sym *s = sym_look($1);
            if (!s)
                add_error("[Semantic Error] Line %d: assignment to undeclared variable '%s'", yylineno, $1);
            else if (strcmp(s->type, "void") == 0)
                add_error("[Semantic Error] Line %d: assignment to void variable '%s'", yylineno, $1);
            else {
                const char *rt = type_of_place($3);
                if (strcmp(rt, "void") == 0)
                    add_error("[Semantic Error] Line %d: void value assigned to '%s'", yylineno, $1);
                else {
                    char *rhs = cast_place($3, rt, s->type);
                    emit_q("=", rhs, "-", $1);
                    sym_sv($1, rhs);
                }
            }
            $$ = strdup($1); free($3);
        }

    | IDENTIFIER ADD_ASSIGN assignment_expression
        {
            Sym *s = sym_look($1);
            if (!s)
                add_error("[Semantic Error] Line %d: assignment to undeclared variable '%s'", yylineno, $1);
            else if (strcmp(s->type, "void") == 0)
                add_error("[Semantic Error] Line %d: assignment to void variable '%s'", yylineno, $1);
            else {
                const char *lt = s->type;
                const char *rt = type_of_place($3);
                if (strcmp(rt, "void") == 0)
                    add_error("[Semantic Error] Line %d: void value used in '+=' for '%s'", yylineno, $1);
                const char *op_t = common_numeric_type(lt, rt);
                char *l = (strcmp(lt, op_t) == 0) ? $1 : cast_place($1, lt, op_t);
                char *r = (strcmp(rt, op_t) == 0) ? $3 : cast_place($3, rt, op_t);
                char *t = nt_of_type(op_t);
                emit_q("+", l, r, t);
                char *asgn = (strcmp(op_t, lt) == 0) ? t : cast_place(t, op_t, lt);
                emit_q("=", asgn, "-", $1);
                sym_sv($1, asgn);
            }
            $$ = strdup($1); free($3);
        }

    | IDENTIFIER SUB_ASSIGN assignment_expression
        {
            Sym *s = sym_look($1);
            if (!s)
                add_error("[Semantic Error] Line %d: assignment to undeclared variable '%s'", yylineno, $1);
            else if (strcmp(s->type, "void") == 0)
                add_error("[Semantic Error] Line %d: assignment to void variable '%s'", yylineno, $1);
            else {
                const char *lt = s->type;
                const char *rt = type_of_place($3);
                if (strcmp(rt, "void") == 0)
                    add_error("[Semantic Error] Line %d: void value used in '-=' for '%s'", yylineno, $1);
                const char *op_t = common_numeric_type(lt, rt);
                char *l = (strcmp(lt, op_t) == 0) ? $1 : cast_place($1, lt, op_t);
                char *r = (strcmp(rt, op_t) == 0) ? $3 : cast_place($3, rt, op_t);
                char *t = nt_of_type(op_t);
                emit_q("-", l, r, t);
                char *asgn = (strcmp(op_t, lt) == 0) ? t : cast_place(t, op_t, lt);
                emit_q("=", asgn, "-", $1);
                sym_sv($1, asgn);
            }
            $$ = strdup($1); free($3);
        }

    | IDENTIFIER MUL_ASSIGN assignment_expression
        {
            Sym *s = sym_look($1);
            if (!s)
                add_error("[Semantic Error] Line %d: assignment to undeclared variable '%s'", yylineno, $1);
            else if (strcmp(s->type, "void") == 0)
                add_error("[Semantic Error] Line %d: assignment to void variable '%s'", yylineno, $1);
            else {
                const char *lt = s->type;
                const char *rt = type_of_place($3);
                if (strcmp(rt, "void") == 0)
                    add_error("[Semantic Error] Line %d: void value used in '*=' for '%s'", yylineno, $1);
                const char *op_t = common_numeric_type(lt, rt);
                char *l = (strcmp(lt, op_t) == 0) ? $1 : cast_place($1, lt, op_t);
                char *r = (strcmp(rt, op_t) == 0) ? $3 : cast_place($3, rt, op_t);
                char *t = nt_of_type(op_t);
                emit_q("*", l, r, t);
                char *asgn = (strcmp(op_t, lt) == 0) ? t : cast_place(t, op_t, lt);
                emit_q("=", asgn, "-", $1);
                sym_sv($1, asgn);
            }
            $$ = strdup($1); free($3);
        }

    | IDENTIFIER DIV_ASSIGN assignment_expression
        {
            Sym *s = sym_look($1);
            if (!s)
                add_error("[Semantic Error] Line %d: assignment to undeclared variable '%s'", yylineno, $1);
            else if (strcmp(s->type, "void") == 0)
                add_error("[Semantic Error] Line %d: assignment to void variable '%s'", yylineno, $1);
            else {
                const char *lt = s->type;
                const char *rt = type_of_place($3);
                if (strcmp(rt, "void") == 0)
                    add_error("[Semantic Error] Line %d: void value used in '/=' for '%s'", yylineno, $1);
                const char *op_t = common_numeric_type(lt, rt);
                char *l = (strcmp(lt, op_t) == 0) ? $1 : cast_place($1, lt, op_t);
                char *r = (strcmp(rt, op_t) == 0) ? $3 : cast_place($3, rt, op_t);
                char *t = nt_of_type(op_t);
                emit_q("/", l, r, t);
                char *asgn = (strcmp(op_t, lt) == 0) ? t : cast_place(t, op_t, lt);
                emit_q("=", asgn, "-", $1);
                sym_sv($1, asgn);
            }
            $$ = strdup($1); free($3);
        }
    ;

logical_or_expression
    : logical_and_expression { $$ = $1; }
    | logical_or_expression OR_OP logical_and_expression
        {
            const char *t1 = type_of_place($1);
            const char *t2 = type_of_place($3);
            if (strcmp(t1, "void") == 0 || strcmp(t2, "void") == 0)
                add_error("[Semantic Error] Line %d: void value used in logical OR", yylineno);
            char *l = (strcmp(t1, "float") == 0) ? cast_place($1, "float", "int") : $1;
            char *r = (strcmp(t2, "float") == 0) ? cast_place($3, "float", "int") : $3;
            char *t = nt_of_type("int");
            emit_q("||", l, r, t);
            free($1); free($3); $$ = t;
        }
    ;

logical_and_expression
    : equality_expression { $$ = $1; }
    | logical_and_expression AND_OP equality_expression
        {
            const char *t1 = type_of_place($1);
            const char *t2 = type_of_place($3);
            if (strcmp(t1, "void") == 0 || strcmp(t2, "void") == 0)
                add_error("[Semantic Error] Line %d: void value used in logical AND", yylineno);
            char *l = (strcmp(t1, "float") == 0) ? cast_place($1, "float", "int") : $1;
            char *r = (strcmp(t2, "float") == 0) ? cast_place($3, "float", "int") : $3;
            char *t = nt_of_type("int");
            emit_q("&&", l, r, t);
            free($1); free($3); $$ = t;
        }
    ;

equality_expression
    : relational_expression { $$ = $1; }
    | equality_expression EQ_OP relational_expression
        {
            const char *t1 = type_of_place($1);
            const char *t2 = type_of_place($3);
            if (strcmp(t1, "void") == 0 || strcmp(t2, "void") == 0)
                add_error("[Semantic Error] Line %d: void value used in '=='", yylineno);
            const char *ct = common_numeric_type(t1, t2);
            char *l = (strcmp(t1, ct) == 0) ? $1 : cast_place($1, t1, ct);
            char *r = (strcmp(t2, ct) == 0) ? $3 : cast_place($3, t2, ct);
            char *t = nt_of_type("int");
            emit_q("==", l, r, t);
            free($1); free($3); $$ = t;
        }
    | equality_expression NE_OP relational_expression
        {
            const char *t1 = type_of_place($1);
            const char *t2 = type_of_place($3);
            if (strcmp(t1, "void") == 0 || strcmp(t2, "void") == 0)
                add_error("[Semantic Error] Line %d: void value used in '!='", yylineno);
            const char *ct = common_numeric_type(t1, t2);
            char *l = (strcmp(t1, ct) == 0) ? $1 : cast_place($1, t1, ct);
            char *r = (strcmp(t2, ct) == 0) ? $3 : cast_place($3, t2, ct);
            char *t = nt_of_type("int");
            emit_q("!=", l, r, t);
            free($1); free($3); $$ = t;
        }
    ;

relational_expression
    : additive_expression { $$ = $1; }
    | relational_expression '<' additive_expression
        {
            const char *t1 = type_of_place($1);
            const char *t2 = type_of_place($3);
            if (strcmp(t1, "void") == 0 || strcmp(t2, "void") == 0)
                add_error("[Semantic Error] Line %d: void value used in '<'", yylineno);
            const char *ct = common_numeric_type(t1, t2);
            char *l = (strcmp(t1, ct) == 0) ? $1 : cast_place($1, t1, ct);
            char *r = (strcmp(t2, ct) == 0) ? $3 : cast_place($3, t2, ct);
            char *t = nt_of_type("int");
            emit_q("<", l, r, t);
            free($1); free($3); $$ = t;
        }
    | relational_expression '>' additive_expression
        {
            const char *t1 = type_of_place($1);
            const char *t2 = type_of_place($3);
            if (strcmp(t1, "void") == 0 || strcmp(t2, "void") == 0)
                add_error("[Semantic Error] Line %d: void value used in '>'", yylineno);
            const char *ct = common_numeric_type(t1, t2);
            char *l = (strcmp(t1, ct) == 0) ? $1 : cast_place($1, t1, ct);
            char *r = (strcmp(t2, ct) == 0) ? $3 : cast_place($3, t2, ct);
            char *t = nt_of_type("int");
            emit_q(">", l, r, t);
            free($1); free($3); $$ = t;
        }
    | relational_expression LE_OP additive_expression
        {
            const char *t1 = type_of_place($1);
            const char *t2 = type_of_place($3);
            if (strcmp(t1, "void") == 0 || strcmp(t2, "void") == 0)
                add_error("[Semantic Error] Line %d: void value used in '<='", yylineno);
            const char *ct = common_numeric_type(t1, t2);
            char *l = (strcmp(t1, ct) == 0) ? $1 : cast_place($1, t1, ct);
            char *r = (strcmp(t2, ct) == 0) ? $3 : cast_place($3, t2, ct);
            char *t = nt_of_type("int");
            emit_q("<=", l, r, t);
            free($1); free($3); $$ = t;
        }
    | relational_expression GE_OP additive_expression
        {
            const char *t1 = type_of_place($1);
            const char *t2 = type_of_place($3);
            if (strcmp(t1, "void") == 0 || strcmp(t2, "void") == 0)
                add_error("[Semantic Error] Line %d: void value used in '>='", yylineno);
            const char *ct = common_numeric_type(t1, t2);
            char *l = (strcmp(t1, ct) == 0) ? $1 : cast_place($1, t1, ct);
            char *r = (strcmp(t2, ct) == 0) ? $3 : cast_place($3, t2, ct);
            char *t = nt_of_type("int");
            emit_q(">=", l, r, t);
            free($1); free($3); $$ = t;
        }
    ;

additive_expression
    : multiplicative_expression { $$ = $1; }
    | additive_expression '+' multiplicative_expression
        {
            const char *t1 = type_of_place($1);
            const char *t2 = type_of_place($3);
            if (strcmp(t1, "void") == 0 || strcmp(t2, "void") == 0)
                add_error("[Semantic Error] Line %d: void value used in '+'", yylineno);
            const char *ct = common_numeric_type(t1, t2);
            char *l = (strcmp(t1, ct) == 0) ? $1 : cast_place($1, t1, ct);
            char *r = (strcmp(t2, ct) == 0) ? $3 : cast_place($3, t2, ct);
            char *t = nt_of_type(ct);
            emit_q("+", l, r, t);
            free($1); free($3); $$ = t;
        }
    | additive_expression '-' multiplicative_expression
        {
            const char *t1 = type_of_place($1);
            const char *t2 = type_of_place($3);
            if (strcmp(t1, "void") == 0 || strcmp(t2, "void") == 0)
                add_error("[Semantic Error] Line %d: void value used in '-'", yylineno);
            const char *ct = common_numeric_type(t1, t2);
            char *l = (strcmp(t1, ct) == 0) ? $1 : cast_place($1, t1, ct);
            char *r = (strcmp(t2, ct) == 0) ? $3 : cast_place($3, t2, ct);
            char *t = nt_of_type(ct);
            emit_q("-", l, r, t);
            free($1); free($3); $$ = t;
        }
    ;

multiplicative_expression
    : unary_expression { $$ = $1; }
    | multiplicative_expression '*' unary_expression
        {
            const char *t1 = type_of_place($1);
            const char *t2 = type_of_place($3);
            if (strcmp(t1, "void") == 0 || strcmp(t2, "void") == 0)
                add_error("[Semantic Error] Line %d: void value used in '*'", yylineno);
            const char *ct = common_numeric_type(t1, t2);
            char *l = (strcmp(t1, ct) == 0) ? $1 : cast_place($1, t1, ct);
            char *r = (strcmp(t2, ct) == 0) ? $3 : cast_place($3, t2, ct);
            char *t = nt_of_type(ct);
            emit_q("*", l, r, t);
            free($1); free($3); $$ = t;
        }
    | multiplicative_expression '/' unary_expression
        {
            const char *t1 = type_of_place($1);
            const char *t2 = type_of_place($3);
            if (strcmp(t1, "void") == 0 || strcmp(t2, "void") == 0)
                add_error("[Semantic Error] Line %d: void value used in '/'", yylineno);
            const char *ct = common_numeric_type(t1, t2);
            char *l = (strcmp(t1, ct) == 0) ? $1 : cast_place($1, t1, ct);
            char *r = (strcmp(t2, ct) == 0) ? $3 : cast_place($3, t2, ct);
            char *t = nt_of_type(ct);
            emit_q("/", l, r, t);
            free($1); free($3); $$ = t;
        }
    | multiplicative_expression '%' unary_expression
        {
            const char *t1 = type_of_place($1);
            const char *t2 = type_of_place($3);
            if (strcmp(t1, "void") == 0 || strcmp(t2, "void") == 0)
                add_error("[Semantic Error] Line %d: void value used in '%%'", yylineno);
            if (strcmp(t1, "float") == 0 || strcmp(t2, "float") == 0)
                add_error("[Semantic Error] Line %d: modulo requires int operands", yylineno);
            char *l = (strcmp(t1, "int") == 0) ? $1 : cast_place($1, t1, "int");
            char *r = (strcmp(t2, "int") == 0) ? $3 : cast_place($3, t2, "int");
            char *t = nt_of_type("int");
            emit_q("%", l, r, t);
            free($1); free($3); $$ = t;
        }
    ;

/* ── Unary ──────────────────────────────────────────────
   -E   →  ( minus , E , - , t )
   !E   →  ( !     , E , - , t )
   ~E   →  ( ~     , E , - , t )
   ++x  →  ( +     , x , 1 , t )  ( = , t , - , x )  result = x
   --x  →  ( -     , x , 1 , t )  ( = , t , - , x )  result = x
   ────────────────────────────────────────────────────── */
unary_expression
    : postfix_expression { $$ = $1; }
    | '-' unary_expression
        {
            const char *t1 = type_of_place($2);
            if (strcmp(t1, "void") == 0)
                add_error("[Semantic Error] Line %d: void value used in unary '-'", yylineno);
            const char *rt = (strcmp(t1, "float") == 0) ? "float" : "int";
            char *t = nt_of_type(rt);
            emit_q("minus", $2, "-", t);
            free($2); $$ = t;
        }
    | '!' unary_expression
        {
            const char *t1 = type_of_place($2);
            if (strcmp(t1, "void") == 0)
                add_error("[Semantic Error] Line %d: void value used in unary '!'", yylineno);
            char *opd = (strcmp(t1, "float") == 0) ? cast_place($2, "float", "int") : $2;
            char *t = nt_of_type("int");
            emit_q("!", opd, "-", t);
            free($2); $$ = t;
        }
    | '~' unary_expression
        {
            const char *t1 = type_of_place($2);
            if (strcmp(t1, "void") == 0)
                add_error("[Semantic Error] Line %d: void value used in unary '~'", yylineno);
            if (strcmp(t1, "float") == 0)
                add_error("[Semantic Error] Line %d: unary '~' requires int operand", yylineno);
            char *opd = (strcmp(t1, "int") == 0) ? $2 : cast_place($2, t1, "int");
            char *t = nt_of_type("int");
            emit_q("~", opd, "-", t);
            free($2); $$ = t;
        }
    | INC_OP unary_expression
        {
            const char *t1 = type_of_place($2);
            if (strcmp(t1, "void") == 0)
                add_error("[Semantic Error] Line %d: void value used in '++'", yylineno);
            const char *rt = (strcmp(t1, "float") == 0) ? "float" : "int";
            const char *one = (strcmp(rt, "float") == 0) ? "1.0" : "1";
            char *t = nt_of_type(rt);
            emit_q("+", $2, one, t);
            emit_q("=", t, "-", $2);
            sym_mk($2);
            $$ = strdup($2); free(t);
        }
    | DEC_OP unary_expression
        {
            const char *t1 = type_of_place($2);
            if (strcmp(t1, "void") == 0)
                add_error("[Semantic Error] Line %d: void value used in '--'", yylineno);
            const char *rt = (strcmp(t1, "float") == 0) ? "float" : "int";
            const char *one = (strcmp(rt, "float") == 0) ? "1.0" : "1";
            char *t = nt_of_type(rt);
            emit_q("-", $2, one, t);
            emit_q("=", t, "-", $2);
            sym_mk($2);
            $$ = strdup($2); free(t);
        }
    ;

/* ── Postfix ────────────────────────────────────────────
   x++  →  ( = , x , - , t1 )  ( + , x , 1 , t2 )  ( = , t2 , - , x )
            result = t1  (old value)
   ────────────────────────────────────────────────────── */
postfix_expression
    : primary_expression { $$ = $1; }
    | postfix_expression INC_OP
        {
            const char *t1t = type_of_place($1);
            if (strcmp(t1t, "void") == 0)
                add_error("[Semantic Error] Line %d: void value used in postfix '++'", yylineno);
            const char *rt = (strcmp(t1t, "float") == 0) ? "float" : "int";
            const char *one = (strcmp(rt, "float") == 0) ? "1.0" : "1";
            char *t1 = nt_of_type(rt), *t2 = nt_of_type(rt);
            emit_q("=", $1, "-", t1);
            emit_q("+", $1, one, t2);
            emit_q("=", t2, "-", $1);
            sym_mk($1); free(t2);
            $$ = t1;
        }
    | postfix_expression DEC_OP
        {
            const char *t1t = type_of_place($1);
            if (strcmp(t1t, "void") == 0)
                add_error("[Semantic Error] Line %d: void value used in postfix '--'", yylineno);
            const char *rt = (strcmp(t1t, "float") == 0) ? "float" : "int";
            const char *one = (strcmp(rt, "float") == 0) ? "1.0" : "1";
            char *t1 = nt_of_type(rt), *t2 = nt_of_type(rt);
            emit_q("=", $1, "-", t1);
            emit_q("-", $1, one, t2);
            emit_q("=", t2, "-", $1);
            sym_mk($1); free(t2);
            $$ = t1;
        }
    ;

primary_expression
    : IDENTIFIER
        {
            Sym *s = sym_look($1);
            if (!s)
                add_error("[Semantic Error] Line %d: use of undeclared variable '%s'", yylineno, $1);
            else if (strcmp(s->type, "void") == 0)
                add_error("[Semantic Error] Line %d: void variable '%s' used in expression", yylineno, $1);
            $$ = $1;
        }
    | I_CONSTANT  { $$ = $1; }
    | F_CONSTANT  { $$ = $1; }
    | '(' expression ')' { $$ = $2; }
    ;

%%

/* ═══════════════════════════════════════════════════════
   ERROR HANDLER
   ═══════════════════════════════════════════════════════ */
void yyerror(const char *s)
{
    add_error("[Parse Error]  Line %d near '%s': %s",
              yylineno,
              (yytext && yytext[0]) ? yytext : "<EOF>",
              s);
}

/* ═══════════════════════════════════════════════════════
   MAIN
   ═══════════════════════════════════════════════════════ */
int main(int argc, char **argv)
{
    extern FILE *yyin;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <source_file>\n", argv[0]);
        return 1;
    }

    /* Load source lines for display */
    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        fprintf(stderr, "Error: cannot open '%s'\n", argv[1]);
        return 1;
    }
    char buf[1024];
    while (fgets(buf, sizeof buf, fp) && src_cnt < MAX_SRC) {
        int l = strlen(buf);
        if (l > 0 && buf[l-1] == '\n') buf[l-1] = '\0';
        src_lines[src_cnt++] = strdup(buf);
    }
    fclose(fp);

    printf("+=======================================================================+\n");
    printf("|   Simple Language Compiler  --  Intermediate Code Generator           |\n");
    printf("|   CS327 Compilers  --  Lab Assignment #4                              |\n");
    printf("+-----------------------------------------------------------------------+\n");
    printf("|   File: %-62s|\n", argv[1]);
    printf("+=======================================================================+\n");
    printf("\n=== SOURCE PROGRAM ===================================================\n");
    for (int i = 0; i < src_cnt; i++)
        printf("  %4d | %s\n", i+1, src_lines[i]);
    printf("======================================================================\n");
    printf("\n=== STATEMENT-BY-STATEMENT IR GENERATION =============================\n");

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        fprintf(stderr, "Error: cannot re-open '%s'\n", argv[1]);
        return 1;
    }
    int ret = yyparse();
    fclose(yyin);

    /* ── Option A decision point ── */
    if (err_cnt > 0 || ret != 0) {
        print_errors();
        printf("\n[FAIL] %d error(s) found. IR output suppressed.\n", err_cnt);
    } else {
        printf("\n[OK] Parsing and IR generation completed successfully.\n");
        printf("\n=== FINAL COMPLETE QUADRUPLE TABLE (Three-Address Code / IR) =========\n");
        print_summary();
    }

    for (int i = 0; i < src_cnt; i++) free(src_lines[i]);
    return (err_cnt > 0 || ret != 0) ? 1 : 0;
}
