%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char *yytext;
extern int yylineno;

char buff[2048];
int mode = -1;

int yylex(void);
void yyerror(const char *s);

char *derivations[20000];
int derivation_count = 0;
%}
%define parse.error verbose

%token	IDENTIFIER I_CONSTANT F_CONSTANT STRING_LITERAL FUNC_NAME SIZEOF
%token	PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP TH_OP
%token	AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token	SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token	XOR_ASSIGN OR_ASSIGN
%token	TYPEDEF_NAME ENUMERATION_CONSTANT
%token  VAR FOREACH IN MATCH
%token  SAFE_DOT LAMBDA_ARROW POW_OP

%token	TYPEDEF EXTERN STATIC AUTO REGISTER INLINE
%token	CONST RESTRICT VOLATILE
%token	BOOL CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE VOID
%token	COMPLEX IMAGINARY 
%token	STRUCT UNION ENUM ELLIPSIS

%token	CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%token	ALIGNAS ALIGNOF ATOMIC GENERIC NORETURN STATIC_ASSERT THREAD_LOCAL

%start translation_unit

%%

lambda_params
	: IDENTIFIER { derivations[derivation_count++] = "lambda_params -> IDENTIFIER"; }
	| lambda_params ',' IDENTIFIER { derivations[derivation_count++] = "lambda_params -> lambda_params , IDENTIFIER"; }
	;

lambda_expression
	: '(' ')' LAMBDA_ARROW expression { derivations[derivation_count++] = "lambda_expression -> ( ) LAMBDA_ARROW expression"; }
	| '(' ')' LAMBDA_ARROW compound_statement { derivations[derivation_count++] = "lambda_expression -> ( ) LAMBDA_ARROW compound_statement"; }
	| '(' lambda_params ')' LAMBDA_ARROW expression { derivations[derivation_count++] = "lambda_expression -> ( lambda_params ) LAMBDA_ARROW expression"; }
	| '(' lambda_params ')' LAMBDA_ARROW compound_statement { derivations[derivation_count++] = "lambda_expression -> ( lambda_params ) LAMBDA_ARROW compound_statement"; }
	;

primary_expression
	: IDENTIFIER { derivations[derivation_count++] = "primary_expression -> IDENTIFIER"; }
	| constant { derivations[derivation_count++] = "primary_expression -> constant"; }
	| string { derivations[derivation_count++] = "primary_expression -> string"; }
	| '(' expression ')' { derivations[derivation_count++] = "primary_expression -> ( expression )"; }
	| generic_selection { derivations[derivation_count++] = "primary_expression -> generic_selection"; }
    | lambda_expression { derivations[derivation_count++] = "primary_expression -> lambda_expression"; }
	;

constant
	: I_CONSTANT { derivations[derivation_count++] = "constant -> I_CONSTANT"; }   /* includes character_constant */
	| F_CONSTANT { derivations[derivation_count++] = "constant -> F_CONSTANT"; }
	| ENUMERATION_CONSTANT { derivations[derivation_count++] = "constant -> ENUMERATION_CONSTANT"; }	/* after it has been defined as such */
	;

enumeration_constant		/* before it has been defined as such */
	: IDENTIFIER { derivations[derivation_count++] = "enumeration_constant -> IDENTIFIER"; }
	;

string
	: STRING_LITERAL { derivations[derivation_count++] = "string -> STRING_LITERAL"; }
	| FUNC_NAME { derivations[derivation_count++] = "string -> FUNC_NAME"; }
	;

generic_selection
	: GENERIC '(' assignment_expression ',' generic_assoc_list ')' { derivations[derivation_count++] = "generic_selection -> GENERIC ( assignment_expression , generic_assoc_list )"; }
	;

generic_assoc_list
	: generic_association { derivations[derivation_count++] = "generic_assoc_list -> generic_association"; }
	| generic_assoc_list ',' generic_association { derivations[derivation_count++] = "generic_assoc_list -> generic_assoc_list , generic_association"; }
	;

generic_association
	: type_name ':' assignment_expression { derivations[derivation_count++] = "generic_association -> type_name : assignment_expression"; }
	| DEFAULT ':' assignment_expression { derivations[derivation_count++] = "generic_association -> DEFAULT : assignment_expression"; }
	;

postfix_expression
	: primary_expression { derivations[derivation_count++] = "postfix_expression -> primary_expression"; }
	| postfix_expression '[' expression ']' { derivations[derivation_count++] = "postfix_expression -> postfix_expression [ expression ]"; }
	| postfix_expression '(' ')' { derivations[derivation_count++] = "postfix_expression -> postfix_expression ( )"; }
	| postfix_expression '(' argument_expression_list ')' { derivations[derivation_count++] = "postfix_expression -> postfix_expression ( argument_expression_list )"; }
	| postfix_expression '.' IDENTIFIER { derivations[derivation_count++] = "postfix_expression -> postfix_expression . IDENTIFIER"; }
	| postfix_expression PTR_OP IDENTIFIER { derivations[derivation_count++] = "postfix_expression -> postfix_expression PTR_OP IDENTIFIER"; }
    | postfix_expression SAFE_DOT IDENTIFIER { derivations[derivation_count++] = "postfix_expression -> postfix_expression SAFE_DOT IDENTIFIER"; }
	| postfix_expression INC_OP { derivations[derivation_count++] = "postfix_expression -> postfix_expression INC_OP"; }
	| postfix_expression DEC_OP { derivations[derivation_count++] = "postfix_expression -> postfix_expression DEC_OP"; }
	| '(' type_name ')' '{' initializer_list '}' { derivations[derivation_count++] = "postfix_expression -> ( type_name ) { initializer_list }"; }
	| '(' type_name ')' '{' initializer_list ',' '}' { derivations[derivation_count++] = "postfix_expression -> ( type_name ) { initializer_list , }"; }
	;

argument_expression_list
	: assignment_expression { derivations[derivation_count++] = "argument_expression_list -> assignment_expression"; }
	| argument_expression_list ',' assignment_expression { derivations[derivation_count++] = "argument_expression_list -> argument_expression_list , assignment_expression"; }
	;

unary_expression
	: postfix_expression { derivations[derivation_count++] = "unary_expression -> postfix_expression"; }
	| INC_OP unary_expression { derivations[derivation_count++] = "unary_expression -> INC_OP unary_expression"; }
	| DEC_OP unary_expression { derivations[derivation_count++] = "unary_expression -> DEC_OP unary_expression"; }
	| unary_operator cast_expression { derivations[derivation_count++] = "unary_expression -> unary_operator cast_expression"; }
	| SIZEOF unary_expression { derivations[derivation_count++] = "unary_expression -> SIZEOF unary_expression"; }
	| SIZEOF '(' type_name ')' { derivations[derivation_count++] = "unary_expression -> SIZEOF ( type_name )"; }
	| ALIGNOF '(' type_name ')' { derivations[derivation_count++] = "unary_expression -> ALIGNOF ( type_name )"; }
	;

unary_operator
	: '&' { derivations[derivation_count++] = "unary_operator -> &"; }
	| '*' { derivations[derivation_count++] = "unary_operator -> *"; }
	| '+' { derivations[derivation_count++] = "unary_operator -> +"; }
	| '-' { derivations[derivation_count++] = "unary_operator -> -"; }
	| '~' { derivations[derivation_count++] = "unary_operator -> ~"; }
	| '!' { derivations[derivation_count++] = "unary_operator -> !"; }
	;

cast_expression
	: unary_expression { derivations[derivation_count++] = "cast_expression -> unary_expression"; }
	| '(' type_name ')' cast_expression { derivations[derivation_count++] = "cast_expression -> ( type_name ) cast_expression"; }
	;

power_expression
	: cast_expression { derivations[derivation_count++] = "power_expression -> cast_expression"; }
	| cast_expression POW_OP power_expression { derivations[derivation_count++] = "power_expression -> cast_expression POW_OP power_expression"; }
	;

multiplicative_expression
	: power_expression { derivations[derivation_count++] = "multiplicative_expression -> power_expression"; }
	| multiplicative_expression '*' power_expression { derivations[derivation_count++] = "multiplicative_expression -> multiplicative_expression * power_expression"; }
	| multiplicative_expression '/' power_expression { derivations[derivation_count++] = "multiplicative_expression -> multiplicative_expression / power_expression"; }
	| multiplicative_expression '%' power_expression { derivations[derivation_count++] = "multiplicative_expression -> multiplicative_expression % power_expression"; }
	;

additive_expression
	: multiplicative_expression { derivations[derivation_count++] = "additive_expression -> multiplicative_expression"; }
	| additive_expression '+' multiplicative_expression { derivations[derivation_count++] = "additive_expression -> additive_expression + multiplicative_expression"; }
	| additive_expression '-' multiplicative_expression { derivations[derivation_count++] = "additive_expression -> additive_expression - multiplicative_expression"; }
	;

shift_expression
	: additive_expression { derivations[derivation_count++] = "shift_expression -> additive_expression"; }
	| shift_expression LEFT_OP additive_expression { derivations[derivation_count++] = "shift_expression -> shift_expression LEFT_OP additive_expression"; }
	| shift_expression RIGHT_OP additive_expression { derivations[derivation_count++] = "shift_expression -> shift_expression RIGHT_OP additive_expression"; }
	;

relational_expression
	: shift_expression { derivations[derivation_count++] = "relational_expression -> shift_expression"; }
	| relational_expression '<' shift_expression { derivations[derivation_count++] = "relational_expression -> relational_expression < shift_expression"; }
	| relational_expression '>' shift_expression { derivations[derivation_count++] = "relational_expression -> relational_expression > shift_expression"; }
	| relational_expression LE_OP shift_expression { derivations[derivation_count++] = "relational_expression -> relational_expression LE_OP shift_expression"; }
	| relational_expression GE_OP shift_expression { derivations[derivation_count++] = "relational_expression -> relational_expression GE_OP shift_expression"; }
	| relational_expression TH_OP shift_expression { derivations[derivation_count++] = "relational_expression -> relational_expression TH_OP shift_expression"; }
	;

equality_expression
	: relational_expression { derivations[derivation_count++] = "equality_expression -> relational_expression"; }
	| equality_expression EQ_OP relational_expression { derivations[derivation_count++] = "equality_expression -> equality_expression EQ_OP relational_expression"; }
	| equality_expression NE_OP relational_expression { derivations[derivation_count++] = "equality_expression -> equality_expression NE_OP relational_expression"; }
	;

and_expression
	: equality_expression { derivations[derivation_count++] = "and_expression -> equality_expression"; }
	| and_expression '&' equality_expression { derivations[derivation_count++] = "and_expression -> and_expression & equality_expression"; }
	;

exclusive_or_expression
	: and_expression { derivations[derivation_count++] = "exclusive_or_expression -> and_expression"; }
	| exclusive_or_expression '^' and_expression { derivations[derivation_count++] = "exclusive_or_expression -> exclusive_or_expression ^ and_expression"; }
	;

inclusive_or_expression
	: exclusive_or_expression { derivations[derivation_count++] = "inclusive_or_expression -> exclusive_or_expression"; }
	| inclusive_or_expression '|' exclusive_or_expression { derivations[derivation_count++] = "inclusive_or_expression -> inclusive_or_expression | exclusive_or_expression"; }
	;

logical_and_expression
	: inclusive_or_expression { derivations[derivation_count++] = "logical_and_expression -> inclusive_or_expression"; }
	| logical_and_expression AND_OP inclusive_or_expression { derivations[derivation_count++] = "logical_and_expression -> logical_and_expression AND_OP inclusive_or_expression"; }
	;

logical_or_expression
	: logical_and_expression { derivations[derivation_count++] = "logical_or_expression -> logical_and_expression"; }
	| logical_or_expression OR_OP logical_and_expression { derivations[derivation_count++] = "logical_or_expression -> logical_or_expression OR_OP logical_and_expression"; }
	;

conditional_expression
	: logical_or_expression { derivations[derivation_count++] = "conditional_expression -> logical_or_expression"; }
	;

lhs_list
	: IDENTIFIER { derivations[derivation_count++] = "lhs_list -> IDENTIFIER"; }
	| lhs_list ',' IDENTIFIER { derivations[derivation_count++] = "lhs_list -> lhs_list , IDENTIFIER"; }
	;

rhs_list
	: assignment_expression { derivations[derivation_count++] = "rhs_list -> assignment_expression"; }
	| rhs_list ',' assignment_expression { derivations[derivation_count++] = "rhs_list -> rhs_list , assignment_expression"; }
	;

multi_assignment
	: lhs_list '=' rhs_list { derivations[derivation_count++] = "multi_assignment -> lhs_list = rhs_list"; }
	;

assignment_expression
	: conditional_expression { derivations[derivation_count++] = "assignment_expression -> conditional_expression"; }
	| unary_expression assignment_operator assignment_expression { derivations[derivation_count++] = "assignment_expression -> unary_expression assignment_operator assignment_expression"; }
	;

assignment_operator
	: '=' { derivations[derivation_count++] = "assignment_operator -> ="; }
	| MUL_ASSIGN { derivations[derivation_count++] = "assignment_operator -> MUL_ASSIGN"; }
	| DIV_ASSIGN { derivations[derivation_count++] = "assignment_operator -> DIV_ASSIGN"; }
	| MOD_ASSIGN { derivations[derivation_count++] = "assignment_operator -> MOD_ASSIGN"; }
	| ADD_ASSIGN { derivations[derivation_count++] = "assignment_operator -> ADD_ASSIGN"; }
	| SUB_ASSIGN { derivations[derivation_count++] = "assignment_operator -> SUB_ASSIGN"; }
	| LEFT_ASSIGN { derivations[derivation_count++] = "assignment_operator -> LEFT_ASSIGN"; }
	| RIGHT_ASSIGN { derivations[derivation_count++] = "assignment_operator -> RIGHT_ASSIGN"; }
	| AND_ASSIGN { derivations[derivation_count++] = "assignment_operator -> AND_ASSIGN"; }
	| XOR_ASSIGN { derivations[derivation_count++] = "assignment_operator -> XOR_ASSIGN"; }
	| OR_ASSIGN { derivations[derivation_count++] = "assignment_operator -> OR_ASSIGN"; }
	;

expression
	: assignment_expression { derivations[derivation_count++] = "expression -> assignment_expression"; }
	| expression ',' assignment_expression { derivations[derivation_count++] = "expression -> expression , assignment_expression"; }
	;

constant_expression
	: conditional_expression { derivations[derivation_count++] = "constant_expression -> conditional_expression"; }	/* with constraints */
	;

var_init_list
	: var_init { derivations[derivation_count++] = "var_init_list -> var_init"; }
	| var_init_list ',' var_init { derivations[derivation_count++] = "var_init_list -> var_init_list , var_init"; }
	;

var_init
	: IDENTIFIER '=' assignment_expression { derivations[derivation_count++] = "var_init -> IDENTIFIER = assignment_expression"; }
	;

var_declaration
	: VAR var_init_list ';' { derivations[derivation_count++] = "var_declaration -> VAR var_init_list ;"; }
	;

declaration
	: declaration_specifiers ';' { derivations[derivation_count++] = "declaration -> declaration_specifiers ;"; }
	| declaration_specifiers init_declarator_list ';' { derivations[derivation_count++] = "declaration -> declaration_specifiers init_declarator_list ;"; }
	| static_assert_declaration { derivations[derivation_count++] = "declaration -> static_assert_declaration"; }
    | var_declaration { derivations[derivation_count++] = "declaration -> var_declaration"; }
	;

declaration_specifiers
	: storage_class_specifier declaration_specifiers { derivations[derivation_count++] = "declaration_specifiers -> storage_class_specifier declaration_specifiers"; }
	| storage_class_specifier { derivations[derivation_count++] = "declaration_specifiers -> storage_class_specifier"; }
	| type_specifier declaration_specifiers { derivations[derivation_count++] = "declaration_specifiers -> type_specifier declaration_specifiers"; }
	| type_specifier { derivations[derivation_count++] = "declaration_specifiers -> type_specifier"; }
	| type_qualifier declaration_specifiers { derivations[derivation_count++] = "declaration_specifiers -> type_qualifier declaration_specifiers"; }
	| type_qualifier { derivations[derivation_count++] = "declaration_specifiers -> type_qualifier"; }
	| function_specifier declaration_specifiers { derivations[derivation_count++] = "declaration_specifiers -> function_specifier declaration_specifiers"; }
	| function_specifier { derivations[derivation_count++] = "declaration_specifiers -> function_specifier"; }
	| alignment_specifier declaration_specifiers { derivations[derivation_count++] = "declaration_specifiers -> alignment_specifier declaration_specifiers"; }
	| alignment_specifier { derivations[derivation_count++] = "declaration_specifiers -> alignment_specifier"; }
	;

init_declarator_list
	: init_declarator { derivations[derivation_count++] = "init_declarator_list -> init_declarator"; }
	| init_declarator_list ',' init_declarator { derivations[derivation_count++] = "init_declarator_list -> init_declarator_list , init_declarator"; }
	;

init_declarator
	: declarator '=' initializer { derivations[derivation_count++] = "init_declarator -> declarator = initializer"; }
	| declarator { derivations[derivation_count++] = "init_declarator -> declarator"; }
	;

storage_class_specifier
	: TYPEDEF { derivations[derivation_count++] = "storage_class_specifier -> TYPEDEF"; }	/* identifiers must be flagged as TYPEDEF_NAME */
	| EXTERN { derivations[derivation_count++] = "storage_class_specifier -> EXTERN"; }
	| STATIC { derivations[derivation_count++] = "storage_class_specifier -> STATIC"; }
	| THREAD_LOCAL { derivations[derivation_count++] = "storage_class_specifier -> THREAD_LOCAL"; }
	| AUTO { derivations[derivation_count++] = "storage_class_specifier -> AUTO"; }
	| REGISTER { derivations[derivation_count++] = "storage_class_specifier -> REGISTER"; }
	;

type_specifier
	: VOID { derivations[derivation_count++] = "type_specifier -> VOID"; }
	| CHAR { derivations[derivation_count++] = "type_specifier -> CHAR"; }
	| SHORT { derivations[derivation_count++] = "type_specifier -> SHORT"; }
	| INT { derivations[derivation_count++] = "type_specifier -> INT"; }
	| LONG { derivations[derivation_count++] = "type_specifier -> LONG"; }
	| FLOAT { derivations[derivation_count++] = "type_specifier -> FLOAT"; }
	| DOUBLE { derivations[derivation_count++] = "type_specifier -> DOUBLE"; }
	| SIGNED { derivations[derivation_count++] = "type_specifier -> SIGNED"; }
	| UNSIGNED { derivations[derivation_count++] = "type_specifier -> UNSIGNED"; }
	| BOOL { derivations[derivation_count++] = "type_specifier -> BOOL"; }
	| COMPLEX { derivations[derivation_count++] = "type_specifier -> COMPLEX"; }
	| IMAGINARY { derivations[derivation_count++] = "type_specifier -> IMAGINARY"; }  	/* non-mandated extension */
	| atomic_type_specifier { derivations[derivation_count++] = "type_specifier -> atomic_type_specifier"; }
	| struct_or_union_specifier { derivations[derivation_count++] = "type_specifier -> struct_or_union_specifier"; }
	| enum_specifier { derivations[derivation_count++] = "type_specifier -> enum_specifier"; }
	| TYPEDEF_NAME { derivations[derivation_count++] = "type_specifier -> TYPEDEF_NAME"; }		/* after it has been defined as such */
	;

struct_or_union_specifier
	: struct_or_union '{' struct_declaration_list '}' { derivations[derivation_count++] = "struct_or_union_specifier -> struct_or_union { struct_declaration_list }"; }
	| struct_or_union IDENTIFIER '{' struct_declaration_list '}' { derivations[derivation_count++] = "struct_or_union_specifier -> struct_or_union IDENTIFIER { struct_declaration_list }"; }
	| struct_or_union IDENTIFIER { derivations[derivation_count++] = "struct_or_union_specifier -> struct_or_union IDENTIFIER"; }
	;

struct_or_union
	: STRUCT { derivations[derivation_count++] = "struct_or_union -> STRUCT"; }
	| UNION { derivations[derivation_count++] = "struct_or_union -> UNION"; }
	;

struct_declaration_list
	: struct_declaration { derivations[derivation_count++] = "struct_declaration_list -> struct_declaration"; }
	| struct_declaration_list struct_declaration { derivations[derivation_count++] = "struct_declaration_list -> struct_declaration_list struct_declaration"; }
	;

struct_declaration
	: specifier_qualifier_list ';' { derivations[derivation_count++] = "struct_declaration -> specifier_qualifier_list ;"; }	/* for anonymous struct/union */
	| specifier_qualifier_list struct_declarator_list ';' { derivations[derivation_count++] = "struct_declaration -> specifier_qualifier_list struct_declarator_list ;"; }
	| static_assert_declaration { derivations[derivation_count++] = "struct_declaration -> static_assert_declaration"; }
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list { derivations[derivation_count++] = "specifier_qualifier_list -> type_specifier specifier_qualifier_list"; }
	| type_specifier { derivations[derivation_count++] = "specifier_qualifier_list -> type_specifier"; }
	| type_qualifier specifier_qualifier_list { derivations[derivation_count++] = "specifier_qualifier_list -> type_qualifier specifier_qualifier_list"; }
	| type_qualifier { derivations[derivation_count++] = "specifier_qualifier_list -> type_qualifier"; }
	;

struct_declarator_list
	: struct_declarator { derivations[derivation_count++] = "struct_declarator_list -> struct_declarator"; }
	| struct_declarator_list ',' struct_declarator { derivations[derivation_count++] = "struct_declarator_list -> struct_declarator_list , struct_declarator"; }
	;

struct_declarator
	: ':' constant_expression { derivations[derivation_count++] = "struct_declarator -> : constant_expression"; }
	| declarator ':' constant_expression { derivations[derivation_count++] = "struct_declarator -> declarator : constant_expression"; }
	| declarator { derivations[derivation_count++] = "struct_declarator -> declarator"; }
	;

enum_specifier
	: ENUM '{' enumerator_list '}' { derivations[derivation_count++] = "enum_specifier -> ENUM { enumerator_list }"; }
	| ENUM '{' enumerator_list ',' '}' { derivations[derivation_count++] = "enum_specifier -> ENUM { enumerator_list , }"; }
	| ENUM IDENTIFIER '{' enumerator_list '}' { derivations[derivation_count++] = "enum_specifier -> ENUM IDENTIFIER { enumerator_list }"; }
	| ENUM IDENTIFIER '{' enumerator_list ',' '}' { derivations[derivation_count++] = "enum_specifier -> ENUM IDENTIFIER { enumerator_list , }"; }
	| ENUM IDENTIFIER { derivations[derivation_count++] = "enum_specifier -> ENUM IDENTIFIER"; }
	;

enumerator_list
	: enumerator { derivations[derivation_count++] = "enumerator_list -> enumerator"; }
	| enumerator_list ',' enumerator { derivations[derivation_count++] = "enumerator_list -> enumerator_list , enumerator"; }
	;

enumerator	/* identifiers must be flagged as ENUMERATION_CONSTANT */
	: enumeration_constant '=' constant_expression { derivations[derivation_count++] = "enumerator -> enumeration_constant = constant_expression"; }
	| enumeration_constant { derivations[derivation_count++] = "enumerator -> enumeration_constant"; }
	;

atomic_type_specifier
	: ATOMIC '(' type_name ')' { derivations[derivation_count++] = "atomic_type_specifier -> ATOMIC ( type_name )"; }
	;

type_qualifier
	: CONST { derivations[derivation_count++] = "type_qualifier -> CONST"; }
	| RESTRICT { derivations[derivation_count++] = "type_qualifier -> RESTRICT"; }
	| VOLATILE { derivations[derivation_count++] = "type_qualifier -> VOLATILE"; }
	| ATOMIC { derivations[derivation_count++] = "type_qualifier -> ATOMIC"; }
	;

function_specifier
	: INLINE { derivations[derivation_count++] = "function_specifier -> INLINE"; }
	| NORETURN { derivations[derivation_count++] = "function_specifier -> NORETURN"; }
	;

alignment_specifier
	: ALIGNAS '(' type_name ')' { derivations[derivation_count++] = "alignment_specifier -> ALIGNAS ( type_name )"; }
	| ALIGNAS '(' constant_expression ')' { derivations[derivation_count++] = "alignment_specifier -> ALIGNAS ( constant_expression )"; }
	;

declarator
	: pointer direct_declarator { derivations[derivation_count++] = "declarator -> pointer direct_declarator"; }
	| direct_declarator { derivations[derivation_count++] = "declarator -> direct_declarator"; }
	;

direct_declarator
	: IDENTIFIER { derivations[derivation_count++] = "direct_declarator -> IDENTIFIER"; }
	| '(' declarator ')' { derivations[derivation_count++] = "direct_declarator -> ( declarator )"; }
	| direct_declarator '[' ']' { derivations[derivation_count++] = "direct_declarator -> direct_declarator [ ]"; }
	| direct_declarator '[' '*' ']' { derivations[derivation_count++] = "direct_declarator -> direct_declarator [ * ]"; }
	| direct_declarator '[' STATIC type_qualifier_list assignment_expression ']' { derivations[derivation_count++] = "direct_declarator -> direct_declarator [ STATIC type_qualifier_list assignment_expression ]"; }
	| direct_declarator '[' STATIC assignment_expression ']' { derivations[derivation_count++] = "direct_declarator -> direct_declarator [ STATIC assignment_expression ]"; }
	| direct_declarator '[' type_qualifier_list '*' ']' { derivations[derivation_count++] = "direct_declarator -> direct_declarator [ type_qualifier_list * ]"; }
	| direct_declarator '[' type_qualifier_list STATIC assignment_expression ']' { derivations[derivation_count++] = "direct_declarator -> direct_declarator [ type_qualifier_list STATIC assignment_expression ]"; }
	| direct_declarator '[' type_qualifier_list assignment_expression ']' { derivations[derivation_count++] = "direct_declarator -> direct_declarator [ type_qualifier_list assignment_expression ]"; }
	| direct_declarator '[' type_qualifier_list ']' { derivations[derivation_count++] = "direct_declarator -> direct_declarator [ type_qualifier_list ]"; }
	| direct_declarator '[' assignment_expression ']' { derivations[derivation_count++] = "direct_declarator -> direct_declarator [ assignment_expression ]"; }
	| direct_declarator '(' parameter_type_list ')' { derivations[derivation_count++] = "direct_declarator -> direct_declarator ( parameter_type_list )"; }
	| direct_declarator '(' ')' { derivations[derivation_count++] = "direct_declarator -> direct_declarator ( )"; }
	| direct_declarator '(' identifier_list ')' { derivations[derivation_count++] = "direct_declarator -> direct_declarator ( identifier_list )"; }
	;

pointer
	: '*' type_qualifier_list pointer { derivations[derivation_count++] = "pointer -> * type_qualifier_list pointer"; }
	| '*' type_qualifier_list { derivations[derivation_count++] = "pointer -> * type_qualifier_list"; }
	| '*' pointer { derivations[derivation_count++] = "pointer -> * pointer"; }
	| '*' { derivations[derivation_count++] = "pointer -> *"; }
	;

type_qualifier_list
	: type_qualifier { derivations[derivation_count++] = "type_qualifier_list -> type_qualifier"; }
	| type_qualifier_list type_qualifier { derivations[derivation_count++] = "type_qualifier_list -> type_qualifier_list type_qualifier"; }
	;


parameter_type_list
	: parameter_list ',' ELLIPSIS { derivations[derivation_count++] = "parameter_type_list -> parameter_list , ELLIPSIS"; }
	| parameter_list { derivations[derivation_count++] = "parameter_type_list -> parameter_list"; }
	;

parameter_list
	: normal_param_list { derivations[derivation_count++] = "parameter_list -> normal_param_list"; }
	| normal_param_list ',' default_param_list { derivations[derivation_count++] = "parameter_list -> normal_param_list , default_param_list"; }
	| default_param_list { derivations[derivation_count++] = "parameter_list -> default_param_list"; }
	;

normal_param_list
	: normal_param { derivations[derivation_count++] = "normal_param_list -> normal_param"; }
	| normal_param_list ',' normal_param { derivations[derivation_count++] = "normal_param_list -> normal_param_list , normal_param"; }
	;

default_param_list
	: default_param { derivations[derivation_count++] = "default_param_list -> default_param"; }
	| default_param_list ',' default_param { derivations[derivation_count++] = "default_param_list -> default_param_list , default_param"; }
	;

normal_param
	: declaration_specifiers declarator { derivations[derivation_count++] = "normal_param -> declaration_specifiers declarator"; }
	| declaration_specifiers abstract_declarator { derivations[derivation_count++] = "normal_param -> declaration_specifiers abstract_declarator"; }
	| declaration_specifiers { derivations[derivation_count++] = "normal_param -> declaration_specifiers"; }
	;

default_param
	: declaration_specifiers declarator '=' assignment_expression { derivations[derivation_count++] = "default_param -> declaration_specifiers declarator = assignment_expression"; }
	;

identifier_list
	: IDENTIFIER { derivations[derivation_count++] = "identifier_list -> IDENTIFIER"; }
	| identifier_list ',' IDENTIFIER { derivations[derivation_count++] = "identifier_list -> identifier_list , IDENTIFIER"; }
	;

type_name
	: specifier_qualifier_list abstract_declarator { derivations[derivation_count++] = "type_name -> specifier_qualifier_list abstract_declarator"; }
	| specifier_qualifier_list { derivations[derivation_count++] = "type_name -> specifier_qualifier_list"; }
	;

abstract_declarator
	: pointer direct_abstract_declarator { derivations[derivation_count++] = "abstract_declarator -> pointer direct_abstract_declarator"; }
	| pointer { derivations[derivation_count++] = "abstract_declarator -> pointer"; }
	| direct_abstract_declarator { derivations[derivation_count++] = "abstract_declarator -> direct_abstract_declarator"; }
	;

direct_abstract_declarator
	: '(' abstract_declarator ')' { derivations[derivation_count++] = "direct_abstract_declarator -> ( abstract_declarator )"; }
	| '[' ']' { derivations[derivation_count++] = "direct_abstract_declarator -> [ ]"; }
	| '[' '*' ']' { derivations[derivation_count++] = "direct_abstract_declarator -> [ * ]"; }
	| '[' STATIC type_qualifier_list assignment_expression ']' { derivations[derivation_count++] = "direct_abstract_declarator -> [ STATIC type_qualifier_list assignment_expression ]"; }
	| '[' STATIC assignment_expression ']' { derivations[derivation_count++] = "direct_abstract_declarator -> [ STATIC assignment_expression ]"; }
	| '[' type_qualifier_list STATIC assignment_expression ']' { derivations[derivation_count++] = "direct_abstract_declarator -> [ type_qualifier_list STATIC assignment_expression ]"; }
	| '[' type_qualifier_list assignment_expression ']' { derivations[derivation_count++] = "direct_abstract_declarator -> [ type_qualifier_list assignment_expression ]"; }
	| '[' type_qualifier_list ']' { derivations[derivation_count++] = "direct_abstract_declarator -> [ type_qualifier_list ]"; }
	| '[' assignment_expression ']' { derivations[derivation_count++] = "direct_abstract_declarator -> [ assignment_expression ]"; }
	| direct_abstract_declarator '[' ']' { derivations[derivation_count++] = "direct_abstract_declarator -> direct_abstract_declarator [ ]"; }
	| direct_abstract_declarator '[' '*' ']' { derivations[derivation_count++] = "direct_abstract_declarator -> direct_abstract_declarator [ * ]"; }
	| direct_abstract_declarator '[' STATIC type_qualifier_list assignment_expression ']' { derivations[derivation_count++] = "direct_abstract_declarator -> direct_abstract_declarator [ STATIC type_qualifier_list assignment_expression ]"; }
	| direct_abstract_declarator '[' STATIC assignment_expression ']' { derivations[derivation_count++] = "direct_abstract_declarator -> direct_abstract_declarator [ STATIC assignment_expression ]"; }
	| direct_abstract_declarator '[' type_qualifier_list assignment_expression ']' { derivations[derivation_count++] = "direct_abstract_declarator -> direct_abstract_declarator [ type_qualifier_list assignment_expression ]"; }
	| direct_abstract_declarator '[' type_qualifier_list STATIC assignment_expression ']' { derivations[derivation_count++] = "direct_abstract_declarator -> direct_abstract_declarator [ type_qualifier_list STATIC assignment_expression ]"; }
	| direct_abstract_declarator '[' type_qualifier_list ']' { derivations[derivation_count++] = "direct_abstract_declarator -> direct_abstract_declarator [ type_qualifier_list ]"; }
	| direct_abstract_declarator '[' assignment_expression ']' { derivations[derivation_count++] = "direct_abstract_declarator -> direct_abstract_declarator [ assignment_expression ]"; }
	| '(' ')' { derivations[derivation_count++] = "direct_abstract_declarator -> ( )"; }
	| '(' parameter_type_list ')' { derivations[derivation_count++] = "direct_abstract_declarator -> ( parameter_type_list )"; }
	| direct_abstract_declarator '(' ')' { derivations[derivation_count++] = "direct_abstract_declarator -> direct_abstract_declarator ( )"; }
	| direct_abstract_declarator '(' parameter_type_list ')' { derivations[derivation_count++] = "direct_abstract_declarator -> direct_abstract_declarator ( parameter_type_list )"; }
	;

initializer
	: '{' initializer_list '}' { derivations[derivation_count++] = "initializer -> { initializer_list }"; }
	| '{' initializer_list ',' '}' { derivations[derivation_count++] = "initializer -> { initializer_list , }"; }
	| assignment_expression { derivations[derivation_count++] = "initializer -> assignment_expression"; }
	;

initializer_list
	: designation initializer { derivations[derivation_count++] = "initializer_list -> designation initializer"; }
	| initializer { derivations[derivation_count++] = "initializer_list -> initializer"; }
	| initializer_list ',' designation initializer { derivations[derivation_count++] = "initializer_list -> initializer_list , designation initializer"; }
	| initializer_list ',' initializer { derivations[derivation_count++] = "initializer_list -> initializer_list , initializer"; }
	;

designation
	: designator_list '=' { derivations[derivation_count++] = "designation -> designator_list ="; }
	;

designator_list
	: designator { derivations[derivation_count++] = "designator_list -> designator"; }
	| designator_list designator { derivations[derivation_count++] = "designator_list -> designator_list designator"; }
	;

designator
	: '[' constant_expression ']' { derivations[derivation_count++] = "designator -> [ constant_expression ]"; }
	| '.' IDENTIFIER { derivations[derivation_count++] = "designator -> . IDENTIFIER"; }
	;

static_assert_declaration
	: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';' { derivations[derivation_count++] = "static_assert_declaration -> STATIC_ASSERT ( constant_expression , STRING_LITERAL ) ;"; }
	;

statement
	: labeled_statement { derivations[derivation_count++] = "statement -> labeled_statement"; }
	| compound_statement { derivations[derivation_count++] = "statement -> compound_statement"; }
	| expression_statement { derivations[derivation_count++] = "statement -> expression_statement"; }
	| selection_statement { derivations[derivation_count++] = "statement -> selection_statement"; }
	| iteration_statement { derivations[derivation_count++] = "statement -> iteration_statement"; }
	| jump_statement { derivations[derivation_count++] = "statement -> jump_statement"; }
	;

labeled_statement
	: IDENTIFIER ':' statement { derivations[derivation_count++] = "labeled_statement -> IDENTIFIER : statement"; }
	| CASE constant_expression ':' statement { derivations[derivation_count++] = "labeled_statement -> CASE constant_expression : statement"; }
	| DEFAULT ':' statement { derivations[derivation_count++] = "labeled_statement -> DEFAULT : statement"; }
	;

compound_statement
	: '{' '}' { derivations[derivation_count++] = "compound_statement -> { }"; }
	| '{'  block_item_list '}' { derivations[derivation_count++] = "compound_statement -> { block_item_list }"; }
	;

block_item_list
	: block_item { derivations[derivation_count++] = "block_item_list -> block_item"; }
	| block_item_list block_item { derivations[derivation_count++] = "block_item_list -> block_item_list block_item"; }
	;

block_item
	: declaration { derivations[derivation_count++] = "block_item -> declaration"; }
	| statement { derivations[derivation_count++] = "block_item -> statement"; }
	;

expression_statement
	: ';' { derivations[derivation_count++] = "expression_statement -> ;"; }
	| expression ';' { derivations[derivation_count++] = "expression_statement -> expression ;"; }
    | multi_assignment ';' { derivations[derivation_count++] = "expression_statement -> multi_assignment ;"; }
	;

match_statement
	: MATCH '(' expression ')' '{' case_list default_opt '}' { derivations[derivation_count++] = "match_statement -> MATCH ( expression ) { case_list default_opt }"; }
	;

case_list
	: case_list match_case { derivations[derivation_count++] = "case_list -> case_list match_case"; }
	| match_case { derivations[derivation_count++] = "case_list -> match_case"; }
	;

match_case
	: CASE constant_expression ':' statement { derivations[derivation_count++] = "match_case -> CASE constant_expression : statement"; }
	;

default_opt
	: /* empty */ { derivations[derivation_count++] = "default_opt -> epsilon"; }
	| DEFAULT ':' statement { derivations[derivation_count++] = "default_opt -> DEFAULT : statement"; }
	;

selection_statement
	: IF '(' expression ')' statement ELSE statement { derivations[derivation_count++] = "selection_statement -> IF ( expression ) statement ELSE statement"; }
	| IF '(' expression ')' statement { derivations[derivation_count++] = "selection_statement -> IF ( expression ) statement"; }
	| SWITCH '(' expression ')' statement { derivations[derivation_count++] = "selection_statement -> SWITCH ( expression ) statement"; }
    | match_statement { derivations[derivation_count++] = "selection_statement -> match_statement"; }
	;

foreach_var
	: IDENTIFIER { derivations[derivation_count++] = "foreach_var -> IDENTIFIER"; }
	| type_specifier IDENTIFIER { derivations[derivation_count++] = "foreach_var -> type_specifier IDENTIFIER"; }
	;

iteration_statement
	: WHILE '(' expression ')' statement { derivations[derivation_count++] = "iteration_statement -> WHILE ( expression ) statement"; }
	| DO statement WHILE '(' expression ')' ';' { derivations[derivation_count++] = "iteration_statement -> DO statement WHILE ( expression ) ;"; }
	| FOR '(' expression_statement expression_statement ')' statement { derivations[derivation_count++] = "iteration_statement -> FOR ( expression_statement expression_statement ) statement"; }
	| FOR '(' expression_statement expression_statement expression ')' statement { derivations[derivation_count++] = "iteration_statement -> FOR ( expression_statement expression_statement expression ) statement"; }
	| FOR '(' declaration expression_statement ')' statement { derivations[derivation_count++] = "iteration_statement -> FOR ( declaration expression_statement ) statement"; }
	| FOR '(' declaration expression_statement expression ')' statement { derivations[derivation_count++] = "iteration_statement -> FOR ( declaration expression_statement expression ) statement"; }
    | FOREACH '(' foreach_var IN expression ')' statement { derivations[derivation_count++] = "iteration_statement -> FOREACH ( foreach_var IN expression ) statement"; }
	;

jump_statement
	: GOTO IDENTIFIER ';' { derivations[derivation_count++] = "jump_statement -> GOTO IDENTIFIER ;"; }
	| CONTINUE ';' { derivations[derivation_count++] = "jump_statement -> CONTINUE ;"; }
	| BREAK ';' { derivations[derivation_count++] = "jump_statement -> BREAK ;"; }
	| RETURN ';' { derivations[derivation_count++] = "jump_statement -> RETURN ;"; }
	| RETURN expression ';' { derivations[derivation_count++] = "jump_statement -> RETURN expression ;"; }
	;

translation_unit
	: external_declaration { derivations[derivation_count++] = "translation_unit -> external_declaration"; }
	| translation_unit external_declaration { derivations[derivation_count++] = "translation_unit -> translation_unit external_declaration"; }
	;

external_declaration
	: function_definition { derivations[derivation_count++] = "external_declaration -> function_definition"; }
	| declaration { derivations[derivation_count++] = "external_declaration -> declaration"; }
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement { derivations[derivation_count++] = "function_definition -> declaration_specifiers declarator declaration_list compound_statement"; }
	| declaration_specifiers declarator compound_statement { derivations[derivation_count++] = "function_definition -> declaration_specifiers declarator compound_statement"; }
	;

declaration_list
	: declaration { derivations[derivation_count++] = "declaration_list -> declaration"; }
	| declaration_list declaration { derivations[derivation_count++] = "declaration_list -> declaration_list declaration"; }
	;

%%

void print_reverse_derivation()
{
    for (int i = derivation_count - 1; i >= 0; i--)
    {
        printf("%s\n", derivations[i]);
    }
}

void yyerror(const char *s)
{
    fflush(stdout);

    fprintf(stderr,
        "*** parsing error at line %d near '%s' ***\n",
        yylineno,
        (yytext && yytext[0]) ? yytext : "EOF");

    fprintf(stderr, "%s\n", s);

    exit(-1);
}

int main(int argc, char **argv)
{
    extern FILE *yyin;

    if (argc < 2)
    {
        sprintf(buff, "***process terminated*** [input error]: invalid number of command-line arguments");
        mode = 1;
        yyerror(buff);
        exit(1);
    }

    yyin = fopen(argv[1], "r");

    if (yyin == NULL)
    {
        sprintf(buff, "***process terminated*** [input error]: no such file \"%s\" exists", argv[1]);
        mode = 1;
        yyerror(buff);
        exit(1);
    }
    else
    {
        do
        {
            yyparse();
        }
        while (!feof(yyin));
    }

    printf("***parsing successful***\n");
	print_reverse_derivation();
    return 0;
}