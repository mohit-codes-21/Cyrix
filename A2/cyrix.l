%option noyywrap

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
WS  [ \t\v\n\f\r]

%{
#include <stdio.h>
#include <stdlib.h>

/* Minimal token IDs */
#define IDENTIFIER 256
#define I_CONSTANT 257
#define F_CONSTANT 258
#define STRING_LITERAL 259

extern char *yytext;
static void comment(void);
static int check_type(void);
%}

%%

"/*"                { comment(); }
"//".*              { /* ignore */ }

"break"     { printf("BREAK\n"); }
"case"      { printf("CASE\n"); }
"char"      { printf("CHAR\n"); }
"continue"  { printf("CONTINUE\n"); }
"default"   { printf("DEFAULT\n"); }
"do"        { printf("DO\n"); }
"double"    { printf("DOUBLE\n"); }
"else"      { printf("ELSE\n"); }
"extern"    { printf("EXTERN\n"); }
"float"     { printf("FLOAT\n"); }
"for"       { printf("FOR\n"); }
"if"        { printf("IF\n"); }
"int"       { printf("INT\n"); }
"long"      { printf("LONG\n"); }
"return"    { printf("RETURN\n"); }
"short"     { printf("SHORT\n"); }
"sizeof"    { printf("SIZEOF\n"); }
"struct"    { printf("STRUCT\n"); }
"switch"    { printf("SWITCH\n"); }
"void"      { printf("VOID\n"); }
"while"     { printf("WHILE\n"); }
"var"      { printf("VAR\n"); }
"foreach"  { printf("FOREACH\n"); }
"in"       { printf("IN\n"); }
"match"    { printf("MATCH\n"); }
"const"    { printf("CONST\n"); }

{L}{A}*     { check_type(); }

{HP}{H}+{IS}?            { printf("I_CONSTANT: %s\n", yytext); }
{NZ}{D}*{IS}?            { printf("I_CONSTANT: %s\n", yytext); }
"0"{O}*{IS}?             { printf("I_CONSTANT: %s\n", yytext); }
{CP}?"'"([^'\\\n]|{ES})+"'" { printf("I_CONSTANT: %s\n", yytext); }

{D}+{E}{FS}?                 { printf("F_CONSTANT: %s\n", yytext); }
{D}*"."{D}+{E}?{FS}?         { printf("F_CONSTANT: %s\n", yytext); }
{D}+"."{E}?{FS}?             { printf("F_CONSTANT: %s\n", yytext); }
{HP}{H}+{P}{FS}?             { printf("F_CONSTANT: %s\n", yytext); }
{HP}{H}*"."{H}+{P}{FS}?      { printf("F_CONSTANT: %s\n", yytext); }
{HP}{H}+"."{P}{FS}?          { printf("F_CONSTANT: %s\n", yytext); }

({SP}?\"([^"\\\n]|{ES})*\"{WS}*)+ { printf("STRING_LITERAL\n"); }

"<=>"      { printf("TH_OP\n"); }
"?."  { printf("SAFE_DOT\n"); }
"=>"  { printf("LAMBDA_ARROW\n"); }
"**"  { printf("POW_OP\n"); }
"++"       { printf("INC_OP\n"); }
"--"       { printf("DEC_OP\n"); }
"->"       { printf("PTR_OP\n"); }
"&&"       { printf("AND_OP\n"); }
"||"       { printf("OR_OP\n"); }
"<="       { printf("LE_OP\n"); }
">="       { printf("GE_OP\n"); }
"=="       { printf("EQ_OP\n"); }
"!="       { printf("NE_OP\n"); }
";"        { printf(";\n"); }
("{"|"<%") { printf("{\n"); }
("}"|"%>") { printf("}\n"); }
","        { printf(",\n"); }
":"        { printf(":\n"); }
"="        { printf("=\n"); }
"("        { printf("(\n"); }
")"        { printf(")\n"); }
("["|"<:") { printf("[\n"); }
("]"|":>") { printf("]\n"); }
"."        { printf(".\n"); }
"&"        { printf("&\n"); }
"!"        { printf("!\n"); }
"~"        { printf("~\n"); }
"-"        { printf("-\n"); }
"+"        { printf("+\n"); }
"*"        { printf("*\n"); }
"/"        { printf("/\n"); }
"%"        { printf("%%\n"); }   
"<"        { printf("<\n"); }
">"        { printf(">\n"); }
"^"        { printf("^\n"); }
"|"        { printf("|\n"); }
"?"        { printf("?\n"); }

{WS}+   { /* ignore */ }
.       { printf("UNKNOWN: %s\n", yytext); }

%%

static void comment(void)
{
    int c;
    while ((c = input()) != 0)
        if (c == '*')
        {
            while ((c = input()) == '*');
            if (c == '/') return;
        }

    printf("***lexing terminated*** [lexer error]: ill-formed comment\n");
    exit(1);
}

static int check_type(void)
{
    printf("IDENTIFIER: %s\n", yytext);
    return IDENTIFIER;
}

int main(int argc, char **argv)
{
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            printf("Cannot open file\n");
            return 1;
        }
        yyin = file;
    }

    printf("Cyrix Lexer Started...\n");
    yylex();
    printf("Cyrix Lexer Finished.\n");
    return 0;
}