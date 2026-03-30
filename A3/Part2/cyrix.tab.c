/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "cyrix.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char *yytext;
extern int yylineno;
extern int token_count, max_depth;
extern int id_count, keyword_count, constant_count, string_count, operator_count;

char buff[2048];
int mode = -1;

int yylex(void);
void yyerror(const char *s);

char *derivations[20000];
int derivation_count = 0;

#line 91 "cyrix.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "cyrix.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_I_CONSTANT = 4,                 /* I_CONSTANT  */
  YYSYMBOL_F_CONSTANT = 5,                 /* F_CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 6,             /* STRING_LITERAL  */
  YYSYMBOL_FUNC_NAME = 7,                  /* FUNC_NAME  */
  YYSYMBOL_SIZEOF = 8,                     /* SIZEOF  */
  YYSYMBOL_PTR_OP = 9,                     /* PTR_OP  */
  YYSYMBOL_INC_OP = 10,                    /* INC_OP  */
  YYSYMBOL_DEC_OP = 11,                    /* DEC_OP  */
  YYSYMBOL_LEFT_OP = 12,                   /* LEFT_OP  */
  YYSYMBOL_RIGHT_OP = 13,                  /* RIGHT_OP  */
  YYSYMBOL_LE_OP = 14,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 15,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 16,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 17,                     /* NE_OP  */
  YYSYMBOL_TH_OP = 18,                     /* TH_OP  */
  YYSYMBOL_AND_OP = 19,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 20,                     /* OR_OP  */
  YYSYMBOL_MUL_ASSIGN = 21,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 22,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 23,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 24,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 25,                /* SUB_ASSIGN  */
  YYSYMBOL_LEFT_ASSIGN = 26,               /* LEFT_ASSIGN  */
  YYSYMBOL_RIGHT_ASSIGN = 27,              /* RIGHT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 28,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 29,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 30,                 /* OR_ASSIGN  */
  YYSYMBOL_TYPEDEF_NAME = 31,              /* TYPEDEF_NAME  */
  YYSYMBOL_ENUMERATION_CONSTANT = 32,      /* ENUMERATION_CONSTANT  */
  YYSYMBOL_VAR = 33,                       /* VAR  */
  YYSYMBOL_FOREACH = 34,                   /* FOREACH  */
  YYSYMBOL_IN = 35,                        /* IN  */
  YYSYMBOL_MATCH = 36,                     /* MATCH  */
  YYSYMBOL_FN = 37,                        /* FN  */
  YYSYMBOL_SAFE_DOT = 38,                  /* SAFE_DOT  */
  YYSYMBOL_LAMBDA_ARROW = 39,              /* LAMBDA_ARROW  */
  YYSYMBOL_POW_OP = 40,                    /* POW_OP  */
  YYSYMBOL_TYPEDEF = 41,                   /* TYPEDEF  */
  YYSYMBOL_EXTERN = 42,                    /* EXTERN  */
  YYSYMBOL_STATIC = 43,                    /* STATIC  */
  YYSYMBOL_AUTO = 44,                      /* AUTO  */
  YYSYMBOL_REGISTER = 45,                  /* REGISTER  */
  YYSYMBOL_INLINE = 46,                    /* INLINE  */
  YYSYMBOL_CONST = 47,                     /* CONST  */
  YYSYMBOL_RESTRICT = 48,                  /* RESTRICT  */
  YYSYMBOL_VOLATILE = 49,                  /* VOLATILE  */
  YYSYMBOL_BOOL = 50,                      /* BOOL  */
  YYSYMBOL_CHAR = 51,                      /* CHAR  */
  YYSYMBOL_SHORT = 52,                     /* SHORT  */
  YYSYMBOL_INT = 53,                       /* INT  */
  YYSYMBOL_LONG = 54,                      /* LONG  */
  YYSYMBOL_SIGNED = 55,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 56,                  /* UNSIGNED  */
  YYSYMBOL_FLOAT = 57,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 58,                    /* DOUBLE  */
  YYSYMBOL_VOID = 59,                      /* VOID  */
  YYSYMBOL_COMPLEX = 60,                   /* COMPLEX  */
  YYSYMBOL_IMAGINARY = 61,                 /* IMAGINARY  */
  YYSYMBOL_STRUCT = 62,                    /* STRUCT  */
  YYSYMBOL_UNION = 63,                     /* UNION  */
  YYSYMBOL_ENUM = 64,                      /* ENUM  */
  YYSYMBOL_ELLIPSIS = 65,                  /* ELLIPSIS  */
  YYSYMBOL_CASE = 66,                      /* CASE  */
  YYSYMBOL_DEFAULT = 67,                   /* DEFAULT  */
  YYSYMBOL_IF = 68,                        /* IF  */
  YYSYMBOL_SWITCH = 69,                    /* SWITCH  */
  YYSYMBOL_WHILE = 70,                     /* WHILE  */
  YYSYMBOL_DO = 71,                        /* DO  */
  YYSYMBOL_FOR = 72,                       /* FOR  */
  YYSYMBOL_GOTO = 73,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 74,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 75,                     /* BREAK  */
  YYSYMBOL_RETURN = 76,                    /* RETURN  */
  YYSYMBOL_ALIGNAS = 77,                   /* ALIGNAS  */
  YYSYMBOL_ALIGNOF = 78,                   /* ALIGNOF  */
  YYSYMBOL_ATOMIC = 79,                    /* ATOMIC  */
  YYSYMBOL_GENERIC = 80,                   /* GENERIC  */
  YYSYMBOL_NORETURN = 81,                  /* NORETURN  */
  YYSYMBOL_STATIC_ASSERT = 82,             /* STATIC_ASSERT  */
  YYSYMBOL_THREAD_LOCAL = 83,              /* THREAD_LOCAL  */
  YYSYMBOL_LOWER_THAN_ELSE = 84,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_ELSE = 85,                      /* ELSE  */
  YYSYMBOL_86_ = 86,                       /* '='  */
  YYSYMBOL_87_ = 87,                       /* '|'  */
  YYSYMBOL_88_ = 88,                       /* '^'  */
  YYSYMBOL_89_ = 89,                       /* '&'  */
  YYSYMBOL_90_ = 90,                       /* '<'  */
  YYSYMBOL_91_ = 91,                       /* '>'  */
  YYSYMBOL_92_ = 92,                       /* '+'  */
  YYSYMBOL_93_ = 93,                       /* '-'  */
  YYSYMBOL_94_ = 94,                       /* '*'  */
  YYSYMBOL_95_ = 95,                       /* '/'  */
  YYSYMBOL_96_ = 96,                       /* '%'  */
  YYSYMBOL_UNARY = 97,                     /* UNARY  */
  YYSYMBOL_98_ = 98,                       /* '['  */
  YYSYMBOL_99_ = 99,                       /* '.'  */
  YYSYMBOL_100_ = 100,                     /* '('  */
  YYSYMBOL_101_ = 101,                     /* ','  */
  YYSYMBOL_102_ = 102,                     /* ')'  */
  YYSYMBOL_103_ = 103,                     /* ':'  */
  YYSYMBOL_104_ = 104,                     /* ']'  */
  YYSYMBOL_105_ = 105,                     /* '{'  */
  YYSYMBOL_106_ = 106,                     /* '}'  */
  YYSYMBOL_107_ = 107,                     /* '~'  */
  YYSYMBOL_108_ = 108,                     /* '!'  */
  YYSYMBOL_109_ = 109,                     /* ';'  */
  YYSYMBOL_YYACCEPT = 110,                 /* $accept  */
  YYSYMBOL_lambda_params = 111,            /* lambda_params  */
  YYSYMBOL_lambda_expression = 112,        /* lambda_expression  */
  YYSYMBOL_primary_expression = 113,       /* primary_expression  */
  YYSYMBOL_constant = 114,                 /* constant  */
  YYSYMBOL_enumeration_constant = 115,     /* enumeration_constant  */
  YYSYMBOL_string = 116,                   /* string  */
  YYSYMBOL_generic_selection = 117,        /* generic_selection  */
  YYSYMBOL_generic_assoc_list = 118,       /* generic_assoc_list  */
  YYSYMBOL_generic_association = 119,      /* generic_association  */
  YYSYMBOL_postfix_expression = 120,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 121, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 122,         /* unary_expression  */
  YYSYMBOL_unary_operator = 123,           /* unary_operator  */
  YYSYMBOL_cast_expression = 124,          /* cast_expression  */
  YYSYMBOL_power_expression = 125,         /* power_expression  */
  YYSYMBOL_multiplicative_expression = 126, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 127,      /* additive_expression  */
  YYSYMBOL_shift_expression = 128,         /* shift_expression  */
  YYSYMBOL_relational_expression = 129,    /* relational_expression  */
  YYSYMBOL_equality_expression = 130,      /* equality_expression  */
  YYSYMBOL_and_expression = 131,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 132,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 133,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 134,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 135,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 136,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 137,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 138,      /* assignment_operator  */
  YYSYMBOL_expression = 139,               /* expression  */
  YYSYMBOL_constant_expression = 140,      /* constant_expression  */
  YYSYMBOL_var_init_list = 141,            /* var_init_list  */
  YYSYMBOL_var_init = 142,                 /* var_init  */
  YYSYMBOL_var_declaration = 143,          /* var_declaration  */
  YYSYMBOL_declaration = 144,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 145,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 146,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 147,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 148,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 149,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 150, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 151,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 152,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 153,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 154, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 155,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 156,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 157,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 158,          /* enumerator_list  */
  YYSYMBOL_enumerator = 159,               /* enumerator  */
  YYSYMBOL_atomic_type_specifier = 160,    /* atomic_type_specifier  */
  YYSYMBOL_type_qualifier = 161,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 162,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 163,      /* alignment_specifier  */
  YYSYMBOL_declarator = 164,               /* declarator  */
  YYSYMBOL_direct_declarator = 165,        /* direct_declarator  */
  YYSYMBOL_pointer = 166,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 167,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 168,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 169,           /* parameter_list  */
  YYSYMBOL_param_declaration = 170,        /* param_declaration  */
  YYSYMBOL_identifier_list = 171,          /* identifier_list  */
  YYSYMBOL_type_name = 172,                /* type_name  */
  YYSYMBOL_abstract_declarator = 173,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 174, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 175,              /* initializer  */
  YYSYMBOL_initializer_list = 176,         /* initializer_list  */
  YYSYMBOL_designation = 177,              /* designation  */
  YYSYMBOL_designator_list = 178,          /* designator_list  */
  YYSYMBOL_designator = 179,               /* designator  */
  YYSYMBOL_static_assert_declaration = 180, /* static_assert_declaration  */
  YYSYMBOL_statement = 181,                /* statement  */
  YYSYMBOL_labeled_statement = 182,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 183,       /* compound_statement  */
  YYSYMBOL_block_item_list = 184,          /* block_item_list  */
  YYSYMBOL_block_item = 185,               /* block_item  */
  YYSYMBOL_expression_statement = 186,     /* expression_statement  */
  YYSYMBOL_match_statement = 187,          /* match_statement  */
  YYSYMBOL_case_list = 188,                /* case_list  */
  YYSYMBOL_match_case = 189,               /* match_case  */
  YYSYMBOL_default_opt = 190,              /* default_opt  */
  YYSYMBOL_selection_statement = 191,      /* selection_statement  */
  YYSYMBOL_foreach_var = 192,              /* foreach_var  */
  YYSYMBOL_iteration_statement = 193,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 194,           /* jump_statement  */
  YYSYMBOL_translation_unit = 195,         /* translation_unit  */
  YYSYMBOL_external_declaration = 196,     /* external_declaration  */
  YYSYMBOL_function_definition = 197,      /* function_definition  */
  YYSYMBOL_declaration_list = 198          /* declaration_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  72
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2867

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  110
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  89
/* YYNRULES -- Number of rules.  */
#define YYNRULES  300
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  537

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   341


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   108,     2,     2,     2,    96,    89,     2,
     100,   102,    94,    92,   101,    93,    99,    95,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   103,   109,
      90,    86,    91,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    98,     2,   104,    88,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   105,    87,   106,   107,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    97
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    66,    66,    67,    71,    72,    73,    74,    78,    79,
      80,    81,    82,    83,    87,    88,    89,    93,    97,    98,
     102,   106,   107,   111,   112,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   130,   131,   135,   136,
     137,   138,   139,   140,   141,   145,   146,   147,   148,   149,
     150,   154,   155,   159,   160,   164,   165,   166,   167,   171,
     172,   173,   177,   178,   179,   183,   184,   185,   186,   187,
     188,   192,   193,   194,   198,   199,   203,   204,   208,   209,
     213,   214,   218,   219,   223,   227,   228,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   246,   247,
     251,   255,   256,   260,   264,   268,   269,   270,   271,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   288,
     289,   293,   294,   298,   299,   300,   301,   302,   303,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   322,   326,   327,   328,   332,   333,
     337,   338,   342,   343,   344,   348,   349,   350,   351,   355,
     356,   360,   361,   362,   366,   367,   368,   369,   370,   374,
     375,   379,   380,   384,   388,   389,   390,   394,   395,   399,
     400,   404,   405,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   426,   427,   428,
     429,   433,   434,   439,   440,   444,   445,   449,   450,   451,
     452,   456,   457,   461,   462,   466,   467,   468,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   492,   496,
     497,   498,   502,   503,   504,   505,   509,   513,   514,   518,
     519,   523,   527,   528,   529,   530,   531,   532,   536,   537,
     538,   542,   543,   547,   548,   552,   553,   557,   558,   562,
     566,   567,   571,   575,   576,   580,   581,   582,   583,   587,
     588,   592,   593,   594,   595,   596,   597,   598,   602,   603,
     604,   605,   606,   610,   611,   615,   616,   620,   621,   625,
     626
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "I_CONSTANT", "F_CONSTANT", "STRING_LITERAL", "FUNC_NAME", "SIZEOF",
  "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "TH_OP", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "TYPEDEF_NAME",
  "ENUMERATION_CONSTANT", "VAR", "FOREACH", "IN", "MATCH", "FN",
  "SAFE_DOT", "LAMBDA_ARROW", "POW_OP", "TYPEDEF", "EXTERN", "STATIC",
  "AUTO", "REGISTER", "INLINE", "CONST", "RESTRICT", "VOLATILE", "BOOL",
  "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE",
  "VOID", "COMPLEX", "IMAGINARY", "STRUCT", "UNION", "ENUM", "ELLIPSIS",
  "CASE", "DEFAULT", "IF", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "ALIGNAS", "ALIGNOF", "ATOMIC", "GENERIC",
  "NORETURN", "STATIC_ASSERT", "THREAD_LOCAL", "LOWER_THAN_ELSE", "ELSE",
  "'='", "'|'", "'^'", "'&'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "UNARY", "'['", "'.'", "'('", "','", "')'", "':'", "']'", "'{'",
  "'}'", "'~'", "'!'", "';'", "$accept", "lambda_params",
  "lambda_expression", "primary_expression", "constant",
  "enumeration_constant", "string", "generic_selection",
  "generic_assoc_list", "generic_association", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "power_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "var_init_list", "var_init", "var_declaration",
  "declaration", "declaration_specifiers", "init_declarator_list",
  "init_declarator", "storage_class_specifier", "type_specifier",
  "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "atomic_type_specifier", "type_qualifier", "function_specifier",
  "alignment_specifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "param_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "static_assert_declaration", "statement", "labeled_statement",
  "compound_statement", "block_item_list", "block_item",
  "expression_statement", "match_statement", "case_list", "match_case",
  "default_opt", "selection_statement", "foreach_var",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "declaration_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-396)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2595,  -396,    30,  -396,  -396,  -396,  -396,  -396,  -396,  -396,
    -396,  -396,  -396,  -396,  -396,  -396,  -396,  -396,  -396,  -396,
    -396,  -396,  -396,  -396,  -396,  -396,    51,   -32,   -28,  -396,
     -21,  -396,  -396,  -396,    74,  2681,  2681,  -396,    55,  -396,
    -396,  2681,  2681,  2681,  -396,  2170,  -396,  -396,   -37,   -71,
    -396,     6,    96,   949,  2788,  1869,  -396,    -6,    92,  -396,
     -62,  -396,  2341,    15,    20,  -396,  -396,    52,  2718,  -396,
    -396,  -396,  -396,  -396,  1869,    30,  -396,    96,  -396,    75,
     -86,  -396,  -396,  -396,  -396,  -396,  -396,  1922,  1975,  1975,
    -396,    84,    93,    97,  -396,  -396,  -396,  -396,   949,  -396,
    -396,  -396,  -396,  -396,  -396,  -396,   222,  -396,  1869,   161,
    -396,   -13,    -2,   168,   225,   213,    86,   118,   133,   207,
     203,  -396,   146,  2788,   -38,  2788,   154,   173,   162,  -396,
    -396,    -6,   212,    92,  -396,  1551,   510,  -396,    74,  -396,
    2406,  1015,  2105,    15,  2718,  2239,  -396,   152,  -396,   508,
    -396,  -396,  -396,   -61,  1869,    11,  -396,   949,  -396,   949,
    -396,  -396,    50,  2788,  1869,  -396,   135,   217,   306,  -396,
    -396,   323,  1869,   325,  1604,  -396,  1869,  1869,  1869,  1869,
    1869,  1869,  1869,  1869,  1869,  1869,  1869,  1869,  1869,  1869,
    1869,  1869,  1869,  1869,  1869,  1869,  -396,  -396,  1069,  2471,
     116,  -396,   121,  -396,  -396,  -396,   248,  -396,  -396,  -396,
    -396,   249,  1444,  -396,  -396,   234,   239,   240,  1869,   241,
     250,   252,   253,   789,   255,   346,   242,   247,   834,  -396,
    -396,   -57,  -396,  -396,  -396,  -396,   617,  -396,  -396,  -396,
    -396,  -396,  -396,  -396,  -396,  1498,   256,  -396,   257,  1123,
    -396,  -396,   105,   260,   258,  -396,   140,  2275,  -396,  -396,
    1869,  -396,   -44,  -396,   261,  -396,  -396,  -396,  -396,  -396,
    -396,  -396,  -396,  -396,  -396,  -396,  1869,    47,  -396,  -396,
    -396,  -396,   264,   265,  -396,   324,   143,   266,   268,  1869,
    -396,  1657,  -396,  -396,   -77,  -396,  -396,   149,  -396,  -396,
    -396,  -396,  -396,   -13,   -13,    -2,    -2,   168,   168,   168,
     168,   168,   225,   225,   213,    86,   118,   133,   207,  1498,
     267,  -396,   270,  1177,  -396,   273,   274,   121,  1231,  2533,
     275,  1869,   369,  -396,   -40,  1551,   -67,  -396,   789,  2205,
    1869,   276,   789,  1869,  1869,  1869,   308,   724,   271,  -396,
    -396,  -396,   -42,  -396,  -396,  -396,   277,  1498,  -396,  -396,
    1869,   278,  -396,   279,  2043,   298,   159,  -396,  -396,  2638,
     382,  -396,  -396,  -396,    82,  -396,  1869,  -396,  -396,   283,
     283,  1710,   386,   351,  -396,  2754,  -396,  1444,  -396,  -396,
    1869,  -396,   289,  1498,  -396,  -396,  1869,  -396,   291,  -396,
    -396,  1498,   292,  -396,   294,  1285,  -396,   297,   293,   300,
    -396,  1338,  -396,  -396,  -396,  -396,  -396,  -396,   398,   370,
     169,   789,  -396,   172,   185,   190,   307,   869,   869,  -396,
    -396,  -396,   304,   309,  -396,  -396,  1869,  -396,  -396,  -396,
    -396,  -396,  -396,  -396,  -396,  1710,   312,   195,  -396,   313,
     -26,  -396,  -396,   315,   317,  -396,   318,  1498,  -396,  -396,
    1869,  -396,   319,  -396,  -396,  -396,  -396,  -396,  1551,  -396,
    1869,   320,  -396,   789,   789,   789,  1869,  1763,  1816,  -396,
    -396,  -396,  -396,  -396,  1869,  2754,  -396,  1869,  1391,  -396,
    -396,  -396,  -396,   326,   327,  -396,  -396,   197,   345,   332,
    -396,  -396,   199,   789,   204,   789,   211,  -396,  -396,  -396,
    -396,  -396,  -396,   789,  1869,   251,  -396,   789,   303,  -396,
     789,  -396,   789,  -396,   329,   330,  -396,   328,  -396,  -396,
    -396,  -396,   789,   789,  -396,  -396,  -396
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   144,     0,   123,   124,   125,   127,   128,   177,   174,
     175,   176,   138,   130,   131,   132,   133,   136,   137,   134,
     135,   129,   139,   140,   148,   149,     0,     0,     0,   178,
       0,   126,   108,   296,     0,   110,   112,   142,     0,   143,
     141,   114,   116,   118,   107,     0,   293,   295,     0,     0,
     101,   168,     0,     0,     0,     0,   183,   200,     0,   105,
       0,   119,   122,   182,     0,   109,   111,   147,     0,   113,
     115,   117,     1,   294,     0,     0,   104,     0,    17,   172,
       0,   169,     8,    14,    15,    18,    19,     0,     0,     0,
      16,     0,     0,     0,    45,    47,    48,    46,     0,    49,
      50,    13,    25,     9,    10,    12,    38,    51,     0,    53,
      55,    59,    62,    65,    71,    74,    76,    78,    80,    82,
      84,   100,     0,   156,   214,   158,     0,     0,     0,   201,
     199,   198,     0,     0,   106,     0,     0,   299,     0,   298,
       0,     0,     0,   181,     0,     0,   150,     0,   154,    51,
      85,   103,   102,     0,     0,     0,   164,     0,    42,     0,
      39,    40,     0,     0,     0,    98,     0,     0,     0,    32,
      33,     0,     0,     0,     0,    41,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   180,   155,     0,     0,
     216,   213,   217,   157,   179,   173,     0,   202,   197,   184,
     120,   122,     0,   241,   121,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   261,
     267,     0,   265,   266,   252,   253,     0,   263,   254,   278,
     255,   256,   257,   300,   297,     0,    46,   185,     0,     0,
     211,   195,   209,     0,   204,   205,     0,     0,   145,   151,
       0,   152,     0,   159,   163,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    87,     0,     0,   166,   171,
     165,   170,     0,     0,     2,     0,     0,     0,     0,     0,
      11,     0,    30,    31,     0,    29,    27,     0,    36,    54,
      56,    57,    58,    60,    61,    63,    64,    68,    69,    70,
      66,    67,    72,    73,    75,    77,    79,    81,    83,     0,
      46,   219,     0,     0,   235,     0,     0,   215,     0,     0,
       0,     0,     0,   243,     0,     0,     0,   247,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   289,
     290,   291,     0,   268,   262,   264,     0,     0,   186,   193,
       0,    46,   192,     0,     0,   207,   216,   208,   194,     0,
       0,   196,   146,   161,     0,   153,     0,    86,   167,    43,
       0,     0,     0,     0,    44,     0,    99,     0,    52,    26,
       0,    28,     0,     0,   220,   226,     0,   225,     0,   236,
     218,     0,    46,   227,     0,     0,   237,     0,     0,     0,
     250,     0,   239,   242,   246,   248,   258,   279,     0,     0,
       0,     0,   260,     0,     0,     0,     0,     0,     0,   288,
     292,   188,     0,     0,   189,   191,     0,   203,   206,   212,
     160,   162,     4,     5,     3,     0,     0,     0,    21,     0,
       0,    37,   222,     0,     0,   224,     0,     0,   228,   234,
       0,   233,     0,   238,   251,   249,   240,   245,     0,   280,
       0,     0,   259,     0,     0,     0,     0,     0,     0,   187,
     190,   210,     6,     7,     0,     0,    20,     0,     0,    34,
     221,   223,   230,     0,     0,   231,   244,     0,     0,   276,
     277,   281,     0,     0,     0,     0,     0,    24,    22,    23,
      35,   229,   232,     0,     0,   273,   271,     0,     0,   285,
       0,   283,     0,   287,     0,     0,   270,     0,   275,   282,
     286,   284,     0,     0,   269,   272,   274
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -396,  -396,  -396,  -396,  -396,  -396,  -396,  -396,  -396,   -49,
    -396,  -396,   -53,  -396,   -97,   106,   150,   151,    81,   153,
     244,   245,   254,   259,   262,  -396,   -52,    13,  -396,   -50,
     -51,  -396,   367,  -396,   -36,    28,  -396,   310,  -396,    90,
    -396,  -396,   301,  -108,    46,  -396,    70,  -396,   371,  -130,
    -396,   -47,  -396,  -396,    12,   -59,   -35,  -124,  -133,  -396,
      77,  -396,    65,  -106,  -187,  -123,    63,  -395,  -396,   115,
     -39,   -34,  -396,   -54,  -396,   216,  -255,  -396,  -396,   -60,
    -396,  -396,  -396,  -396,  -396,  -396,   409,  -396,  -396
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   286,   101,   102,   103,    79,   104,   105,   447,   448,
     106,   297,   149,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   150,   165,   276,   231,
     122,    49,    50,    32,    33,   138,    60,    61,    35,    36,
      37,    38,   145,   146,   124,   262,   263,    39,    80,    81,
      40,    41,    42,    43,   132,    63,    64,   131,   325,   254,
     255,   256,   449,   326,   202,   333,   334,   335,   336,   337,
      44,   233,   234,   235,   236,   237,   238,   239,   515,   516,
     527,   240,   419,   241,   242,    45,    46,    47,   140
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     107,   121,   107,   121,   128,   143,   125,   125,   139,   253,
     129,   175,   214,   327,    78,   155,   468,   249,   201,   414,
     156,   125,   130,    56,   289,   281,   137,   389,    34,   148,
      75,   331,   332,    48,   158,   160,   161,   259,    76,   133,
     277,     9,    10,    11,   289,   278,    62,   134,   166,    74,
      78,   125,   353,   284,    51,   107,    57,   374,    67,   289,
     198,   411,   199,    65,    66,   375,   412,   430,    53,    69,
      70,    71,    54,    34,   323,   488,   125,    56,   125,    55,
     489,   177,   178,   179,   207,    56,   244,   151,    57,   200,
     180,   181,   428,   468,   129,    56,   208,   125,   125,    78,
     232,   107,   121,   279,   243,   148,   148,   166,    56,   166,
     125,    77,   125,   141,   147,   142,   125,   280,   126,   127,
      58,   357,   294,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   123,   123,   211,   367,   281,   213,   259,
     211,   129,   285,   378,   248,    56,    52,   144,   123,   264,
      68,   154,    56,   167,   200,   107,   121,   341,    57,   197,
     252,   203,   477,   478,    58,   191,    57,   288,   352,   327,
     182,   183,    58,    59,   162,   260,    57,   298,   123,   346,
     147,   147,    58,   163,   388,   393,   407,   164,   129,    57,
     232,   176,   207,   198,   405,   364,   192,   107,   121,   373,
     125,   322,   413,   123,   198,   123,   199,   366,   148,   328,
     193,   329,   282,   195,   283,   213,   194,   252,   287,   189,
     190,   168,   169,   170,   123,   123,   289,   290,   107,   184,
     185,   370,   371,   186,   382,   383,    57,   123,   196,   123,
     390,   391,    58,   123,   330,   260,   204,   198,   356,   364,
     171,   261,   363,   206,   365,   307,   308,   309,   310,   311,
     289,   471,   129,   289,   473,   205,   207,   457,   107,   121,
     409,   129,   299,   300,   301,   302,   289,   474,   467,   377,
     420,   289,   475,   423,   424,   425,   485,   486,   289,   513,
     289,   518,   386,   147,   416,   289,   520,   143,   422,   292,
     207,   427,   289,   522,   209,   187,   188,   514,   525,   291,
     172,   173,   174,   107,   121,   441,   293,   443,   295,   366,
     303,   304,   392,   305,   306,   135,   398,   338,   125,   339,
     340,   404,   312,   313,   342,   496,   207,   123,   213,   348,
     343,   349,   344,   345,   129,   347,   350,   252,   207,   369,
     358,   359,   368,   381,   376,   467,   379,   380,   384,   385,
     432,   394,   410,   433,   395,   399,   400,   408,   426,   421,
     429,   431,   434,   435,   436,   439,   264,   472,   387,   444,
     445,   483,   252,   452,   442,   455,   458,   252,   459,   463,
     213,   469,   464,   451,   465,   470,   453,   476,   479,   454,
     207,   514,   529,   480,   456,   484,   487,   517,   462,   490,
     497,   491,   492,   495,   213,   498,   502,   504,   506,   418,
     511,   512,   532,   533,   534,   314,   508,   315,   125,   499,
     500,   501,   152,   210,   440,   257,   438,   316,   153,   481,
     450,   415,   355,   317,    73,   526,     0,   318,   482,     0,
       0,   107,   121,   524,     0,     0,     0,     0,     0,   519,
     493,   521,     0,   494,     0,   123,     0,     0,     0,   523,
       0,   213,     0,   528,     0,     0,   530,     0,   531,     0,
       0,     0,     0,     0,     0,     0,     0,   507,   535,   536,
     509,   213,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   215,    83,    84,    85,    86,    87,     0,
      88,    89,     0,     0,     0,     0,     0,     0,     0,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,     0,
       0,     1,    90,     2,   216,     0,   217,    91,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   123,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,    27,    92,    28,
      93,    29,    30,    31,   275,     0,     0,     0,     0,    94,
       0,     0,    95,    96,    97,     0,     0,     0,     0,     0,
      98,     0,     0,     0,     0,   136,   229,    99,   100,   230,
     215,    83,    84,    85,    86,    87,     0,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,    90,
       2,   216,     0,   217,    91,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,     0,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,    27,    92,    28,    93,    29,    30,
      31,     0,     0,     0,     0,     0,    94,     0,     0,    95,
      96,    97,     0,     0,     0,     0,     0,    98,     0,     0,
       0,     0,   136,   354,    99,   100,   230,    82,    83,    84,
      85,    86,    87,     0,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,    90,     2,     0,     0,
       0,    91,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     0,
       0,     0,   215,    83,    84,    85,    86,    87,     0,    88,
      89,    27,    92,    28,    93,    29,    30,    31,     0,     0,
       0,     0,     0,    94,     0,     0,    95,    96,    97,     0,
       0,    90,     0,   216,    98,   217,    91,     0,     0,     0,
       0,    99,   100,   230,     0,     0,     0,    82,    83,    84,
      85,    86,    87,     0,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,    90,    92,     0,    93,
       0,    91,    82,    83,    84,    85,    86,    87,    94,    88,
      89,    95,    96,    97,     0,     0,     0,     0,     0,    98,
       0,     0,     0,     0,   136,     0,    99,   100,   230,     0,
       0,    90,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,    92,     0,    93,     0,     0,     0,     0,     0,
       0,     0,     0,    94,     0,     0,    95,    96,    97,     0,
       0,     0,     0,     0,    98,     0,     0,     0,     0,     0,
       0,    99,   100,   351,     0,     0,     0,    92,     0,    93,
       0,     0,    82,    83,    84,    85,    86,    87,    94,    88,
      89,    95,    96,    97,     0,     0,     0,     0,     0,    98,
       0,     0,     0,     0,     0,     0,    99,   100,   230,     0,
       1,    90,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,     0,     0,     0,     0,    82,    83,
      84,    85,    86,    87,     0,    88,    89,    92,    28,    93,
       0,     0,     0,     0,     0,     0,     0,     0,    94,     0,
       0,    95,    96,    97,     0,     0,     0,    90,     0,    98,
       0,     0,    91,     0,     0,     0,    99,   100,   245,     0,
       0,     0,     9,    10,    11,     0,     0,     0,     0,     0,
       0,     0,    82,    83,    84,    85,    86,    87,     0,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,     0,    93,     0,     0,     0,     0,
       0,    90,     0,     0,    94,     0,    91,    95,    96,   246,
       0,     0,   319,     0,     0,    98,     9,    10,    11,   247,
       0,     0,    99,   100,     0,     0,    82,    83,    84,    85,
      86,    87,     0,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    92,     0,    93,
       0,     0,     0,     0,     0,    90,     0,     0,    94,     0,
      91,    95,    96,   320,     0,     0,   360,     0,     0,    98,
       9,    10,    11,   321,     0,     0,    99,   100,     0,     0,
      82,    83,    84,    85,    86,    87,     0,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,     0,    93,     0,     0,     0,     0,     0,    90,
       0,     0,    94,     0,    91,    95,    96,   361,     0,     0,
     396,     0,     0,    98,     9,    10,    11,   362,     0,     0,
      99,   100,     0,     0,    82,    83,    84,    85,    86,    87,
       0,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,     0,    93,     0,     0,
       0,     0,     0,    90,     0,     0,    94,     0,    91,    95,
      96,    97,     0,     0,   401,     0,     0,    98,     9,    10,
      11,   397,     0,     0,    99,   100,     0,     0,    82,    83,
      84,    85,    86,    87,     0,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    92,
       0,    93,     0,     0,     0,     0,     0,    90,     0,     0,
      94,     0,    91,    95,    96,   402,     0,     0,   460,     0,
       0,    98,     9,    10,    11,   403,     0,     0,    99,   100,
       0,    82,    83,    84,    85,    86,    87,     0,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,     0,    93,     0,     0,     0,     0,
      90,     0,     0,     0,    94,    91,     0,    95,    96,    97,
       0,     0,     0,     0,     0,    98,     0,     0,     0,   461,
       0,     0,    99,   100,    82,    83,    84,    85,    86,    87,
       0,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,     0,    93,     0,
       0,     0,     0,    90,     0,     0,     0,    94,    91,     0,
      95,    96,    97,     0,     0,     0,   331,   332,    98,     0,
       0,     0,     0,   212,   466,    99,   100,    82,    83,    84,
      85,    86,    87,     0,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    92,
       0,    93,     0,     0,     0,     0,    90,     0,     0,     0,
      94,    91,     0,    95,    96,    97,     0,     0,     0,   331,
     332,    98,     0,     0,     0,     0,   212,   510,    99,   100,
       0,    82,    83,    84,    85,    86,    87,     0,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,     0,    93,     0,     0,     0,     0,     0,
      90,     0,     0,    94,     0,    91,    95,    96,    97,     0,
       0,     0,   331,   332,    98,     9,    10,    11,     0,   212,
       0,    99,   100,     0,    82,    83,    84,    85,    86,    87,
       0,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    92,     0,    93,     0,
       0,     0,     0,    90,     0,     0,     0,    94,    91,     0,
      95,    96,    97,     0,     0,     0,     0,     0,    98,     0,
       0,     0,     0,     0,     0,    99,   100,    82,    83,    84,
      85,    86,    87,     0,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    92,
       0,    93,     0,     0,     0,     0,    90,     0,     0,     0,
      94,    91,     0,    95,    96,    97,     0,     0,     0,     0,
       0,    98,     0,     0,     0,     0,   212,     0,    99,   100,
      82,    83,    84,    85,    86,    87,     0,    88,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,     0,    93,     0,     0,     0,     0,    90,
       0,     0,     0,    94,    91,     0,    95,    96,    97,     0,
       0,     0,     0,     0,    98,     0,   296,     0,     0,     0,
       0,    99,   100,    82,    83,    84,    85,    86,    87,     0,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,     0,    93,     0,     0,
       0,     0,    90,     0,     0,     0,    94,    91,     0,    95,
      96,    97,     0,     0,     0,     0,     0,    98,     0,     0,
       0,     0,   387,     0,    99,   100,    82,    83,    84,    85,
      86,    87,     0,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,     0,
      93,     0,     0,     0,     0,    90,     0,     0,     0,    94,
      91,     0,    95,    96,    97,     0,     0,     0,     0,     0,
      98,     0,     0,     0,     0,   136,     0,    99,   100,    82,
      83,    84,    85,    86,    87,     0,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,     0,    93,     0,     0,     0,     0,    90,     0,
       0,     0,    94,    91,     0,    95,    96,    97,     0,     0,
       0,     0,     0,    98,     0,   503,     0,     0,     0,     0,
      99,   100,    82,    83,    84,    85,    86,    87,     0,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,     0,    93,     0,     0,     0,
       0,    90,     0,     0,     0,    94,    91,     0,    95,    96,
      97,     0,     0,     0,     0,     0,    98,     0,   505,     0,
       0,     0,     0,    99,   100,    82,    83,    84,    85,    86,
      87,     0,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    92,     0,    93,
       0,     0,     0,     0,    90,     0,     0,     0,    94,    91,
       0,    95,    96,    97,     0,     0,     0,     0,     0,    98,
       0,     0,     0,     0,     0,     0,    99,   100,    82,    83,
      84,    85,    86,    87,     0,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,     0,    93,     0,     0,     0,     0,    90,     0,     0,
       0,    94,    91,     0,    95,    96,    97,     0,     0,     0,
       0,     0,   157,     0,     0,     0,     0,     0,     0,    99,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    56,     0,     0,     0,
       0,     0,     0,    92,     0,    93,     0,     0,     0,     0,
       0,     0,     0,     0,    94,     0,     0,    95,    96,    97,
       0,     0,     0,     0,     1,   159,     0,     0,     0,     0,
       0,     0,    99,   100,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,   250,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,     0,    28,     0,    29,     0,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,    57,     0,     0,
       0,   198,     0,   364,     0,   324,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      72,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     0,    28,     0,    29,     0,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     2,     0,     0,     0,   251,   417,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,     0,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,    28,
       0,    29,    30,    31,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    28,     0,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,     0,     0,     1,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,     0,
       0,    30,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       0,     0,     0,     0,     0,   258,     0,     0,     0,     0,
       0,     0,     0,     0,    28,     0,     0,    30,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     2,     0,     0,     0,     0,     0,
       0,   372,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,     0,
      28,     0,    29,    30,    31,     0,     0,   135,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,     2,
       0,     0,     0,     0,     0,     0,   136,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,     0,    28,     0,    29,    30,    31,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,   136,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,     0,
      28,     0,    29,     0,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,    57,     0,     0,     0,   198,
       0,   199,     0,   324,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,     0,    28,     0,    29,     0,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,     2,     0,
       0,     0,     0,     0,     0,   406,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     0,    27,     0,    28,     0,    29,    30,    31,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,   437,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,    27,     0,    28,     0,    29,
       0,    31,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     0,     0,     0,     1,
       0,     0,     0,     0,     0,     0,     0,     0,    27,     0,
      28,     0,    29,     0,    31,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,     0,     0,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28,     0,     0,
      30,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     1,
       0,   446,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    28,     0,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    28
};

static const yytype_int16 yycheck[] =
{
      53,    53,    55,    55,    55,    64,    53,    54,    62,   142,
      57,   108,   135,   200,     3,   101,   411,   141,   124,    86,
     106,    68,    57,     3,   101,   155,    62,   104,     0,    68,
     101,    98,    99,     3,    87,    88,    89,   145,   109,   101,
     101,    47,    48,    49,   101,   106,    34,   109,    98,    86,
       3,    98,   109,     3,     3,   108,    94,   101,     3,   101,
      98,   101,   100,    35,    36,   109,   106,   109,   100,    41,
      42,    43,   100,    45,   198,   101,   123,     3,   125,   100,
     106,    94,    95,    96,   131,     3,   140,    74,    94,   124,
      92,    93,   347,   488,   141,     3,   131,   144,   145,     3,
     136,   154,   154,   154,   140,   144,   145,   157,     3,   159,
     157,   105,   159,    98,    68,   100,   163,   106,    53,    54,
     100,   245,   172,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,    53,    54,   133,   252,   277,   135,   257,
     138,   198,   102,   106,   141,     3,   105,   105,    68,   147,
     105,    86,     3,    98,   199,   218,   218,   218,    94,   123,
     142,   125,   427,   428,   100,    89,    94,   164,   228,   366,
      12,    13,   100,   109,   100,   103,    94,   174,    98,   223,
     144,   145,   100,   100,   291,   319,   329,   100,   245,    94,
     236,    40,   249,    98,   328,   100,    88,   260,   260,   260,
     257,   198,   335,   123,    98,   125,   100,   252,   257,    98,
      87,   100,   157,    20,   159,   212,    19,   199,   163,    16,
      17,     9,    10,    11,   144,   145,   101,   102,   291,    14,
      15,   101,   102,    18,   101,   102,    94,   157,   102,   159,
     101,   102,   100,   163,     6,   103,   102,    98,   245,   100,
      38,   109,   249,   101,   252,   184,   185,   186,   187,   188,
     101,   102,   319,   101,   102,   102,   323,   401,   331,   331,
     331,   328,   176,   177,   178,   179,   101,   102,   411,   276,
     340,   101,   102,   343,   344,   345,   101,   102,   101,   102,
     101,   102,   289,   257,   338,   101,   102,   366,   342,     3,
     357,   347,   101,   102,   102,    90,    91,    66,    67,   102,
      98,    99,   100,   376,   376,   376,     3,   381,     3,   364,
     180,   181,   319,   182,   183,    86,   323,   103,   385,   100,
     100,   328,   189,   190,   103,   468,   393,   257,   335,     3,
     100,   109,   100,   100,   401,   100,   109,   329,   405,   101,
     104,   104,   102,    39,   103,   488,   102,   102,   102,   101,
     357,   104,     3,   360,   104,   102,   102,   102,    70,   103,
     109,   104,   104,   104,    86,     3,   374,   421,   105,     3,
      39,   445,   364,   104,   381,   104,   104,   369,   104,   102,
     387,     3,   109,   390,   104,    35,   393,   100,   104,   396,
     457,    66,   109,   104,   401,   103,   103,    85,   405,   104,
     470,   104,   104,   104,   411,   105,   476,   477,   478,   339,
     104,   104,   103,   103,   106,   191,   485,   192,   485,   473,
     474,   475,    75,   133,   374,   144,   369,   193,    77,   436,
     387,   336,   236,   194,    45,   515,    -1,   195,   445,    -1,
      -1,   514,   514,   514,    -1,    -1,    -1,    -1,    -1,   503,
     457,   505,    -1,   460,    -1,   385,    -1,    -1,    -1,   513,
      -1,   468,    -1,   517,    -1,    -1,   520,    -1,   522,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   484,   532,   533,
     487,   488,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    31,    32,    33,    34,    -1,    36,    37,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,   485,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    86,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    92,    93,    94,    -1,    -1,    -1,    -1,    -1,
     100,    -1,    -1,    -1,    -1,   105,   106,   107,   108,   109,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      33,    34,    -1,    36,    37,    -1,    -1,    -1,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    -1,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,
      93,    94,    -1,    -1,    -1,    -1,    -1,   100,    -1,    -1,
      -1,    -1,   105,   106,   107,   108,   109,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,    -1,    -1,
      -1,    37,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    77,    78,    79,    80,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    93,    94,    -1,
      -1,    32,    -1,    34,   100,    36,    37,    -1,    -1,    -1,
      -1,   107,   108,   109,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    32,    78,    -1,    80,
      -1,    37,     3,     4,     5,     6,     7,     8,    89,    10,
      11,    92,    93,    94,    -1,    -1,    -1,    -1,    -1,   100,
      -1,    -1,    -1,    -1,   105,    -1,   107,   108,   109,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    92,    93,    94,    -1,
      -1,    -1,    -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,
      -1,   107,   108,   109,    -1,    -1,    -1,    78,    -1,    80,
      -1,    -1,     3,     4,     5,     6,     7,     8,    89,    10,
      11,    92,    93,    94,    -1,    -1,    -1,    -1,    -1,   100,
      -1,    -1,    -1,    -1,    -1,    -1,   107,   108,   109,    -1,
      31,    32,    -1,    -1,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    78,    79,    80,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    92,    93,    94,    -1,    -1,    -1,    32,    -1,   100,
      -1,    -1,    37,    -1,    -1,    -1,   107,   108,    43,    -1,
      -1,    -1,    47,    48,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,
      -1,    32,    -1,    -1,    89,    -1,    37,    92,    93,    94,
      -1,    -1,    43,    -1,    -1,   100,    47,    48,    49,   104,
      -1,    -1,   107,   108,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    80,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    89,    -1,
      37,    92,    93,    94,    -1,    -1,    43,    -1,    -1,   100,
      47,    48,    49,   104,    -1,    -1,   107,   108,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    -1,    80,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    89,    -1,    37,    92,    93,    94,    -1,    -1,
      43,    -1,    -1,   100,    47,    48,    49,   104,    -1,    -1,
     107,   108,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    -1,    80,    -1,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    89,    -1,    37,    92,
      93,    94,    -1,    -1,    43,    -1,    -1,   100,    47,    48,
      49,   104,    -1,    -1,   107,   108,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      -1,    80,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      89,    -1,    37,    92,    93,    94,    -1,    -1,    43,    -1,
      -1,   100,    47,    48,    49,   104,    -1,    -1,   107,   108,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    -1,    89,    37,    -1,    92,    93,    94,
      -1,    -1,    -1,    -1,    -1,   100,    -1,    -1,    -1,   104,
      -1,    -1,   107,   108,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    80,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    89,    37,    -1,
      92,    93,    94,    -1,    -1,    -1,    98,    99,   100,    -1,
      -1,    -1,    -1,   105,   106,   107,   108,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      -1,    80,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
      89,    37,    -1,    92,    93,    94,    -1,    -1,    -1,    98,
      99,   100,    -1,    -1,    -1,    -1,   105,   106,   107,   108,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    89,    -1,    37,    92,    93,    94,    -1,
      -1,    -1,    98,    99,   100,    47,    48,    49,    -1,   105,
      -1,   107,   108,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    80,    -1,
      -1,    -1,    -1,    32,    -1,    -1,    -1,    89,    37,    -1,
      92,    93,    94,    -1,    -1,    -1,    -1,    -1,   100,    -1,
      -1,    -1,    -1,    -1,    -1,   107,   108,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      -1,    80,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,
      89,    37,    -1,    92,    93,    94,    -1,    -1,    -1,    -1,
      -1,   100,    -1,    -1,    -1,    -1,   105,    -1,   107,   108,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    89,    37,    -1,    92,    93,    94,    -1,
      -1,    -1,    -1,    -1,   100,    -1,   102,    -1,    -1,    -1,
      -1,   107,   108,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    -1,    80,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    -1,    89,    37,    -1,    92,
      93,    94,    -1,    -1,    -1,    -1,    -1,   100,    -1,    -1,
      -1,    -1,   105,    -1,   107,   108,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,
      80,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    89,
      37,    -1,    92,    93,    94,    -1,    -1,    -1,    -1,    -1,
     100,    -1,    -1,    -1,    -1,   105,    -1,   107,   108,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    -1,    80,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    89,    37,    -1,    92,    93,    94,    -1,    -1,
      -1,    -1,    -1,   100,    -1,   102,    -1,    -1,    -1,    -1,
     107,   108,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    89,    37,    -1,    92,    93,
      94,    -1,    -1,    -1,    -1,    -1,   100,    -1,   102,    -1,
      -1,    -1,    -1,   107,   108,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    80,
      -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    89,    37,
      -1,    92,    93,    94,    -1,    -1,    -1,    -1,    -1,   100,
      -1,    -1,    -1,    -1,    -1,    -1,   107,   108,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    -1,    80,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    89,    37,    -1,    92,    93,    94,    -1,    -1,    -1,
      -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,   107,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    92,    93,    94,
      -1,    -1,    -1,    -1,    31,   100,    -1,    -1,    -1,    -1,
      -1,    -1,   107,   108,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    -1,    79,    -1,    81,    -1,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    94,    -1,    -1,
      -1,    98,    -1,   100,    -1,   102,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    -1,    79,    -1,    81,    -1,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    33,    -1,    -1,    -1,   102,     3,    -1,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    79,
      -1,    81,    82,    83,    -1,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      -1,    82,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    79,    -1,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      -1,   106,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,
      79,    -1,    81,    82,    83,    -1,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    33,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    79,    -1,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,
      79,    -1,    81,    -1,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    94,    -1,    -1,    -1,    98,
      -1,   100,    -1,   102,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    -1,    79,    -1,    81,    -1,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    33,    -1,
      -1,    -1,    -1,    -1,    -1,   102,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    -1,    77,    -1,    79,    -1,    81,    82,    83,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    77,    -1,    79,    -1,    81,
      -1,    83,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,
      79,    -1,    81,    -1,    83,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,    -1,
      82,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    31,
      -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    79
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,    33,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    77,    79,    81,
      82,    83,   143,   144,   145,   148,   149,   150,   151,   157,
     160,   161,   162,   163,   180,   195,   196,   197,     3,   141,
     142,     3,   105,   100,   100,   100,     3,    94,   100,   109,
     146,   147,   164,   165,   166,   145,   145,     3,   105,   145,
     145,   145,     0,   196,    86,   101,   109,   105,     3,   115,
     158,   159,     3,     4,     5,     6,     7,     8,    10,    11,
      32,    37,    78,    80,    89,    92,    93,    94,   100,   107,
     108,   112,   113,   114,   116,   117,   120,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   140,   149,   154,   161,   172,   172,   140,   161,
     166,   167,   164,   101,   109,    86,   105,   144,   145,   183,
     198,    98,   100,   165,   105,   152,   153,   154,   180,   122,
     136,   137,   142,   158,    86,   101,   106,   100,   122,   100,
     122,   122,   100,   100,   100,   137,   139,   172,     9,    10,
      11,    38,    98,    99,   100,   124,    40,    94,    95,    96,
      92,    93,    12,    13,    14,    15,    18,    90,    91,    16,
      17,    89,    88,    87,    19,    20,   102,   154,    98,   100,
     166,   173,   174,   154,   102,   102,   101,   161,   166,   102,
     147,   164,   105,   137,   175,     3,    34,    36,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,   106,
     109,   139,   144,   181,   182,   183,   184,   185,   186,   187,
     191,   193,   194,   144,   183,    43,    94,   104,   137,   167,
       3,   102,   145,   168,   169,   170,   171,   152,   106,   153,
     103,   109,   155,   156,   164,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    86,   138,   101,   106,   140,
     106,   159,   172,   172,     3,   102,   111,   172,   137,   101,
     102,   102,     3,     3,   139,     3,   102,   121,   137,   125,
     125,   125,   125,   126,   126,   127,   127,   128,   128,   128,
     128,   128,   129,   129,   130,   131,   132,   133,   134,    43,
      94,   104,   137,   167,   102,   168,   173,   174,    98,   100,
       6,    98,    99,   175,   176,   177,   178,   179,   103,   100,
     100,   140,   103,   100,   100,   100,   181,   100,     3,   109,
     109,   109,   139,   109,   106,   185,   137,   167,   104,   104,
      43,    94,   104,   137,   100,   164,   166,   173,   102,   101,
     101,   102,   106,   140,   101,   109,   103,   137,   106,   102,
     102,    39,   101,   102,   102,   101,   137,   105,   124,   104,
     101,   102,   137,   167,   104,   104,    43,   104,   137,   102,
     102,    43,    94,   104,   137,   167,   102,   168,   102,   140,
       3,   101,   106,   175,    86,   179,   181,     3,   149,   192,
     139,   103,   181,   139,   139,   139,    70,   144,   186,   109,
     109,   104,   137,   137,   104,   104,    86,    65,   170,     3,
     156,   140,   137,   183,     3,    39,    67,   118,   119,   172,
     176,   137,   104,   137,   137,   104,   137,   167,   104,   104,
      43,   104,   137,   102,   109,   104,   106,   175,   177,     3,
      35,   102,   181,   102,   102,   102,   100,   186,   186,   104,
     104,   137,   137,   183,   103,   101,   102,   103,   101,   106,
     104,   104,   104,   137,   137,   104,   175,   139,   105,   181,
     181,   181,   139,   102,   139,   102,   139,   137,   119,   137,
     106,   104,   104,   102,    66,   188,   189,    85,   102,   181,
     102,   181,   102,   181,   140,    67,   189,   190,   181,   109,
     181,   181,   103,   103,   106,   181,   181
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   110,   111,   111,   112,   112,   112,   112,   113,   113,
     113,   113,   113,   113,   114,   114,   114,   115,   116,   116,
     117,   118,   118,   119,   119,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   121,   121,   122,   122,
     122,   122,   122,   122,   122,   123,   123,   123,   123,   123,
     123,   124,   124,   125,   125,   126,   126,   126,   126,   127,
     127,   127,   128,   128,   128,   129,   129,   129,   129,   129,
     129,   130,   130,   130,   131,   131,   132,   132,   133,   133,
     134,   134,   135,   135,   136,   137,   137,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   138,   139,   139,
     140,   141,   141,   142,   143,   144,   144,   144,   144,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   146,
     146,   147,   147,   148,   148,   148,   148,   148,   148,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   150,   150,   150,   151,   151,
     152,   152,   153,   153,   153,   154,   154,   154,   154,   155,
     155,   156,   156,   156,   157,   157,   157,   157,   157,   158,
     158,   159,   159,   160,   161,   161,   161,   162,   162,   163,
     163,   164,   164,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   166,   166,   166,
     166,   167,   167,   168,   168,   169,   169,   170,   170,   170,
     170,   171,   171,   172,   172,   173,   173,   173,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   175,
     175,   175,   176,   176,   176,   176,   177,   178,   178,   179,
     179,   180,   181,   181,   181,   181,   181,   181,   182,   182,
     182,   183,   183,   184,   184,   185,   185,   186,   186,   187,
     188,   188,   189,   190,   190,   191,   191,   191,   191,   192,
     192,   193,   193,   193,   193,   193,   193,   193,   194,   194,
     194,   194,   194,   195,   195,   196,   196,   197,   197,   198,
     198
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     5,     5,     6,     6,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       6,     1,     3,     3,     3,     1,     4,     3,     4,     3,
       3,     3,     2,     2,     6,     7,     1,     3,     1,     2,
       2,     2,     2,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     3,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     3,     3,     3,     2,     3,     1,     1,     2,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     5,     2,     1,     1,
       1,     2,     2,     3,     1,     2,     1,     2,     1,     1,
       3,     2,     3,     1,     4,     5,     5,     6,     2,     1,
       3,     3,     1,     4,     1,     1,     1,     1,     1,     4,
       4,     2,     1,     1,     3,     3,     4,     6,     5,     5,
       6,     5,     4,     4,     4,     3,     4,     3,     2,     2,
       1,     1,     2,     3,     1,     1,     3,     2,     2,     1,
       4,     1,     3,     2,     1,     2,     1,     1,     3,     2,
       3,     5,     4,     5,     4,     3,     3,     3,     4,     6,
       5,     5,     6,     4,     4,     2,     3,     3,     4,     3,
       4,     1,     2,     1,     4,     3,     2,     1,     2,     3,
       2,     7,     1,     1,     1,     1,     1,     1,     3,     4,
       3,     2,     3,     1,     2,     1,     1,     1,     2,     8,
       2,     1,     4,     0,     3,     7,     5,     5,     1,     1,
       2,     5,     7,     6,     7,     6,     7,     7,     3,     2,
       2,     2,     3,     1,     2,     1,     1,     4,     3,     1,
       2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* lambda_params: IDENTIFIER  */
#line 66 "cyrix.y"
                     { derivations[derivation_count++] = "lambda_params -> IDENTIFIER"; }
#line 2422 "cyrix.tab.c"
    break;

  case 3: /* lambda_params: lambda_params ',' IDENTIFIER  */
#line 67 "cyrix.y"
                                       { derivations[derivation_count++] = "lambda_params -> lambda_params , IDENTIFIER"; }
#line 2428 "cyrix.tab.c"
    break;

  case 4: /* lambda_expression: FN '(' ')' LAMBDA_ARROW assignment_expression  */
#line 71 "cyrix.y"
                                                        { derivations[derivation_count++] = "lambda_expression -> FN ( ) LAMBDA_ARROW assignment_expression"; }
#line 2434 "cyrix.tab.c"
    break;

  case 5: /* lambda_expression: FN '(' ')' LAMBDA_ARROW compound_statement  */
#line 72 "cyrix.y"
                                                     { derivations[derivation_count++] = "lambda_expression -> FN ( ) LAMBDA_ARROW compound_statement"; }
#line 2440 "cyrix.tab.c"
    break;

  case 6: /* lambda_expression: FN '(' lambda_params ')' LAMBDA_ARROW assignment_expression  */
#line 73 "cyrix.y"
                                                                      { derivations[derivation_count++] = "lambda_expression -> FN ( lambda_params ) LAMBDA_ARROW assignment_expression"; }
#line 2446 "cyrix.tab.c"
    break;

  case 7: /* lambda_expression: FN '(' lambda_params ')' LAMBDA_ARROW compound_statement  */
#line 74 "cyrix.y"
                                                                   { derivations[derivation_count++] = "lambda_expression -> FN ( lambda_params ) LAMBDA_ARROW compound_statement"; }
#line 2452 "cyrix.tab.c"
    break;

  case 8: /* primary_expression: IDENTIFIER  */
#line 78 "cyrix.y"
                     { derivations[derivation_count++] = "primary_expression -> IDENTIFIER"; }
#line 2458 "cyrix.tab.c"
    break;

  case 9: /* primary_expression: constant  */
#line 79 "cyrix.y"
                   { derivations[derivation_count++] = "primary_expression -> constant"; }
#line 2464 "cyrix.tab.c"
    break;

  case 10: /* primary_expression: string  */
#line 80 "cyrix.y"
                 { derivations[derivation_count++] = "primary_expression -> string"; }
#line 2470 "cyrix.tab.c"
    break;

  case 11: /* primary_expression: '(' expression ')'  */
#line 81 "cyrix.y"
                             { derivations[derivation_count++] = "primary_expression -> ( expression )"; }
#line 2476 "cyrix.tab.c"
    break;

  case 12: /* primary_expression: generic_selection  */
#line 82 "cyrix.y"
                            { derivations[derivation_count++] = "primary_expression -> generic_selection"; }
#line 2482 "cyrix.tab.c"
    break;

  case 13: /* primary_expression: lambda_expression  */
#line 83 "cyrix.y"
                        { derivations[derivation_count++] = "primary_expression -> lambda_expression"; }
#line 2488 "cyrix.tab.c"
    break;

  case 14: /* constant: I_CONSTANT  */
#line 87 "cyrix.y"
                     { derivations[derivation_count++] = "constant -> I_CONSTANT"; }
#line 2494 "cyrix.tab.c"
    break;

  case 15: /* constant: F_CONSTANT  */
#line 88 "cyrix.y"
                     { derivations[derivation_count++] = "constant -> F_CONSTANT"; }
#line 2500 "cyrix.tab.c"
    break;

  case 16: /* constant: ENUMERATION_CONSTANT  */
#line 89 "cyrix.y"
                               { derivations[derivation_count++] = "constant -> ENUMERATION_CONSTANT"; }
#line 2506 "cyrix.tab.c"
    break;

  case 17: /* enumeration_constant: IDENTIFIER  */
#line 93 "cyrix.y"
                     { derivations[derivation_count++] = "enumeration_constant -> IDENTIFIER"; }
#line 2512 "cyrix.tab.c"
    break;

  case 18: /* string: STRING_LITERAL  */
#line 97 "cyrix.y"
                         { derivations[derivation_count++] = "string -> STRING_LITERAL"; }
#line 2518 "cyrix.tab.c"
    break;

  case 19: /* string: FUNC_NAME  */
#line 98 "cyrix.y"
                    { derivations[derivation_count++] = "string -> FUNC_NAME"; }
#line 2524 "cyrix.tab.c"
    break;

  case 20: /* generic_selection: GENERIC '(' assignment_expression ',' generic_assoc_list ')'  */
#line 102 "cyrix.y"
                                                                       { derivations[derivation_count++] = "generic_selection -> GENERIC ( assignment_expression , generic_assoc_list )"; }
#line 2530 "cyrix.tab.c"
    break;

  case 21: /* generic_assoc_list: generic_association  */
#line 106 "cyrix.y"
                              { derivations[derivation_count++] = "generic_assoc_list -> generic_association"; }
#line 2536 "cyrix.tab.c"
    break;

  case 22: /* generic_assoc_list: generic_assoc_list ',' generic_association  */
#line 107 "cyrix.y"
                                                     { derivations[derivation_count++] = "generic_assoc_list -> generic_assoc_list , generic_association"; }
#line 2542 "cyrix.tab.c"
    break;

  case 23: /* generic_association: type_name ':' assignment_expression  */
#line 111 "cyrix.y"
                                              { derivations[derivation_count++] = "generic_association -> type_name : assignment_expression"; }
#line 2548 "cyrix.tab.c"
    break;

  case 24: /* generic_association: DEFAULT ':' assignment_expression  */
#line 112 "cyrix.y"
                                            { derivations[derivation_count++] = "generic_association -> DEFAULT : assignment_expression"; }
#line 2554 "cyrix.tab.c"
    break;

  case 25: /* postfix_expression: primary_expression  */
#line 116 "cyrix.y"
                             { derivations[derivation_count++] = "postfix_expression -> primary_expression"; }
#line 2560 "cyrix.tab.c"
    break;

  case 26: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 117 "cyrix.y"
                                                { derivations[derivation_count++] = "postfix_expression -> postfix_expression [ expression ]"; }
#line 2566 "cyrix.tab.c"
    break;

  case 27: /* postfix_expression: postfix_expression '(' ')'  */
#line 118 "cyrix.y"
                                     { derivations[derivation_count++] = "postfix_expression -> postfix_expression ( )"; }
#line 2572 "cyrix.tab.c"
    break;

  case 28: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 119 "cyrix.y"
                                                              { derivations[derivation_count++] = "postfix_expression -> postfix_expression ( argument_expression_list )"; }
#line 2578 "cyrix.tab.c"
    break;

  case 29: /* postfix_expression: postfix_expression '.' IDENTIFIER  */
#line 120 "cyrix.y"
                                            { derivations[derivation_count++] = "postfix_expression -> postfix_expression . IDENTIFIER"; }
#line 2584 "cyrix.tab.c"
    break;

  case 30: /* postfix_expression: postfix_expression PTR_OP IDENTIFIER  */
#line 121 "cyrix.y"
                                               { derivations[derivation_count++] = "postfix_expression -> postfix_expression PTR_OP IDENTIFIER"; }
#line 2590 "cyrix.tab.c"
    break;

  case 31: /* postfix_expression: postfix_expression SAFE_DOT IDENTIFIER  */
#line 122 "cyrix.y"
                                             { derivations[derivation_count++] = "postfix_expression -> postfix_expression SAFE_DOT IDENTIFIER"; }
#line 2596 "cyrix.tab.c"
    break;

  case 32: /* postfix_expression: postfix_expression INC_OP  */
#line 123 "cyrix.y"
                                    { derivations[derivation_count++] = "postfix_expression -> postfix_expression INC_OP"; }
#line 2602 "cyrix.tab.c"
    break;

  case 33: /* postfix_expression: postfix_expression DEC_OP  */
#line 124 "cyrix.y"
                                    { derivations[derivation_count++] = "postfix_expression -> postfix_expression DEC_OP"; }
#line 2608 "cyrix.tab.c"
    break;

  case 34: /* postfix_expression: '(' type_name ')' '{' initializer_list '}'  */
#line 125 "cyrix.y"
                                                     { derivations[derivation_count++] = "postfix_expression -> ( type_name ) { initializer_list }"; }
#line 2614 "cyrix.tab.c"
    break;

  case 35: /* postfix_expression: '(' type_name ')' '{' initializer_list ',' '}'  */
#line 126 "cyrix.y"
                                                         { derivations[derivation_count++] = "postfix_expression -> ( type_name ) { initializer_list , }"; }
#line 2620 "cyrix.tab.c"
    break;

  case 36: /* argument_expression_list: assignment_expression  */
#line 130 "cyrix.y"
                                { derivations[derivation_count++] = "argument_expression_list -> assignment_expression"; }
#line 2626 "cyrix.tab.c"
    break;

  case 37: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 131 "cyrix.y"
                                                             { derivations[derivation_count++] = "argument_expression_list -> argument_expression_list , assignment_expression"; }
#line 2632 "cyrix.tab.c"
    break;

  case 38: /* unary_expression: postfix_expression  */
#line 135 "cyrix.y"
                                                   { derivations[derivation_count++] = "unary_expression -> postfix_expression"; }
#line 2638 "cyrix.tab.c"
    break;

  case 39: /* unary_expression: INC_OP unary_expression  */
#line 136 "cyrix.y"
                                  { derivations[derivation_count++] = "unary_expression -> INC_OP unary_expression"; }
#line 2644 "cyrix.tab.c"
    break;

  case 40: /* unary_expression: DEC_OP unary_expression  */
#line 137 "cyrix.y"
                                  { derivations[derivation_count++] = "unary_expression -> DEC_OP unary_expression"; }
#line 2650 "cyrix.tab.c"
    break;

  case 41: /* unary_expression: unary_operator cast_expression  */
#line 138 "cyrix.y"
                                                     { derivations[derivation_count++] = "unary_expression -> unary_operator cast_expression"; }
#line 2656 "cyrix.tab.c"
    break;

  case 42: /* unary_expression: SIZEOF unary_expression  */
#line 139 "cyrix.y"
                                  { derivations[derivation_count++] = "unary_expression -> SIZEOF unary_expression"; }
#line 2662 "cyrix.tab.c"
    break;

  case 43: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 140 "cyrix.y"
                                   { derivations[derivation_count++] = "unary_expression -> SIZEOF ( type_name )"; }
#line 2668 "cyrix.tab.c"
    break;

  case 44: /* unary_expression: ALIGNOF '(' type_name ')'  */
#line 141 "cyrix.y"
                                    { derivations[derivation_count++] = "unary_expression -> ALIGNOF ( type_name )"; }
#line 2674 "cyrix.tab.c"
    break;

  case 45: /* unary_operator: '&'  */
#line 145 "cyrix.y"
              { derivations[derivation_count++] = "unary_operator -> &"; }
#line 2680 "cyrix.tab.c"
    break;

  case 46: /* unary_operator: '*'  */
#line 146 "cyrix.y"
              { derivations[derivation_count++] = "unary_operator -> *"; }
#line 2686 "cyrix.tab.c"
    break;

  case 47: /* unary_operator: '+'  */
#line 147 "cyrix.y"
              { derivations[derivation_count++] = "unary_operator -> +"; }
#line 2692 "cyrix.tab.c"
    break;

  case 48: /* unary_operator: '-'  */
#line 148 "cyrix.y"
              { derivations[derivation_count++] = "unary_operator -> -"; }
#line 2698 "cyrix.tab.c"
    break;

  case 49: /* unary_operator: '~'  */
#line 149 "cyrix.y"
              { derivations[derivation_count++] = "unary_operator -> ~"; }
#line 2704 "cyrix.tab.c"
    break;

  case 50: /* unary_operator: '!'  */
#line 150 "cyrix.y"
              { derivations[derivation_count++] = "unary_operator -> !"; }
#line 2710 "cyrix.tab.c"
    break;

  case 51: /* cast_expression: unary_expression  */
#line 154 "cyrix.y"
                                                 { derivations[derivation_count++] = "cast_expression -> unary_expression"; }
#line 2716 "cyrix.tab.c"
    break;

  case 52: /* cast_expression: '(' type_name ')' cast_expression  */
#line 155 "cyrix.y"
                                            { derivations[derivation_count++] = "cast_expression -> ( type_name ) cast_expression"; }
#line 2722 "cyrix.tab.c"
    break;

  case 53: /* power_expression: cast_expression  */
#line 159 "cyrix.y"
                                                { derivations[derivation_count++] = "power_expression -> cast_expression"; }
#line 2728 "cyrix.tab.c"
    break;

  case 54: /* power_expression: cast_expression POW_OP power_expression  */
#line 160 "cyrix.y"
                                                  { derivations[derivation_count++] = "power_expression -> cast_expression POW_OP power_expression"; }
#line 2734 "cyrix.tab.c"
    break;

  case 55: /* multiplicative_expression: power_expression  */
#line 164 "cyrix.y"
                                                 { derivations[derivation_count++] = "multiplicative_expression -> power_expression"; }
#line 2740 "cyrix.tab.c"
    break;

  case 56: /* multiplicative_expression: multiplicative_expression '*' power_expression  */
#line 165 "cyrix.y"
                                                         { derivations[derivation_count++] = "multiplicative_expression -> multiplicative_expression * power_expression"; }
#line 2746 "cyrix.tab.c"
    break;

  case 57: /* multiplicative_expression: multiplicative_expression '/' power_expression  */
#line 166 "cyrix.y"
                                                         { derivations[derivation_count++] = "multiplicative_expression -> multiplicative_expression / power_expression"; }
#line 2752 "cyrix.tab.c"
    break;

  case 58: /* multiplicative_expression: multiplicative_expression '%' power_expression  */
#line 167 "cyrix.y"
                                                         { derivations[derivation_count++] = "multiplicative_expression -> multiplicative_expression % power_expression"; }
#line 2758 "cyrix.tab.c"
    break;

  case 59: /* additive_expression: multiplicative_expression  */
#line 171 "cyrix.y"
                                                          { derivations[derivation_count++] = "additive_expression -> multiplicative_expression"; }
#line 2764 "cyrix.tab.c"
    break;

  case 60: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 172 "cyrix.y"
                                                            { derivations[derivation_count++] = "additive_expression -> additive_expression + multiplicative_expression"; }
#line 2770 "cyrix.tab.c"
    break;

  case 61: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 173 "cyrix.y"
                                                            { derivations[derivation_count++] = "additive_expression -> additive_expression - multiplicative_expression"; }
#line 2776 "cyrix.tab.c"
    break;

  case 62: /* shift_expression: additive_expression  */
#line 177 "cyrix.y"
                                                    { derivations[derivation_count++] = "shift_expression -> additive_expression"; }
#line 2782 "cyrix.tab.c"
    break;

  case 63: /* shift_expression: shift_expression LEFT_OP additive_expression  */
#line 178 "cyrix.y"
                                                       { derivations[derivation_count++] = "shift_expression -> shift_expression LEFT_OP additive_expression"; }
#line 2788 "cyrix.tab.c"
    break;

  case 64: /* shift_expression: shift_expression RIGHT_OP additive_expression  */
#line 179 "cyrix.y"
                                                        { derivations[derivation_count++] = "shift_expression -> shift_expression RIGHT_OP additive_expression"; }
#line 2794 "cyrix.tab.c"
    break;

  case 65: /* relational_expression: shift_expression  */
#line 183 "cyrix.y"
                                                 { derivations[derivation_count++] = "relational_expression -> shift_expression"; }
#line 2800 "cyrix.tab.c"
    break;

  case 66: /* relational_expression: relational_expression '<' shift_expression  */
#line 184 "cyrix.y"
                                                     { derivations[derivation_count++] = "relational_expression -> relational_expression < shift_expression"; }
#line 2806 "cyrix.tab.c"
    break;

  case 67: /* relational_expression: relational_expression '>' shift_expression  */
#line 185 "cyrix.y"
                                                     { derivations[derivation_count++] = "relational_expression -> relational_expression > shift_expression"; }
#line 2812 "cyrix.tab.c"
    break;

  case 68: /* relational_expression: relational_expression LE_OP shift_expression  */
#line 186 "cyrix.y"
                                                       { derivations[derivation_count++] = "relational_expression -> relational_expression LE_OP shift_expression"; }
#line 2818 "cyrix.tab.c"
    break;

  case 69: /* relational_expression: relational_expression GE_OP shift_expression  */
#line 187 "cyrix.y"
                                                       { derivations[derivation_count++] = "relational_expression -> relational_expression GE_OP shift_expression"; }
#line 2824 "cyrix.tab.c"
    break;

  case 70: /* relational_expression: relational_expression TH_OP shift_expression  */
#line 188 "cyrix.y"
                                                       { derivations[derivation_count++] = "relational_expression -> relational_expression TH_OP shift_expression"; }
#line 2830 "cyrix.tab.c"
    break;

  case 71: /* equality_expression: relational_expression  */
#line 192 "cyrix.y"
                                                      { derivations[derivation_count++] = "equality_expression -> relational_expression"; }
#line 2836 "cyrix.tab.c"
    break;

  case 72: /* equality_expression: equality_expression EQ_OP relational_expression  */
#line 193 "cyrix.y"
                                                          { derivations[derivation_count++] = "equality_expression -> equality_expression EQ_OP relational_expression"; }
#line 2842 "cyrix.tab.c"
    break;

  case 73: /* equality_expression: equality_expression NE_OP relational_expression  */
#line 194 "cyrix.y"
                                                          { derivations[derivation_count++] = "equality_expression -> equality_expression NE_OP relational_expression"; }
#line 2848 "cyrix.tab.c"
    break;

  case 74: /* and_expression: equality_expression  */
#line 198 "cyrix.y"
                                                    { derivations[derivation_count++] = "and_expression -> equality_expression"; }
#line 2854 "cyrix.tab.c"
    break;

  case 75: /* and_expression: and_expression '&' equality_expression  */
#line 199 "cyrix.y"
                                                 { derivations[derivation_count++] = "and_expression -> and_expression & equality_expression"; }
#line 2860 "cyrix.tab.c"
    break;

  case 76: /* exclusive_or_expression: and_expression  */
#line 203 "cyrix.y"
                                               { derivations[derivation_count++] = "exclusive_or_expression -> and_expression"; }
#line 2866 "cyrix.tab.c"
    break;

  case 77: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 204 "cyrix.y"
                                                     { derivations[derivation_count++] = "exclusive_or_expression -> exclusive_or_expression ^ and_expression"; }
#line 2872 "cyrix.tab.c"
    break;

  case 78: /* inclusive_or_expression: exclusive_or_expression  */
#line 208 "cyrix.y"
                                                        { derivations[derivation_count++] = "inclusive_or_expression -> exclusive_or_expression"; }
#line 2878 "cyrix.tab.c"
    break;

  case 79: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 209 "cyrix.y"
                                                              { derivations[derivation_count++] = "inclusive_or_expression -> inclusive_or_expression | exclusive_or_expression"; }
#line 2884 "cyrix.tab.c"
    break;

  case 80: /* logical_and_expression: inclusive_or_expression  */
#line 213 "cyrix.y"
                                                        { derivations[derivation_count++] = "logical_and_expression -> inclusive_or_expression"; }
#line 2890 "cyrix.tab.c"
    break;

  case 81: /* logical_and_expression: logical_and_expression AND_OP inclusive_or_expression  */
#line 214 "cyrix.y"
                                                                { derivations[derivation_count++] = "logical_and_expression -> logical_and_expression AND_OP inclusive_or_expression"; }
#line 2896 "cyrix.tab.c"
    break;

  case 82: /* logical_or_expression: logical_and_expression  */
#line 218 "cyrix.y"
                                                       { derivations[derivation_count++] = "logical_or_expression -> logical_and_expression"; }
#line 2902 "cyrix.tab.c"
    break;

  case 83: /* logical_or_expression: logical_or_expression OR_OP logical_and_expression  */
#line 219 "cyrix.y"
                                                             { derivations[derivation_count++] = "logical_or_expression -> logical_or_expression OR_OP logical_and_expression"; }
#line 2908 "cyrix.tab.c"
    break;

  case 84: /* conditional_expression: logical_or_expression  */
#line 223 "cyrix.y"
                                                      { derivations[derivation_count++] = "conditional_expression -> logical_or_expression"; }
#line 2914 "cyrix.tab.c"
    break;

  case 85: /* assignment_expression: conditional_expression  */
#line 227 "cyrix.y"
                                 { derivations[derivation_count++] = "assignment_expression -> conditional_expression"; }
#line 2920 "cyrix.tab.c"
    break;

  case 86: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 228 "cyrix.y"
                                                                     { derivations[derivation_count++] = "assignment_expression -> unary_expression assignment_operator assignment_expression"; }
#line 2926 "cyrix.tab.c"
    break;

  case 87: /* assignment_operator: '='  */
#line 232 "cyrix.y"
              { derivations[derivation_count++] = "assignment_operator -> ="; }
#line 2932 "cyrix.tab.c"
    break;

  case 88: /* assignment_operator: MUL_ASSIGN  */
#line 233 "cyrix.y"
                     { derivations[derivation_count++] = "assignment_operator -> MUL_ASSIGN"; }
#line 2938 "cyrix.tab.c"
    break;

  case 89: /* assignment_operator: DIV_ASSIGN  */
#line 234 "cyrix.y"
                     { derivations[derivation_count++] = "assignment_operator -> DIV_ASSIGN"; }
#line 2944 "cyrix.tab.c"
    break;

  case 90: /* assignment_operator: MOD_ASSIGN  */
#line 235 "cyrix.y"
                     { derivations[derivation_count++] = "assignment_operator -> MOD_ASSIGN"; }
#line 2950 "cyrix.tab.c"
    break;

  case 91: /* assignment_operator: ADD_ASSIGN  */
#line 236 "cyrix.y"
                     { derivations[derivation_count++] = "assignment_operator -> ADD_ASSIGN"; }
#line 2956 "cyrix.tab.c"
    break;

  case 92: /* assignment_operator: SUB_ASSIGN  */
#line 237 "cyrix.y"
                     { derivations[derivation_count++] = "assignment_operator -> SUB_ASSIGN"; }
#line 2962 "cyrix.tab.c"
    break;

  case 93: /* assignment_operator: LEFT_ASSIGN  */
#line 238 "cyrix.y"
                      { derivations[derivation_count++] = "assignment_operator -> LEFT_ASSIGN"; }
#line 2968 "cyrix.tab.c"
    break;

  case 94: /* assignment_operator: RIGHT_ASSIGN  */
#line 239 "cyrix.y"
                       { derivations[derivation_count++] = "assignment_operator -> RIGHT_ASSIGN"; }
#line 2974 "cyrix.tab.c"
    break;

  case 95: /* assignment_operator: AND_ASSIGN  */
#line 240 "cyrix.y"
                     { derivations[derivation_count++] = "assignment_operator -> AND_ASSIGN"; }
#line 2980 "cyrix.tab.c"
    break;

  case 96: /* assignment_operator: XOR_ASSIGN  */
#line 241 "cyrix.y"
                     { derivations[derivation_count++] = "assignment_operator -> XOR_ASSIGN"; }
#line 2986 "cyrix.tab.c"
    break;

  case 97: /* assignment_operator: OR_ASSIGN  */
#line 242 "cyrix.y"
                    { derivations[derivation_count++] = "assignment_operator -> OR_ASSIGN"; }
#line 2992 "cyrix.tab.c"
    break;

  case 98: /* expression: assignment_expression  */
#line 246 "cyrix.y"
                                { derivations[derivation_count++] = "expression -> assignment_expression"; }
#line 2998 "cyrix.tab.c"
    break;

  case 99: /* expression: expression ',' assignment_expression  */
#line 247 "cyrix.y"
                                               { derivations[derivation_count++] = "expression -> expression , assignment_expression"; }
#line 3004 "cyrix.tab.c"
    break;

  case 100: /* constant_expression: conditional_expression  */
#line 251 "cyrix.y"
                                 { derivations[derivation_count++] = "constant_expression -> conditional_expression"; }
#line 3010 "cyrix.tab.c"
    break;

  case 101: /* var_init_list: var_init  */
#line 255 "cyrix.y"
                   { derivations[derivation_count++] = "var_init_list -> var_init"; }
#line 3016 "cyrix.tab.c"
    break;

  case 102: /* var_init_list: var_init_list ',' var_init  */
#line 256 "cyrix.y"
                                     { derivations[derivation_count++] = "var_init_list -> var_init_list , var_init"; }
#line 3022 "cyrix.tab.c"
    break;

  case 103: /* var_init: IDENTIFIER '=' assignment_expression  */
#line 260 "cyrix.y"
                                               { derivations[derivation_count++] = "var_init -> IDENTIFIER = assignment_expression"; }
#line 3028 "cyrix.tab.c"
    break;

  case 104: /* var_declaration: VAR var_init_list ';'  */
#line 264 "cyrix.y"
                                { derivations[derivation_count++] = "var_declaration -> VAR var_init_list ;"; }
#line 3034 "cyrix.tab.c"
    break;

  case 105: /* declaration: declaration_specifiers ';'  */
#line 268 "cyrix.y"
                                     { derivations[derivation_count++] = "declaration -> declaration_specifiers ;"; }
#line 3040 "cyrix.tab.c"
    break;

  case 106: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 269 "cyrix.y"
                                                          { derivations[derivation_count++] = "declaration -> declaration_specifiers init_declarator_list ;"; }
#line 3046 "cyrix.tab.c"
    break;

  case 107: /* declaration: static_assert_declaration  */
#line 270 "cyrix.y"
                                    { derivations[derivation_count++] = "declaration -> static_assert_declaration"; }
#line 3052 "cyrix.tab.c"
    break;

  case 108: /* declaration: var_declaration  */
#line 271 "cyrix.y"
                      { derivations[derivation_count++] = "declaration -> var_declaration"; }
#line 3058 "cyrix.tab.c"
    break;

  case 109: /* declaration_specifiers: storage_class_specifier declaration_specifiers  */
#line 275 "cyrix.y"
                                                         { derivations[derivation_count++] = "declaration_specifiers -> storage_class_specifier declaration_specifiers"; }
#line 3064 "cyrix.tab.c"
    break;

  case 110: /* declaration_specifiers: storage_class_specifier  */
#line 276 "cyrix.y"
                                  { derivations[derivation_count++] = "declaration_specifiers -> storage_class_specifier"; }
#line 3070 "cyrix.tab.c"
    break;

  case 111: /* declaration_specifiers: type_specifier declaration_specifiers  */
#line 277 "cyrix.y"
                                                { derivations[derivation_count++] = "declaration_specifiers -> type_specifier declaration_specifiers"; }
#line 3076 "cyrix.tab.c"
    break;

  case 112: /* declaration_specifiers: type_specifier  */
#line 278 "cyrix.y"
                         { derivations[derivation_count++] = "declaration_specifiers -> type_specifier"; }
#line 3082 "cyrix.tab.c"
    break;

  case 113: /* declaration_specifiers: type_qualifier declaration_specifiers  */
#line 279 "cyrix.y"
                                                { derivations[derivation_count++] = "declaration_specifiers -> type_qualifier declaration_specifiers"; }
#line 3088 "cyrix.tab.c"
    break;

  case 114: /* declaration_specifiers: type_qualifier  */
#line 280 "cyrix.y"
                         { derivations[derivation_count++] = "declaration_specifiers -> type_qualifier"; }
#line 3094 "cyrix.tab.c"
    break;

  case 115: /* declaration_specifiers: function_specifier declaration_specifiers  */
#line 281 "cyrix.y"
                                                    { derivations[derivation_count++] = "declaration_specifiers -> function_specifier declaration_specifiers"; }
#line 3100 "cyrix.tab.c"
    break;

  case 116: /* declaration_specifiers: function_specifier  */
#line 282 "cyrix.y"
                             { derivations[derivation_count++] = "declaration_specifiers -> function_specifier"; }
#line 3106 "cyrix.tab.c"
    break;

  case 117: /* declaration_specifiers: alignment_specifier declaration_specifiers  */
#line 283 "cyrix.y"
                                                     { derivations[derivation_count++] = "declaration_specifiers -> alignment_specifier declaration_specifiers"; }
#line 3112 "cyrix.tab.c"
    break;

  case 118: /* declaration_specifiers: alignment_specifier  */
#line 284 "cyrix.y"
                              { derivations[derivation_count++] = "declaration_specifiers -> alignment_specifier"; }
#line 3118 "cyrix.tab.c"
    break;

  case 119: /* init_declarator_list: init_declarator  */
#line 288 "cyrix.y"
                          { derivations[derivation_count++] = "init_declarator_list -> init_declarator"; }
#line 3124 "cyrix.tab.c"
    break;

  case 120: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 289 "cyrix.y"
                                                   { derivations[derivation_count++] = "init_declarator_list -> init_declarator_list , init_declarator"; }
#line 3130 "cyrix.tab.c"
    break;

  case 121: /* init_declarator: declarator '=' initializer  */
#line 293 "cyrix.y"
                                     { derivations[derivation_count++] = "init_declarator -> declarator = initializer"; }
#line 3136 "cyrix.tab.c"
    break;

  case 122: /* init_declarator: declarator  */
#line 294 "cyrix.y"
                     { derivations[derivation_count++] = "init_declarator -> declarator"; }
#line 3142 "cyrix.tab.c"
    break;

  case 123: /* storage_class_specifier: TYPEDEF  */
#line 298 "cyrix.y"
                  { derivations[derivation_count++] = "storage_class_specifier -> TYPEDEF"; }
#line 3148 "cyrix.tab.c"
    break;

  case 124: /* storage_class_specifier: EXTERN  */
#line 299 "cyrix.y"
                 { derivations[derivation_count++] = "storage_class_specifier -> EXTERN"; }
#line 3154 "cyrix.tab.c"
    break;

  case 125: /* storage_class_specifier: STATIC  */
#line 300 "cyrix.y"
                 { derivations[derivation_count++] = "storage_class_specifier -> STATIC"; }
#line 3160 "cyrix.tab.c"
    break;

  case 126: /* storage_class_specifier: THREAD_LOCAL  */
#line 301 "cyrix.y"
                       { derivations[derivation_count++] = "storage_class_specifier -> THREAD_LOCAL"; }
#line 3166 "cyrix.tab.c"
    break;

  case 127: /* storage_class_specifier: AUTO  */
#line 302 "cyrix.y"
               { derivations[derivation_count++] = "storage_class_specifier -> AUTO"; }
#line 3172 "cyrix.tab.c"
    break;

  case 128: /* storage_class_specifier: REGISTER  */
#line 303 "cyrix.y"
                   { derivations[derivation_count++] = "storage_class_specifier -> REGISTER"; }
#line 3178 "cyrix.tab.c"
    break;

  case 129: /* type_specifier: VOID  */
#line 307 "cyrix.y"
               { derivations[derivation_count++] = "type_specifier -> VOID"; }
#line 3184 "cyrix.tab.c"
    break;

  case 130: /* type_specifier: CHAR  */
#line 308 "cyrix.y"
               { derivations[derivation_count++] = "type_specifier -> CHAR"; }
#line 3190 "cyrix.tab.c"
    break;

  case 131: /* type_specifier: SHORT  */
#line 309 "cyrix.y"
                { derivations[derivation_count++] = "type_specifier -> SHORT"; }
#line 3196 "cyrix.tab.c"
    break;

  case 132: /* type_specifier: INT  */
#line 310 "cyrix.y"
              { derivations[derivation_count++] = "type_specifier -> INT"; }
#line 3202 "cyrix.tab.c"
    break;

  case 133: /* type_specifier: LONG  */
#line 311 "cyrix.y"
               { derivations[derivation_count++] = "type_specifier -> LONG"; }
#line 3208 "cyrix.tab.c"
    break;

  case 134: /* type_specifier: FLOAT  */
#line 312 "cyrix.y"
                { derivations[derivation_count++] = "type_specifier -> FLOAT"; }
#line 3214 "cyrix.tab.c"
    break;

  case 135: /* type_specifier: DOUBLE  */
#line 313 "cyrix.y"
                 { derivations[derivation_count++] = "type_specifier -> DOUBLE"; }
#line 3220 "cyrix.tab.c"
    break;

  case 136: /* type_specifier: SIGNED  */
#line 314 "cyrix.y"
                 { derivations[derivation_count++] = "type_specifier -> SIGNED"; }
#line 3226 "cyrix.tab.c"
    break;

  case 137: /* type_specifier: UNSIGNED  */
#line 315 "cyrix.y"
                   { derivations[derivation_count++] = "type_specifier -> UNSIGNED"; }
#line 3232 "cyrix.tab.c"
    break;

  case 138: /* type_specifier: BOOL  */
#line 316 "cyrix.y"
               { derivations[derivation_count++] = "type_specifier -> BOOL"; }
#line 3238 "cyrix.tab.c"
    break;

  case 139: /* type_specifier: COMPLEX  */
#line 317 "cyrix.y"
                  { derivations[derivation_count++] = "type_specifier -> COMPLEX"; }
#line 3244 "cyrix.tab.c"
    break;

  case 140: /* type_specifier: IMAGINARY  */
#line 318 "cyrix.y"
                    { derivations[derivation_count++] = "type_specifier -> IMAGINARY"; }
#line 3250 "cyrix.tab.c"
    break;

  case 141: /* type_specifier: atomic_type_specifier  */
#line 319 "cyrix.y"
                                { derivations[derivation_count++] = "type_specifier -> atomic_type_specifier"; }
#line 3256 "cyrix.tab.c"
    break;

  case 142: /* type_specifier: struct_or_union_specifier  */
#line 320 "cyrix.y"
                                    { derivations[derivation_count++] = "type_specifier -> struct_or_union_specifier"; }
#line 3262 "cyrix.tab.c"
    break;

  case 143: /* type_specifier: enum_specifier  */
#line 321 "cyrix.y"
                         { derivations[derivation_count++] = "type_specifier -> enum_specifier"; }
#line 3268 "cyrix.tab.c"
    break;

  case 144: /* type_specifier: TYPEDEF_NAME  */
#line 322 "cyrix.y"
                       { derivations[derivation_count++] = "type_specifier -> TYPEDEF_NAME"; }
#line 3274 "cyrix.tab.c"
    break;

  case 145: /* struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}'  */
#line 326 "cyrix.y"
                                                          { derivations[derivation_count++] = "struct_or_union_specifier -> struct_or_union { struct_declaration_list }"; }
#line 3280 "cyrix.tab.c"
    break;

  case 146: /* struct_or_union_specifier: struct_or_union IDENTIFIER '{' struct_declaration_list '}'  */
#line 327 "cyrix.y"
                                                                     { derivations[derivation_count++] = "struct_or_union_specifier -> struct_or_union IDENTIFIER { struct_declaration_list }"; }
#line 3286 "cyrix.tab.c"
    break;

  case 147: /* struct_or_union_specifier: struct_or_union IDENTIFIER  */
#line 328 "cyrix.y"
                                     { derivations[derivation_count++] = "struct_or_union_specifier -> struct_or_union IDENTIFIER"; }
#line 3292 "cyrix.tab.c"
    break;

  case 148: /* struct_or_union: STRUCT  */
#line 332 "cyrix.y"
                 { derivations[derivation_count++] = "struct_or_union -> STRUCT"; }
#line 3298 "cyrix.tab.c"
    break;

  case 149: /* struct_or_union: UNION  */
#line 333 "cyrix.y"
                { derivations[derivation_count++] = "struct_or_union -> UNION"; }
#line 3304 "cyrix.tab.c"
    break;

  case 150: /* struct_declaration_list: struct_declaration  */
#line 337 "cyrix.y"
                             { derivations[derivation_count++] = "struct_declaration_list -> struct_declaration"; }
#line 3310 "cyrix.tab.c"
    break;

  case 151: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 338 "cyrix.y"
                                                     { derivations[derivation_count++] = "struct_declaration_list -> struct_declaration_list struct_declaration"; }
#line 3316 "cyrix.tab.c"
    break;

  case 152: /* struct_declaration: specifier_qualifier_list ';'  */
#line 342 "cyrix.y"
                                       { derivations[derivation_count++] = "struct_declaration -> specifier_qualifier_list ;"; }
#line 3322 "cyrix.tab.c"
    break;

  case 153: /* struct_declaration: specifier_qualifier_list struct_declarator_list ';'  */
#line 343 "cyrix.y"
                                                              { derivations[derivation_count++] = "struct_declaration -> specifier_qualifier_list struct_declarator_list ;"; }
#line 3328 "cyrix.tab.c"
    break;

  case 154: /* struct_declaration: static_assert_declaration  */
#line 344 "cyrix.y"
                                    { derivations[derivation_count++] = "struct_declaration -> static_assert_declaration"; }
#line 3334 "cyrix.tab.c"
    break;

  case 155: /* specifier_qualifier_list: type_specifier specifier_qualifier_list  */
#line 348 "cyrix.y"
                                                  { derivations[derivation_count++] = "specifier_qualifier_list -> type_specifier specifier_qualifier_list"; }
#line 3340 "cyrix.tab.c"
    break;

  case 156: /* specifier_qualifier_list: type_specifier  */
#line 349 "cyrix.y"
                         { derivations[derivation_count++] = "specifier_qualifier_list -> type_specifier"; }
#line 3346 "cyrix.tab.c"
    break;

  case 157: /* specifier_qualifier_list: type_qualifier specifier_qualifier_list  */
#line 350 "cyrix.y"
                                                  { derivations[derivation_count++] = "specifier_qualifier_list -> type_qualifier specifier_qualifier_list"; }
#line 3352 "cyrix.tab.c"
    break;

  case 158: /* specifier_qualifier_list: type_qualifier  */
#line 351 "cyrix.y"
                         { derivations[derivation_count++] = "specifier_qualifier_list -> type_qualifier"; }
#line 3358 "cyrix.tab.c"
    break;

  case 159: /* struct_declarator_list: struct_declarator  */
#line 355 "cyrix.y"
                            { derivations[derivation_count++] = "struct_declarator_list -> struct_declarator"; }
#line 3364 "cyrix.tab.c"
    break;

  case 160: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 356 "cyrix.y"
                                                       { derivations[derivation_count++] = "struct_declarator_list -> struct_declarator_list , struct_declarator"; }
#line 3370 "cyrix.tab.c"
    break;

  case 161: /* struct_declarator: ':' constant_expression  */
#line 360 "cyrix.y"
                                  { derivations[derivation_count++] = "struct_declarator -> : constant_expression"; }
#line 3376 "cyrix.tab.c"
    break;

  case 162: /* struct_declarator: declarator ':' constant_expression  */
#line 361 "cyrix.y"
                                             { derivations[derivation_count++] = "struct_declarator -> declarator : constant_expression"; }
#line 3382 "cyrix.tab.c"
    break;

  case 163: /* struct_declarator: declarator  */
#line 362 "cyrix.y"
                     { derivations[derivation_count++] = "struct_declarator -> declarator"; }
#line 3388 "cyrix.tab.c"
    break;

  case 164: /* enum_specifier: ENUM '{' enumerator_list '}'  */
#line 366 "cyrix.y"
                                       { derivations[derivation_count++] = "enum_specifier -> ENUM { enumerator_list }"; }
#line 3394 "cyrix.tab.c"
    break;

  case 165: /* enum_specifier: ENUM '{' enumerator_list ',' '}'  */
#line 367 "cyrix.y"
                                           { derivations[derivation_count++] = "enum_specifier -> ENUM { enumerator_list , }"; }
#line 3400 "cyrix.tab.c"
    break;

  case 166: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list '}'  */
#line 368 "cyrix.y"
                                                  { derivations[derivation_count++] = "enum_specifier -> ENUM IDENTIFIER { enumerator_list }"; }
#line 3406 "cyrix.tab.c"
    break;

  case 167: /* enum_specifier: ENUM IDENTIFIER '{' enumerator_list ',' '}'  */
#line 369 "cyrix.y"
                                                      { derivations[derivation_count++] = "enum_specifier -> ENUM IDENTIFIER { enumerator_list , }"; }
#line 3412 "cyrix.tab.c"
    break;

  case 168: /* enum_specifier: ENUM IDENTIFIER  */
#line 370 "cyrix.y"
                          { derivations[derivation_count++] = "enum_specifier -> ENUM IDENTIFIER"; }
#line 3418 "cyrix.tab.c"
    break;

  case 169: /* enumerator_list: enumerator  */
#line 374 "cyrix.y"
                     { derivations[derivation_count++] = "enumerator_list -> enumerator"; }
#line 3424 "cyrix.tab.c"
    break;

  case 170: /* enumerator_list: enumerator_list ',' enumerator  */
#line 375 "cyrix.y"
                                         { derivations[derivation_count++] = "enumerator_list -> enumerator_list , enumerator"; }
#line 3430 "cyrix.tab.c"
    break;

  case 171: /* enumerator: enumeration_constant '=' constant_expression  */
#line 379 "cyrix.y"
                                                       { derivations[derivation_count++] = "enumerator -> enumeration_constant = constant_expression"; }
#line 3436 "cyrix.tab.c"
    break;

  case 172: /* enumerator: enumeration_constant  */
#line 380 "cyrix.y"
                               { derivations[derivation_count++] = "enumerator -> enumeration_constant"; }
#line 3442 "cyrix.tab.c"
    break;

  case 173: /* atomic_type_specifier: ATOMIC '(' type_name ')'  */
#line 384 "cyrix.y"
                                   { derivations[derivation_count++] = "atomic_type_specifier -> ATOMIC ( type_name )"; }
#line 3448 "cyrix.tab.c"
    break;

  case 174: /* type_qualifier: CONST  */
#line 388 "cyrix.y"
                { derivations[derivation_count++] = "type_qualifier -> CONST"; }
#line 3454 "cyrix.tab.c"
    break;

  case 175: /* type_qualifier: RESTRICT  */
#line 389 "cyrix.y"
                   { derivations[derivation_count++] = "type_qualifier -> RESTRICT"; }
#line 3460 "cyrix.tab.c"
    break;

  case 176: /* type_qualifier: VOLATILE  */
#line 390 "cyrix.y"
                   { derivations[derivation_count++] = "type_qualifier -> VOLATILE"; }
#line 3466 "cyrix.tab.c"
    break;

  case 177: /* function_specifier: INLINE  */
#line 394 "cyrix.y"
                 { derivations[derivation_count++] = "function_specifier -> INLINE"; }
#line 3472 "cyrix.tab.c"
    break;

  case 178: /* function_specifier: NORETURN  */
#line 395 "cyrix.y"
                   { derivations[derivation_count++] = "function_specifier -> NORETURN"; }
#line 3478 "cyrix.tab.c"
    break;

  case 179: /* alignment_specifier: ALIGNAS '(' type_name ')'  */
#line 399 "cyrix.y"
                                    { derivations[derivation_count++] = "alignment_specifier -> ALIGNAS ( type_name )"; }
#line 3484 "cyrix.tab.c"
    break;

  case 180: /* alignment_specifier: ALIGNAS '(' constant_expression ')'  */
#line 400 "cyrix.y"
                                              { derivations[derivation_count++] = "alignment_specifier -> ALIGNAS ( constant_expression )"; }
#line 3490 "cyrix.tab.c"
    break;

  case 181: /* declarator: pointer direct_declarator  */
#line 404 "cyrix.y"
                                    { derivations[derivation_count++] = "declarator -> pointer direct_declarator"; }
#line 3496 "cyrix.tab.c"
    break;

  case 182: /* declarator: direct_declarator  */
#line 405 "cyrix.y"
                            { derivations[derivation_count++] = "declarator -> direct_declarator"; }
#line 3502 "cyrix.tab.c"
    break;

  case 183: /* direct_declarator: IDENTIFIER  */
#line 409 "cyrix.y"
                     { derivations[derivation_count++] = "direct_declarator -> IDENTIFIER"; }
#line 3508 "cyrix.tab.c"
    break;

  case 184: /* direct_declarator: '(' declarator ')'  */
#line 410 "cyrix.y"
                             { derivations[derivation_count++] = "direct_declarator -> ( declarator )"; }
#line 3514 "cyrix.tab.c"
    break;

  case 185: /* direct_declarator: direct_declarator '[' ']'  */
#line 411 "cyrix.y"
                                    { derivations[derivation_count++] = "direct_declarator -> direct_declarator [ ]"; }
#line 3520 "cyrix.tab.c"
    break;

  case 186: /* direct_declarator: direct_declarator '[' '*' ']'  */
#line 412 "cyrix.y"
                                        { derivations[derivation_count++] = "direct_declarator -> direct_declarator [ * ]"; }
#line 3526 "cyrix.tab.c"
    break;

  case 187: /* direct_declarator: direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'  */
#line 413 "cyrix.y"
                                                                                     { derivations[derivation_count++] = "direct_declarator -> direct_declarator [ STATIC type_qualifier_list assignment_expression ]"; }
#line 3532 "cyrix.tab.c"
    break;

  case 188: /* direct_declarator: direct_declarator '[' STATIC assignment_expression ']'  */
#line 414 "cyrix.y"
                                                                 { derivations[derivation_count++] = "direct_declarator -> direct_declarator [ STATIC assignment_expression ]"; }
#line 3538 "cyrix.tab.c"
    break;

  case 189: /* direct_declarator: direct_declarator '[' type_qualifier_list '*' ']'  */
#line 415 "cyrix.y"
                                                            { derivations[derivation_count++] = "direct_declarator -> direct_declarator [ type_qualifier_list * ]"; }
#line 3544 "cyrix.tab.c"
    break;

  case 190: /* direct_declarator: direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'  */
#line 416 "cyrix.y"
                                                                                     { derivations[derivation_count++] = "direct_declarator -> direct_declarator [ type_qualifier_list STATIC assignment_expression ]"; }
#line 3550 "cyrix.tab.c"
    break;

  case 191: /* direct_declarator: direct_declarator '[' type_qualifier_list assignment_expression ']'  */
#line 417 "cyrix.y"
                                                                              { derivations[derivation_count++] = "direct_declarator -> direct_declarator [ type_qualifier_list assignment_expression ]"; }
#line 3556 "cyrix.tab.c"
    break;

  case 192: /* direct_declarator: direct_declarator '[' type_qualifier_list ']'  */
#line 418 "cyrix.y"
                                                        { derivations[derivation_count++] = "direct_declarator -> direct_declarator [ type_qualifier_list ]"; }
#line 3562 "cyrix.tab.c"
    break;

  case 193: /* direct_declarator: direct_declarator '[' assignment_expression ']'  */
#line 419 "cyrix.y"
                                                          { derivations[derivation_count++] = "direct_declarator -> direct_declarator [ assignment_expression ]"; }
#line 3568 "cyrix.tab.c"
    break;

  case 194: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 420 "cyrix.y"
                                                        { derivations[derivation_count++] = "direct_declarator -> direct_declarator ( parameter_type_list )"; }
#line 3574 "cyrix.tab.c"
    break;

  case 195: /* direct_declarator: direct_declarator '(' ')'  */
#line 421 "cyrix.y"
                                    { derivations[derivation_count++] = "direct_declarator -> direct_declarator ( )"; }
#line 3580 "cyrix.tab.c"
    break;

  case 196: /* direct_declarator: direct_declarator '(' identifier_list ')'  */
#line 422 "cyrix.y"
                                                    { derivations[derivation_count++] = "direct_declarator -> direct_declarator ( identifier_list )"; }
#line 3586 "cyrix.tab.c"
    break;

  case 197: /* pointer: '*' type_qualifier_list pointer  */
#line 426 "cyrix.y"
                                          { derivations[derivation_count++] = "pointer -> * type_qualifier_list pointer"; }
#line 3592 "cyrix.tab.c"
    break;

  case 198: /* pointer: '*' type_qualifier_list  */
#line 427 "cyrix.y"
                                  { derivations[derivation_count++] = "pointer -> * type_qualifier_list"; }
#line 3598 "cyrix.tab.c"
    break;

  case 199: /* pointer: '*' pointer  */
#line 428 "cyrix.y"
                      { derivations[derivation_count++] = "pointer -> * pointer"; }
#line 3604 "cyrix.tab.c"
    break;

  case 200: /* pointer: '*'  */
#line 429 "cyrix.y"
              { derivations[derivation_count++] = "pointer -> *"; }
#line 3610 "cyrix.tab.c"
    break;

  case 201: /* type_qualifier_list: type_qualifier  */
#line 433 "cyrix.y"
                         { derivations[derivation_count++] = "type_qualifier_list -> type_qualifier"; }
#line 3616 "cyrix.tab.c"
    break;

  case 202: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 434 "cyrix.y"
                                             { derivations[derivation_count++] = "type_qualifier_list -> type_qualifier_list type_qualifier"; }
#line 3622 "cyrix.tab.c"
    break;

  case 203: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 439 "cyrix.y"
                                      { derivations[derivation_count++] = "parameter_type_list -> parameter_list , ELLIPSIS"; }
#line 3628 "cyrix.tab.c"
    break;

  case 204: /* parameter_type_list: parameter_list  */
#line 440 "cyrix.y"
                         { derivations[derivation_count++] = "parameter_type_list -> parameter_list"; }
#line 3634 "cyrix.tab.c"
    break;

  case 205: /* parameter_list: param_declaration  */
#line 444 "cyrix.y"
                            { derivations[derivation_count++] = "parameter_list -> param_declaration"; }
#line 3640 "cyrix.tab.c"
    break;

  case 206: /* parameter_list: parameter_list ',' param_declaration  */
#line 445 "cyrix.y"
                                               { derivations[derivation_count++] = "parameter_list -> parameter_list , param_declaration"; }
#line 3646 "cyrix.tab.c"
    break;

  case 207: /* param_declaration: declaration_specifiers declarator  */
#line 449 "cyrix.y"
                                            { derivations[derivation_count++] = "param_declaration -> declaration_specifiers declarator"; }
#line 3652 "cyrix.tab.c"
    break;

  case 208: /* param_declaration: declaration_specifiers abstract_declarator  */
#line 450 "cyrix.y"
                                                     { derivations[derivation_count++] = "param_declaration -> declaration_specifiers abstract_declarator"; }
#line 3658 "cyrix.tab.c"
    break;

  case 209: /* param_declaration: declaration_specifiers  */
#line 451 "cyrix.y"
                                 { derivations[derivation_count++] = "param_declaration -> declaration_specifiers"; }
#line 3664 "cyrix.tab.c"
    break;

  case 210: /* param_declaration: declaration_specifiers declarator '=' assignment_expression  */
#line 452 "cyrix.y"
                                                                      { derivations[derivation_count++] = "param_declaration -> declaration_specifiers declarator = assignment_expression"; }
#line 3670 "cyrix.tab.c"
    break;

  case 211: /* identifier_list: IDENTIFIER  */
#line 456 "cyrix.y"
                     { derivations[derivation_count++] = "identifier_list -> IDENTIFIER"; }
#line 3676 "cyrix.tab.c"
    break;

  case 212: /* identifier_list: identifier_list ',' IDENTIFIER  */
#line 457 "cyrix.y"
                                         { derivations[derivation_count++] = "identifier_list -> identifier_list , IDENTIFIER"; }
#line 3682 "cyrix.tab.c"
    break;

  case 213: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 461 "cyrix.y"
                                                       { derivations[derivation_count++] = "type_name -> specifier_qualifier_list abstract_declarator"; }
#line 3688 "cyrix.tab.c"
    break;

  case 214: /* type_name: specifier_qualifier_list  */
#line 462 "cyrix.y"
                                   { derivations[derivation_count++] = "type_name -> specifier_qualifier_list"; }
#line 3694 "cyrix.tab.c"
    break;

  case 215: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 466 "cyrix.y"
                                             { derivations[derivation_count++] = "abstract_declarator -> pointer direct_abstract_declarator"; }
#line 3700 "cyrix.tab.c"
    break;

  case 216: /* abstract_declarator: pointer  */
#line 467 "cyrix.y"
                  { derivations[derivation_count++] = "abstract_declarator -> pointer"; }
#line 3706 "cyrix.tab.c"
    break;

  case 217: /* abstract_declarator: direct_abstract_declarator  */
#line 468 "cyrix.y"
                                     { derivations[derivation_count++] = "abstract_declarator -> direct_abstract_declarator"; }
#line 3712 "cyrix.tab.c"
    break;

  case 218: /* direct_abstract_declarator: '(' abstract_declarator ')'  */
#line 472 "cyrix.y"
                                      { derivations[derivation_count++] = "direct_abstract_declarator -> ( abstract_declarator )"; }
#line 3718 "cyrix.tab.c"
    break;

  case 219: /* direct_abstract_declarator: '[' ']'  */
#line 473 "cyrix.y"
                  { derivations[derivation_count++] = "direct_abstract_declarator -> [ ]"; }
#line 3724 "cyrix.tab.c"
    break;

  case 220: /* direct_abstract_declarator: '[' '*' ']'  */
#line 474 "cyrix.y"
                      { derivations[derivation_count++] = "direct_abstract_declarator -> [ * ]"; }
#line 3730 "cyrix.tab.c"
    break;

  case 221: /* direct_abstract_declarator: '[' STATIC type_qualifier_list assignment_expression ']'  */
#line 475 "cyrix.y"
                                                                   { derivations[derivation_count++] = "direct_abstract_declarator -> [ STATIC type_qualifier_list assignment_expression ]"; }
#line 3736 "cyrix.tab.c"
    break;

  case 222: /* direct_abstract_declarator: '[' STATIC assignment_expression ']'  */
#line 476 "cyrix.y"
                                               { derivations[derivation_count++] = "direct_abstract_declarator -> [ STATIC assignment_expression ]"; }
#line 3742 "cyrix.tab.c"
    break;

  case 223: /* direct_abstract_declarator: '[' type_qualifier_list STATIC assignment_expression ']'  */
#line 477 "cyrix.y"
                                                                   { derivations[derivation_count++] = "direct_abstract_declarator -> [ type_qualifier_list STATIC assignment_expression ]"; }
#line 3748 "cyrix.tab.c"
    break;

  case 224: /* direct_abstract_declarator: '[' type_qualifier_list assignment_expression ']'  */
#line 478 "cyrix.y"
                                                            { derivations[derivation_count++] = "direct_abstract_declarator -> [ type_qualifier_list assignment_expression ]"; }
#line 3754 "cyrix.tab.c"
    break;

  case 225: /* direct_abstract_declarator: '[' type_qualifier_list ']'  */
#line 479 "cyrix.y"
                                      { derivations[derivation_count++] = "direct_abstract_declarator -> [ type_qualifier_list ]"; }
#line 3760 "cyrix.tab.c"
    break;

  case 226: /* direct_abstract_declarator: '[' assignment_expression ']'  */
#line 480 "cyrix.y"
                                        { derivations[derivation_count++] = "direct_abstract_declarator -> [ assignment_expression ]"; }
#line 3766 "cyrix.tab.c"
    break;

  case 227: /* direct_abstract_declarator: direct_abstract_declarator '[' ']'  */
#line 481 "cyrix.y"
                                             { derivations[derivation_count++] = "direct_abstract_declarator -> direct_abstract_declarator [ ]"; }
#line 3772 "cyrix.tab.c"
    break;

  case 228: /* direct_abstract_declarator: direct_abstract_declarator '[' '*' ']'  */
#line 482 "cyrix.y"
                                                 { derivations[derivation_count++] = "direct_abstract_declarator -> direct_abstract_declarator [ * ]"; }
#line 3778 "cyrix.tab.c"
    break;

  case 229: /* direct_abstract_declarator: direct_abstract_declarator '[' STATIC type_qualifier_list assignment_expression ']'  */
#line 483 "cyrix.y"
                                                                                              { derivations[derivation_count++] = "direct_abstract_declarator -> direct_abstract_declarator [ STATIC type_qualifier_list assignment_expression ]"; }
#line 3784 "cyrix.tab.c"
    break;

  case 230: /* direct_abstract_declarator: direct_abstract_declarator '[' STATIC assignment_expression ']'  */
#line 484 "cyrix.y"
                                                                          { derivations[derivation_count++] = "direct_abstract_declarator -> direct_abstract_declarator [ STATIC assignment_expression ]"; }
#line 3790 "cyrix.tab.c"
    break;

  case 231: /* direct_abstract_declarator: direct_abstract_declarator '[' type_qualifier_list assignment_expression ']'  */
#line 485 "cyrix.y"
                                                                                       { derivations[derivation_count++] = "direct_abstract_declarator -> direct_abstract_declarator [ type_qualifier_list assignment_expression ]"; }
#line 3796 "cyrix.tab.c"
    break;

  case 232: /* direct_abstract_declarator: direct_abstract_declarator '[' type_qualifier_list STATIC assignment_expression ']'  */
#line 486 "cyrix.y"
                                                                                              { derivations[derivation_count++] = "direct_abstract_declarator -> direct_abstract_declarator [ type_qualifier_list STATIC assignment_expression ]"; }
#line 3802 "cyrix.tab.c"
    break;

  case 233: /* direct_abstract_declarator: direct_abstract_declarator '[' type_qualifier_list ']'  */
#line 487 "cyrix.y"
                                                                 { derivations[derivation_count++] = "direct_abstract_declarator -> direct_abstract_declarator [ type_qualifier_list ]"; }
#line 3808 "cyrix.tab.c"
    break;

  case 234: /* direct_abstract_declarator: direct_abstract_declarator '[' assignment_expression ']'  */
#line 488 "cyrix.y"
                                                                   { derivations[derivation_count++] = "direct_abstract_declarator -> direct_abstract_declarator [ assignment_expression ]"; }
#line 3814 "cyrix.tab.c"
    break;

  case 235: /* direct_abstract_declarator: '(' ')'  */
#line 489 "cyrix.y"
                  { derivations[derivation_count++] = "direct_abstract_declarator -> ( )"; }
#line 3820 "cyrix.tab.c"
    break;

  case 236: /* direct_abstract_declarator: '(' parameter_type_list ')'  */
#line 490 "cyrix.y"
                                      { derivations[derivation_count++] = "direct_abstract_declarator -> ( parameter_type_list )"; }
#line 3826 "cyrix.tab.c"
    break;

  case 237: /* direct_abstract_declarator: direct_abstract_declarator '(' ')'  */
#line 491 "cyrix.y"
                                             { derivations[derivation_count++] = "direct_abstract_declarator -> direct_abstract_declarator ( )"; }
#line 3832 "cyrix.tab.c"
    break;

  case 238: /* direct_abstract_declarator: direct_abstract_declarator '(' parameter_type_list ')'  */
#line 492 "cyrix.y"
                                                                 { derivations[derivation_count++] = "direct_abstract_declarator -> direct_abstract_declarator ( parameter_type_list )"; }
#line 3838 "cyrix.tab.c"
    break;

  case 239: /* initializer: '{' initializer_list '}'  */
#line 496 "cyrix.y"
                                   { derivations[derivation_count++] = "initializer -> { initializer_list }"; }
#line 3844 "cyrix.tab.c"
    break;

  case 240: /* initializer: '{' initializer_list ',' '}'  */
#line 497 "cyrix.y"
                                       { derivations[derivation_count++] = "initializer -> { initializer_list , }"; }
#line 3850 "cyrix.tab.c"
    break;

  case 241: /* initializer: assignment_expression  */
#line 498 "cyrix.y"
                                { derivations[derivation_count++] = "initializer -> assignment_expression"; }
#line 3856 "cyrix.tab.c"
    break;

  case 242: /* initializer_list: designation initializer  */
#line 502 "cyrix.y"
                                  { derivations[derivation_count++] = "initializer_list -> designation initializer"; }
#line 3862 "cyrix.tab.c"
    break;

  case 243: /* initializer_list: initializer  */
#line 503 "cyrix.y"
                      { derivations[derivation_count++] = "initializer_list -> initializer"; }
#line 3868 "cyrix.tab.c"
    break;

  case 244: /* initializer_list: initializer_list ',' designation initializer  */
#line 504 "cyrix.y"
                                                       { derivations[derivation_count++] = "initializer_list -> initializer_list , designation initializer"; }
#line 3874 "cyrix.tab.c"
    break;

  case 245: /* initializer_list: initializer_list ',' initializer  */
#line 505 "cyrix.y"
                                           { derivations[derivation_count++] = "initializer_list -> initializer_list , initializer"; }
#line 3880 "cyrix.tab.c"
    break;

  case 246: /* designation: designator_list '='  */
#line 509 "cyrix.y"
                              { derivations[derivation_count++] = "designation -> designator_list ="; }
#line 3886 "cyrix.tab.c"
    break;

  case 247: /* designator_list: designator  */
#line 513 "cyrix.y"
                     { derivations[derivation_count++] = "designator_list -> designator"; }
#line 3892 "cyrix.tab.c"
    break;

  case 248: /* designator_list: designator_list designator  */
#line 514 "cyrix.y"
                                     { derivations[derivation_count++] = "designator_list -> designator_list designator"; }
#line 3898 "cyrix.tab.c"
    break;

  case 249: /* designator: '[' constant_expression ']'  */
#line 518 "cyrix.y"
                                      { derivations[derivation_count++] = "designator -> [ constant_expression ]"; }
#line 3904 "cyrix.tab.c"
    break;

  case 250: /* designator: '.' IDENTIFIER  */
#line 519 "cyrix.y"
                         { derivations[derivation_count++] = "designator -> . IDENTIFIER"; }
#line 3910 "cyrix.tab.c"
    break;

  case 251: /* static_assert_declaration: STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'  */
#line 523 "cyrix.y"
                                                                           { derivations[derivation_count++] = "static_assert_declaration -> STATIC_ASSERT ( constant_expression , STRING_LITERAL ) ;"; }
#line 3916 "cyrix.tab.c"
    break;

  case 252: /* statement: labeled_statement  */
#line 527 "cyrix.y"
                            { derivations[derivation_count++] = "statement -> labeled_statement"; }
#line 3922 "cyrix.tab.c"
    break;

  case 253: /* statement: compound_statement  */
#line 528 "cyrix.y"
                             { derivations[derivation_count++] = "statement -> compound_statement"; }
#line 3928 "cyrix.tab.c"
    break;

  case 254: /* statement: expression_statement  */
#line 529 "cyrix.y"
                               { derivations[derivation_count++] = "statement -> expression_statement"; }
#line 3934 "cyrix.tab.c"
    break;

  case 255: /* statement: selection_statement  */
#line 530 "cyrix.y"
                              { derivations[derivation_count++] = "statement -> selection_statement"; }
#line 3940 "cyrix.tab.c"
    break;

  case 256: /* statement: iteration_statement  */
#line 531 "cyrix.y"
                              { derivations[derivation_count++] = "statement -> iteration_statement"; }
#line 3946 "cyrix.tab.c"
    break;

  case 257: /* statement: jump_statement  */
#line 532 "cyrix.y"
                         { derivations[derivation_count++] = "statement -> jump_statement"; }
#line 3952 "cyrix.tab.c"
    break;

  case 258: /* labeled_statement: IDENTIFIER ':' statement  */
#line 536 "cyrix.y"
                                   { derivations[derivation_count++] = "labeled_statement -> IDENTIFIER : statement"; }
#line 3958 "cyrix.tab.c"
    break;

  case 259: /* labeled_statement: CASE constant_expression ':' statement  */
#line 537 "cyrix.y"
                                                 { derivations[derivation_count++] = "labeled_statement -> CASE constant_expression : statement"; }
#line 3964 "cyrix.tab.c"
    break;

  case 260: /* labeled_statement: DEFAULT ':' statement  */
#line 538 "cyrix.y"
                                { derivations[derivation_count++] = "labeled_statement -> DEFAULT : statement"; }
#line 3970 "cyrix.tab.c"
    break;

  case 261: /* compound_statement: '{' '}'  */
#line 542 "cyrix.y"
                  { derivations[derivation_count++] = "compound_statement -> { }"; }
#line 3976 "cyrix.tab.c"
    break;

  case 262: /* compound_statement: '{' block_item_list '}'  */
#line 543 "cyrix.y"
                                   { derivations[derivation_count++] = "compound_statement -> { block_item_list }"; }
#line 3982 "cyrix.tab.c"
    break;

  case 263: /* block_item_list: block_item  */
#line 547 "cyrix.y"
                     { derivations[derivation_count++] = "block_item_list -> block_item"; }
#line 3988 "cyrix.tab.c"
    break;

  case 264: /* block_item_list: block_item_list block_item  */
#line 548 "cyrix.y"
                                     { derivations[derivation_count++] = "block_item_list -> block_item_list block_item"; }
#line 3994 "cyrix.tab.c"
    break;

  case 265: /* block_item: declaration  */
#line 552 "cyrix.y"
                      { derivations[derivation_count++] = "block_item -> declaration"; }
#line 4000 "cyrix.tab.c"
    break;

  case 266: /* block_item: statement  */
#line 553 "cyrix.y"
                    { derivations[derivation_count++] = "block_item -> statement"; }
#line 4006 "cyrix.tab.c"
    break;

  case 267: /* expression_statement: ';'  */
#line 557 "cyrix.y"
              { derivations[derivation_count++] = "expression_statement -> ;"; }
#line 4012 "cyrix.tab.c"
    break;

  case 268: /* expression_statement: expression ';'  */
#line 558 "cyrix.y"
                         { derivations[derivation_count++] = "expression_statement -> expression ;"; }
#line 4018 "cyrix.tab.c"
    break;

  case 269: /* match_statement: MATCH '(' expression ')' '{' case_list default_opt '}'  */
#line 562 "cyrix.y"
                                                                 { derivations[derivation_count++] = "match_statement -> MATCH ( expression ) { case_list default_opt }"; }
#line 4024 "cyrix.tab.c"
    break;

  case 270: /* case_list: case_list match_case  */
#line 566 "cyrix.y"
                               { derivations[derivation_count++] = "case_list -> case_list match_case"; }
#line 4030 "cyrix.tab.c"
    break;

  case 271: /* case_list: match_case  */
#line 567 "cyrix.y"
                     { derivations[derivation_count++] = "case_list -> match_case"; }
#line 4036 "cyrix.tab.c"
    break;

  case 272: /* match_case: CASE constant_expression ':' statement  */
#line 571 "cyrix.y"
                                                 { derivations[derivation_count++] = "match_case -> CASE constant_expression : statement"; }
#line 4042 "cyrix.tab.c"
    break;

  case 273: /* default_opt: %empty  */
#line 575 "cyrix.y"
                      { derivations[derivation_count++] = "default_opt -> epsilon"; }
#line 4048 "cyrix.tab.c"
    break;

  case 274: /* default_opt: DEFAULT ':' statement  */
#line 576 "cyrix.y"
                                { derivations[derivation_count++] = "default_opt -> DEFAULT : statement"; }
#line 4054 "cyrix.tab.c"
    break;

  case 275: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 580 "cyrix.y"
                                                         { derivations[derivation_count++] = "selection_statement -> IF ( expression ) statement ELSE statement"; }
#line 4060 "cyrix.tab.c"
    break;

  case 276: /* selection_statement: IF '(' expression ')' statement  */
#line 581 "cyrix.y"
                                                                { derivations[derivation_count++] = "selection_statement -> IF ( expression ) statement"; }
#line 4066 "cyrix.tab.c"
    break;

  case 277: /* selection_statement: SWITCH '(' expression ')' statement  */
#line 582 "cyrix.y"
                                              { derivations[derivation_count++] = "selection_statement -> SWITCH ( expression ) statement"; }
#line 4072 "cyrix.tab.c"
    break;

  case 278: /* selection_statement: match_statement  */
#line 583 "cyrix.y"
                      { derivations[derivation_count++] = "selection_statement -> match_statement"; }
#line 4078 "cyrix.tab.c"
    break;

  case 279: /* foreach_var: IDENTIFIER  */
#line 587 "cyrix.y"
                     { derivations[derivation_count++] = "foreach_var -> IDENTIFIER"; }
#line 4084 "cyrix.tab.c"
    break;

  case 280: /* foreach_var: type_specifier IDENTIFIER  */
#line 588 "cyrix.y"
                                    { derivations[derivation_count++] = "foreach_var -> type_specifier IDENTIFIER"; }
#line 4090 "cyrix.tab.c"
    break;

  case 281: /* iteration_statement: WHILE '(' expression ')' statement  */
#line 592 "cyrix.y"
                                             { derivations[derivation_count++] = "iteration_statement -> WHILE ( expression ) statement"; }
#line 4096 "cyrix.tab.c"
    break;

  case 282: /* iteration_statement: DO statement WHILE '(' expression ')' ';'  */
#line 593 "cyrix.y"
                                                    { derivations[derivation_count++] = "iteration_statement -> DO statement WHILE ( expression ) ;"; }
#line 4102 "cyrix.tab.c"
    break;

  case 283: /* iteration_statement: FOR '(' expression_statement expression_statement ')' statement  */
#line 594 "cyrix.y"
                                                                          { derivations[derivation_count++] = "iteration_statement -> FOR ( expression_statement expression_statement ) statement"; }
#line 4108 "cyrix.tab.c"
    break;

  case 284: /* iteration_statement: FOR '(' expression_statement expression_statement expression ')' statement  */
#line 595 "cyrix.y"
                                                                                     { derivations[derivation_count++] = "iteration_statement -> FOR ( expression_statement expression_statement expression ) statement"; }
#line 4114 "cyrix.tab.c"
    break;

  case 285: /* iteration_statement: FOR '(' declaration expression_statement ')' statement  */
#line 596 "cyrix.y"
                                                                 { derivations[derivation_count++] = "iteration_statement -> FOR ( declaration expression_statement ) statement"; }
#line 4120 "cyrix.tab.c"
    break;

  case 286: /* iteration_statement: FOR '(' declaration expression_statement expression ')' statement  */
#line 597 "cyrix.y"
                                                                            { derivations[derivation_count++] = "iteration_statement -> FOR ( declaration expression_statement expression ) statement"; }
#line 4126 "cyrix.tab.c"
    break;

  case 287: /* iteration_statement: FOREACH '(' foreach_var IN expression ')' statement  */
#line 598 "cyrix.y"
                                                          { derivations[derivation_count++] = "iteration_statement -> FOREACH ( foreach_var IN expression ) statement"; }
#line 4132 "cyrix.tab.c"
    break;

  case 288: /* jump_statement: GOTO IDENTIFIER ';'  */
#line 602 "cyrix.y"
                              { derivations[derivation_count++] = "jump_statement -> GOTO IDENTIFIER ;"; }
#line 4138 "cyrix.tab.c"
    break;

  case 289: /* jump_statement: CONTINUE ';'  */
#line 603 "cyrix.y"
                       { derivations[derivation_count++] = "jump_statement -> CONTINUE ;"; }
#line 4144 "cyrix.tab.c"
    break;

  case 290: /* jump_statement: BREAK ';'  */
#line 604 "cyrix.y"
                    { derivations[derivation_count++] = "jump_statement -> BREAK ;"; }
#line 4150 "cyrix.tab.c"
    break;

  case 291: /* jump_statement: RETURN ';'  */
#line 605 "cyrix.y"
                     { derivations[derivation_count++] = "jump_statement -> RETURN ;"; }
#line 4156 "cyrix.tab.c"
    break;

  case 292: /* jump_statement: RETURN expression ';'  */
#line 606 "cyrix.y"
                                { derivations[derivation_count++] = "jump_statement -> RETURN expression ;"; }
#line 4162 "cyrix.tab.c"
    break;

  case 293: /* translation_unit: external_declaration  */
#line 610 "cyrix.y"
                               { derivations[derivation_count++] = "translation_unit -> external_declaration"; }
#line 4168 "cyrix.tab.c"
    break;

  case 294: /* translation_unit: translation_unit external_declaration  */
#line 611 "cyrix.y"
                                                { derivations[derivation_count++] = "translation_unit -> translation_unit external_declaration"; }
#line 4174 "cyrix.tab.c"
    break;

  case 295: /* external_declaration: function_definition  */
#line 615 "cyrix.y"
                              { derivations[derivation_count++] = "external_declaration -> function_definition"; }
#line 4180 "cyrix.tab.c"
    break;

  case 296: /* external_declaration: declaration  */
#line 616 "cyrix.y"
                      { derivations[derivation_count++] = "external_declaration -> declaration"; }
#line 4186 "cyrix.tab.c"
    break;

  case 297: /* function_definition: declaration_specifiers declarator declaration_list compound_statement  */
#line 620 "cyrix.y"
                                                                                { derivations[derivation_count++] = "function_definition -> declaration_specifiers declarator declaration_list compound_statement"; }
#line 4192 "cyrix.tab.c"
    break;

  case 298: /* function_definition: declaration_specifiers declarator compound_statement  */
#line 621 "cyrix.y"
                                                               { derivations[derivation_count++] = "function_definition -> declaration_specifiers declarator compound_statement"; }
#line 4198 "cyrix.tab.c"
    break;

  case 299: /* declaration_list: declaration  */
#line 625 "cyrix.y"
                      { derivations[derivation_count++] = "declaration_list -> declaration"; }
#line 4204 "cyrix.tab.c"
    break;

  case 300: /* declaration_list: declaration_list declaration  */
#line 626 "cyrix.y"
                                       { derivations[derivation_count++] = "declaration_list -> declaration_list declaration"; }
#line 4210 "cyrix.tab.c"
    break;


#line 4214 "cyrix.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 629 "cyrix.y"


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
	printf("\n=== Reverse Derivation (Top-Down) ===\n");
	print_reverse_derivation();

	printf("\n=== Additional Information ===\n");

	printf("\nStatistics:\n");
	printf("  Lines processed        : %d\n", yylineno);
	printf("  Tokens processed       : %d\n", token_count);
	printf("  Derivation steps       : %d\n", derivation_count);
	printf("  Maximum nesting depth  : %d\n", max_depth);

	printf("\nToken Breakdown:\n");
	printf("  Identifiers            : %d\n", id_count);
	printf("  Keywords               : %d\n", keyword_count);
	printf("  Constants              : %d\n", constant_count);
	printf("  Strings                : %d\n", string_count);
	printf("  Operators/Symbols      : %d\n", operator_count);
    return 0;
}
