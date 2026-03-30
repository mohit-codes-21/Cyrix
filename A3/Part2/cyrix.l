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
P   ([Pp][+-]?{D}+)
FS  (f|F|l|L)
IS  (((u|U)(l|L|ll|LL)?)|((l|L|ll|LL)(u|U)?))
CP  (u|U|L)
SP  (u8|u|U|L)
ES  (\\(['"\?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+))
WS  [ \t\v\n\f]

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cyrix.tab.h"

extern char buff[2048];
extern int mode;
extern void yyerror(const char *);  /* prints grammar violation message */
int token_count = 0;

int id_count = 0;
int keyword_count = 0;
int constant_count = 0;
int string_count = 0;
int operator_count = 0;
int depth = 0;
int max_depth = 0;

static void comment(void);
static int check_type(void);
%}

%%
"/*"                                    { comment(); }
"//".*                                  { /* consume //-comment */ }

"break"     { keyword_count++; token_count++; return BREAK; }
"case"      { keyword_count++; token_count++; return CASE; }
"char"      { keyword_count++; token_count++; return CHAR; }
"continue"  { keyword_count++; token_count++; return CONTINUE; }
"default"   { keyword_count++; token_count++; return DEFAULT; }
"do"        { keyword_count++; token_count++; return DO; }
"double"    { keyword_count++; token_count++; return DOUBLE; }
"else"      { keyword_count++; token_count++; return ELSE; }
"extern"    { keyword_count++; token_count++; return EXTERN; }
"float"     { keyword_count++; token_count++; return FLOAT; }
"for"       { keyword_count++; token_count++; return FOR; }
"if"        { keyword_count++; token_count++; return IF; }
"int"       { keyword_count++; token_count++; return INT; }
"long"      { keyword_count++; token_count++; return LONG; }
"return"    { keyword_count++; token_count++; return RETURN; }
"short"     { keyword_count++; token_count++; return SHORT; }
"sizeof"    { keyword_count++; token_count++; return SIZEOF; }
"struct"    { keyword_count++; token_count++; return STRUCT; }
"switch"    { keyword_count++; token_count++; return SWITCH; }
"void"      { keyword_count++; token_count++; return VOID; }
"while"     { keyword_count++; token_count++; return WHILE; }
"var"       { keyword_count++; token_count++; return VAR; }
"foreach"   { keyword_count++; token_count++; return FOREACH; }
"in"        { keyword_count++; token_count++; return IN; }
"match"     { keyword_count++; token_count++; return MATCH; }
"fn"        { keyword_count++; token_count++; return FN; }
"const"     { keyword_count++; token_count++; return CONST; }

{L}{A}* { id_count++; token_count++; return check_type(); }

{HP}{H}+{IS}?               { constant_count++; token_count++; return I_CONSTANT; }
{NZ}{D}*{IS}?               { constant_count++; token_count++; return I_CONSTANT; }
"0"{O}*{IS}?                { constant_count++; token_count++; return I_CONSTANT; }
{CP}?"'"([^'\\\n]|{ES})+"'" { constant_count++; token_count++; return I_CONSTANT; }

{D}+{E}{FS}?                { constant_count++; token_count++; return F_CONSTANT; }
{D}*"."{D}+{E}?{FS}?        { constant_count++; token_count++; return F_CONSTANT; }
{D}+"."{E}?{FS}?            { constant_count++; token_count++; return F_CONSTANT; }
{HP}{H}+{P}{FS}?            { constant_count++; token_count++; return F_CONSTANT; }
{HP}{H}*"."{H}+{P}{FS}?     { constant_count++; token_count++; return F_CONSTANT; }
{HP}{H}+"."{P}{FS}?         { constant_count++; token_count++; return F_CONSTANT; }

({SP}?\"([^"\\\n]|{ES})*\"{WS}*)+       { string_count++; token_count++; return STRING_LITERAL; }

"<=>" { operator_count++; token_count++; return TH_OP; }
"?."  { operator_count++; token_count++; return SAFE_DOT; }
"=>"  { operator_count++; token_count++; return LAMBDA_ARROW; }
"**"  { operator_count++; token_count++; return POW_OP; }
"++"  { operator_count++; token_count++; return INC_OP; }
"--"  { operator_count++; token_count++; return DEC_OP; }
"->"  { operator_count++; token_count++; return PTR_OP; }
"&&"  { operator_count++; token_count++; return AND_OP; }
"||"  { operator_count++; token_count++; return OR_OP; }
"<="  { operator_count++; token_count++; return LE_OP; }
">="  { operator_count++; token_count++; return GE_OP; }
"=="  { operator_count++; token_count++; return EQ_OP; }
"!="  { operator_count++; token_count++; return NE_OP; }
";"   { operator_count++; token_count++; return ';'; }
("{"|"<%") { depth++; if (depth > max_depth) max_depth = depth; operator_count++; token_count++; return '{'; }
("}"|"%>") { depth--; operator_count++; token_count++; return '}'; }
","   { operator_count++; token_count++; return ','; }
":"   { operator_count++; token_count++; return ':'; }
"="   { operator_count++; token_count++; return '='; }
"("   { operator_count++; token_count++; return '('; }
")"   { operator_count++; token_count++; return ')'; }
("["|"<:") { operator_count++; token_count++; return '['; }
("]"|":>") { operator_count++; token_count++; return ']'; }
"."   { operator_count++; token_count++; return '.'; }
"&"   { operator_count++; token_count++; return '&'; }
"!"   { operator_count++; token_count++; return '!'; }
"~"   { operator_count++; token_count++; return '~'; }
"-"   { operator_count++; token_count++; return '-'; }
"+"   { operator_count++; token_count++; return '+'; }
"*"   { operator_count++; token_count++; return '*'; }
"/"   { operator_count++; token_count++; return '/'; }
"%"   { operator_count++; token_count++; return '%'; }
"<"   { operator_count++; token_count++; return '<'; }
">"   { operator_count++; token_count++; return '>'; }
"^"   { operator_count++; token_count++; return '^'; }
"|"   { operator_count++; token_count++; return '|'; }
"?"   { operator_count++; token_count++; return '?'; }

{WS}+ {
    for(int i = 0; i < yyleng; i++)
        if(yytext[i] == '\n')
            yylineno++;
}
.                                       { /* discard bad characters */ }

%%
int yywrap(void)        /* called at end of input */
{
    return 1;           /* terminate now */
}

static void comment(void)
{
    int c;

    while ((c = input()) != 0)
        if (c == '*')
        {
            while ((c = input()) == '*')
                ;

            if (c == '/')
                return;

            if (c == 0)
                break;
        }

    sprintf(buff,"***lexing terminated*** [lexer error]: ill-formed comment");
    mode = 0;
    yyerror(buff);
}

static int check_type(void)
{
    return IDENTIFIER;
}