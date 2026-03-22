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
#line 2 "cyrix.y"

#include<stdio.h>
extern char *yytext;

#line 76 "cyrix.tab.c"

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
  YYSYMBOL_SAFE_DOT = 37,                  /* SAFE_DOT  */
  YYSYMBOL_LAMBDA_ARROW = 38,              /* LAMBDA_ARROW  */
  YYSYMBOL_POW_OP = 39,                    /* POW_OP  */
  YYSYMBOL_TYPEDEF = 40,                   /* TYPEDEF  */
  YYSYMBOL_EXTERN = 41,                    /* EXTERN  */
  YYSYMBOL_STATIC = 42,                    /* STATIC  */
  YYSYMBOL_AUTO = 43,                      /* AUTO  */
  YYSYMBOL_REGISTER = 44,                  /* REGISTER  */
  YYSYMBOL_INLINE = 45,                    /* INLINE  */
  YYSYMBOL_CONST = 46,                     /* CONST  */
  YYSYMBOL_RESTRICT = 47,                  /* RESTRICT  */
  YYSYMBOL_VOLATILE = 48,                  /* VOLATILE  */
  YYSYMBOL_BOOL = 49,                      /* BOOL  */
  YYSYMBOL_CHAR = 50,                      /* CHAR  */
  YYSYMBOL_SHORT = 51,                     /* SHORT  */
  YYSYMBOL_INT = 52,                       /* INT  */
  YYSYMBOL_LONG = 53,                      /* LONG  */
  YYSYMBOL_SIGNED = 54,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 55,                  /* UNSIGNED  */
  YYSYMBOL_FLOAT = 56,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 57,                    /* DOUBLE  */
  YYSYMBOL_VOID = 58,                      /* VOID  */
  YYSYMBOL_COMPLEX = 59,                   /* COMPLEX  */
  YYSYMBOL_IMAGINARY = 60,                 /* IMAGINARY  */
  YYSYMBOL_STRUCT = 61,                    /* STRUCT  */
  YYSYMBOL_UNION = 62,                     /* UNION  */
  YYSYMBOL_ENUM = 63,                      /* ENUM  */
  YYSYMBOL_ELLIPSIS = 64,                  /* ELLIPSIS  */
  YYSYMBOL_CASE = 65,                      /* CASE  */
  YYSYMBOL_DEFAULT = 66,                   /* DEFAULT  */
  YYSYMBOL_IF = 67,                        /* IF  */
  YYSYMBOL_ELSE = 68,                      /* ELSE  */
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
  YYSYMBOL_84_ = 84,                       /* ','  */
  YYSYMBOL_85_ = 85,                       /* '('  */
  YYSYMBOL_86_ = 86,                       /* ')'  */
  YYSYMBOL_87_ = 87,                       /* ':'  */
  YYSYMBOL_88_ = 88,                       /* '['  */
  YYSYMBOL_89_ = 89,                       /* ']'  */
  YYSYMBOL_90_ = 90,                       /* '.'  */
  YYSYMBOL_91_ = 91,                       /* '{'  */
  YYSYMBOL_92_ = 92,                       /* '}'  */
  YYSYMBOL_93_ = 93,                       /* '&'  */
  YYSYMBOL_94_ = 94,                       /* '*'  */
  YYSYMBOL_95_ = 95,                       /* '+'  */
  YYSYMBOL_96_ = 96,                       /* '-'  */
  YYSYMBOL_97_ = 97,                       /* '~'  */
  YYSYMBOL_98_ = 98,                       /* '!'  */
  YYSYMBOL_99_ = 99,                       /* '/'  */
  YYSYMBOL_100_ = 100,                     /* '%'  */
  YYSYMBOL_101_ = 101,                     /* '<'  */
  YYSYMBOL_102_ = 102,                     /* '>'  */
  YYSYMBOL_103_ = 103,                     /* '^'  */
  YYSYMBOL_104_ = 104,                     /* '|'  */
  YYSYMBOL_105_ = 105,                     /* '='  */
  YYSYMBOL_106_ = 106,                     /* ';'  */
  YYSYMBOL_YYACCEPT = 107,                 /* $accept  */
  YYSYMBOL_lambda_params = 108,            /* lambda_params  */
  YYSYMBOL_lambda_expression = 109,        /* lambda_expression  */
  YYSYMBOL_primary_expression = 110,       /* primary_expression  */
  YYSYMBOL_constant = 111,                 /* constant  */
  YYSYMBOL_enumeration_constant = 112,     /* enumeration_constant  */
  YYSYMBOL_string = 113,                   /* string  */
  YYSYMBOL_generic_selection = 114,        /* generic_selection  */
  YYSYMBOL_generic_assoc_list = 115,       /* generic_assoc_list  */
  YYSYMBOL_generic_association = 116,      /* generic_association  */
  YYSYMBOL_postfix_expression = 117,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 118, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 119,         /* unary_expression  */
  YYSYMBOL_unary_operator = 120,           /* unary_operator  */
  YYSYMBOL_cast_expression = 121,          /* cast_expression  */
  YYSYMBOL_power_expression = 122,         /* power_expression  */
  YYSYMBOL_multiplicative_expression = 123, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 124,      /* additive_expression  */
  YYSYMBOL_shift_expression = 125,         /* shift_expression  */
  YYSYMBOL_relational_expression = 126,    /* relational_expression  */
  YYSYMBOL_equality_expression = 127,      /* equality_expression  */
  YYSYMBOL_and_expression = 128,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 129,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 130,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 131,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 132,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 133,   /* conditional_expression  */
  YYSYMBOL_lhs_list = 134,                 /* lhs_list  */
  YYSYMBOL_rhs_list = 135,                 /* rhs_list  */
  YYSYMBOL_multi_assignment = 136,         /* multi_assignment  */
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
  YYSYMBOL_normal_param_list = 170,        /* normal_param_list  */
  YYSYMBOL_default_param_list = 171,       /* default_param_list  */
  YYSYMBOL_normal_param = 172,             /* normal_param  */
  YYSYMBOL_default_param = 173,            /* default_param  */
  YYSYMBOL_identifier_list = 174,          /* identifier_list  */
  YYSYMBOL_type_name = 175,                /* type_name  */
  YYSYMBOL_abstract_declarator = 176,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 177, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 178,              /* initializer  */
  YYSYMBOL_initializer_list = 179,         /* initializer_list  */
  YYSYMBOL_designation = 180,              /* designation  */
  YYSYMBOL_designator_list = 181,          /* designator_list  */
  YYSYMBOL_designator = 182,               /* designator  */
  YYSYMBOL_static_assert_declaration = 183, /* static_assert_declaration  */
  YYSYMBOL_statement = 184,                /* statement  */
  YYSYMBOL_labeled_statement = 185,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 186,       /* compound_statement  */
  YYSYMBOL_block_item_list = 187,          /* block_item_list  */
  YYSYMBOL_block_item = 188,               /* block_item  */
  YYSYMBOL_expression_statement = 189,     /* expression_statement  */
  YYSYMBOL_match_statement = 190,          /* match_statement  */
  YYSYMBOL_case_list = 191,                /* case_list  */
  YYSYMBOL_match_case = 192,               /* match_case  */
  YYSYMBOL_default_opt = 193,              /* default_opt  */
  YYSYMBOL_selection_statement = 194,      /* selection_statement  */
  YYSYMBOL_foreach_var = 195,              /* foreach_var  */
  YYSYMBOL_iteration_statement = 196,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 197,           /* jump_statement  */
  YYSYMBOL_translation_unit = 198,         /* translation_unit  */
  YYSYMBOL_external_declaration = 199,     /* external_declaration  */
  YYSYMBOL_function_definition = 200,      /* function_definition  */
  YYSYMBOL_declaration_list = 201          /* declaration_list  */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYLAST   2719

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  107
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  95
/* YYNRULES -- Number of rules.  */
#define YYNRULES  312
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  557

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   338


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
       2,     2,     2,    98,     2,     2,     2,   100,    93,     2,
      85,    86,    94,    95,    84,    96,    90,    99,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    87,   106,
     101,   105,   102,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    88,     2,    89,   103,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    91,   104,    92,    97,     2,     2,     2,
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
      75,    76,    77,    78,    79,    80,    81,    82,    83
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    31,    31,    32,    36,    37,    38,    39,    43,    44,
      45,    46,    47,    48,    52,    53,    54,    58,    62,    63,
      67,    71,    72,    76,    77,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    95,    96,   100,   101,
     102,   103,   104,   105,   106,   110,   111,   112,   113,   114,
     115,   119,   120,   124,   125,   129,   130,   131,   132,   136,
     137,   138,   142,   143,   144,   148,   149,   150,   151,   152,
     153,   157,   158,   159,   163,   164,   168,   169,   173,   174,
     178,   179,   183,   184,   188,   192,   193,   197,   198,   202,
     206,   207,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   225,   226,   230,   234,   235,   239,   243,
     247,   248,   249,   250,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   267,   268,   272,   273,   277,   278,
     279,   280,   281,   282,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     305,   306,   307,   311,   312,   316,   317,   321,   322,   323,
     327,   328,   329,   330,   334,   335,   339,   340,   341,   345,
     346,   347,   348,   349,   353,   354,   358,   359,   363,   367,
     368,   369,   370,   374,   375,   379,   380,   384,   385,   389,
     390,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   406,   407,   408,   409,   413,   414,   419,
     420,   424,   425,   426,   430,   431,   435,   436,   440,   441,
     442,   446,   450,   451,   455,   456,   460,   461,   462,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     490,   491,   492,   496,   497,   498,   499,   503,   507,   508,
     512,   513,   517,   521,   522,   523,   524,   525,   526,   530,
     531,   532,   536,   537,   541,   542,   546,   547,   551,   552,
     553,   557,   561,   562,   566,   570,   571,   575,   576,   577,
     578,   582,   583,   587,   588,   589,   590,   591,   592,   593,
     597,   598,   599,   600,   601,   605,   606,   610,   611,   615,
     616,   620,   621
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
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
  "ENUMERATION_CONSTANT", "VAR", "FOREACH", "IN", "MATCH", "SAFE_DOT",
  "LAMBDA_ARROW", "POW_OP", "TYPEDEF", "EXTERN", "STATIC", "AUTO",
  "REGISTER", "INLINE", "CONST", "RESTRICT", "VOLATILE", "BOOL", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "VOID",
  "COMPLEX", "IMAGINARY", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "ALIGNAS", "ALIGNOF", "ATOMIC", "GENERIC",
  "NORETURN", "STATIC_ASSERT", "THREAD_LOCAL", "','", "'('", "')'", "':'",
  "'['", "']'", "'.'", "'{'", "'}'", "'&'", "'*'", "'+'", "'-'", "'~'",
  "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'='", "';'", "$accept",
  "lambda_params", "lambda_expression", "primary_expression", "constant",
  "enumeration_constant", "string", "generic_selection",
  "generic_assoc_list", "generic_association", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "power_expression", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression", "lhs_list",
  "rhs_list", "multi_assignment", "assignment_expression",
  "assignment_operator", "expression", "constant_expression",
  "var_init_list", "var_init", "var_declaration", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "atomic_type_specifier", "type_qualifier", "function_specifier",
  "alignment_specifier", "declarator", "direct_declarator", "pointer",
  "type_qualifier_list", "parameter_type_list", "parameter_list",
  "normal_param_list", "default_param_list", "normal_param",
  "default_param", "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "designation", "designator_list", "designator",
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

#define YYPACT_NINF (-419)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2592,  -419,    24,  -419,  -419,  -419,  -419,  -419,  -419,  -419,
    -419,  -419,  -419,  -419,  -419,  -419,  -419,  -419,  -419,  -419,
    -419,  -419,  -419,  -419,  -419,  -419,    27,   -41,   -15,  -419,
       9,  -419,  -419,  -419,    77,  2636,  2636,  -419,    29,  -419,
    -419,  2636,  2636,  2636,  -419,  2262,  -419,  -419,   -72,   -65,
    -419,   -39,    35,  1179,   993,  2019,  -419,    78,   203,  -419,
     -61,  -419,  2370,   -19,    88,  -419,  -419,    19,   500,  -419,
    -419,  -419,  -419,  -419,  2019,    24,  -419,    35,  -419,    79,
     -25,  -419,  -419,  -419,  -419,  -419,  -419,  2115,  2138,  2138,
    -419,    15,   106,  1083,  -419,  -419,  -419,  -419,  -419,  -419,
    -419,  -419,  -419,  -419,  -419,   201,  -419,  2019,   184,  -419,
     -57,   -56,   195,   175,   218,   146,   163,   200,   260,   268,
    -419,   207,   993,   -17,   993,   219,   229,   236,   235,  -419,
    -419,  -419,   203,    78,  -419,   562,  1717,  -419,    77,  -419,
    2492,  2323,  1027,   -19,   500,  1652,  -419,    82,  -419,   380,
    -419,  -419,  -419,    86,  2019,    22,  -419,  1083,  -419,  1083,
    -419,  -419,   993,  2019,   147,   284,   156,  -419,   178,   237,
     321,  -419,  -419,   322,  1813,  2019,   323,  -419,  2019,  2019,
    2019,  2019,  2019,  2019,  2019,  2019,  2019,  2019,  2019,  2019,
    2019,  2019,  2019,  2019,  2019,  2019,  2019,  2019,  -419,  -419,
    2436,  1275,   134,  -419,   140,  -419,  -419,  -419,   324,  -419,
    -419,  -419,  -419,   223,   242,   247,   248,  2019,   253,   249,
     256,   261,   853,   262,   342,   243,   244,   889,  -419,  -419,
      76,   246,   -34,  -419,  -419,  -419,  -419,   659,  -419,  -419,
    -419,  -419,  -419,  -419,  1686,  -419,  -419,  -419,  -419,  -419,
    -419,    21,   270,   274,   275,   276,  -419,  -419,   181,  1536,
    -419,   277,   279,  1298,  1802,  -419,  -419,  2019,  -419,   -33,
    -419,   278,  -419,  -419,  -419,  -419,  -419,  -419,  -419,  -419,
    -419,  -419,  -419,  2019,    61,  -419,  -419,  -419,  -419,   283,
     285,   286,   280,  1836,   360,   335,  2019,  -419,  1868,  -419,
    -419,  -419,   185,  -419,    91,  -419,  -419,  -419,  -419,  -419,
     -57,   -57,   -56,   -56,   195,   195,   195,   195,   195,   175,
     175,   218,   146,   163,   200,   260,  -419,   289,   292,  1536,
    -419,   290,   291,  1394,   140,  2545,  1417,   295,   853,   466,
    2019,   296,   853,  2019,  2019,  2019,   312,   756,   288,  -419,
    -419,  -419,   -27,   381,  2019,  -419,  -419,  -419,  -419,  2019,
     382,  -419,   103,  1717,   -30,  -419,  2198,   294,   121,  -419,
    -419,   327,  2636,  2636,   392,  -419,   307,  1536,  -419,  -419,
    2019,  -419,   311,   325,  -419,  -419,   109,  -419,  2019,  -419,
    -419,   320,   320,  -419,  1954,   328,  -419,  -419,  1836,  -419,
    1686,  -419,  2019,  -419,  -419,  -419,  -419,   326,  1536,  -419,
    -419,  2019,  -419,   329,  -419,   330,  1536,  -419,   332,   336,
    1513,   313,  -419,  -419,   -15,   410,   389,   186,   853,  -419,
     189,   194,   210,   341,  -419,   986,   986,  -419,  -419,  -419,
     333,  -419,   339,  -419,  1567,  -419,  -419,  -419,  -419,  2019,
    -419,   276,  -419,    78,  -419,  -419,  -419,   340,   344,  -419,
    -419,  -419,  -419,   347,   214,  -419,   348,   328,  -419,   137,
    -419,  -419,   349,   351,  -419,  -419,   353,  1536,  -419,  -419,
    2019,  -419,   354,  -419,  -419,  2019,   346,  -419,   853,   853,
     853,  2019,  1964,  1987,  2019,  -419,  -419,  -419,  1717,  -419,
     294,  -419,  -419,  2019,  1954,  -419,  2019,  1663,  -419,  -419,
    -419,  -419,   355,   356,  -419,   217,   384,   378,  -419,  -419,
     225,   853,   228,   853,   232,  -419,  -419,  -419,  -419,  -419,
    -419,  -419,  -419,   853,  2019,   132,  -419,   853,   350,  -419,
     853,  -419,   853,  -419,   363,   366,  -419,   362,  -419,  -419,
    -419,  -419,   853,   853,  -419,  -419,  -419
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,   149,     0,   128,   129,   130,   132,   133,   183,   179,
     180,   181,   143,   135,   136,   137,   138,   141,   142,   139,
     140,   134,   144,   145,   153,   154,     0,     0,   182,   184,
       0,   131,   113,   308,     0,   115,   117,   147,     0,   148,
     146,   119,   121,   123,   112,     0,   305,   307,     0,     0,
     106,   173,     0,     0,     0,     0,   189,     0,   206,   110,
       0,   124,   127,   188,     0,   114,   116,   152,     0,   118,
     120,   122,     1,   306,     0,     0,   109,     0,    17,   177,
       0,   174,     8,    14,    15,    18,    19,     0,     0,     0,
      16,     0,     0,     0,    45,    46,    47,    48,    49,    50,
      13,    25,     9,    10,    12,    38,    51,     0,    53,    55,
      59,    62,    65,    71,    74,    76,    78,    80,    82,    84,
     105,     0,   161,   225,   163,     0,     0,     0,     0,   182,
     207,   205,   204,     0,   111,     0,     0,   311,     0,   310,
       0,     0,     0,   187,     0,     0,   155,     0,   159,    51,
      90,   108,   107,     0,     0,     0,   169,     0,    42,     0,
      39,    40,     0,     0,     8,     0,     0,   103,     0,     0,
       0,    32,    33,     0,     0,     0,     0,    41,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   186,   160,
       0,     0,   227,   224,   228,   162,   185,   178,     0,   190,
     208,   203,   125,   127,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   272,   278,
       0,     0,     0,   276,   277,   263,   264,     0,   274,   265,
     290,   266,   267,   268,     0,   252,   126,   312,   309,   222,
     201,   220,     0,   210,   211,   213,   214,   216,     0,     0,
     191,    46,     0,     0,     0,   150,   156,     0,   157,     0,
     164,   168,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    92,     0,     0,   171,   176,   170,   175,     0,
       0,     0,     0,     0,     0,     0,     0,    11,     0,    30,
      31,    27,     0,    36,     0,    29,    54,    56,    57,    58,
      60,    61,    63,    64,    68,    69,    70,    66,    67,    72,
      73,    75,    77,    79,    81,    83,   246,     0,     0,     0,
     230,    46,     0,     0,   226,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   301,
     302,   303,     0,     0,     0,   280,   279,   273,   275,     0,
       0,   254,     0,     0,     0,   258,     0,   218,   227,   219,
     200,     0,     0,     0,     0,   202,     0,     0,   192,   199,
       0,   198,    46,     0,   151,   166,     0,   158,     0,    91,
     172,    43,     0,    44,     0,     4,     5,     3,     0,   104,
       0,    52,     0,    28,    26,   247,   229,     0,     0,   231,
     237,     0,   236,     0,   248,     0,     0,   238,    46,     0,
       0,     0,   269,   291,     0,     0,     0,     0,     0,   271,
       0,     0,     0,     0,     8,     0,     0,   300,   304,    86,
      89,    87,     0,   261,     0,   250,   253,   257,   259,     0,
     209,   212,   215,     0,   217,   223,   194,     0,     0,   195,
     197,   165,   167,     0,     0,    21,     0,     6,     7,     0,
      37,   233,     0,     0,   235,   249,     0,     0,   239,   245,
       0,   244,     0,   262,   292,     0,     0,   270,     0,     0,
       0,     0,     0,     0,     0,   260,   251,   256,     0,   221,
       0,   193,   196,     0,     0,    20,     0,     0,    34,   232,
     234,   241,     0,     0,   242,     0,     0,   288,   289,   293,
       0,     0,     0,     0,     0,    88,   255,    24,    22,    23,
      35,   240,   243,     0,     0,   285,   283,     0,     0,   297,
       0,   295,     0,   299,     0,     0,   282,     0,   287,   294,
     298,   296,     0,     0,   281,   284,   286
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -419,  -419,  -419,  -419,  -419,  -419,  -419,  -419,  -419,   -44,
    -419,  -419,   -53,  -419,   -97,    80,    65,    59,    66,    93,
     254,   265,   266,   259,   269,  -419,   -52,  -419,  -419,  -419,
      94,  -419,    -1,   -51,  -419,   387,  -419,   -45,    20,  -419,
     334,  -419,   -40,  -419,  -419,   319,  -116,    55,  -419,    84,
    -419,   391,  -137,  -419,   -46,  -419,  -419,    12,   -58,   -49,
     -55,  -130,  -419,  -419,   100,   101,   102,  -419,    -5,  -102,
    -186,  -131,    87,  -418,  -419,   112,   -37,  -101,  -419,   -47,
    -419,   240,  -250,  -419,  -419,   -42,  -419,  -419,  -419,  -419,
    -419,  -419,   433,  -419,  -419
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   166,   100,   101,   102,    79,   103,   104,   464,   465,
     105,   302,   149,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   150,   230,   440,   231,
     167,   283,   232,   121,    49,    50,    32,    33,   138,    60,
      61,    35,    36,    37,    38,   145,   146,   123,   269,   270,
      39,    80,    81,    40,    41,    42,    43,   128,    63,    64,
     132,   327,   253,   254,   255,   256,   257,   258,   466,   328,
     204,   361,   362,   363,   364,   365,    44,   234,   235,   236,
     237,   238,   239,   240,   535,   536,   547,   241,   426,   242,
     243,    45,    46,    47,   140
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     106,   120,   106,   120,   127,   246,   143,   124,   124,   131,
     177,   252,   130,   122,   122,   139,   334,   137,   288,    75,
      34,   203,   124,   133,    56,    78,   498,    48,   122,   266,
      51,   148,    67,    74,   158,   160,   161,   179,    78,   182,
     183,    76,   180,   181,    53,   134,    62,   124,   125,   126,
     296,   386,    77,   122,   106,    65,    66,   296,   359,   155,
     360,    69,    70,    71,    78,    34,   141,   156,   200,   142,
      54,   201,   356,   387,   202,   447,   124,    58,   124,   438,
      56,    56,   122,   211,   122,    56,   210,   263,   169,   498,
     233,    56,   168,   248,    55,   247,   130,   436,   124,   124,
     162,   106,   120,   286,   122,   122,   366,   148,   148,   201,
     144,   124,    56,   124,   287,    58,   124,   122,    52,   122,
      68,   346,   122,   147,    56,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   213,   333,   288,   266,   369,
     213,   202,   289,   390,   290,   130,   168,   291,   168,   271,
     353,   251,    57,    57,   106,   120,   341,    57,   151,   267,
     284,    58,    58,    57,   304,   296,    58,   199,   285,   205,
     404,   354,   334,    59,   154,   492,   493,   444,   268,   186,
     187,   163,   233,   188,    57,   445,   267,   534,   545,   147,
     147,   401,   368,    58,   377,   415,   366,   184,   185,   201,
     170,   171,   172,   130,   106,   120,   385,   210,   124,   200,
     251,   507,   201,   178,   122,   335,   352,   148,   336,   508,
     245,    -2,   446,    -2,   191,   192,   262,   422,   173,   193,
     294,   429,   295,   312,   313,   106,   396,   310,   311,     9,
      10,    11,   314,   315,   316,   317,   318,   292,   306,   307,
     308,   309,   296,   367,   297,   374,   194,   375,   303,   402,
     296,   403,   486,   296,   408,   488,   189,   190,   296,   196,
     489,   420,   129,   130,   319,   320,   174,   210,   197,   175,
     130,   176,   395,   198,   296,   332,   490,    58,   504,   425,
     505,   296,   435,   533,   195,   206,   106,   120,   442,   296,
     143,   538,   296,   497,   540,   207,   296,   368,   542,   147,
     208,   209,   293,   298,   299,   300,   305,   487,   136,   338,
     337,   210,   339,   340,   343,   106,   120,   462,   245,   427,
     342,   344,   430,   431,   432,   348,   345,   347,   124,   349,
     350,   468,   355,   376,   122,   251,   370,   383,   371,   372,
     373,   477,   210,   397,   394,   388,   378,   526,   379,   391,
     130,   392,   393,   398,   210,   405,   497,   389,   406,   409,
     410,   421,   433,   428,   439,   443,   251,   517,   518,   519,
     399,   450,   251,   453,   437,   455,   456,   467,   271,   449,
     459,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   400,   296,   484,   460,   471,   475,   494,   474,   483,
     539,   478,   541,   407,   485,   479,   491,   413,   495,   501,
     419,   210,   543,   502,   503,   506,   548,   516,   509,   550,
     510,   551,   511,   514,   531,   532,   537,   321,   441,   534,
     552,   555,   556,   553,   554,   324,   549,   245,   124,   322,
     528,   323,   152,   264,   122,   500,   325,   212,   153,   423,
     461,   457,   451,   452,   458,   454,   448,   358,    73,     0,
       0,   106,   120,   544,   515,   282,     0,   469,     0,     0,
     520,   522,   524,   546,   245,     0,   470,     1,     0,     0,
       0,     0,   472,     0,     0,   473,     0,     0,     0,     0,
     476,     0,     0,     0,   482,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       0,     1,     0,     0,     0,     0,     0,     0,   245,     0,
       0,     0,     0,   499,     0,   424,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,     0,   214,    83,    84,    85,    86,
      87,   512,    88,    89,   513,     0,     0,     0,     0,    28,
       0,     0,    30,     0,     0,     0,     0,     0,   525,     0,
       0,     0,   245,     1,    90,     2,   215,   527,   216,     0,
     529,   245,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     0,   217,   218,   219,
       0,   220,   221,   222,   223,   224,   225,   226,   227,    27,
      91,    28,    92,    29,    30,    31,     0,    93,     0,     0,
       0,     0,     0,   135,   228,    94,    95,    96,    97,    98,
      99,     0,   214,    83,    84,    85,    86,    87,   229,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,    90,     2,   215,     0,   216,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,     0,   217,   218,   219,     0,   220,   221,
     222,   223,   224,   225,   226,   227,    27,    91,    28,    92,
      29,    30,    31,     0,    93,     0,     0,     0,     0,     0,
     135,   357,    94,    95,    96,    97,    98,    99,     0,   434,
      83,    84,    85,    86,    87,   229,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,    90,     2,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,    91,    28,    92,    29,    30,    31,
       0,    93,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,    98,    99,     0,   214,    83,    84,    85,
      86,    87,   229,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    90,     0,   215,     0,   216,
       0,     0,    82,    83,    84,    85,    86,    87,     0,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   217,   218,
     219,    90,   220,   221,   222,   223,   224,   225,   226,   227,
       0,    91,     0,    92,     0,     0,     0,     0,    93,     0,
       0,     0,     0,     0,   135,     0,    94,    95,    96,    97,
      98,    99,     0,     0,     0,     0,     0,     0,     0,   229,
       0,     0,     0,     0,     0,     0,     0,    91,     0,    92,
       0,     0,     0,     0,    93,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,    98,    99,     0,   434,
      83,    84,    85,    86,    87,   351,    88,    89,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,     0,
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
      82,    83,    84,    85,    86,    87,     0,    88,    89,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,     0,     0,    90,
       0,     0,     0,     0,    91,     0,    92,     0,     0,   259,
       0,    93,    28,     9,    10,    11,     0,     0,     0,    94,
      95,    96,    97,    98,    99,     0,   164,    83,    84,    85,
      86,    87,   229,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    91,   129,    92,     0,     0,
       0,     0,    93,     0,     1,    90,   260,     0,     0,     0,
      94,   261,    96,    97,    98,    99,     0,     0,     0,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    28,    92,     0,     0,     0,     0,    93,   165,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
      98,    99,    82,    83,    84,    85,    86,    87,     0,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,    90,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    28,    92,
       0,     0,     0,     0,    93,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,    98,    99,    82,    83,
      84,    85,    86,    87,     0,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,    83,    84,    85,    86,    87,    90,    88,    89,
       0,     0,     0,     0,     0,     0,     0,   329,     0,     0,
       0,     9,    10,    11,     0,     0,     0,     0,     0,     0,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     380,     0,     0,     0,     9,    10,    11,     0,     0,     0,
       0,     0,     0,    91,   129,    92,     0,     0,     0,     0,
      93,     0,     0,     0,   330,     0,     0,     0,    94,   331,
      96,    97,    98,    99,     0,     0,    91,   129,    92,     0,
       0,     0,     0,    93,     0,     0,     0,   381,     0,     0,
       0,    94,   382,    96,    97,    98,    99,    82,    83,    84,
      85,    86,    87,     0,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,    83,    84,    85,    86,    87,    90,    88,    89,     0,
       0,     0,     0,     0,     0,     0,   411,     0,     0,     0,
       9,    10,    11,     0,     0,     0,     0,     0,     0,    90,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   416,
       0,     0,     0,     9,    10,    11,     0,     0,     0,     0,
       0,     0,    91,   129,    92,     0,     0,     0,     0,    93,
       0,     0,     0,   412,     0,     0,     0,    94,    95,    96,
      97,    98,    99,     0,     0,    91,   129,    92,     0,     0,
       0,     0,    93,     0,     0,     0,   417,     0,     0,     0,
      94,   418,    96,    97,    98,    99,    82,    83,    84,    85,
      86,    87,     0,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    90,    88,    89,     0,     0,
       0,     0,     0,     0,     0,   480,     0,     0,     0,     9,
      10,    11,     0,     0,     0,     0,     0,     0,    90,     0,
      82,    83,    84,    85,    86,    87,     0,    88,    89,     0,
       0,     0,     9,    10,    11,     0,     0,     0,     0,     0,
       0,    91,   129,    92,     0,     0,     0,     0,    93,    90,
       0,     0,   481,     0,     0,     0,    94,    95,    96,    97,
      98,    99,     0,     0,    91,   129,    92,     0,     0,     0,
       0,    93,     0,     0,     0,     0,     0,     0,     0,    94,
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    91,     0,    92,     0,     0,
       0,     0,    93,     0,     0,   359,     0,   360,   244,   496,
      94,    95,    96,    97,    98,    99,    82,    83,    84,    85,
      86,    87,     0,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     0,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    90,    88,    89,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     0,     0,    90,     0,
      82,    83,    84,    85,    86,    87,     0,    88,    89,     0,
       0,    28,     0,     0,    30,     0,     0,     0,     0,     0,
       0,    91,     0,    92,   265,     0,     0,     0,    93,    90,
       0,   359,     0,   360,   244,   530,    94,    95,    96,    97,
      98,    99,     0,     0,    91,     0,    92,     0,     0,     0,
       0,    93,     0,     0,   359,     0,   360,   244,     0,    94,
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    91,     0,    92,     0,     0,
       0,     0,    93,     0,     0,     0,     0,     0,   244,     0,
      94,    95,    96,    97,    98,    99,    82,    83,    84,    85,
      86,    87,     0,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,     0,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    90,    88,    89,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     0,     0,    90,     0,
       0,    82,    83,    84,    85,    86,    87,     0,    88,    89,
       0,    28,     0,     0,    30,     0,     0,     0,     0,     0,
       0,    91,     0,    92,   384,     0,     0,     0,    93,   301,
      90,     0,     0,     0,     0,     0,    94,    95,    96,    97,
      98,    99,     0,     0,    91,     0,    92,     0,     0,     0,
       0,    93,     0,     0,     0,     0,     0,   135,     0,    94,
      95,    96,    97,    98,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91,     0,    92,     0,
       0,     0,     0,    93,     0,     0,     0,     0,     0,   400,
       0,    94,    95,    96,    97,    98,    99,    82,    83,    84,
      85,    86,    87,     0,    88,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     0,     0,     0,     0,
      82,    83,    84,    85,    86,    87,    90,    88,    89,     0,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,     0,    90,
     463,     0,    82,    83,    84,    85,    86,    87,     0,    88,
      89,     0,     0,    28,     0,     0,     0,     0,     0,     0,
       0,     0,    91,     0,    92,     0,     0,     0,     0,    93,
     521,    90,     0,     0,     0,     0,     0,    94,    95,    96,
      97,    98,    99,     0,     0,    91,     0,    92,     0,     0,
       0,     0,    93,   523,     0,     0,     0,     0,     0,     0,
      94,    95,    96,    97,    98,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    91,     0,    92,
       0,     0,     0,     0,    93,     0,     0,     0,     0,     0,
       0,     0,    94,    95,    96,    97,    98,    99,    82,    83,
      84,    85,    86,    87,     0,    88,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,    83,    84,    85,    86,    87,    90,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,     0,    92,     0,     0,     0,     0,
     157,    56,     0,     0,     0,     0,     0,     0,    94,    95,
      96,    97,    98,    99,     0,     0,    91,     0,    92,     0,
       0,     0,     0,   159,     0,     0,     0,     0,     0,     1,
       0,    94,    95,    96,    97,    98,    99,     0,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    27,     0,    28,     0,    29,
       0,    31,     0,   366,   326,     0,   201,     0,     0,     0,
       0,     0,    58,     1,     0,     2,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   249,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,    28,     0,    29,    30,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,     1,    28,     2,    29,     0,    31,     0,     0,   250,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,    28,
       0,    29,    30,    31,     0,     0,     0,     0,     0,     0,
       0,   135,     0,     0,     0,     0,     0,     1,     0,     0,
       0,     0,     0,     0,     0,   136,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,     0,    28,     0,    29,     0,    31,
       0,   200,   326,     1,   201,     2,     0,     0,     0,     0,
      58,     0,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,    28,     0,    29,    30,    31,     1,     0,     0,     0,
       0,     0,     0,   135,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     1,    28,     2,    29,     0,    31,     0,
       0,   414,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     0,    27,
       0,    28,     0,    29,    30,    31,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,     0,    28,     0,    29,     0,    31
};

static const yytype_int16 yycheck[] =
{
      53,    53,    55,    55,    55,   136,    64,    53,    54,    58,
     107,   141,    58,    53,    54,    62,   202,    62,   155,    84,
       0,   123,    68,    84,     3,     3,   444,     3,    68,   145,
       3,    68,     3,   105,    87,    88,    89,    94,     3,    95,
      96,   106,    99,   100,    85,   106,    34,    93,    53,    54,
      84,    84,    91,    93,   107,    35,    36,    84,    88,    84,
      90,    41,    42,    43,     3,    45,    85,    92,    85,    88,
      85,    88,   106,   106,   123,   105,   122,    94,   124,   106,
       3,     3,   122,   132,   124,     3,   132,   142,    93,   507,
     135,     3,    93,   140,    85,   140,   142,   347,   144,   145,
      85,   154,   154,   154,   144,   145,    85,   144,   145,    88,
      91,   157,     3,   159,    92,    94,   162,   157,    91,   159,
      91,   222,   162,    68,     3,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   133,   201,   284,   264,   251,
     138,   200,   157,    92,   159,   201,   157,   162,   159,   147,
      84,   141,    85,    85,   217,   217,   217,    85,    74,    87,
      84,    94,    94,    85,   175,    84,    94,   122,    92,   124,
      89,   105,   368,   106,   105,   435,   436,    84,   106,    14,
      15,    85,   237,    18,    85,    92,    87,    65,    66,   144,
     145,   298,   251,    94,   259,   335,    85,    12,    13,    88,
       9,    10,    11,   259,   267,   267,   267,   263,   264,    85,
     200,    84,    88,    39,   264,    85,   227,   264,    88,    92,
     136,    84,   363,    86,    16,    17,   142,   338,    37,    93,
      84,   342,    86,   184,   185,   298,   293,   182,   183,    46,
      47,    48,   186,   187,   188,   189,   190,   163,   178,   179,
     180,   181,    84,   251,    86,    84,   103,    86,   174,    84,
      84,    86,    86,    84,   329,    86,   101,   102,    84,    19,
      86,   336,    79,   329,   191,   192,    85,   333,    20,    88,
     336,    90,   293,    86,    84,   201,    86,    94,    84,   339,
      86,    84,   347,    86,   104,    86,   359,   359,   359,    84,
     368,    86,    84,   444,    86,    86,    84,   366,    86,   264,
      84,    86,    38,    86,     3,     3,     3,   428,   105,    87,
       6,   377,    85,    85,    85,   388,   388,   388,   244,   340,
      87,    85,   343,   344,   345,     3,    85,    85,   394,   106,
     106,   398,   106,   259,   394,   335,    86,   263,    84,    84,
      84,   416,   408,     3,    84,    87,    89,   498,    89,    86,
     416,    86,    86,    38,   420,    86,   507,   283,    86,    89,
      89,    86,    70,    87,     3,     3,   366,   488,   489,   490,
     296,    64,   372,   373,   106,     3,    89,   398,   386,   105,
      89,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    91,    84,     3,    89,    89,    86,    84,    89,   106,
     521,    89,   523,   329,    35,    89,    85,   333,    89,    89,
     336,   477,   533,    89,    87,    87,   537,    91,    89,   540,
      89,   542,    89,    89,    89,    89,    68,   193,   354,    65,
      87,   552,   553,    87,    92,   196,   106,   363,   504,   194,
     504,   195,    75,   144,   504,   453,   197,   133,    77,     3,
     386,   377,   372,   372,   380,   373,   364,   237,    45,    -1,
      -1,   534,   534,   534,   485,   105,    -1,   400,    -1,    -1,
     491,   492,   493,   535,   400,    -1,   402,    31,    -1,    -1,
      -1,    -1,   408,    -1,    -1,   411,    -1,    -1,    -1,    -1,
     416,    -1,    -1,    -1,   420,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,   444,    -1,
      -1,    -1,    -1,   449,    -1,    79,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,     3,     4,     5,     6,     7,
       8,   477,    10,    11,   480,    -1,    -1,    -1,    -1,    79,
      -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,   494,    -1,
      -1,    -1,   498,    31,    32,    33,    34,   503,    36,    -1,
     506,   507,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    85,    -1,    -1,
      -1,    -1,    -1,    91,    92,    93,    94,    95,    96,    97,
      98,    -1,     3,     4,     5,     6,     7,     8,   106,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    -1,    36,    -1,    -1,    -1,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    -1,    85,    -1,    -1,    -1,    -1,    -1,
      91,    92,    93,    94,    95,    96,    97,    98,    -1,     3,
       4,     5,     6,     7,     8,   106,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,    80,    81,    82,    83,
      -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      94,    95,    96,    97,    98,    -1,     3,     4,     5,     6,
       7,     8,   106,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    -1,    34,    -1,    36,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,
      67,    32,    69,    70,    71,    72,    73,    74,    75,    76,
      -1,    78,    -1,    80,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    -1,    -1,    -1,    91,    -1,    93,    94,    95,    96,
      97,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    80,
      -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    95,    96,    97,    98,    -1,     3,
       4,     5,     6,     7,     8,   106,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    32,
      -1,    -1,    -1,    -1,    78,    -1,    80,    -1,    -1,    42,
      -1,    85,    79,    46,    47,    48,    -1,    -1,    -1,    93,
      94,    95,    96,    97,    98,    -1,     3,     4,     5,     6,
       7,     8,   106,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    79,    80,    -1,    -1,
      -1,    -1,    85,    -1,    31,    32,    89,    -1,    -1,    -1,
      93,    94,    95,    96,    97,    98,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    -1,    -1,    -1,    -1,    85,    86,
      -1,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,
      97,    98,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,
      -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    95,    96,    97,    98,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    32,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    46,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    -1,    -1,    -1,    -1,
      85,    -1,    -1,    -1,    89,    -1,    -1,    -1,    93,    94,
      95,    96,    97,    98,    -1,    -1,    78,    79,    80,    -1,
      -1,    -1,    -1,    85,    -1,    -1,    -1,    89,    -1,    -1,
      -1,    93,    94,    95,    96,    97,    98,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    32,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      46,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    46,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    79,    80,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    89,    -1,    -1,    -1,    93,    94,    95,
      96,    97,    98,    -1,    -1,    78,    79,    80,    -1,    -1,
      -1,    -1,    85,    -1,    -1,    -1,    89,    -1,    -1,    -1,
      93,    94,    95,    96,    97,    98,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    32,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    46,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    -1,    -1,    -1,    -1,    85,    32,
      -1,    -1,    89,    -1,    -1,    -1,    93,    94,    95,    96,
      97,    98,    -1,    -1,    78,    79,    80,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      94,    95,    96,    97,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    -1,    80,    -1,    -1,
      -1,    -1,    85,    -1,    -1,    88,    -1,    90,    91,    92,
      93,    94,    95,    96,    97,    98,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    32,    10,    11,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    32,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    79,    -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    -1,    80,    92,    -1,    -1,    -1,    85,    32,
      -1,    88,    -1,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    88,    -1,    90,    91,    -1,    93,
      94,    95,    96,    97,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78,    -1,    80,    -1,    -1,
      -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,    91,    -1,
      93,    94,    95,    96,    97,    98,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    32,    10,    11,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    32,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    79,    -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    -1,    80,    92,    -1,    -1,    -1,    85,    86,
      32,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,    96,
      97,    98,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    -1,    -1,    91,    -1,    93,
      94,    95,    96,    97,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    80,    -1,
      -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,    91,
      -1,    93,    94,    95,    96,    97,    98,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    32,    10,    11,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    -1,    32,
      66,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,    85,
      86,    32,    -1,    -1,    -1,    -1,    -1,    93,    94,    95,
      96,    97,    98,    -1,    -1,    78,    -1,    80,    -1,    -1,
      -1,    -1,    85,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    94,    95,    96,    97,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    80,
      -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    95,    96,    97,    98,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    32,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,    -1,
      85,     3,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      95,    96,    97,    98,    -1,    -1,    78,    -1,    80,    -1,
      -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,    31,
      -1,    93,    94,    95,    96,    97,    98,    -1,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,     0,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    77,    -1,    79,    -1,    81,
      -1,    83,    -1,    85,    86,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    94,    31,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      -1,    79,    -1,    81,    82,    83,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    31,    79,    33,    81,    -1,    83,    -1,    -1,    86,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    79,
      -1,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    91,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   105,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    79,    -1,    81,    -1,    83,
      -1,    85,    86,    31,    88,    33,    -1,    -1,    -1,    -1,
      94,    -1,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      -1,    79,    -1,    81,    82,    83,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    91,    -1,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    31,    79,    33,    81,    -1,    83,    -1,
      -1,    86,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    77,
      -1,    79,    -1,    81,    82,    83,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    -1,    79,    -1,    81,    -1,    83
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,    33,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    77,    79,    81,
      82,    83,   143,   144,   145,   148,   149,   150,   151,   157,
     160,   161,   162,   163,   183,   198,   199,   200,     3,   141,
     142,     3,    91,    85,    85,    85,     3,    85,    94,   106,
     146,   147,   164,   165,   166,   145,   145,     3,    91,   145,
     145,   145,     0,   199,   105,    84,   106,    91,     3,   112,
     158,   159,     3,     4,     5,     6,     7,     8,    10,    11,
      32,    78,    80,    85,    93,    94,    95,    96,    97,    98,
     109,   110,   111,   113,   114,   117,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   140,   149,   154,   161,   175,   175,   140,   164,    79,
     161,   166,   167,    84,   106,    91,   105,   144,   145,   186,
     201,    85,    88,   165,    91,   152,   153,   154,   183,   119,
     133,   137,   142,   158,   105,    84,    92,    85,   119,    85,
     119,   119,    85,    85,     3,    86,   108,   137,   139,   175,
       9,    10,    11,    37,    85,    88,    90,   121,    39,    94,
      99,   100,    95,    96,    12,    13,    14,    15,    18,   101,
     102,    16,    17,    93,   103,   104,    19,    20,    86,   154,
      85,    88,   166,   176,   177,   154,    86,    86,    84,    86,
     161,   166,   147,   164,     3,    34,    36,    65,    66,    67,
      69,    70,    71,    72,    73,    74,    75,    76,    92,   106,
     134,   136,   139,   144,   184,   185,   186,   187,   188,   189,
     190,   194,   196,   197,    91,   137,   178,   144,   186,     3,
      86,   145,   168,   169,   170,   171,   172,   173,   174,    42,
      89,    94,   137,   167,   152,    92,   153,    87,   106,   155,
     156,   164,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,   105,   138,    84,    92,   140,    92,   159,   175,
     175,   175,   137,    38,    84,    86,    84,    86,    86,     3,
       3,    86,   118,   137,   139,     3,   122,   122,   122,   122,
     123,   123,   124,   124,   125,   125,   125,   125,   125,   126,
     126,   127,   128,   129,   130,   131,    86,   168,   176,    42,
      89,    94,   137,   167,   177,    85,    88,     6,    87,    85,
      85,   140,    87,    85,    85,    85,   184,    85,     3,   106,
     106,   106,   139,    84,   105,   106,   106,    92,   188,    88,
      90,   178,   179,   180,   181,   182,    85,   164,   166,   176,
      86,    84,    84,    84,    84,    86,   137,   167,    89,    89,
      42,    89,    94,   137,    92,   140,    84,   106,    87,   137,
      92,    86,    86,    86,    84,   139,   186,     3,    38,   137,
      91,   121,    84,    86,    89,    86,    86,   137,   167,    89,
      89,    42,    89,   137,    86,   168,    42,    89,    94,   137,
     167,    86,   184,     3,    79,   149,   195,   139,    87,   184,
     139,   139,   139,    70,     3,   144,   189,   106,   106,     3,
     135,   137,   140,     3,    84,    92,   178,   105,   182,   105,
      64,   171,   172,   145,   173,     3,    89,   137,   137,    89,
      89,   156,   140,    66,   115,   116,   175,   139,   186,   179,
     137,    89,   137,   137,    89,    86,   137,   167,    89,    89,
      42,    89,   137,   106,     3,    35,    86,   184,    86,    86,
      86,    85,   189,   189,    84,    89,    92,   178,   180,   137,
     164,    89,    89,    87,    84,    86,    87,    84,    92,    89,
      89,    89,   137,   137,    89,   139,    91,   184,   184,   184,
     139,    86,   139,    86,   139,   137,   178,   137,   116,   137,
      92,    89,    89,    86,    65,   191,   192,    68,    86,   184,
      86,   184,    86,   184,   140,    66,   192,   193,   184,   106,
     184,   184,    87,    87,    92,   184,   184
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   107,   108,   108,   109,   109,   109,   109,   110,   110,
     110,   110,   110,   110,   111,   111,   111,   112,   113,   113,
     114,   115,   115,   116,   116,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   118,   118,   119,   119,
     119,   119,   119,   119,   119,   120,   120,   120,   120,   120,
     120,   121,   121,   122,   122,   123,   123,   123,   123,   124,
     124,   124,   125,   125,   125,   126,   126,   126,   126,   126,
     126,   127,   127,   127,   128,   128,   129,   129,   130,   130,
     131,   131,   132,   132,   133,   134,   134,   135,   135,   136,
     137,   137,   138,   138,   138,   138,   138,   138,   138,   138,
     138,   138,   138,   139,   139,   140,   141,   141,   142,   143,
     144,   144,   144,   144,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   146,   146,   147,   147,   148,   148,
     148,   148,   148,   148,   149,   149,   149,   149,   149,   149,
     149,   149,   149,   149,   149,   149,   149,   149,   149,   149,
     150,   150,   150,   151,   151,   152,   152,   153,   153,   153,
     154,   154,   154,   154,   155,   155,   156,   156,   156,   157,
     157,   157,   157,   157,   158,   158,   159,   159,   160,   161,
     161,   161,   161,   162,   162,   163,   163,   164,   164,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   166,   166,   166,   166,   167,   167,   168,
     168,   169,   169,   169,   170,   170,   171,   171,   172,   172,
     172,   173,   174,   174,   175,   175,   176,   176,   176,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   177,
     178,   178,   178,   179,   179,   179,   179,   180,   181,   181,
     182,   182,   183,   184,   184,   184,   184,   184,   184,   185,
     185,   185,   186,   186,   187,   187,   188,   188,   189,   189,
     189,   190,   191,   191,   192,   193,   193,   194,   194,   194,
     194,   195,   195,   196,   196,   196,   196,   196,   196,   196,
     197,   197,   197,   197,   197,   198,   198,   199,   199,   200,
     200,   201,   201
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     4,     4,     5,     5,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       6,     1,     3,     3,     3,     1,     4,     3,     4,     3,
       3,     3,     2,     2,     6,     7,     1,     3,     1,     2,
       2,     2,     2,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     3,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     3,     1,     3,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     3,     3,     3,
       2,     3,     1,     1,     2,     1,     2,     1,     2,     1,
       2,     1,     2,     1,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     5,     2,     1,     1,     1,     2,     2,     3,     1,
       2,     1,     2,     1,     1,     3,     2,     3,     1,     4,
       5,     5,     6,     2,     1,     3,     3,     1,     4,     1,
       1,     1,     1,     1,     1,     4,     4,     2,     1,     1,
       3,     3,     4,     6,     5,     5,     6,     5,     4,     4,
       4,     3,     4,     3,     2,     2,     1,     1,     2,     3,
       1,     1,     3,     1,     1,     3,     1,     3,     2,     2,
       1,     4,     1,     3,     2,     1,     2,     1,     1,     3,
       2,     3,     5,     4,     5,     4,     3,     3,     3,     4,
       6,     5,     5,     6,     4,     4,     2,     3,     3,     4,
       3,     4,     1,     2,     1,     4,     3,     2,     1,     2,
       3,     2,     7,     1,     1,     1,     1,     1,     1,     3,
       4,     3,     2,     3,     1,     2,     1,     1,     1,     2,
       2,     8,     2,     1,     4,     0,     3,     7,     5,     5,
       1,     1,     2,     5,     7,     6,     7,     6,     7,     7,
       3,     2,     2,     2,     3,     1,     2,     1,     1,     4,
       3,     1,     2
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

#line 2118 "cyrix.tab.c"

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
      yyerror (YY_("syntax error"));
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

  return yyresult;
}

#line 624 "cyrix.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buff[2048];

int yylex(void);
int mode=-1;

void yyerror(const char *s)
{
	fflush(stdout);
	
	if(mode==-1)
		printf("***parsing terminated*** [syntax error]\n");
	else if(mode==0 || mode==1)
		printf("%s\n",s);
		
	exit(-1);
}

int main(int argc, char **argv)
{
    extern FILE *yyin;

	if(argc<2)
	{
		sprintf(buff,"***process terminated*** [input error]: invalid number of command-line arguments");
		mode=1;
		yyerror(buff);
		exit(1);
	}

	yyin=fopen(argv[1],"r");

	if(yyin==NULL)
	{
		sprintf(buff,"***process terminated*** [input error]: no such file \"%s\" exists",argv[1]);
		mode=1;
		yyerror(buff);
		exit(1);
	}
	else
	{
		do
		{
			yyparse();
		}
		while(!feof(yyin));
	}

	printf("***parsing successful***\n");

	return(0);
}
