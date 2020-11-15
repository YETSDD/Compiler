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
#line 1 "syntax.y" /* yacc.c:339  */

    #include"lex.yy.c"

    void yyerror(const char *s){
    printf("Error type B ");
    }
    struct symTab* head;

    struct funTab* funHead;
    struct arrTab* arrHead;
    struct strTab* strHead;

#line 79 "syntax.tab.c" /* yacc.c:339  */

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
   by #include "syntax.tab.h".  */
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    FLOAT = 259,
    CHAR = 260,
    ID = 261,
    ERROR = 262,
    TYPE = 263,
    STRUCT = 264,
    IF = 265,
    ELSE = 266,
    WHILE = 267,
    RETURN = 268,
    DOT = 269,
    SEMI = 270,
    COMMA = 271,
    ASSIGN = 272,
    LT = 273,
    LE = 274,
    GT = 275,
    GE = 276,
    NE = 277,
    EQ = 278,
    PLUS = 279,
    MINUS = 280,
    MUL = 281,
    DIV = 282,
    AND = 283,
    OR = 284,
    NOT = 285,
    LP = 286,
    RP = 287,
    LC = 288,
    RC = 289,
    LB = 290,
    RB = 291,
    STAR = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "syntax.y" /* yacc.c:355  */

    struct node* n;
    double d;

#line 162 "syntax.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 179 "syntax.tab.c" /* yacc.c:358  */

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   420

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  151

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

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
      35,    36,    37
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    35,    35,    38,    39,    40,    41,    44,    45,    61,
      72,    75,    76,    77,   119,   129,   141,   144,   176,   187,
     188,   189,   190,   191,   192,   298,   299,   300,   301,   302,
     303,   304,   308,   309,   310,   311,   312,   315,   316,   317,
     461,   462,   465,   466,   467,   470,   479,   480,   482,   494,
     495,   496,   502,   508,   514,   520,   526,   532,   548,   564,
     580,   595,   596,   597,   598,   651,   666,   681,   694,   704,
     705,   706,   707,   708,   709,   710,   711,   712,   713,   714,
     715
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "CHAR", "ID", "ERROR",
  "TYPE", "STRUCT", "IF", "ELSE", "WHILE", "RETURN", "DOT", "SEMI",
  "COMMA", "ASSIGN", "LT", "LE", "GT", "GE", "NE", "EQ", "PLUS", "MINUS",
  "MUL", "DIV", "AND", "OR", "NOT", "LP", "RP", "LC", "RC", "LB", "RB",
  "STAR", "$accept", "Program", "ExtDefList", "ExtDef", "ExtDecList",
  "Specifier", "StructSpecifier", "VarDec", "FunDec", "VarList",
  "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def", "DecList",
  "Dec", "Exp", "Args", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292
};
# endif

#define YYPACT_NINF -103

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-103)))

#define YYTABLE_NINF -39

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      94,  -103,    11,    44,  -103,    75,    32,  -103,    -1,  -103,
    -103,    60,    80,    94,    58,  -103,    76,    -7,    85,    94,
     107,    -2,    62,    13,  -103,   114,  -103,     3,  -103,   119,
     123,    94,  -103,    93,    65,    65,  -103,  -103,  -103,   114,
      10,   127,  -103,  -103,   119,     7,    77,  -103,    96,   219,
    -103,  -103,  -103,  -103,    98,  -103,    65,    65,    65,   308,
     308,  -103,  -103,   112,  -103,  -103,    94,   147,  -103,   118,
     122,    65,  -103,     2,   219,   262,   211,   375,   385,    87,
      65,   144,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,  -103,  -103,    65,    65,
     116,  -103,  -103,  -103,  -103,  -103,  -103,   178,     9,  -103,
    -103,   308,  -103,   308,   308,   308,   308,   308,   308,   308,
     375,   375,   308,   385,   353,   331,   239,   145,   285,  -103,
    -103,    65,    65,    65,    65,   153,  -103,  -103,  -103,  -103,
     219,   219,   154,  -103,   375,  -103,   146,  -103,  -103,   219,
    -103
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    11,     0,     0,     2,     5,     0,    12,    14,     1,
       3,     0,     0,    38,    15,     7,     0,     9,     0,    38,
      47,    44,     0,    41,     4,     0,    37,     0,     6,     0,
       0,    38,     8,     0,     0,     0,    40,    39,    15,     0,
      44,     0,    20,    18,     0,     0,    22,    10,     0,    28,
      13,    69,    70,    71,    68,    76,     0,     0,     0,    46,
      45,    42,    43,    24,    19,    17,     0,     0,    16,     0,
       0,     0,    30,     0,    28,     0,     0,    62,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,    23,     0,     0,
       0,    26,    25,    27,    29,    73,    65,    78,     0,    74,
      61,    75,    67,    48,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    49,    50,     0,     0,     0,    36,
      31,    76,     0,     0,     0,     0,    72,    64,    66,    35,
       0,     0,     0,    77,    58,    80,    33,    34,    79,     0,
      32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -103,  -103,   151,  -103,   129,    16,  -103,    -4,  -103,   -40,
    -103,   142,   101,   -62,    61,  -103,    -5,  -103,   -34,  -102
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    16,    25,     7,    40,    18,    45,
      46,    72,    73,    74,    12,    13,    22,    23,    75,   108
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      59,    60,    17,   101,    42,   135,    67,    21,    64,    29,
     136,     1,     2,    -9,    29,    35,     6,     8,    41,    38,
      20,    11,    77,    78,    79,    17,    96,    35,    30,    39,
     142,   143,    19,    30,    61,    43,   102,   100,    14,    65,
      63,   137,   107,    44,     9,    30,   111,    15,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    44,    36,   127,   128,    14,    20,    51,    52,
      53,    54,    55,   107,    26,    15,   -38,    37,   146,   147,
      33,    24,    44,     1,     2,     1,     2,   150,   109,    27,
      56,    28,    49,    66,    80,    57,    58,   111,   107,   107,
     144,    81,     1,     2,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,   129,    31,   110,
      38,    20,    95,    80,    34,    38,    48,    50,    62,    76,
      81,   130,    68,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,   139,    30,    97,    98,
     112,    95,    80,    99,   145,   148,    10,   149,    47,    81,
      32,     0,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,   103,     0,   140,     0,     0,
      95,    51,    52,    53,    54,   131,     0,     0,     0,     0,
       0,     0,    81,   132,   133,    82,    83,    84,    85,    86,
      87,    88,    89,   134,    91,    92,    93,    94,    57,    58,
       0,     0,   105,    95,    51,    52,    53,    54,    55,     0,
       0,     0,    51,    52,    53,    54,    55,     0,     0,    69,
       0,    70,    71,     0,     0,     0,    56,     0,     0,     0,
       0,    57,    58,   106,    56,     0,    80,     0,     0,    57,
      58,     0,    31,    81,     0,     0,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    80,
       0,     0,     0,     0,    95,   138,    81,   104,     0,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    80,     0,     0,     0,     0,    95,     0,    81,
       0,     0,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    80,     0,   141,     0,     0,
      95,     0,    81,     0,     0,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    80,     0,
       0,     0,     0,    95,     0,    81,     0,     0,     0,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      80,     0,     0,     0,     0,     0,    95,    81,     0,     0,
       0,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,     0,    80,     0,     0,     0,     0,     0,    95,    81,
       0,     0,    80,    83,    84,    85,    86,    87,    88,    81,
       0,    91,    92,    83,    84,    85,    86,    87,    88,     0,
      95,    91,     0,     0,     0,     0,     0,     0,     0,     0,
      95
};

static const yytype_int16 yycheck[] =
{
      34,    35,     6,     1,     1,   107,    46,    11,     1,    16,
       1,     8,     9,    15,    16,    17,     0,     6,    23,     6,
       7,     5,    56,    57,    58,    29,    66,    17,    35,    16,
     132,   133,    33,    35,    39,    32,    34,    71,     6,    32,
      44,    32,    76,    27,     0,    35,    80,    15,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    46,     1,    98,    99,     6,     7,     3,     4,
       5,     6,     7,   107,    13,    15,     1,    15,   140,   141,
      19,     1,    66,     8,     9,     8,     9,   149,     1,    31,
      25,    15,    31,    16,     7,    30,    31,   131,   132,   133,
     134,    14,     8,     9,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,     1,    33,    32,
       6,     7,    35,     7,    17,     6,     3,    34,     1,    31,
      14,    15,    36,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,     1,    35,     1,    31,
       6,    35,     7,    31,     1,     1,     5,    11,    29,    14,
      18,    -1,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    74,    -1,    32,    -1,    -1,
      35,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      -1,    -1,     1,    35,     3,     4,     5,     6,     7,    -1,
      -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,    10,
      -1,    12,    13,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      -1,    30,    31,    32,    25,    -1,     7,    -1,    -1,    30,
      31,    -1,    33,    14,    -1,    -1,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     7,
      -1,    -1,    -1,    -1,    35,    36,    14,    15,    -1,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,     7,    -1,    -1,    -1,    -1,    35,    -1,    14,
      -1,    -1,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     7,    -1,    32,    -1,    -1,
      35,    -1,    14,    -1,    -1,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,     7,    -1,
      -1,    -1,    -1,    35,    -1,    14,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       7,    -1,    -1,    -1,    -1,    -1,    35,    14,    -1,    -1,
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,     7,    -1,    -1,    -1,    -1,    -1,    35,    14,
      -1,    -1,     7,    18,    19,    20,    21,    22,    23,    14,
      -1,    26,    27,    18,    19,    20,    21,    22,    23,    -1,
      35,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    39,    40,    41,    43,    44,     6,     0,
      40,    43,    52,    53,     6,    15,    42,    45,    46,    33,
       7,    45,    54,    55,     1,    43,    52,    31,    15,    16,
      35,    33,    49,    52,    17,    17,     1,    15,     6,    16,
      45,    54,     1,    32,    43,    47,    48,    42,     3,    52,
      34,     3,     4,     5,     6,     7,    25,    30,    31,    56,
      56,    54,     1,    45,     1,    32,    16,    47,    36,    10,
      12,    13,    49,    50,    51,    56,    31,    56,    56,    56,
       7,    14,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    35,    47,     1,    31,    31,
      56,     1,    34,    50,    15,     1,    32,    56,    57,     1,
      32,    56,     6,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,     1,
      15,     7,    15,    16,    25,    57,     1,    32,    36,     1,
      32,    32,    57,    57,    56,     1,    51,    51,     1,    11,
      51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    40,    40,    40,    41,    41,    41,    42,
      42,    43,    43,    44,    44,    45,    45,    46,    46,    46,
      46,    47,    47,    47,    48,    49,    49,    50,    50,    51,
      51,    51,    51,    51,    51,    51,    51,    52,    52,    53,
      53,    54,    54,    54,    55,    55,    55,    55,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    57,    57,    57,
      57
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     3,     0,     3,     2,     3,     1,
       3,     1,     1,     5,     2,     1,     4,     4,     3,     4,
       3,     3,     1,     3,     2,     4,     4,     2,     0,     2,
       1,     3,     7,     5,     5,     4,     3,     2,     0,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     4,     3,     4,     3,     1,     1,
       1,     1,     4,     3,     3,     3,     1,     3,     1,     4,
       3
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
#line 35 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("Program",temp,1); 
//if(!hasError)travesal($$,0);
}
#line 1414 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 38 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-1].n); temp[1]=(yyvsp[0].n);(yyval.n) = createNode("ExtDefList",temp,2);}
#line 1420 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 39 "syntax.y" /* yacc.c:1646  */
    {hasError=1;printf("at line %d : Cannot define here\n",(yyvsp[-1].n)->line);}
#line 1426 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 40 "syntax.y" /* yacc.c:1646  */
    {(yyval.n) = createLeafNode("ExtDefList",-1,"");}
#line 1432 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 41 "syntax.y" /* yacc.c:1646  */
    { 
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("ExtDef",temp,3);}
#line 1439 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 44 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-1].n); temp[1]=(yyvsp[0].n);(yyval.n) = createNode("ExtDef",temp,2);}
#line 1445 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 45 "syntax.y" /* yacc.c:1646  */
    {
    //printf("Func: %s %s ",$1->type->name,$2->id);
    findfunc((yyvsp[-1].n)->id,funHead)->type=(yyvsp[-2].n)->type;
    struct node* tmp=(struct node*)malloc(sizeof(struct node));
    tmp=(yyvsp[0].n)->child[2];//StmtList
    while(tmp->num==2){
        struct node* stmt=(struct node*)malloc(sizeof(struct node));
        stmt=tmp->child[0];
        //printf("CHECK RETURN\n");
        if(checkReturn((yyvsp[-2].n)->type,stmt)==0)
            hasError=1;
        tmp=tmp->child[1];
    }
    //printf("Type check:%s %s",$1->id,$2->id);
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("ExtDef",temp,3);
    }
#line 1466 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 61 "syntax.y" /* yacc.c:1646  */
    {
    // if(lookup($1->id,head)==1){ 
    //     printf("Error type 3 at Line %d: variable %s is redefined\n", $1->line, $1->id);
    //     hasError=1;
    //     }
    // else{
    //     printf("not exist\n");
    //     struct symTab *newSym=newSymTab("",$1->id);
    //     insert("",$1->id,head);
  struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("ExtDecList",temp,1);}
#line 1481 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 72 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("ExtDecList",temp,3);}
#line 1487 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 75 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("Specifier",temp,1);(yyval.n)->type=newType((yyvsp[0].n)->id);}
#line 1493 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 76 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("Specifier",temp,1);(yyval.n)->type=(yyvsp[0].n)->type;}
#line 1499 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 77 "syntax.y" /* yacc.c:1646  */
    {
    //printf("Struct Specifier");
    if(lookupstr((yyvsp[-3].n)->id,strHead)==1){
        printf("Error type 15 at Line %d: structure %s is redefined\n", (yyvsp[-3].n)->line, (yyvsp[-3].n)->id);
        hasError=1;
    }
    //printf("struct id valid %s",$2->id);
    struct Type* strType=newType("STRUCT");
    strcpy(strType->uName,(yyvsp[-3].n)->id);
    struct node* tmp=(struct node *)malloc(sizeof(struct node));
    tmp=(yyvsp[-1].n);
    //printf("tmp: %s %d",tmp->name,tmp->num);
     while(tmp->num==2){
        struct Type* type=tmp->child[0]->child[0]->type;
        struct node* dec=(struct node *)malloc(sizeof(struct node));
        dec=tmp->child[0]->child[1];
        while(dec->num==3){
            struct FieldList* newField=(struct FieldList *)malloc(sizeof(struct FieldList));
            strcpy(newField->name,dec->child[0]->id);
            newField->type=type;
            newField->next=NULL;
            if(strType->structure==NULL)
                strType->structure=newField;
            else
                strType->structure->next=newField;
            dec=dec->child[2];
        }
        struct FieldList* newField=(struct FieldList *)malloc(sizeof(struct FieldList));
        strcpy(newField->name,dec->child[0]->id);

        newField->type=type;
        newField->next=NULL;
        if(strType->structure==NULL)
            strType->structure=newField;
        else
            strType->structure->next=newField;
        tmp=tmp->child[1];
    }
    insertstr(strType,(yyvsp[-3].n)->id,strHead);
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-4].n); temp[1]=(yyvsp[-3].n); temp[2]=(yyvsp[-2].n); temp[3]= (yyvsp[-1].n); temp[4]= (yyvsp[0].n);(yyval.n) = createNode("StructSpecifier",temp,5);
    (yyval.n)->type=strType;
    }
#line 1546 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 119 "syntax.y" /* yacc.c:1646  */
    {
    //printf("use struct\n");
    if(lookupstr((yyvsp[0].n)->id,strHead)==0){
        printf("Error type 14 at Line %d: structure %s is undefined\n", (yyvsp[0].n)->line, (yyvsp[0].n)->id);
        hasError=1;
    }

    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-1].n); temp[1]=(yyvsp[0].n);(yyval.n) = createNode("StructSpecifier",temp,2);(yyval.n)->type=findstr((yyvsp[0].n)->id,strHead)->type;}
#line 1559 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 129 "syntax.y" /* yacc.c:1646  */
    {
    //printf("VarDec ID: %s\n",$1->id);
    if(lookup((yyvsp[0].n)->id,head)==1||lookupfunc((yyvsp[0].n)->id,funHead)==1||lookupstr((yyvsp[0].n)->id,strHead)==1||lookuparr((yyvsp[0].n)->id,arrHead)==1){ 
        printf("Error type 3 at Line %d: variable %s is redefined\n",(yyvsp[0].n)->line, (yyvsp[0].n)->id);
        hasError=1;
        }
    else{
        //printf("not exist\n");
        // struct symTab *newSym=newSymTab("",$1->id);
        insert("",(yyvsp[0].n)->id,head);
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("VarDec",temp,1);}
    }
#line 1576 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 141 "syntax.y" /* yacc.c:1646  */
    {
    
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-3].n); temp[1]=(yyvsp[-2].n); temp[2]=(yyvsp[-1].n); temp[3]= (yyvsp[0].n); (yyval.n) = createNode("VarDec",temp,4);}
#line 1584 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 144 "syntax.y" /* yacc.c:1646  */
    {
    //printf("FunDec ID: %s\n",$1->id);
    if(lookupfunc((yyvsp[-3].n)->id,funHead)==1){ 
        printf("Error type 4 at Line %d: function %s is redefined\n",(yyvsp[-3].n)->line, (yyvsp[-3].n)->id);
        hasError=1;
        }
    else{
        struct symTab* param[MAX_SIZE];
        int pnum=0;
        struct node* tmp=(struct node *)malloc(sizeof(struct node));
        tmp=(yyvsp[-1].n);
        while(tmp->num==3){
            char *type=tmp->child[0]->child[0]->id;
            char *name=tmp->child[0]->child[1]->id;
            if(findType(name,head)==NULL&&strcmp(findType(name,head)->name,"")==0)
            setType(type,name,head);
            //printf("%s %s\n",type,name);
            param[pnum]=newSymTab(type,name);
            pnum++;
            tmp=tmp->child[2];
        }
        char *type=tmp->child[0]->child[0]->id;
        char *name=tmp->child[0]->child[1]->id;
        if(findType(name,head)==NULL&&strcmp(findType(name,head)->name,"")==0)
        setType(type,name,head);
        //printf("%s %s\n",tmp->child[0]->child[0]->id,tmp->child[0]->child[1]->id);
        param[pnum]=newSymTab(type,name);
        pnum++;
        //printf("Parameter number: %d",pnum);
        insertfunc("",(yyvsp[-3].n)->id,1,pnum,param,funHead);
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-3].n); temp[1]=(yyvsp[-2].n); temp[2]=(yyvsp[-1].n); temp[3]= (yyvsp[0].n); (yyval.n) = createNode("FunDec",temp,4);}
    }
#line 1621 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 176 "syntax.y" /* yacc.c:1646  */
    {
    //printf("ID: %s",$1->id);
    if(lookupfunc((yyvsp[-2].n)->id,funHead)==1){ 
        printf("Error type 4 at Line %d: function %s is redefined\n",(yyvsp[-2].n)->line, (yyvsp[-2].n)->id);
        hasError=1;
        }
    else{
        struct symTab* param[MAX_SIZE];
        insertfunc("",(yyvsp[-2].n)->id,1,0,param,funHead);
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("FunDec",temp,3);}
    }
#line 1637 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 187 "syntax.y" /* yacc.c:1646  */
    {hasError=1;printf("at line %d : Missing RP\n", (yyvsp[-1].n)->line);}
#line 1643 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 188 "syntax.y" /* yacc.c:1646  */
    {hasError=1;printf("at line %d : Missing RP\n", (yyvsp[-2].n)->line);}
#line 1649 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 189 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("VarList",temp,3);}
#line 1655 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 190 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("VarList",temp,1);}
#line 1661 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 191 "syntax.y" /* yacc.c:1646  */
    {hasError=1;printf("at line %d : Missing COMMA\n", (yyvsp[-2].n)->line);}
#line 1667 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 192 "syntax.y" /* yacc.c:1646  */
    {
       struct Type* type=(yyvsp[-1].n)->type;
    //printf("Def %s\n",type->name);
    if(type->category==PRIMITIVE){
    
        //printf("DEF: %s %s %s\n",$1->name,type->name,$2->name);
        struct node* tmp=(struct node *)malloc(sizeof(struct node));
        tmp=(yyvsp[0].n);
        
        if(tmp->num==4){
                //printf("ARRAY");
                struct node* var=(struct node *)malloc(sizeof(struct node));
                struct Type* oldType=(struct Type*)malloc(sizeof(struct Type));
                oldType=type;
                var=tmp;
                while(var->num==4){
                    ////printf("newArray: %s,  %s, %d",oldType->name,var->child[2]->type->name,var->child[2]->ival);
                    oldType=newArrType(oldType,var->child[2]->ival);
                    var=var->child[0];
                }
                insertarr(oldType,var->child[0]->id,arrHead);
                findSym(var->child[0]->id,head)->type=oldType;
                //printf("set Type : %s %s\n",var->child[0]->id,oldType->name);
        }
        else{
            //printf("PRIMITIVE");
            if(findType(tmp->child[0]->id,head)!=NULL&&strcmp(findType(tmp->child[0]->id,head)->name,"")!=0){//match type of Specifier and DecList
                struct Type* type=findType(tmp->child[0]->id,head);
                //printf("Type check: %s, %s\n",$1->id,type->name);
                if(strcmp(type->name,(yyvsp[-1].n)->id)!=0){
                    printf("Error type 5 at Line %d: unmatching type %s and %s\n",(yyvsp[-1].n)->line,(yyvsp[-1].n)->id,type->name);
                    hasError=1;
                }
            }
            else{
                //printf("-----\n");
                setType((yyvsp[-1].n)->type->name,tmp->child[0]->id,head);
            }
            
        }

    }

    else if(type->category==STRUCTURE){

        //printf("STRUCT");
        //printf("DEF: %s %s %s\n",$1->name,type->uName,$2->name);
        struct node* tmp=(struct node *)malloc(sizeof(struct node));
        tmp=(yyvsp[0].n);

        while(tmp->num==3){
            if(tmp->child[0]->child[0]->num==4){
                //printf("STRUCT ARRAY");
                struct node* var=(struct node *)malloc(sizeof(struct node));
                struct Type* oldType=(struct Type*)malloc(sizeof(struct Type));
                oldType=type;
                var=tmp->child[0]->child[0];
                while(var->num==4){
                    oldType=newArrType(oldType,atoi(var->child[3]->id));
                    var=var->child[0];
                }
                insertarr(oldType,var->child[0]->id,arrHead);
                findSym(var->child[0]->id,head)->type=oldType;
                //printf("set Type : %s %s\n",var->child[0]->id,oldType->name);
            }
            else{
            if(findType(tmp->child[0]->id,head)!=NULL&&strcmp(findType(tmp->child[0]->id,head)->name,"")!=0){//match type of Specifier and DecList
                struct Type* type=findType(tmp->child[0]->id,head);
                //printf("Type check: %s, %s\n",$1->id,type->name);
                if(strcmp(type->name,(yyvsp[-1].n)->id)!=0){
                    printf("Error type 5 at Line %d: unmatching type %s and %s\n",(yyvsp[-1].n)->line,(yyvsp[-1].n)->id,type->name);
                    hasError=1;
                }
            }
            else{
                //printf("Set type: %s,%s\n",type->uName,tmp->child[0]->id);
                // setType(type->name,tmp->child[0]->id,head);
                findSym(tmp->child[0]->id,head)->type=findstr(type->uName,strHead)->type;
            }
            }
            tmp=tmp->child[2];
        }

        if(tmp->child[0]->child[0]->num==4){
                //printf("STRUCT ARRAY");
                struct node* var=(struct node *)malloc(sizeof(struct node));
                struct Type* oldType=(struct Type*)malloc(sizeof(struct Type));
                oldType=type;
                var=tmp->child[0]->child[0];
                while(var->num==4){
                    oldType=newArrType(oldType,var->child[2]->ival);
                    var=var->child[0];
                }
                insertarr(oldType,var->child[0]->id,arrHead);
                findSym(var->child[0]->id,head)->type=oldType;
                //printf("set Type : %s %s\n",var->child[0]->id,oldType->name);
            }
        else{
            //printf("Set type: %s,%s\n",type->uName,tmp->child[0]->id);
            findSym(tmp->child[0]->id,head)->type=findstr(type->uName,strHead)->type;
        }
    }
    //printf("finish: %s %s\n",$2->child[0]->id,findType($2->child[0]->id,head)->name);
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-1].n); temp[1]=(yyvsp[0].n);(yyval.n) = createNode("ParamDec",temp,2);}
#line 1776 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 298 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-3].n); temp[1]=(yyvsp[-2].n); temp[2]=(yyvsp[-1].n); temp[3]= (yyvsp[0].n); (yyval.n) = createNode("CompSt",temp,4);}
#line 1782 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 299 "syntax.y" /* yacc.c:1646  */
    {hasError=1;printf("at line %d : Missing RC\n", (yyvsp[-2].n)->line);}
#line 1788 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 300 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-1].n); temp[1]=(yyvsp[0].n);(yyval.n) = createNode("StmtList",temp,2);}
#line 1794 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 301 "syntax.y" /* yacc.c:1646  */
    {(yyval.n) = createLeafNode("StmtList",-1,"");}
#line 1800 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 302 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-1].n); temp[1]=(yyvsp[0].n);(yyval.n) = createNode("Stmt",temp,2);}
#line 1806 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 303 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("Stmt",temp,1);}
#line 1812 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 304 "syntax.y" /* yacc.c:1646  */
    {
    //printf("RETURN\n");
    //printf("RETURN %s",$2->type->name);
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Stmt",temp,3);}
#line 1821 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 308 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-6].n); temp[1]=(yyvsp[-5].n); temp[2]=(yyvsp[-4].n); temp[3]= (yyvsp[-3].n); temp[4]= (yyvsp[-2].n); temp[5]= (yyvsp[-1].n); temp[6] = (yyvsp[0].n);(yyval.n) = createNode("Stmt",temp,7);}
#line 1827 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 309 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-4].n); temp[1]=(yyvsp[-3].n); temp[2]=(yyvsp[-2].n); temp[3]= (yyvsp[-1].n); (yyval.n) = createNode("Stmt",temp,4);}
#line 1833 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 310 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-4].n); temp[1]=(yyvsp[-3].n); temp[2]=(yyvsp[-2].n); temp[3]= (yyvsp[-1].n); temp[4]= (yyvsp[0].n);(yyval.n) = createNode("Stmt",temp,5);}
#line 1839 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 311 "syntax.y" /* yacc.c:1646  */
    {hasError=1;printf("at line %d : Missing RP\n", (yyvsp[-1].n)->line);}
#line 1845 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 312 "syntax.y" /* yacc.c:1646  */
    {hasError=1;printf("at line %d : Missing semicolon \';\'\n",(yyvsp[-1].n)->line);}
#line 1851 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 315 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-1].n); temp[1]=(yyvsp[0].n);(yyval.n) = createNode("DefList",temp,2);}
#line 1857 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 316 "syntax.y" /* yacc.c:1646  */
    {(yyval.n) = createLeafNode("DefList",-1,"");}
#line 1863 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 317 "syntax.y" /* yacc.c:1646  */
    {
    struct Type* type=(yyvsp[-2].n)->type;
    //printf("Def %s\n",type->name);
    if(type->category==PRIMITIVE){
    
        //printf("DEF: %s %s %s\n",$1->name,type->name,$2->name);
        struct node* tmp=(struct node *)malloc(sizeof(struct node));
        tmp=(yyvsp[-1].n);
        
        while(tmp->num==3){
            if(tmp->child[0]->child[0]->num==4){
                //printf("ARRAY");
                struct node* var=(struct node *)malloc(sizeof(struct node));
                struct Type* oldType=(struct Type*)malloc(sizeof(struct Type));
                oldType=type;
                var=tmp->child[0]->child[0];
                while(var->num==4){
                    oldType=newArrType(oldType,atoi(var->child[3]->id));
                    var=var->child[0];
                }
                insertarr(oldType,var->child[0]->id,arrHead);
                findSym(var->child[0]->id,head)->type=oldType;
                //printf("set Type : %s %s\n",var->child[0]->id,oldType->name);
            }
            else{
                //printf("PRIMITIVE");
                if(findType(tmp->child[0]->id,head)!=NULL&&strcmp(findType(tmp->child[0]->id,head)->name,"")!=0){//match type of Specifier and DecList
                    struct Type* type=findType(tmp->child[0]->id,head);
                    //printf("Type check: %s, %s\n",$1->id,type->name);
                    if(strcmp(type->name,(yyvsp[-2].n)->id)!=0){
                        //printf("Error type 5 at Line %d: unmatching type %s and %s\n",$1->line,$1->id,type->name);
                        hasError=1;
                    }
                }
                else{
                    //printf("======\n");
                    setType((yyvsp[-2].n)->id,tmp->child[0]->id,head);
                }
                
            }
            tmp=tmp->child[2];
        }
        
        if(tmp->child[0]->child[0]->num==4){
                //printf("ARRAY");
                struct node* var=(struct node *)malloc(sizeof(struct node));
                struct Type* oldType=(struct Type*)malloc(sizeof(struct Type));
                oldType=type;
                var=tmp->child[0]->child[0];
                while(var->num==4){
                    ////printf("newArray: %s,  %s, %d",oldType->name,var->child[2]->type->name,var->child[2]->ival);
                    oldType=newArrType(oldType,var->child[2]->ival);
                    var=var->child[0];
                }
                insertarr(oldType,var->child[0]->id,arrHead);
                findSym(var->child[0]->id,head)->type=oldType;
                //printf("set Type : %s %s\n",var->child[0]->id,oldType->name);
        }
        else{
            //printf("PRIMITIVE");
            if(findType(tmp->child[0]->id,head)!=NULL&&strcmp(findType(tmp->child[0]->id,head)->name,"")!=0){//match type of Specifier and DecList
                struct Type* type=findType(tmp->child[0]->id,head);
                //printf("Type check: %s, %s\n",$1->id,type->name);
                if(strcmp(type->name,(yyvsp[-2].n)->id)!=0){
                    printf("Error type 5 at Line %d: unmatching type %s and %s\n",(yyvsp[-2].n)->line,(yyvsp[-2].n)->id,type->name);
                    hasError=1;
                }
            }
            else{
                //printf("++++++\n");
                setType((yyvsp[-2].n)->id,tmp->child[0]->id,head);
            }
            
        }

    }

    else if(type->category==STRUCTURE){

        //printf("STRUCT");
        //printf("DEF: %s %s %s\n",$1->name,type->uName,$2->name);
        struct node* tmp=(struct node *)malloc(sizeof(struct node));
        tmp=(yyvsp[-1].n);

        while(tmp->num==3){
            if(tmp->child[0]->child[0]->num==4){
                //printf("STRUCT ARRAY");
                struct node* var=(struct node *)malloc(sizeof(struct node));
                struct Type* oldType=(struct Type*)malloc(sizeof(struct Type));
                oldType=type;
                var=tmp->child[0]->child[0];
                while(var->num==4){
                    oldType=newArrType(oldType,atoi(var->child[3]->id));
                    var=var->child[0];
                }
                insertarr(oldType,var->child[0]->id,arrHead);
                findSym(var->child[0]->id,head)->type=oldType;
                //printf("set Type : %s %s\n",var->child[0]->id,oldType->name);
            }
            else{
            if(findType(tmp->child[0]->id,head)!=NULL&&strcmp(findType(tmp->child[0]->id,head)->name,"")!=0){//match type of Specifier and DecList
                struct Type* type=findType(tmp->child[0]->id,head);
                //printf("Type check: %s, %s\n",$1->id,type->name);
                if(strcmp(type->name,(yyvsp[-2].n)->id)!=0){
                    printf("Error type 5 at Line %d: unmatching type %s and %s\n",(yyvsp[-2].n)->line,(yyvsp[-2].n)->id,type->name);
                    hasError=1;
                }
            }
            else{
                //printf("Set type: %s,%s\n",type->uName,tmp->child[0]->id);
                // setType(type->name,tmp->child[0]->id,head);
                findSym(tmp->child[0]->id,head)->type=findstr(type->uName,strHead)->type;
            }
            }
            tmp=tmp->child[2];
        }

        if(tmp->child[0]->child[0]->num==4){
                //printf("STRUCT ARRAY");
                struct node* var=(struct node *)malloc(sizeof(struct node));
                struct Type* oldType=(struct Type*)malloc(sizeof(struct Type));
                oldType=type;
                var=tmp->child[0]->child[0];
                while(var->num==4){
                    oldType=newArrType(oldType,var->child[2]->ival);
                    var=var->child[0];
                }
                insertarr(oldType,var->child[0]->id,arrHead);
                findSym(var->child[0]->id,head)->type=oldType;
                //printf("set Type : %s %s\n",var->child[0]->id,oldType->name);
            }
        else{
            //printf("Set type: %s,%s\n",type->uName,tmp->child[0]->id);
            findSym(tmp->child[0]->id,head)->type=findstr(type->uName,strHead)->type;
        }
    }
    //printf("%d",lookup($2->name,head));
    // if(lookup($2->name,head)==1){printf("exist");hasError=1;}
    // else{
    //     printf("not exist");
    //     struct symTab *newSym=newSymTab("",$1->name,tail);
    //     tail=newSym;
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Def",temp,3);
    }
#line 2012 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 461 "syntax.y" /* yacc.c:1646  */
    {hasError=1;printf("at line %d : Missing SEMI\n",(yyvsp[-2].n)->line);}
#line 2018 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 462 "syntax.y" /* yacc.c:1646  */
    {
    //printf("DecList: Dec\n");
     struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("DecList",temp,1);}
#line 2026 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 465 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("DecList",temp,3);}
#line 2032 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 466 "syntax.y" /* yacc.c:1646  */
    {hasError=1;printf("at line %d : Missing COMMA \n",(yyvsp[-1].n)->line);}
#line 2038 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 467 "syntax.y" /* yacc.c:1646  */
    {
    //printf("Dec: VarDec\n");
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("Dec",temp,1);}
#line 2046 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 470 "syntax.y" /* yacc.c:1646  */
    {
    // if(strcmp($1->type->name,$3->type->name)==0){
    //     printf("Error type 5 at Line %d: unmatching type %s and %s\n",$1->line,$1->type->name,$3->type->name);
    //     hasError=1;   
    // }

    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Dec",temp,3); 
    //printf("))))))\n");
    setType((yyvsp[0].n)->type->name,(yyvsp[-2].n)->id,head);}
#line 2060 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 479 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n);temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Dec",temp,3);}
#line 2066 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 480 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n);  (yyval.n) = createNode("Dec",temp,1);}
#line 2072 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 482 "syntax.y" /* yacc.c:1646  */
    { 
     //printf("%s ASSIGN %s\n",$1->type->name,$3->type->name);
     //printf("%s",$1->id);
    if(strcmp((yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",(yyvsp[-2].n)->line,(yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name);
        hasError=1;   
    }
    else if((yyvsp[-2].n)->id==NULL){
        printf("Error type 6 at Line %d: rvalue on the left side\n",(yyvsp[-2].n)->line);
        hasError=1;
    }
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);}
#line 2089 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 494 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);}
#line 2095 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 495 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);}
#line 2101 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 496 "syntax.y" /* yacc.c:1646  */
    {
    if(strcmp((yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",(yyvsp[-2].n)->line,(yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name);
        hasError=1;   
    }
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3); (yyval.n)->type=newType("int");}
#line 2112 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 502 "syntax.y" /* yacc.c:1646  */
    {
    if(strcmp((yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",(yyvsp[-2].n)->line,(yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name);
        hasError=1;   
    }
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);(yyval.n)->type=newType("int");}
#line 2123 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 508 "syntax.y" /* yacc.c:1646  */
    {
    if(strcmp((yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",(yyvsp[-2].n)->line,(yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name);
        hasError=1;   
    }
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);(yyval.n)->type=newType("int");}
#line 2134 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 514 "syntax.y" /* yacc.c:1646  */
    {
    if(strcmp((yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",(yyvsp[-2].n)->line,(yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name);
        hasError=1;   
    }
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);(yyval.n)->type=newType("int");}
#line 2145 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 520 "syntax.y" /* yacc.c:1646  */
    {
    if(strcmp((yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",(yyvsp[-2].n)->line,(yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name);
        hasError=1;   
    }
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);(yyval.n)->type=newType("int");}
#line 2156 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 526 "syntax.y" /* yacc.c:1646  */
    {
    if(strcmp((yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",(yyvsp[-2].n)->line,(yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name);
        hasError=1;   
    }
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);(yyval.n)->type=newType("int");}
#line 2167 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 532 "syntax.y" /* yacc.c:1646  */
    {
    struct Type* type1=(yyvsp[-2].n)->type;
    struct Type* type2=(yyvsp[0].n)->type;
    if(type1->category!=type2->category){
        printf("Error type 7 at Line %d: unmatching operands between %s and %s\n",(yyvsp[-2].n)->line,(yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name);
        hasError=1;    
        struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);(yyval.n)->type=newType("error");
    }   
    else if(strcmp((yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",(yyvsp[-2].n)->line,(yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name);
        hasError=1;  
        struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);(yyval.n)->type=newType("error"); 
    }
    else{
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);}
}
#line 2188 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 548 "syntax.y" /* yacc.c:1646  */
    {
    struct Type* type1=(yyvsp[-2].n)->type;
    struct Type* type2=(yyvsp[0].n)->type;
    if(type1->category!=type2->category){
        printf("Error type 7 at Line %d: unmatching operands between %s and %s\n",(yyvsp[-2].n)->line,(yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name);
        hasError=1;    
        struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);(yyval.n)->type=newType("error");
    }   
    else if(strcmp((yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",(yyvsp[-2].n)->line,(yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name);
        hasError=1;  
        struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);(yyval.n)->type=newType("error"); 
    }
    else{
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);}
}
#line 2209 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 564 "syntax.y" /* yacc.c:1646  */
    {
    struct Type* type1=(yyvsp[-2].n)->type;
    struct Type* type2=(yyvsp[0].n)->type;
    if(type1->category!=type2->category){
        printf("Error type 7 at Line %d: unmatching operands between %s and %s\n",(yyvsp[-2].n)->line,(yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name);
        hasError=1;    
        struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);(yyval.n)->type=newType("error");
    }   
    else if(strcmp((yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",(yyvsp[-2].n)->line,(yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name);
        hasError=1;  
        struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);(yyval.n)->type=newType("error"); 
    }
    else{
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);}
}
#line 2230 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 580 "syntax.y" /* yacc.c:1646  */
    {
    struct Type* type1=(yyvsp[-2].n)->type;
    struct Type* type2=(yyvsp[0].n)->type;
    if(type1->category!=type2->category){
        printf("Error type 7 at Line %d: unmatching operands between %s and %s\n",(yyvsp[-2].n)->line,(yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name);
        hasError=1;    
        struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);(yyval.n)->type=newType("error");
    }   
    else if(strcmp((yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",(yyvsp[-2].n)->line,(yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name);
        hasError=1;  
        struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);(yyval.n)->type=newType("error"); 
    }
    else{
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);}}
#line 2250 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 595 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);(yyval.n)->type=(yyvsp[-1].n)->type;}
#line 2256 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 596 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-1].n); temp[1]=(yyvsp[0].n);(yyval.n) = createNode("Exp",temp,2); (yyval.n)->type=(yyvsp[0].n)->type;}
#line 2262 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 597 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-1].n); temp[1]=(yyvsp[0].n);(yyval.n) = createNode("Exp",temp,2);(yyval.n)->type=(yyvsp[0].n)->type;}
#line 2268 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 598 "syntax.y" /* yacc.c:1646  */
    {
    //printf("func use\n");
    if(lookupfunc((yyvsp[-3].n)->id,funHead)==0){
        printf("Error type 11 at Line %d: function %s is used without definition\n",(yyvsp[-3].n)->line,(yyvsp[-3].n)->id);
        hasError=1; 
        struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-3].n); temp[1]=(yyvsp[-2].n); temp[2]=(yyvsp[-1].n); temp[3]= (yyvsp[0].n); (yyval.n) = createNode("Exp",temp,4);(yyval.n)->type=newType("error");       
    }
    else {
        struct funTab* func= findfunc((yyvsp[-3].n)->id,funHead);
        struct node* tmp=(struct node *)malloc(sizeof(struct node));
        tmp=(yyvsp[-1].n);
        int paraNum=0;
        int flag=1;
        while(tmp->num==3){
            //printf("para: %d %d",paraNum, func->pnum);
            
            //printf("type: %s, %s\n",tmp->child[0]->type->name,func->param[paraNum]->type->name);
            if(strcmp(tmp->child[0]->type->name,func->param[paraNum]->type->name)!=0){
                printf("Error type 9 at Line %d: function %s requires %s but recieve %s\n",(yyvsp[-3].n)->line,(yyvsp[-3].n)->id,func->param[paraNum]->type->name,tmp->child[0]->type->name);
                hasError=1;
                flag=0;
                break;
            }
            paraNum++;
            if(paraNum==func->pnum){
                printf("Error type 9 at Line %d: function %s recieves wrong number of args \n",(yyvsp[-3].n)->line,(yyvsp[-3].n)->id);
                    hasError=1;
                flag=0;
                break;
            }
            tmp=tmp->child[2];
        }
        //printf("type: %s, %s\n",tmp->child[0]->type->name,func->param[paraNum]->type->name);
        if(flag!=0){
            if(paraNum+1!=func->pnum){
                    printf("Error type 9 at Line %d: function %s recieves wrong number of args \n",(yyvsp[-3].n)->line,(yyvsp[-3].n)->id);
                    hasError=1;
                    flag=0;
            }
            else if(strcmp(tmp->child[0]->type->name,func->param[paraNum]->type->name)!=0){
                printf("Error type 9 at Line %d: function %s requires %s but recieve %s\n",(yyvsp[-3].n)->line,(yyvsp[-3].n)->id,func->param[paraNum]->type->name,tmp->child[0]->type->name);
                hasError=1;
                flag=0;
            }
        }
        
        struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-3].n); temp[1]=(yyvsp[-2].n); temp[2]=(yyvsp[-1].n); temp[3]= (yyvsp[0].n); (yyval.n) = createNode("Exp",temp,4);
        if(flag)
            (yyval.n)->type=func->type;
        else
            (yyval.n)->type=newType("error");
    }
    }
#line 2326 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 651 "syntax.y" /* yacc.c:1646  */
    {
    //printf("Function use\n");
    if(lookupfunc((yyvsp[-2].n)->id,funHead)==0){
        printf("Error type 11 at Line %d: function %s is used without definition\n",(yyvsp[-2].n)->line,(yyvsp[-2].n)->id);
        hasError=1;        
        struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);(yyval.n)->type=newType("error");
    }
    else if(findfunc((yyvsp[-2].n)->id,funHead)->pnum!=0){
        printf("Error type 9 at Line %d: function %s requires %d parameters but recieve 0",(yyvsp[-2].n)->line,(yyvsp[-2].n)->id,findfunc((yyvsp[-2].n)->id,funHead)->pnum);
        hasError=1;
        struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);(yyval.n)->type=newType("error");
    }
    else{
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);(yyval.n)->type=findfunc((yyvsp[-2].n)->id,funHead)->type;}
    }
#line 2346 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 666 "syntax.y" /* yacc.c:1646  */
    {
    //printf("%s\n",$1->type->name);
    if(strcmp((yyvsp[-1].n)->type->name,"int")!=0){
        printf("Error type 12 at Line %d: array indexing with non-integer value\n",(yyvsp[-3].n)->line);
        hasError=1;
    }
    else if((yyvsp[-3].n)->type->category!=ARRAY){
        printf("Error type 10 at Line %d: apply indexing operator to non-array variable\n",(yyvsp[-3].n)->line);
        hasError=1;
        struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-3].n); temp[1]=(yyvsp[-2].n); temp[2]=(yyvsp[-1].n); temp[3]= (yyvsp[0].n); (yyval.n) = createNode("Exp",temp,4);(yyval.n)->type=newType("error");
    }
    else{
    //printf("type is %s\n",$1->type->name);
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-3].n); temp[1]=(yyvsp[-2].n); temp[2]=(yyvsp[-1].n); temp[3]= (yyvsp[0].n); (yyval.n) = createNode("Exp",temp,4);(yyval.n)->type=(yyvsp[-3].n)->type->array->base;}
}
#line 2366 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 681 "syntax.y" /* yacc.c:1646  */
    {
    //printf("%s dot %s\n",$1->type->name,findType($3->id,head)->name);
    if(lookup((yyvsp[0].n)->id,head)==0){
        printf("Error type 14 at Line %d: no such variable %s\n",(yyvsp[-2].n)->line,(yyvsp[0].n)->id);
        hasError =1;
        struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);(yyval.n)->type=newType("error");
    }
    else if((yyvsp[-2].n)->type->category!=STRUCTURE){
        printf("Error type 13 at Line %d: non-structure variable\n",(yyvsp[-2].n)->line);
        hasError =1;
    }
    else{
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);(yyval.n)->type=findType((yyvsp[0].n)->id,head);}}
#line 2384 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 694 "syntax.y" /* yacc.c:1646  */
    {
    //printf("ID: %s %s\n",$1->id,findType($1->id,head)->name);
    if(lookup((yyvsp[0].n)->id,head)==0){ 
        printf("Error type 1 at Line %d: variable %s is used without definition\n",(yyvsp[0].n)->line,(yyvsp[0].n)->id);
        hasError=1;
        struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,1);(yyval.n)->type=newType("error");
        }
    else{
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,1);(yyval.n)->type=findType((yyvsp[0].n)->id,head);}
}
#line 2399 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 704 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,1);(yyval.n)->type=newType("int");}
#line 2405 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 705 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,1);(yyval.n)->type=newType("float");}
#line 2411 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 706 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,1);(yyval.n)->type=newType("char");}
#line 2417 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 707 "syntax.y" /* yacc.c:1646  */
    {hasError=1;printf("at line %d : Missing RP\n", (yyvsp[-3].n)->line);}
#line 2423 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 708 "syntax.y" /* yacc.c:1646  */
    {hasError=1;printf("at line %d : Missing RP\n", (yyvsp[-2].n)->line);}
#line 2429 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 709 "syntax.y" /* yacc.c:1646  */
    {hasError=1;printf("at line %d : Missing RP\n", (yyvsp[-1].n)->line);}
#line 2435 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 710 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);}
#line 2441 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 711 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,1);}
#line 2447 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 712 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Args",temp,3);}
#line 2453 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 713 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("Args",temp,1);}
#line 2459 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 714 "syntax.y" /* yacc.c:1646  */
    {hasError=1;printf("at line %d : COMMA instead of SEMI\n", (yyvsp[-2].n)->line);}
#line 2465 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 715 "syntax.y" /* yacc.c:1646  */
    {hasError=1;printf("at line %d : Missing COMMA\n", (yyvsp[-1].n)->line);}
#line 2471 "syntax.tab.c" /* yacc.c:1646  */
    break;


#line 2475 "syntax.tab.c" /* yacc.c:1646  */
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
#line 717 "syntax.y" /* yacc.c:1906  */


char* substr(const char* str, unsigned start, unsigned end){
    unsigned n=end-start;
    static char stbuf[256];
    strncpy(stbuf,str+start,n);
    stbuf[n]=0;
    return stbuf;
}


int main(int argc, char **argv){
    head=(struct symTab*)malloc(sizeof(struct symTab));
    head->name="header";
    head->next=NULL;
    // tail=(struct symTab*)malloc(sizeof(struct symTab));
    // tail=head;
    // struct symTab* newSym=newSymTab("","test");
    // insert("","i",head);

    // if(lookup("i",head)==1){
    //     printf("i exist\n");
    // }
    // else{
    //     struct symTab* temp=(struct symTab*)malloc(sizeof(struct symTab));
    //     temp=head;
    //     while(temp->next!=NULL){
    //         printf("%s %s\n",temp->type,temp->name);
    //         temp=temp->next;
    //     }
    // }
    funHead=(struct funTab*)malloc(sizeof(struct funTab));
    funHead->name="header";
    funHead->next=NULL;
    arrHead=(struct arrTab*)malloc(sizeof (struct arrTab));
    arrHead->name="header";
    arrHead->next=NULL;

    strHead=(struct strTab*)malloc(sizeof(struct strTab));
    strHead->name="header";
    strHead->next=NULL;
    //lookup("test",head);
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(-1);
    }
    else if(!(yyin = fopen(argv[1], "r"))) {
        perror(argv[1]);
        exit(-1);
    }
    printf("%s",argv[1]);
    
    char* filepath=argv[1];
    char* fileExt;
    char* ptr,c='.';
    ptr = strrchr(filepath,c);
    int pos = ptr- filepath;
    fileExt=substr(filepath,pos+1,strlen(filepath));
    printf("%s",fileExt);
    char* outpath="./test/output.out";
    if(strcmp(fileExt,"spl")==0){
        int i= strlen(filepath);
        char* fn1=filepath+i;
        while(fn1>filepath){
            if(*fn1=='.'){
                *fn1=0;
                break;
            }
            fn1--;
        }
        outpath=strcat(filepath,".out");
    }
    printf("out %s",outpath);
    if(freopen(outpath,"w",stdout)==NULL)
        printf("redirect fail");
    
    yyparse();
    return 0;
}
