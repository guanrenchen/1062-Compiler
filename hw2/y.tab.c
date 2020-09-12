/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "compiler_hw2.y" /* yacc.c:339  */

extern int yylineno;
extern int yylex();

extern void yyerror(const char *s);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int type;
    union {
        int i;
        float f;
        char *s;
    } val;
} Inst;

typedef struct symbol{
    int depth;
    char *id;
    Inst inst;
    struct symbol *next;
} Symbol;

typedef struct scope{
    int depth;
    Symbol *symbols;
    struct scope *next, *prev, *side;
} Scope;

Scope *topScope = NULL;
Scope *curScope = NULL;

char err[4096];
int is_err = 0;
int lastline = 0;

/* Symbol table function - you can add new function if need. */
Symbol *lookup_symbol_cur(const char *id);
Symbol *lookup_symbol_all(const char *id);
void create_symbol();
void insert_symbol();
void dump_symbol();

void enter_scope();
void leave_scope();
void init_scope();

Inst calc(void *a, int op, void *b);
void print_inst(Inst inst);
void print_op(int op);
void print_type(int type);

void myerror(const char *s);
void flush_error();

// use struct(value, type) to implement type checking


#line 128 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 65 "compiler_hw2.y" /* yacc.c:355  */

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

#line 272 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 289 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   169

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  90

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   123,   123,   131,   132,   136,   137,   138,   139,   140,
     141,   142,   143,   151,   152,   153,   154,   155,   158,   161,
     167,   168,   172,   173,   177,   181,   185,   189,   193,   197,
     201,   205,   209,   213,   217,   221,   228,   229,   230,   248,
     249,   250,   254,   258,   262,   269,   305,   306,   307,   308,
     309,   310,   314,   318,   319,   320,   324,   331,   332
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSIGN", "ASSIGN_ADD", "ASSIGN_SUB",
  "ASSIGN_MUL", "ASSIGN_DIV", "ASSIGN_MOD", "OR", "AND", "GE", "LE", "EQ",
  "NE", "GT", "LT", "ADD", "SUB", "MUL", "DIV", "MOD", "INC", "DEC",
  "NEWLINE", "MY_EOF", "INT", "FLOAT", "PRINT", "PRINTLN", "IF", "ELSE",
  "FOR", "VAR", "LB", "RB", "LCB", "RCB", "BOOL", "T_ERROR", "I_CONST",
  "F_CONST", "STRING", "ID", "$accept", "program", "stmts", "stmt",
  "block", "lcb", "rcb", "lb", "rb", "declaration", "type", "expr",
  "operand", "incdec_op", "literal", "assignment", "assign_op", "for_stmt",
  "if_stmt", "print_stmt", "print_op", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298
};
# endif

#define YYPACT_NINF -30

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-30)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -30,    13,   -14,   -30,   -30,   -30,   -30,   -30,    -9,    -9,
     -26,   -30,   -30,   -30,   -30,   -30,     1,   -30,   -30,   -30,
      -9,   -30,   114,   -30,   -30,   -30,   -30,   -30,   -30,   -13,
      48,    47,    47,    46,   -30,   -30,   -30,   -30,   -30,   -30,
     -30,   -30,   -30,    -9,    79,    75,    -9,    -9,    -9,    -9,
      -9,    -9,    -9,    -9,    -9,    -9,    -9,    -9,    -9,    -9,
       6,   -30,   -30,   -30,    66,   114,   -30,   -30,   -30,   -30,
     126,   137,   148,   148,   148,   148,   148,   148,    33,    33,
     -30,   -30,   -30,    75,     0,    -9,   -30,   -30,   -30,   114
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,    11,     2,    57,    58,     0,     0,
       0,    16,    14,    42,    43,    44,    41,     3,    10,     4,
       0,     5,    12,    22,    36,     6,     7,     8,     9,     0,
      41,     0,     0,     0,    46,    47,    48,    49,    50,    51,
      39,    40,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,    52,    20,    21,    19,    45,    15,    13,    17,    37,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,     0,     0,     0,    56,    55,    54,    18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -30,   -30,    55,   -30,   -29,   -30,   -30,    49,    -7,   -30,
     -30,    -8,   -30,   -30,   -30,   -30,   -30,   -30,    -5,   -30,
     -30
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    17,    18,    19,    67,    20,    69,    21,
      64,    22,    23,    42,    24,    25,    43,    26,    27,    28,
      29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      31,    32,    60,    61,    34,    35,    36,    37,    38,    39,
       4,     5,    45,     3,     6,     7,     8,    33,     9,    10,
      11,    11,    12,    40,    41,    11,    13,    14,    15,    16,
       8,    13,    14,    15,    30,    65,    12,    84,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    56,    57,    58,    87,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    85,
      40,    41,    62,    63,    44,     0,    86,    89,    59,    88,
       0,     0,     0,    12,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,     0,     0,     0,
       0,     0,     0,     4,     0,     0,     0,     6,     7,     8,
      68,     9,    10,    11,     0,    12,    66,     0,     0,    13,
      14,    15,    16,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    56,    57,    58
};

static const yytype_int8 yycheck[] =
{
       8,     9,    31,    32,     3,     4,     5,     6,     7,     8,
      24,    25,    20,     0,    28,    29,    30,    43,    32,    33,
      34,    34,    36,    22,    23,    34,    40,    41,    42,    43,
      30,    40,    41,    42,    43,    43,    36,    31,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    19,    20,    21,    84,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,     3,
      22,    23,    26,    27,    19,    -1,    83,    85,    29,    84,
      -1,    -1,    -1,    36,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    28,    29,    30,
      35,    32,    33,    34,    -1,    36,    37,    -1,    -1,    40,
      41,    42,    43,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,    46,     0,    24,    25,    28,    29,    30,    32,
      33,    34,    36,    40,    41,    42,    43,    47,    48,    49,
      51,    53,    55,    56,    58,    59,    61,    62,    63,    64,
      43,    55,    55,    43,     3,     4,     5,     6,     7,     8,
      22,    23,    57,    60,    46,    55,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    51,
      48,    48,    26,    27,    54,    55,    37,    50,    35,    52,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    31,     3,    52,    48,    62,    55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    47,    47,
      47,    47,    47,    48,    49,    50,    51,    52,    53,    53,
      54,    54,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    56,    56,    56,    57,
      57,    57,    58,    58,    58,    59,    60,    60,    60,    60,
      60,    60,    61,    62,    62,    62,    63,    64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     5,     3,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     2,     1,
       1,     0,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     3,     3,     5,     5,     4,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 123 "compiler_hw2.y" /* yacc.c:1646  */
    {
        flush_error();
        dump_symbol(); 
        exit(0); 
        }
#line 1448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 138 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("for_stmt\n");}
#line 1454 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 139 "compiler_hw2.y" /* yacc.c:1646  */
    {printf("if_stmt\n");}
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 142 "compiler_hw2.y" /* yacc.c:1646  */
    {flush_error();}
#line 1466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 143 "compiler_hw2.y" /* yacc.c:1646  */
    {
        if ((yyvsp[0].inst).type==BOOL) {
            print_inst(*(Inst*)&((yyvsp[0].inst)));
            printf("\n");
        }
    }
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 152 "compiler_hw2.y" /* yacc.c:1646  */
    { enter_scope(); }
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 153 "compiler_hw2.y" /* yacc.c:1646  */
    { leave_scope(); }
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 154 "compiler_hw2.y" /* yacc.c:1646  */
    { enter_scope(); }
#line 1495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 155 "compiler_hw2.y" /* yacc.c:1646  */
    { leave_scope(); }
#line 1501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 158 "compiler_hw2.y" /* yacc.c:1646  */
    {
        insert_symbol((yyvsp[-3].s), (yyvsp[-2].type), (Inst*)&((yyvsp[0].inst)));
        }
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 161 "compiler_hw2.y" /* yacc.c:1646  */
    {
        insert_symbol((yyvsp[-1].s), (yyvsp[0].type), NULL);
        }
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 167 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.type) = INT; }
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 168 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.type) = FLOAT; }
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 172 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.inst) = (yyvsp[0].inst); }
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 173 "compiler_hw2.y" /* yacc.c:1646  */
    { 
        Inst tmp = calc(&((yyvsp[-2].inst)),  OR, &((yyvsp[0].inst))); 
        memcpy(&((yyval.inst)), &tmp, sizeof((yyval.inst)));
        }
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 177 "compiler_hw2.y" /* yacc.c:1646  */
    { 
        Inst tmp = calc(&((yyvsp[-2].inst)), AND, &((yyvsp[0].inst))); 
        memcpy(&((yyval.inst)), &tmp, sizeof((yyval.inst)));
        }
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 181 "compiler_hw2.y" /* yacc.c:1646  */
    { 
        Inst tmp = calc(&((yyvsp[-2].inst)),  GE, &((yyvsp[0].inst))); 
        memcpy(&((yyval.inst)), &tmp, sizeof((yyval.inst)));
        }
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 185 "compiler_hw2.y" /* yacc.c:1646  */
    { 
        Inst tmp = calc(&((yyvsp[-2].inst)),  LE, &((yyvsp[0].inst))); 
        memcpy(&((yyval.inst)), &tmp, sizeof((yyval.inst)));
        }
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 189 "compiler_hw2.y" /* yacc.c:1646  */
    { 
        Inst tmp = calc(&((yyvsp[-2].inst)),  EQ, &((yyvsp[0].inst))); 
        memcpy(&((yyval.inst)), &tmp, sizeof((yyval.inst)));
        }
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 193 "compiler_hw2.y" /* yacc.c:1646  */
    { 
        Inst tmp = calc(&((yyvsp[-2].inst)),  NE, &((yyvsp[0].inst))); 
        memcpy(&((yyval.inst)), &tmp, sizeof((yyval.inst)));
        }
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 197 "compiler_hw2.y" /* yacc.c:1646  */
    { 
        Inst tmp = calc(&((yyvsp[-2].inst)),  GT, &((yyvsp[0].inst))); 
        memcpy(&((yyval.inst)), &tmp, sizeof((yyval.inst)));
        }
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 201 "compiler_hw2.y" /* yacc.c:1646  */
    { 
        Inst tmp = calc(&((yyvsp[-2].inst)),  LT, &((yyvsp[0].inst))); 
        memcpy(&((yyval.inst)), &tmp, sizeof((yyval.inst)));
        }
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 205 "compiler_hw2.y" /* yacc.c:1646  */
    { 
        Inst tmp = calc(&((yyvsp[-2].inst)), ADD, &((yyvsp[0].inst))); 
        memcpy(&((yyval.inst)), &tmp, sizeof((yyval.inst)));
        }
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 209 "compiler_hw2.y" /* yacc.c:1646  */
    { 
        Inst tmp = calc(&((yyvsp[-2].inst)), SUB, &((yyvsp[0].inst))); 
        memcpy(&((yyval.inst)), &tmp, sizeof((yyval.inst)));
        }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 213 "compiler_hw2.y" /* yacc.c:1646  */
    { 
        Inst tmp = calc(&((yyvsp[-2].inst)), MUL, &((yyvsp[0].inst))); 
        memcpy(&((yyval.inst)), &tmp, sizeof((yyval.inst)));
        }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 217 "compiler_hw2.y" /* yacc.c:1646  */
    { 
        Inst tmp = calc(&((yyvsp[-2].inst)), DIV, &((yyvsp[0].inst))); 
        memcpy(&((yyval.inst)), &tmp, sizeof((yyval.inst)));
        }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 221 "compiler_hw2.y" /* yacc.c:1646  */
    { 
        Inst tmp = calc(&((yyvsp[-2].inst)), MOD, &((yyvsp[0].inst))); 
        memcpy(&((yyval.inst)), &tmp, sizeof((yyval.inst)));
        }
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 228 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.inst)=(yyvsp[0].inst);}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 229 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.inst)=(yyvsp[-1].inst);}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 230 "compiler_hw2.y" /* yacc.c:1646  */
    {
        Symbol *sym = lookup_symbol_all((yyvsp[-1].s));
        if(!sym) {
            myerror("Undefined variable");
            (yyval.inst).type = T_ERROR;
        }else{
            // printf("\tvariable %s is in depth %d\n", sym->id, sym->depth);
            memcpy(&((yyval.inst)), &(sym->inst), sizeof((yyval.inst)));
            if(sym->inst.type==INT){
                sym->inst.val.i += (yyvsp[0].i);
            }else if ((yyvsp[0].i)!=0) {
                myerror("Invalid operation on variable");
            }
        }
        }
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 248 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.i)= 1;}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 249 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.i)=-1;}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 250 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.i)= 0;}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 254 "compiler_hw2.y" /* yacc.c:1646  */
    { 
        (yyval.inst).type = INT;
        (yyval.inst).val.i = (yyvsp[0].i);
        }
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 258 "compiler_hw2.y" /* yacc.c:1646  */
    { 
        (yyval.inst).type = FLOAT;
        (yyval.inst).val.f = (yyvsp[0].f);
        }
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 262 "compiler_hw2.y" /* yacc.c:1646  */
    { 
        (yyval.inst).type = STRING;
        (yyval.inst).val.s = strdup((yyvsp[0].s));
        }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 269 "compiler_hw2.y" /* yacc.c:1646  */
    {
        Symbol *sym = lookup_symbol_all((yyvsp[-2].s));

        Inst *lv, *rv;
        lv = &(sym->inst);
        rv = (Inst*)&((yyvsp[0].inst));

        if(!sym) {
            myerror("Undefined variable");
        }else{
            Inst ret;
            switch ((yyvsp[-1].op)) {
            case ASSIGN_ADD : ret = calc(lv, ADD, rv); break;
            case ASSIGN_SUB : ret = calc(lv, SUB, rv); break;
            case ASSIGN_MUL : ret = calc(lv, MUL, rv); break;
            case ASSIGN_DIV : ret = calc(lv, DIV, rv); break;
            case ASSIGN_MOD : ret = calc(lv, MOD, rv); break;
            case ASSIGN     : ret = *rv;
            }

            if (ret.type==INT || ret.type==FLOAT) {
                if(sym->inst.type == INT){
                    sym->inst.val.i = 
                        (ret.type==FLOAT? ret.val.f : ret.val.i);
                }else{
                    sym->inst.val.f = 
                        (ret.type==FLOAT? ret.val.f : ret.val.i);
                }
            } else if (ret.type!=T_ERROR) {
                myerror("Assignment type error");
            }
        }
        }
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 305 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.op)=ASSIGN;}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 306 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.op)=ASSIGN_ADD;}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 307 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.op)=ASSIGN_SUB;}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 308 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.op)=ASSIGN_MUL;}
#line 1791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 309 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.op)=ASSIGN_DIV;}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 310 "compiler_hw2.y" /* yacc.c:1646  */
    {(yyval.op)=ASSIGN_MOD;}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 324 "compiler_hw2.y" /* yacc.c:1646  */
    {
        print_inst(*(Inst*)&((yyvsp[-1].inst)));
        if((yyvsp[-3].op)==PRINTLN) printf("\n");
        }
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 331 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.op) = PRINT; }
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 332 "compiler_hw2.y" /* yacc.c:1646  */
    { (yyval.op) = PRINTLN; }
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1828 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 335 "compiler_hw2.y" /* yacc.c:1906  */


/* C code section */
int main(int argc, char** argv)
{
    enter_scope();

    yylineno = 0;
    yyparse();

    return 0;
}

void yyerror(const char *s){
    fprintf(stderr, "line %d\t: %s\n", yylineno+1, s);
}

void myerror(const char *s) {
    if(strcmp(err,"")==0){
        strncpy(err, s, sizeof(err));
    }
}

void flush_error() {
    if(strcmp(err,"")!=0){
        fprintf(stderr, "line %d\t: %s\n", yylineno, err);
        memset(err, 0, sizeof(err));
    }
}

Symbol *lookup_symbol_cur(const char *id){
    Symbol *sym;
    for (sym=curScope->symbols; sym; sym=sym->next)
        if (strcmp(id, sym->id)==0)
            return sym;
    return NULL;
}
Symbol *lookup_symbol_all(const char* id){
    Scope *scp;
    Symbol *sym;
    for(scp=curScope; scp; scp=scp->prev){
        for(sym=scp->symbols; sym; sym=sym->next){
            if(strcmp(id, sym->id)==0) {
                // printf("variable %s is depth %d\n", sym->id, sym->depth);
                return sym;
            }
        }
    }
    return NULL;
}
void create_symbol() {
    curScope->symbols = malloc(sizeof(Symbol));
    // printf("create symbol table for depth %d\n", curScope->depth);
}
void insert_symbol(const char *id, int type, Inst *inst) {
    if (lookup_symbol_cur(id)) {
        myerror("Redefined variable");
        return;
    }
    
    Symbol *tmp = curScope->symbols;
    if (tmp) {
        while(tmp->next) tmp=tmp->next;
        tmp->next = malloc(sizeof(Symbol));
        tmp = tmp->next;
    } else {    
        create_symbol();
        tmp = curScope->symbols;
    }
    tmp->depth = curScope->depth;
    tmp->id = strdup(id);
    tmp->next = NULL;

    if (inst) {
        if (inst->type==T_ERROR){
            return;
        } else if (inst->type!=INT && inst->type!=FLOAT) {
            myerror("Declaration type mismatch");
            return;
        } else {
            tmp->inst = *inst;
        }
    } else {
        memset(&(tmp->inst), 0, sizeof(Inst));
        tmp->inst.type = type;
    }

    printf("declare %s in block of depth %d\n", id, curScope->depth);
        
}
void dump_symbol() {
    Scope *scp;
    Symbol *sym;
    printf("\tSYMBOL TABLE\n");
    for (scp=curScope; scp; scp=scp->prev) {
        printf("\tdepth %d :\n", scp->depth);
        for (sym=scp->symbols; sym; sym=sym->next){
            printf("\t\t%s\t", sym->id);
            print_type(sym->inst.type);
            printf("\t");
            print_inst(sym->inst);
            printf("\n");
        }
    }
}

void enter_scope() {
    if (!topScope){
        topScope = malloc(sizeof(Scope));
        init_scope(topScope, 0);
        curScope = topScope;
    }else{
        if(!(curScope->next)){
            curScope->next = malloc(sizeof(Scope));
            init_scope(curScope->next, curScope->depth+1);
            curScope->next->prev = curScope;
            curScope = curScope->next;
        }else{
            Scope *tmp;
            for (tmp=curScope->next; tmp->side; tmp=tmp->side);
            tmp->side = malloc(sizeof(Scope));
            tmp = tmp->side;
            init_scope(tmp, curScope->depth+1);
            tmp->prev = curScope;
            curScope = tmp;
        }
        // printf("%s %d\n", __func__, curScope->depth);
    }
} 
void leave_scope() {
    if (curScope->prev) {
        // printf("%s %d\n", __func__, curScope->depth);
        curScope = curScope->prev;
    }
}
void init_scope(Scope *scp, int depth) {
    scp->depth = depth;
    scp->symbols = NULL;
    scp->next = NULL;
    scp->prev = NULL;
    scp->side = NULL;
}

void print_inst(Inst inst){
    switch (inst.type) {
    case INT:       printf("%d", inst.val.i);   break;
    case FLOAT:     printf("%f", inst.val.f);   break;
    case STRING:    printf("%s", inst.val.s);   break;
    case BOOL:      printf(inst.val.i? "true": "false"); break;
    default: break;
    }
}
void print_op(int op){
    switch (op) {
    case OR:    printf("||");   break;
    case AND:   printf("&&");   break;
    case GE:    printf(">=");   break;
    case LE:    printf("<=");   break;
    case EQ:    printf("==");   break;
    case NE:    printf("!=");   break;
    case GT:    printf( ">");   break;
    case LT:    printf( "<");   break;
    case ADD:   printf( "+");   break;
    case SUB:   printf( "-");   break;
    case MUL:   printf( "*");   break;
    case DIV:   printf( "/");   break;
    case MOD:   printf("%%");   break;
    case INC:   printf("++");   break;
    case DEC:   printf("--");   break;
    default:    printf("op?");   break;
    }
    printf(" ");
}
void print_type(int type){
    switch (type) {
        case INT:       printf("int");          break;
        case FLOAT:     printf("float32");      break;
        case STRING:    printf("String");       break;
        case BOOL:      printf("Boolean");      break;
        case T_ERROR:   printf("T_ERROR");      break;
        default :       printf("type?");        break;
    }
}

Inst calc(void *a, int op, void *b){
    Inst ret;
    Inst x=*(Inst*)a, y=*(Inst*)b;

    ret.type = T_ERROR;

    if (x.type==T_ERROR || y.type==T_ERROR){
        return ret;
    }

    if(x.type==STRING || y.type==STRING){
        myerror("Invalid operation with string");
        return ret;
    }

    switch (op) {
    case OR:
        ret.type = BOOL;
        ret.val.i = (*(float*)&x.val) || (*(float*)&y.val);
        return ret;
    case AND:
        ret.type = BOOL;
        ret.val.i = (*(float*)&x.val) && (*(float*)&y.val);
        return ret;
    case GE:
        ret.type = BOOL;
        ret.val.i = 
            (x.type==FLOAT? x.val.f: x.val.i) >= 
            (y.type==FLOAT? y.val.f: y.val.i);
        return ret;
    case LE:
        ret.type = BOOL;
        ret.val.i = 
            (x.type==FLOAT? x.val.f: x.val.i) <= 
            (y.type==FLOAT? y.val.f: y.val.i);
        return ret;
    case EQ:
        ret.type = BOOL;
        ret.val.i = 
            (x.type==FLOAT? x.val.f: x.val.i) == 
            (y.type==FLOAT? y.val.f: y.val.i);
        return ret;
    case NE:
        ret.type = BOOL;
        ret.val.i = 
            (x.type==FLOAT? x.val.f: x.val.i) != 
            (y.type==FLOAT? y.val.f: y.val.i);
        return ret;
    case GT:
        ret.type = BOOL;
        ret.val.i = 
            (x.type==FLOAT? x.val.f: x.val.i) > 
            (y.type==FLOAT? y.val.f: y.val.i);
        return ret;
    case LT:
        ret.type = BOOL;
        ret.val.i = 
            (x.type==FLOAT? x.val.f: x.val.i) < 
            (y.type==FLOAT? y.val.f: y.val.i);
        return ret;
    case ADD:
        if (x.type==FLOAT || y.type==FLOAT){
            ret.type = FLOAT;
            ret.val.f = 
                (x.type==FLOAT? x.val.f: x.val.i) + 
                (y.type==FLOAT? y.val.f: y.val.i);
        }else{
            ret.type = INT;
            ret.val.i = 
                (x.type==FLOAT? x.val.f: x.val.i) + 
                (y.type==FLOAT? y.val.f: y.val.i);
        }
        return ret;
    case SUB:
        if (x.type==FLOAT || y.type==FLOAT){
            ret.type = FLOAT;
            ret.val.f = 
                (x.type==FLOAT? x.val.f: x.val.i) - 
                (y.type==FLOAT? y.val.f: y.val.i);
        }else{
            ret.type = INT;
            ret.val.i = 
                (x.type==FLOAT? x.val.f: x.val.i) -
                (y.type==FLOAT? y.val.f: y.val.i);
        }
        return ret;
    case MUL:
        if (x.type==FLOAT || y.type==FLOAT){
            ret.type = FLOAT;
            ret.val.f = 
                (x.type==FLOAT? x.val.f: x.val.i) * 
                (y.type==FLOAT? y.val.f: y.val.i);
        }else{
            ret.type = INT;
            ret.val.i = 
                (x.type==FLOAT? x.val.f: x.val.i) * 
                (y.type==FLOAT? y.val.f: y.val.i);
        }
        return ret;
    case DIV:
        if ( (y.type==FLOAT? y.val.f: y.val.i)==0 ) {
            myerror("Divide by 0");
        }else if (x.type==FLOAT || y.type==FLOAT){
            ret.type = FLOAT;
            ret.val.f = 
                (x.type==FLOAT? x.val.f: x.val.i) /
                (y.type==FLOAT? y.val.f: y.val.i);
        }else{
            ret.type = INT;
            ret.val.i = 
                (x.type==FLOAT? x.val.f: x.val.i) / 
                (y.type==FLOAT? y.val.f: y.val.i);
        }
        return ret;
    case MOD:
        if (x.type==FLOAT || y.type==FLOAT){
            myerror("Modulus with float32");
        }else if(y.val.i==0) {
            myerror("Divide by 0 (modulus)");
        }else{
            ret.type = INT;
            ret.val.i = x.val.i % y.val.i;
        }
        return ret;
    default:
        return ret;
    }
}