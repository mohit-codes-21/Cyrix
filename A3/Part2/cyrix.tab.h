/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_CYRIX_TAB_H_INCLUDED
# define YY_YY_CYRIX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    I_CONSTANT = 259,              /* I_CONSTANT  */
    F_CONSTANT = 260,              /* F_CONSTANT  */
    STRING_LITERAL = 261,          /* STRING_LITERAL  */
    FUNC_NAME = 262,               /* FUNC_NAME  */
    SIZEOF = 263,                  /* SIZEOF  */
    PTR_OP = 264,                  /* PTR_OP  */
    INC_OP = 265,                  /* INC_OP  */
    DEC_OP = 266,                  /* DEC_OP  */
    LEFT_OP = 267,                 /* LEFT_OP  */
    RIGHT_OP = 268,                /* RIGHT_OP  */
    LE_OP = 269,                   /* LE_OP  */
    GE_OP = 270,                   /* GE_OP  */
    EQ_OP = 271,                   /* EQ_OP  */
    NE_OP = 272,                   /* NE_OP  */
    TH_OP = 273,                   /* TH_OP  */
    AND_OP = 274,                  /* AND_OP  */
    OR_OP = 275,                   /* OR_OP  */
    MUL_ASSIGN = 276,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 277,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 278,              /* MOD_ASSIGN  */
    ADD_ASSIGN = 279,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 280,              /* SUB_ASSIGN  */
    LEFT_ASSIGN = 281,             /* LEFT_ASSIGN  */
    RIGHT_ASSIGN = 282,            /* RIGHT_ASSIGN  */
    AND_ASSIGN = 283,              /* AND_ASSIGN  */
    XOR_ASSIGN = 284,              /* XOR_ASSIGN  */
    OR_ASSIGN = 285,               /* OR_ASSIGN  */
    TYPEDEF_NAME = 286,            /* TYPEDEF_NAME  */
    ENUMERATION_CONSTANT = 287,    /* ENUMERATION_CONSTANT  */
    VAR = 288,                     /* VAR  */
    FOREACH = 289,                 /* FOREACH  */
    IN = 290,                      /* IN  */
    MATCH = 291,                   /* MATCH  */
    FN = 292,                      /* FN  */
    SAFE_DOT = 293,                /* SAFE_DOT  */
    LAMBDA_ARROW = 294,            /* LAMBDA_ARROW  */
    POW_OP = 295,                  /* POW_OP  */
    TYPEDEF = 296,                 /* TYPEDEF  */
    EXTERN = 297,                  /* EXTERN  */
    STATIC = 298,                  /* STATIC  */
    AUTO = 299,                    /* AUTO  */
    REGISTER = 300,                /* REGISTER  */
    INLINE = 301,                  /* INLINE  */
    CONST = 302,                   /* CONST  */
    RESTRICT = 303,                /* RESTRICT  */
    VOLATILE = 304,                /* VOLATILE  */
    BOOL = 305,                    /* BOOL  */
    CHAR = 306,                    /* CHAR  */
    SHORT = 307,                   /* SHORT  */
    INT = 308,                     /* INT  */
    LONG = 309,                    /* LONG  */
    SIGNED = 310,                  /* SIGNED  */
    UNSIGNED = 311,                /* UNSIGNED  */
    FLOAT = 312,                   /* FLOAT  */
    DOUBLE = 313,                  /* DOUBLE  */
    VOID = 314,                    /* VOID  */
    COMPLEX = 315,                 /* COMPLEX  */
    IMAGINARY = 316,               /* IMAGINARY  */
    STRUCT = 317,                  /* STRUCT  */
    UNION = 318,                   /* UNION  */
    ENUM = 319,                    /* ENUM  */
    ELLIPSIS = 320,                /* ELLIPSIS  */
    CASE = 321,                    /* CASE  */
    DEFAULT = 322,                 /* DEFAULT  */
    IF = 323,                      /* IF  */
    SWITCH = 324,                  /* SWITCH  */
    WHILE = 325,                   /* WHILE  */
    DO = 326,                      /* DO  */
    FOR = 327,                     /* FOR  */
    GOTO = 328,                    /* GOTO  */
    CONTINUE = 329,                /* CONTINUE  */
    BREAK = 330,                   /* BREAK  */
    RETURN = 331,                  /* RETURN  */
    ALIGNAS = 332,                 /* ALIGNAS  */
    ALIGNOF = 333,                 /* ALIGNOF  */
    ATOMIC = 334,                  /* ATOMIC  */
    GENERIC = 335,                 /* GENERIC  */
    NORETURN = 336,                /* NORETURN  */
    STATIC_ASSERT = 337,           /* STATIC_ASSERT  */
    THREAD_LOCAL = 338,            /* THREAD_LOCAL  */
    LOWER_THAN_ELSE = 339,         /* LOWER_THAN_ELSE  */
    ELSE = 340,                    /* ELSE  */
    UNARY = 341                    /* UNARY  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CYRIX_TAB_H_INCLUDED  */
