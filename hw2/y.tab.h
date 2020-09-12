/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ASSIGN = 258,
    ASSIGN_ADD = 259,
    ASSIGN_SUB = 260,
    ASSIGN_MUL = 261,
    ASSIGN_DIV = 262,
    ASSIGN_MOD = 263,
    OR = 264,
    AND = 265,
    GE = 266,
    LE = 267,
    EQ = 268,
    NE = 269,
    GT = 270,
    LT = 271,
    ADD = 272,
    SUB = 273,
    MUL = 274,
    DIV = 275,
    MOD = 276,
    INC = 277,
    DEC = 278,
    NEWLINE = 279,
    MY_EOF = 280,
    INT = 281,
    FLOAT = 282,
    PRINT = 283,
    PRINTLN = 284,
    IF = 285,
    ELSE = 286,
    FOR = 287,
    VAR = 288,
    LB = 289,
    RB = 290,
    LCB = 291,
    RCB = 292,
    BOOL = 293,
    T_ERROR = 294,
    I_CONST = 295,
    F_CONST = 296,
    STRING = 297,
    ID = 298
  };
#endif
/* Tokens.  */
#define ASSIGN 258
#define ASSIGN_ADD 259
#define ASSIGN_SUB 260
#define ASSIGN_MUL 261
#define ASSIGN_DIV 262
#define ASSIGN_MOD 263
#define OR 264
#define AND 265
#define GE 266
#define LE 267
#define EQ 268
#define NE 269
#define GT 270
#define LT 271
#define ADD 272
#define SUB 273
#define MUL 274
#define DIV 275
#define MOD 276
#define INC 277
#define DEC 278
#define NEWLINE 279
#define MY_EOF 280
#define INT 281
#define FLOAT 282
#define PRINT 283
#define PRINTLN 284
#define IF 285
#define ELSE 286
#define FOR 287
#define VAR 288
#define LB 289
#define RB 290
#define LCB 291
#define RCB 292
#define BOOL 293
#define T_ERROR 294
#define I_CONST 295
#define F_CONST 296
#define STRING 297
#define ID 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 65 "compiler_hw2.y" /* yacc.c:1909  */

    struct {
        int type;
        union {
            int i;
            float f;
            char *s;
        } val;
    } inst;

    int i;
    float f;
    char *s;
    int type;

    int op;

#line 158 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
