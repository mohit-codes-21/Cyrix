%e  1019
%p  2807
%n  371
%k  284
%a  1213
%o  1117

O   [0-7]
D   [0-9]
NZ  [1-9]
L   [a-zA-Z_]
A   [a-zA-Z_0-9]
H   [a-fA-F0-9]
HP  (0[xX])
E   ([Ee][+-]?{D}+)
FS  (f|F|l|L)
IS  (((u|U)(l|L|ll|LL)?)|((l|L|ll|LL)(u|U)?))
ES  (\\(['"\?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+))
WS  [ \t\v\f]

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simple.tab.h"

/* NOTE: yylineno is declared by flex automatically when %option yylineno
   is used. We do NOT declare it here. */
extern void yyerror(const char *s);

static void comment(void);
%}

%option yylineno

%%

"/*"                        { comment(); }
"//".*                      { /* consume line comment */ }

"if"        { return IF; }
"else"      { return ELSE; }
"while"     { return WHILE; }
"for"       { return FOR; }
"int"       { return INT; }
"float"     { return FLOAT; }
"char"      { return CHAR; }
"double"    { return DOUBLE; }
"void"      { return VOID; }
"return"    { return RETURN; }
"break"     { return BREAK; }
"continue"  { return CONTINUE; }

{L}{A}*     { yylval.sval = strdup(yytext); return IDENTIFIER; }

{NZ}{D}*{IS}?               { yylval.sval = strdup(yytext); return I_CONSTANT; }
"0"{O}*{IS}?                { yylval.sval = strdup(yytext); return I_CONSTANT; }
{HP}{H}+{IS}?               { yylval.sval = strdup(yytext); return I_CONSTANT; }

{D}+{E}{FS}?                { yylval.sval = strdup(yytext); return F_CONSTANT; }
{D}*"."{D}+{E}?{FS}?        { yylval.sval = strdup(yytext); return F_CONSTANT; }
{D}+"."{E}?{FS}?            { yylval.sval = strdup(yytext); return F_CONSTANT; }

"++"        { return INC_OP; }
"--"        { return DEC_OP; }
"&&"        { return AND_OP; }
"||"        { return OR_OP; }
"<="        { return LE_OP; }
">="        { return GE_OP; }
"=="        { return EQ_OP; }
"!="        { return NE_OP; }
"+="        { return ADD_ASSIGN; }
"-="        { return SUB_ASSIGN; }
"*="        { return MUL_ASSIGN; }
"/="        { return DIV_ASSIGN; }

";"         { return ';'; }
"{"         { return '{'; }
"}"         { return '}'; }
","         { return ','; }
"="         { return '='; }
"("         { return '('; }
")"         { return ')'; }
"+"         { return '+'; }
"-"         { return '-'; }
"*"         { return '*'; }
"/"         { return '/'; }
"%"         { return '%'; }
"<"         { return '<'; }
">"         { return '>'; }
"!"         { return '!'; }
"~"         { return '~'; }
"&"         { return '&'; }
"|"         { return '|'; }
"^"         { return '^'; }

\n          { /* yylineno auto-incremented by %option yylineno */ }
{WS}+       { /* skip whitespace */ }
.           {
                fprintf(stderr,
                    "[Lex Error] Line %d: unknown character '%s'\n",
                    yylineno, yytext);
            }

%%

int yywrap(void) { return 1; }

static void comment(void)
{
    int c;
    while ((c = input()) != 0) {
        if (c == '*') {
            while ((c = input()) == '*')
                ;
            if (c == '/') return;
            if (c == 0)  break;
        }
    }
    fprintf(stderr,
        "[Lex Error] Line %d: unterminated block comment\n", yylineno);
}
