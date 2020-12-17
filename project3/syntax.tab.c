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
    struct varTab* varHead;
    struct resTab* resHead;
    int varnum = 1;
    int resnum = 1;
    int labelnum = 0;
    int debug=0;

#line 85 "syntax.tab.c" /* yacc.c:339  */

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
    RB = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 20 "syntax.y" /* yacc.c:355  */

    struct node* n;
    double d;

#line 167 "syntax.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 184 "syntax.tab.c" /* yacc.c:358  */

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
#define YYLAST   397

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  137

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

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
      35,    36
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    41,    41,    44,    45,    46,    49,    50,   101,   112,
     115,   116,   117,   159,   169,   193,   196,   259,   275,   276,
     277,   383,   421,   424,   425,   429,   433,   444,   469,   489,
     514,   515,   516,   660,   663,   665,   671,   682,   683,   686,
     706,   709,   711,   727,   742,   757,   772,   787,   802,   833,
     863,   894,   924,   928,   929,   930,  1033,  1082,  1097,  1110,
    1131,  1168,  1169,  1170,  1171,  1172,  1173,  1174,  1175,  1176,
    1177,  1178
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
  "$accept", "Program", "ExtDefList", "ExtDef", "ExtDecList", "Specifier",
  "StructSpecifier", "VarDec", "FunDec", "VarList", "ParamDec", "CompSt",
  "StmtList", "Stmt", "DefList", "Def", "DecList", "Dec", "Exp", "Args", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291
};
# endif

#define YYPACT_NINF -78

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-78)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,   -78,     1,    24,   -78,    11,    41,   -78,    12,   -78,
     -78,    21,   -78,    38,    30,    22,    11,    31,   -78,    51,
      58,    11,   -78,    -2,    26,    11,   -78,    51,    34,    46,
     -78,   -78,    52,   131,    56,    37,    72,    74,   -78,   -78,
      63,   -78,    11,   -78,   -78,   -78,   -78,    60,   -78,    68,
      69,   366,   366,   366,   366,   -78,    67,   131,   174,   366,
     366,   -78,    -2,   -78,   123,   366,   366,   197,   333,   343,
      57,   -78,   -78,   366,    96,   -78,   366,   366,   366,   366,
     366,   366,   366,   366,   366,   366,   366,   366,   366,   366,
     266,   266,   -78,   -78,   -78,    90,     9,   220,   243,   -78,
     -78,   -78,   266,   -78,   266,   266,   266,   266,   266,   266,
     266,   333,   333,   343,   343,   311,   289,   151,   366,   366,
     366,   366,   102,   -78,   -78,   131,   131,   -78,   121,   -78,
     333,   -78,   112,   -78,   -78,   131,   -78
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    10,     0,     0,     2,     4,     0,    11,    13,     1,
       3,    14,     6,     0,     8,     0,    31,     0,     5,     0,
       0,    31,     7,     0,     0,    31,    17,     0,     0,    19,
      14,     9,     0,    23,    38,    35,     0,    33,    12,    30,
      20,    16,     0,    15,    60,    61,    62,    59,    67,     0,
       0,     0,     0,     0,     0,    25,     0,    23,     0,     0,
       0,    32,     0,    18,     0,     0,     0,     0,    53,    54,
       0,    21,    22,     0,     0,    24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,    36,    34,    64,    56,    69,     0,     0,     0,    26,
      65,    52,    66,    58,    39,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    40,    41,     0,    67,     0,
       0,     0,     0,    63,    55,     0,     0,    57,     0,    68,
      49,    71,    28,    29,    70,     0,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -78,   -78,   126,   -78,   113,     6,   -78,   -11,   -78,    91,
     -78,   124,    83,   -76,    -4,   -78,    80,   -78,   -51,   -77
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    13,    23,     7,    14,    15,    28,
      29,    55,    56,    57,    24,    25,    36,    37,    58,    96
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      67,    68,    69,    70,    30,    34,     6,     8,    90,    91,
     123,     6,    35,    95,    97,    98,    40,    33,   122,     1,
       2,    39,   102,    27,     9,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,     1,
       2,   124,   128,   129,    95,    16,    19,    11,    27,   132,
     133,    35,    17,    18,    60,    21,    12,    30,   100,   136,
      38,    32,    42,    26,    73,    20,    41,   102,    95,    95,
     130,    74,    20,    59,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    61,    43,   101,
      62,    64,    89,    44,    45,    46,    47,   118,    20,    65,
      66,    71,   103,   131,    74,   119,   120,    76,    77,    78,
      79,    80,    81,    82,    83,   121,    85,    86,    87,    88,
      53,    54,   134,   135,    93,    89,    44,    45,    46,    47,
      48,    10,    31,    63,    44,    45,    46,    47,    48,    22,
      72,    49,    92,    50,    51,     0,     0,     0,    52,     0,
       0,     0,     0,    53,    54,    94,    52,     0,    73,     0,
       0,    53,    54,     0,    21,    74,     0,     0,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    73,     0,     0,     0,     0,    89,   127,    74,    75,
       0,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    73,     0,     0,     0,     0,    89,
       0,    74,    99,     0,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    73,     0,     0,
       0,     0,    89,     0,    74,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      73,     0,   125,     0,     0,    89,     0,    74,     0,     0,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    73,     0,   126,     0,     0,    89,     0,
      74,     0,     0,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    73,     0,     0,     0,
       0,    89,     0,    74,     0,     0,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    73,     0,
       0,     0,     0,     0,    89,    74,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,     0,
      73,     0,     0,     0,     0,     0,    89,    74,     0,     0,
      73,    77,    78,    79,    80,    81,    82,    74,     0,    85,
      86,    77,    78,    79,    80,    81,    82,     0,    89,    44,
      45,    46,    47,    48,     0,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,     0,     0,     0,     0,    53,    54
};

static const yytype_int16 yycheck[] =
{
      51,    52,    53,    54,     6,     7,     0,     6,    59,    60,
       1,     5,    23,    64,    65,    66,    27,    21,    95,     8,
       9,    25,    73,    17,     0,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     8,
       9,    32,   119,   120,    95,    33,    16,     6,    42,   125,
     126,    62,    31,    15,    17,    33,    15,     6,     1,   135,
      34,     3,    16,    32,     7,    35,    32,   118,   119,   120,
     121,    14,    35,    17,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    15,    36,    32,
      16,    31,    35,     3,     4,     5,     6,     7,    35,    31,
      31,    34,     6,     1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     1,    11,     1,    35,     3,     4,     5,     6,
       7,     5,    19,    42,     3,     4,     5,     6,     7,    15,
      57,    10,    62,    12,    13,    -1,    -1,    -1,    25,    -1,
      -1,    -1,    -1,    30,    31,    32,    25,    -1,     7,    -1,
      -1,    30,    31,    -1,    33,    14,    -1,    -1,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     7,    -1,    -1,    -1,    -1,    35,    36,    14,    15,
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     7,    -1,    -1,    -1,    -1,    35,
      -1,    14,    15,    -1,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,     7,    -1,    -1,
      -1,    -1,    35,    -1,    14,    -1,    -1,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
       7,    -1,    32,    -1,    -1,    35,    -1,    14,    -1,    -1,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     7,    -1,    32,    -1,    -1,    35,    -1,
      14,    -1,    -1,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,     7,    -1,    -1,    -1,
      -1,    35,    -1,    14,    -1,    -1,    -1,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,     7,    -1,
      -1,    -1,    -1,    -1,    35,    14,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
       7,    -1,    -1,    -1,    -1,    -1,    35,    14,    -1,    -1,
       7,    18,    19,    20,    21,    22,    23,    14,    -1,    26,
      27,    18,    19,    20,    21,    22,    23,    -1,    35,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    -1,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    -1,    -1,    -1,    -1,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    38,    39,    40,    42,    43,     6,     0,
      39,     6,    15,    41,    44,    45,    33,    31,    15,    16,
      35,    33,    48,    42,    51,    52,    32,    42,    46,    47,
       6,    41,     3,    51,     7,    44,    53,    54,    34,    51,
      44,    32,    16,    36,     3,     4,     5,     6,     7,    10,
      12,    13,    25,    30,    31,    48,    49,    50,    55,    17,
      17,    15,    16,    46,    31,    31,    31,    55,    55,    55,
      55,    34,    49,     7,    14,    15,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    35,
      55,    55,    53,     1,    32,    55,    56,    55,    55,    15,
       1,    32,    55,     6,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,     7,    15,
      16,    25,    56,     1,    32,    32,    32,    36,    56,    56,
      55,     1,    50,    50,     1,    11,    50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    40,    41,    41,
      42,    42,    43,    43,    44,    44,    45,    45,    46,    46,
      47,    48,    49,    49,    50,    50,    50,    50,    50,    50,
      51,    51,    52,    53,    53,    54,    54,    54,    54,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    56,    56,
      56,    56
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     1,     3,
       1,     1,     5,     2,     1,     4,     4,     3,     3,     1,
       2,     4,     2,     0,     2,     1,     3,     7,     5,     5,
       2,     0,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     4,     3,     4,     3,     1,
       1,     1,     1,     4,     3,     3,     3,     1,     3,     1,
       4,     3
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
#line 41 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("Program",temp,1); 
//if(!hasError)travesal($$,0);
}
#line 1403 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 44 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-1].n); temp[1]=(yyvsp[0].n);(yyval.n) = createNode("ExtDefList",temp,2);}
#line 1409 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 45 "syntax.y" /* yacc.c:1646  */
    {(yyval.n) = createLeafNode("ExtDefList",-1,"");}
#line 1415 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 46 "syntax.y" /* yacc.c:1646  */
    { 
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("ExtDef",temp,3);}
#line 1422 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 49 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-1].n); temp[1]=(yyvsp[0].n);(yyval.n) = createNode("ExtDef",temp,2);}
#line 1428 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 50 "syntax.y" /* yacc.c:1646  */
    {
    //project3 GENERATE
    if(debug)printf("Begin\n");
    printf("%s",(yyvsp[0].n)->code);
    // struct node*compSt=(struct node *)malloc(sizeof(struct node));
    // compSt = $3->child[1];
    // while(compSt->num>0){
    // struct node*dec=(struct node *)malloc(sizeof(struct node));
    // dec=compSt->child[0]->child[1];
    // while(dec->num==3){
    //     //if(strcmp("",dec->child[0]->code))
    //     if(debug)  printf("def %s",dec->child[0]->code);
    //     else printf("%s",dec->child[0]->code);
    //     dec=dec->child[2];
    // }
    // dec=dec->child[0];
    // //if(strcmp("",dec->child[0]->code))
    // if(debug)  printf("def %s",dec->code);
    // else printf("%s",dec->code);
    // compSt=compSt->child[1];
    // }
    // compSt = $3->child[2];
    // while(compSt->num==2){
    //     if(debug)printf("stmt: %s",compSt->child[0]->code);
    //     else printf("%s",compSt->child[0]->code);
    //     compSt=compSt->child[1];
    // }
    // if(debug){
    //     struct resTab* res=(struct resTab*)malloc(sizeof(struct resTab));
    //     res = resHead;
    //     while(res->next!=NULL){
    //         printf("%s,%s,%s,%s\n",res->opera,res->var1,res->var2,res->var3);
    //         res = res->next;
    //     }
    // }

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
#line 1484 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 101 "syntax.y" /* yacc.c:1646  */
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
#line 1499 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 112 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("ExtDecList",temp,3);}
#line 1505 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 115 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("Specifier",temp,1);(yyval.n)->type=newType((yyvsp[0].n)->id);}
#line 1511 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 116 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("Specifier",temp,1);(yyval.n)->type=(yyvsp[0].n)->type;}
#line 1517 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 117 "syntax.y" /* yacc.c:1646  */
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
#line 1564 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 159 "syntax.y" /* yacc.c:1646  */
    {
    //printf("use struct\n");
    if(lookupstr((yyvsp[0].n)->id,strHead)==0){
        printf("Error type 14 at Line %d: structure %s is undefined\n", (yyvsp[0].n)->line, (yyvsp[0].n)->id);
        hasError=1;
    }

    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-1].n); temp[1]=(yyvsp[0].n);(yyval.n) = createNode("StructSpecifier",temp,2);(yyval.n)->type=findstr((yyvsp[0].n)->id,strHead)->type;}
#line 1577 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 169 "syntax.y" /* yacc.c:1646  */
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
    //project3
    //struct varTab* tmp= (struct varTab*)malloc(sizeof(struct varTab));
    newVarTab((yyvsp[0].n)->id,varHead);
    varnum++;
    // if(tmp!=NULL){
    //     printf("exist\n");
    // }
    char* a=(char*)malloc(10);
    sprintf(a,"v%d",lookupVar((yyvsp[0].n)->id,varHead));
    //printf("change place %s\n",a);
    (yyval.n)->place=a;
    (yyval.n)->code = "";
    }
#line 1606 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 193 "syntax.y" /* yacc.c:1646  */
    {
    
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-3].n); temp[1]=(yyvsp[-2].n); temp[2]=(yyvsp[-1].n); temp[3]= (yyvsp[0].n); (yyval.n) = createNode("VarDec",temp,4);}
#line 1614 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 196 "syntax.y" /* yacc.c:1646  */
    {
    //project3 function
    printf("FUNCTION %s :\n",(yyvsp[-3].n)->id);
    //TODO parameters
    struct node* para=(struct node *)malloc(sizeof(struct node));
    para = (yyvsp[-1].n);
    while (para->num==3){
        if(lookupVar(para->child[0]->child[1]->child[0]->id,varHead)){
            printf("PARAM v%d\n",lookupVar(para->child[0]->child[1]->child[0]->id,varHead));
        }
        else{
            printf("PARAM v%d\n",varnum);
            varnum++;
            newVarTab(para->child[0]->child[1]->child[0]->id,varHead);
        }
        if(debug) printf("%s",para->child[0]->child[1]->child[0]->id);
        
        para = para->child[2];
    }
    if(para->num!=0){
        if(lookupVar(para->child[0]->child[1]->child[0]->id,varHead)){
            printf("PARAM v%d\n",lookupVar(para->child[0]->child[1]->child[0]->id,varHead));
        }
        else{
            printf("PARAM v%d\n",varnum);
            varnum++;
            newVarTab(para->child[0]->child[1]->child[0]->id,varHead);
        }
        
        if(debug) printf("%s\n",para->child[0]->child[1]->child[0]->id);

    }
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
        insertfunc("int",(yyvsp[-3].n)->id,1,pnum,param,funHead);
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-3].n); temp[1]=(yyvsp[-2].n); temp[2]=(yyvsp[-1].n); temp[3]= (yyvsp[0].n); (yyval.n) = createNode("FunDec",temp,4);}
    }
#line 1682 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 259 "syntax.y" /* yacc.c:1646  */
    {
    //project3 function
    printf("FUNCTION %s :\n",(yyvsp[-2].n)->id);


    //printf("ID: %s",$1->id);
    if(lookupfunc((yyvsp[-2].n)->id,funHead)==1){ 
        printf("Error type 4 at Line %d: function %s is redefined\n",(yyvsp[-2].n)->line, (yyvsp[-2].n)->id);
        hasError=1;
        }
    else{
        struct symTab* param[MAX_SIZE];
        insertfunc("int",(yyvsp[-2].n)->id,1,0,param,funHead);
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("FunDec",temp,3);}
    }
#line 1702 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 275 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("VarList",temp,3);}
#line 1708 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 276 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("VarList",temp,1);}
#line 1714 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 277 "syntax.y" /* yacc.c:1646  */
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
#line 1823 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 383 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-3].n); temp[1]=(yyvsp[-2].n); temp[2]=(yyvsp[-1].n); temp[3]= (yyvsp[0].n); (yyval.n) = createNode("CompSt",temp,4);
//TODO
char code1[10000]="";
char code2[10000]="";

struct node*compSt=(struct node *)malloc(sizeof(struct node));
compSt = (yyvsp[-2].n);
while(compSt->num>0){
struct node*dec=(struct node *)malloc(sizeof(struct node));
dec=compSt->child[0]->child[1];
while(dec->num==3){
    //if(strcmp("",dec->child[0]->code))
    //if(debug)  printf("def %s",dec->child[0]->code);
    //else printf("%s",dec->child[0]->code);
    strcat(code1,dec->child[0]->code);
    dec=dec->child[2];
}
dec=dec->child[0];
//if(strcmp("",dec->child[0]->code))
//if(debug)  printf("def %s",dec->code);
//else printf("%s",dec->code);
strcat(code1,dec->code);
compSt=compSt->child[1];
}
compSt = (yyvsp[-1].n);
while(compSt->num==2){
    //if(debug)printf("stmt: %s",compSt->child[0]->code);
    //else printf("%s",compSt->child[0]->code);
    strcat(code2,compSt->child[0]->code);
    compSt=compSt->child[1];
}

char *code =(char*)malloc(100000);

sprintf(code,"%s%s",code1,code2);
(yyval.n)->code = code;

}
#line 1866 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 421 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-1].n); temp[1]=(yyvsp[0].n);(yyval.n) = createNode("StmtList",temp,2);
//printf("Stmt: %s\n",$1->code);
}
#line 1874 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 424 "syntax.y" /* yacc.c:1646  */
    {(yyval.n) = createLeafNode("StmtList",-1,"");}
#line 1880 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 425 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-1].n); temp[1]=(yyvsp[0].n);(yyval.n) = createNode("Stmt",temp,2);
(yyval.n)->code= (yyvsp[-1].n)->code;
//printf("code: %s",$$->code);
}
#line 1889 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 429 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("Stmt",temp,1);
(yyval.n)->code = (yyvsp[0].n)->code;
(yyval.n)->place = (yyvsp[0].n)->place;
}
#line 1898 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 433 "syntax.y" /* yacc.c:1646  */
    {
    //printf("RETURN\n");
    //printf("RETURN %s",$2->type->name);
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Stmt",temp,3);

    //printf("====%s\n",$2->code);
    char* code= (char*)malloc(10000);
    sprintf(code,"%sRETURN %s\n",(yyvsp[-1].n)->code,(yyvsp[-1].n)->place);
    //code = strcat($2->code,code);
    (yyval.n) -> code = code;
    }
#line 1914 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 445 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-6].n); temp[1]=(yyvsp[-5].n); temp[2]=(yyvsp[-4].n); temp[3]= (yyvsp[-3].n); temp[4]= (yyvsp[-2].n); temp[5]= (yyvsp[-1].n); temp[6] = (yyvsp[0].n);(yyval.n) = createNode("Stmt",temp,7);
//printf("IF %s GOTO label\n",$3->id);
//printf("GOTO label\n");
int label1 = labelnum;
labelnum++;
int label2 = labelnum;
labelnum++;
int label3 = labelnum;
labelnum++;
char *code1=(char*)malloc(100000);
sprintf(code1,"%s",(yyvsp[-4].n)->code);
char *code2=(char*)malloc(100000);
sprintf(code2,"IF %s GOTO label%d\n",(yyvsp[-4].n)->place,label1);
char *code3=(char*)malloc(100);
sprintf(code3,"GOTO label%d\n",label2);
char *code4=(char*)malloc(100000);
sprintf(code4,"LABEL label%d :\n%sGOTO label%d\nLABEL label%d :\n%sLABEL label%d :\n",label1,(yyvsp[-2].n)->code,label3,label2,(yyvsp[0].n)->code,label3);
//printf("--------%s",code4);
char *code=(char*)malloc(400000);
if(debug)sprintf(code,"code1: %s code2: %s code3: %s code4: %s",code1,code2,code3,code4);
else sprintf(code,"%s%s%s%s",code1,code2,code3,code4);
(yyval.n)->code = code;
//printf("code: %s",$$->code);
}
#line 1943 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 470 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-4].n); temp[1]=(yyvsp[-3].n); temp[2]=(yyvsp[-2].n); temp[3]= (yyvsp[-1].n); (yyval.n) = createNode("Stmt",temp,4);
int label1 = labelnum;
labelnum++;
int label2 = labelnum;
labelnum++;
char *code1=(char*)malloc(100000);
sprintf(code1,"%s",(yyvsp[-2].n)->code);
char *code2=(char*)malloc(100000);
sprintf(code2,"IF %s GOTO label%d\n",(yyvsp[-2].n)->place,label1);
char *code3=(char*)malloc(100);
sprintf(code3,"GOTO label%d\n",label2);
char *code4=(char*)malloc(100000);
sprintf(code4,"LABEL label%d :\n%sLABEL label%d :\n",label1,(yyvsp[0].n)->code,label2);
//printf("--------%s",code4);
char *code=(char*)malloc(400000);
if(debug)sprintf(code,"code1: %s code2: %s code3: %s code4: %s",code1,code2,code3,code4);
else sprintf(code,"%s%s%s%s",code1,code2,code3,code4);
(yyval.n)->code = code;
}
#line 1967 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 490 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-4].n); temp[1]=(yyvsp[-3].n); temp[2]=(yyvsp[-2].n); temp[3]= (yyvsp[-1].n); temp[4]= (yyvsp[0].n);(yyval.n) = createNode("Stmt",temp,5);
//TODO
int label1 = labelnum;
labelnum++;
int label2 = labelnum;
labelnum++;
int label3 = labelnum;
labelnum++;
char *code1=(char*)malloc(100000);
sprintf(code1,"LABEL label%d :\n%s",label1,(yyvsp[-2].n)->code);
char *code2=(char*)malloc(100000);
sprintf(code2,"IF %s GOTO label%d\n",(yyvsp[-2].n)->place,label2);
char *code3=(char*)malloc(100);
sprintf(code3,"GOTO label%d\n",label3);
char *code4=(char*)malloc(100000);
sprintf(code4,"LABEL label%d :\n%sGOTO label%d\nLABEL label%d :\n",label2,(yyvsp[0].n)->code,label1,label3);
//printf("--------%s",code4);
char *code=(char*)malloc(400000);
if(debug)sprintf(code,"code1: %s code2: %s code3: %s code4: %s",code1,code2,code3,code4);
else sprintf(code,"%s%s%s%s",code1,code2,code3,code4);
(yyval.n)->code = code;
}
#line 1994 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 514 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-1].n); temp[1]=(yyvsp[0].n);(yyval.n) = createNode("DefList",temp,2);}
#line 2000 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 515 "syntax.y" /* yacc.c:1646  */
    {(yyval.n) = createLeafNode("DefList",-1,"");}
#line 2006 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 516 "syntax.y" /* yacc.c:1646  */
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
#line 2155 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 660 "syntax.y" /* yacc.c:1646  */
    {
    //printf("DecList: Dec\n");
     struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("DecList",temp,1);}
#line 2163 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 663 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("DecList",temp,3);}
#line 2169 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 665 "syntax.y" /* yacc.c:1646  */
    {
    //printf("Dec: VarDec\n");
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("Dec",temp,1);
    (yyval.n)->code="";
    (yyval.n)->place="";
    }
#line 2180 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 671 "syntax.y" /* yacc.c:1646  */
    {
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Dec",temp,3); 
    setType((yyvsp[0].n)->type->name,(yyvsp[-2].n)->id,head);
    //project3 
    char* code = (char*)malloc(1000);
    char* place = (char*)malloc(10);
    sprintf(code,"%s%s := %s\n",(yyvsp[0].n)->code,(yyvsp[-2].n)->place,(yyvsp[0].n)->place);
    //sprintf(place,"");
    (yyval.n)->code=code;
    (yyval.n)->place="";
    }
#line 2196 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 682 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n);temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Dec",temp,3);}
#line 2202 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 683 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n);  (yyval.n) = createNode("Dec",temp,1);}
#line 2208 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 686 "syntax.y" /* yacc.c:1646  */
    { 
     //printf("%s ASSIGN %s\n",$1->type->name,$3->type->name);
     //printf("%s = %s\n",$1->place, $3->place);
    if(strcmp((yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",(yyvsp[-2].n)->line,(yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name);
        hasError=1;   
    }
    else if((yyvsp[-2].n)->id==NULL){
        printf("Error type 6 at Line %d: rvalue on the left side\n",(yyvsp[-2].n)->line);
        hasError=1;
    }
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);

    //project3
    
    
    char* code= (char*)malloc(10000);
    sprintf(code,"%s%s := %s \n",(yyvsp[0].n)->code,(yyvsp[-2].n)->place,(yyvsp[0].n)->place);
    (yyval.n) -> code = code;
    }
#line 2233 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 706 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);
//
}
#line 2241 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 709 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);
}
#line 2248 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 711 "syntax.y" /* yacc.c:1646  */
    {
    if(strcmp((yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",(yyvsp[-2].n)->line,(yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name);
        hasError=1;   
    }
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3); (yyval.n)->type=newType("int");
    //project3
    
    char* code= (char*)malloc(100);
    char* place = (char*)malloc(10);
    sprintf(code,"%s%s",(yyvsp[-2].n)->code,(yyvsp[0].n)->code);
    sprintf(place,"%s < %s",(yyvsp[-2].n)->place,(yyvsp[0].n)->place);
    
    (yyval.n) -> code = code;
    (yyval.n)->place=place;
    }
#line 2269 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 727 "syntax.y" /* yacc.c:1646  */
    {
    if(strcmp((yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",(yyvsp[-2].n)->line,(yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name);
        hasError=1;   
    }
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);(yyval.n)->type=newType("int");
    //project3
    char* code= (char*)malloc(10000);
    char* place = (char*)malloc(10);
    sprintf(code,"%s%s",(yyvsp[-2].n)->code,(yyvsp[0].n)->code);
    sprintf(place,"%s <= %s",(yyvsp[-2].n)->place,(yyvsp[0].n)->place);
    
    (yyval.n) -> code = code;
    (yyval.n)->place=place;
    }
#line 2289 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 742 "syntax.y" /* yacc.c:1646  */
    {
    if(strcmp((yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",(yyvsp[-2].n)->line,(yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name);
        hasError=1;   
    }
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);(yyval.n)->type=newType("int");
    //project3
    char* code= (char*)malloc(10000);
    char* place = (char*)malloc(10);
    sprintf(code,"%s%s",(yyvsp[-2].n)->code,(yyvsp[0].n)->code);
    sprintf(place,"%s > %s",(yyvsp[-2].n)->place,(yyvsp[0].n)->place);
    
    (yyval.n) -> code = code;
    (yyval.n)->place=place;
    }
#line 2309 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 757 "syntax.y" /* yacc.c:1646  */
    {
    if(strcmp((yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",(yyvsp[-2].n)->line,(yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name);
        hasError=1;   
    }
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);(yyval.n)->type=newType("int");
    //project3
    char* code= (char*)malloc(10000);
    char* place = (char*)malloc(10);
    sprintf(code,"%s%s",(yyvsp[-2].n)->code,(yyvsp[0].n)->code);
    sprintf(place,"%s >= %s",(yyvsp[-2].n)->place,(yyvsp[0].n)->place);
    
    (yyval.n) -> code = code;
    (yyval.n)->place=place;
    }
#line 2329 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 772 "syntax.y" /* yacc.c:1646  */
    {
    if(strcmp((yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",(yyvsp[-2].n)->line,(yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name);
        hasError=1;   
    }
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);(yyval.n)->type=newType("int");
    //project3
    char* code= (char*)malloc(10000);
    char* place = (char*)malloc(10);
    sprintf(code,"%s%s",(yyvsp[-2].n)->code,(yyvsp[0].n)->code);
    sprintf(place,"%s != %s",(yyvsp[-2].n)->place,(yyvsp[0].n)->place);
    
    (yyval.n) -> code = code;
    (yyval.n)->place=place;
    }
#line 2349 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 787 "syntax.y" /* yacc.c:1646  */
    {
    if(strcmp((yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",(yyvsp[-2].n)->line,(yyvsp[-2].n)->type->name,(yyvsp[0].n)->type->name);
        hasError=1;   
    }
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);(yyval.n)->type=newType("int");
    //project3
    char* code= (char*)malloc(10000);
    char* place = (char*)malloc(10);
    sprintf(code,"%s%s",(yyvsp[-2].n)->code,(yyvsp[0].n)->code);
    sprintf(place,"%s == %s",(yyvsp[-2].n)->place,(yyvsp[0].n)->place);
    
    (yyval.n) -> code = code;
    (yyval.n)->place=place;
    }
#line 2369 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 802 "syntax.y" /* yacc.c:1646  */
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
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);
    }
    //project3
    char* code= (char*)malloc(10000);
    char* place = (char*)malloc(10);
    
       if(debug) printf("'%s + %s' not exist,put into t%d\n",(yyvsp[-2].n)->place,(yyvsp[0].n)->place,resnum);
        sprintf(place,"t%d",resnum);
        resnum++;
        newResTab("+",(yyvsp[-2].n)->place,(yyvsp[0].n)->place,"",resHead);
        sprintf(code,"%s%s%s := %s + %s\n",(yyvsp[-2].n)->code,(yyvsp[0].n)->code,place,(yyvsp[-2].n)->place,(yyvsp[0].n)->place);
    
    
    (yyval.n) -> code = code;
    (yyval.n)->place=place;
    //printf("%s%s\n",code,place);
}
#line 2405 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 833 "syntax.y" /* yacc.c:1646  */
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
    //project3
    //printf("MINUS\n");
    char* code= (char*)malloc(10000);
    char* place = (char*)malloc(10);
    
       if(debug) printf("'%s - %s' not exist,put into t%d\n",(yyvsp[-2].n)->place,(yyvsp[0].n)->place,resnum);
        sprintf(place,"t%d",resnum);
        resnum++;
        newResTab("-",(yyvsp[-2].n)->place,(yyvsp[0].n)->place,"",resHead);
        sprintf(code,"%s%s%s := %s - %s\n",(yyvsp[-2].n)->code,(yyvsp[0].n)->code,place,(yyvsp[-2].n)->place,(yyvsp[0].n)->place);
    
    
    (yyval.n) -> code = code;
    (yyval.n)->place=place;
}
#line 2440 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 863 "syntax.y" /* yacc.c:1646  */
    {
    struct Type* type1=(yyvsp[-2].n)->type;
    struct Type* type2=(yyvsp[0].n)->type;
    //printf("type1: %s type2: %s\n",type1->name,type2->name);
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
    //project3
    //printf("MUL: %s %s\n",$1->place,$3->place);
    char* code= (char*)malloc(10000);
    char* place = (char*)malloc(10);
     
       if(debug) printf("'%s * %s' not exist,put into t%d\n",(yyvsp[-2].n)->place,(yyvsp[0].n)->place,resnum);
        sprintf(place,"t%d",resnum);
        resnum++;
        newResTab("*",(yyvsp[-2].n)->place,(yyvsp[0].n)->place,"",resHead);
        sprintf(code,"%s%s%s := %s * %s\n",(yyvsp[-2].n)->code,(yyvsp[0].n)->code,place,(yyvsp[-2].n)->place,(yyvsp[0].n)->place);
    
    
    (yyval.n) -> code = code;
    (yyval.n)->place=place;
}
#line 2476 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 894 "syntax.y" /* yacc.c:1646  */
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
    //project3
    //printf("DIV\n");
    char* code= (char*)malloc(10000);
    char* place = (char*)malloc(10);
    
       if(debug) printf("'%s / %s' not exist,put into t%d\n",(yyvsp[-2].n)->place,(yyvsp[0].n)->place,resnum);
        sprintf(place,"t%d",resnum);
        resnum++;
        newResTab("/",(yyvsp[-2].n)->place,(yyvsp[0].n)->place,"",resHead);
        sprintf(code,"%s%s%s := %s / %s\n",(yyvsp[-2].n)->code,(yyvsp[0].n)->code,place,(yyvsp[-2].n)->place,(yyvsp[0].n)->place);
    
    
    (yyval.n) -> code = code;
    (yyval.n)->place=place;
    }
#line 2511 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 924 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);(yyval.n)->type=(yyvsp[-1].n)->type;
(yyval.n)-> code = (yyvsp[-1].n)->code;
(yyval.n)-> place = (yyvsp[-1].n)->place;
}
#line 2520 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 928 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-1].n); temp[1]=(yyvsp[0].n);(yyval.n) = createNode("Exp",temp,2); (yyval.n)->type=(yyvsp[0].n)->type;}
#line 2526 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 929 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-1].n); temp[1]=(yyvsp[0].n);(yyval.n) = createNode("Exp",temp,2);(yyval.n)->type=(yyvsp[0].n)->type;}
#line 2532 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 930 "syntax.y" /* yacc.c:1646  */
    {
    //printf("func use\n");
    if(strcmp((yyvsp[-3].n)->id,"write")==0){
        //printf("WRITE %d\n",$3->child[0]->child[0]->ival); 
        struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-3].n); temp[1]=(yyvsp[-2].n); temp[2]=(yyvsp[-1].n); temp[3]= (yyvsp[0].n); (yyval.n) = createNode("Exp",temp,4);
        
        char* code= (char*)malloc(10000);
        sprintf(code,"%sWRITE %s\n",(yyvsp[-1].n)->child[0]->code,(yyvsp[-1].n)->child[0]->place);  
        (yyval.n)->code = code; 
        //printf("code: %s",$$->code);
    }
    else{
    if(lookupfunc((yyvsp[-3].n)->id,funHead)==0){
        printf("Error type 11 at Line %d: function %s is used without definition\n",(yyvsp[-3].n)->line,(yyvsp[-3].n)->id);
        hasError=1; 
        struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-3].n); temp[1]=(yyvsp[-2].n); temp[2]=(yyvsp[-1].n); temp[3]= (yyvsp[0].n); (yyval.n) = createNode("Exp",temp,4);(yyval.n)->type=newType("error");       
    }
    else {
        struct funTab* func= findfunc((yyvsp[-3].n)->id,funHead);
        //printf("=====================fun type: %s",func->type->name);
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
        if(flag){
            (yyval.n)->type=func->type;
            //printf("REEEEEEEEEETURN %s",$$->type->name);
        }
        else
            (yyval.n)->type=newType("error");
    }
	//project 3
    struct node* args=(struct node *)malloc(sizeof(struct node));
    args=(yyvsp[-1].n);
    
    char* place= (char*)malloc(10);
    char code1[10000]="";
    char code2[10000]="";
    char* code3=(char*)malloc(10000);
    char* code =(char*)malloc(10000);
    sprintf(place,"t%d",resnum);
    resnum++;

    while(args->num==3){
        char tmp1[10000]="";
        sprintf(tmp1,"%s",args->child[0]->code);
        strcat(code1,tmp1);
        char tmp2[10000]="";
        sprintf(tmp2,"ARG %s\n",args->child[0]->place);
        strcat(tmp2,code2);
        strcpy(code2,tmp2);
        args=args->child[2];
    }
    char tmp1[10000]="";
    sprintf(tmp1,"%s",args->child[0]->code);
    strcat(code1,tmp1);
    char tmp2[10000]="";
    sprintf(tmp2,"ARG %s\n",args->child[0]->place);
    strcat(tmp2,code2);
    strcpy(code2,tmp2);
    
    
    //strcat(code2,args->child[0]->place);
    sprintf(code3,"%s := CALL %s\n",place,(yyvsp[-3].n)->id);  
    sprintf(code,"%s%s%s",code1,code2,code3);
    (yyval.n)->code = code;
    (yyval.n)->place= place;
    }
    }
#line 2640 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 1033 "syntax.y" /* yacc.c:1646  */
    {
    //printf("Function use\n");
    if(strcmp((yyvsp[-2].n)->id,"read")==0){ //READ
        int num;
        struct resTab* temp = (struct resTab*)malloc(sizeof(struct resTab));

        //TODO optimize function getNum
        temp= resHead;
        while (temp->next!=NULL){
            temp=temp->next;
        }
        num=temp->num+1;
        
        char res[10];
        sprintf(res,"t%d",num);
        char* a= (char*)malloc(sizeof(res));
        strcpy(a,res);
        char* code=(char*)malloc(10000);
        sprintf(code,"READ %s\n",res);
        struct node*child[MAX_SIZE];child[0]=(yyvsp[-2].n); child[1]=(yyvsp[-1].n); child[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",child,3);(yyval.n)->type=findfunc((yyvsp[-2].n)->id,funHead)->type;
        (yyval.n)->place= a;
        (yyval.n)->code = code;
        newResTab("read",a,"","",resHead);
        resnum++;
    }
    else{
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
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);(yyval.n)->type=findfunc((yyvsp[-2].n)->id,funHead)->type;
    }
    //project3
    char* place= (char*)malloc(10);
    char* code=(char*)malloc(10000);
    sprintf(place,"t%d",resnum);
    resnum++;
    sprintf(code,"%s := CALL %s\n",place,(yyvsp[-2].n)->id);
    (yyval.n)->code = code;
    (yyval.n)->place= place;
    }
}
#line 2694 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 1082 "syntax.y" /* yacc.c:1646  */
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
#line 2714 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1097 "syntax.y" /* yacc.c:1646  */
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
#line 2732 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1110 "syntax.y" /* yacc.c:1646  */
    {
    //printf("ID: %s %s\n",$1->id,findType($1->id,head)->name);
    if(lookup((yyvsp[0].n)->id,head)==0){ 
        printf("Error type 1 at Line %d: variable %s is used without definition\n",(yyvsp[0].n)->line,(yyvsp[0].n)->id);
        hasError=1;
        struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,1);(yyval.n)->type=newType("error");
        }
    else{
    struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,1);(yyval.n)->type=findType((yyvsp[0].n)->id,head);}
    //project3 
    //printf("ID: %s\n",$1->id);
    
    newVarTab((yyvsp[0].n)->id,varHead);
    varnum++;
    char* a=(char*)malloc(10);
    sprintf(a,"v%d",lookupVar((yyvsp[0].n)->id,varHead));
    //printf("change place %s\n",a);
    (yyval.n)->place=a;
    (yyval.n)->code = "";
    //memset(res,0,sizeof(res));
}
#line 2758 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1131 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,1);(yyval.n)->type=newType("int");
    //project3
    char* value = (char*)malloc(10);
    sprintf(value,"#%d",(yyvsp[0].n)->ival);
    char* a=(char*)malloc(10);
    char*code =(char*)malloc(10);
    if(lookupRes("int",value,"","",resHead)==0){
        if((yyvsp[0].n)->ival<0){
            if(debug) printf("%s not exist,put into t%d\n",value,resnum);
        sprintf(a,"t%d",resnum);
        resnum++;
        char* tmp=(char*)malloc(10);
        sprintf(tmp,"t%d",resnum);
        resnum++;
        newResTab("int",value,"","",resHead);
        sprintf(code,"%s := #%d\n%s := #0 - %s\n",tmp,(-(yyvsp[0].n)->ival),a,tmp);
        }
        else{
       if(debug) printf("%s not exist,put into t%d\n",value,resnum);
        sprintf(a,"t%d",resnum);
        resnum++;
        newResTab("int",value,"","",resHead);
        sprintf(code,"%s := #%d\n",a,(yyvsp[0].n)->ival);
        }
    }
    else {
        if(debug) printf("%s exist in t%d\n",value,lookupRes("int",value,"","",resHead));
        sprintf(a,"t%d",lookupRes("int",value,"","",resHead));
        sprintf(code,"%s := #%d\n",a,(yyvsp[0].n)->ival);
    }
    //TODO optional duplicate int
    
    //printf("CCCCCCCODE: %s\n",code);
    (yyval.n)->place=a;
    (yyval.n)->code = code;
    
}
#line 2800 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1168 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,1);(yyval.n)->type=newType("float");}
#line 2806 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1169 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,1);(yyval.n)->type=newType("char");}
#line 2812 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1170 "syntax.y" /* yacc.c:1646  */
    {hasError=1;printf("at line %d : Missing RP\n", (yyvsp[-3].n)->line);}
#line 2818 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1171 "syntax.y" /* yacc.c:1646  */
    {hasError=1;printf("at line %d : Missing RP\n", (yyvsp[-2].n)->line);}
#line 2824 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1172 "syntax.y" /* yacc.c:1646  */
    {hasError=1;printf("at line %d : Missing RP\n", (yyvsp[-1].n)->line);}
#line 2830 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1173 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,3);}
#line 2836 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1174 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("Exp",temp,1);}
#line 2842 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1175 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[-2].n); temp[1]=(yyvsp[-1].n); temp[2]=(yyvsp[0].n); (yyval.n) = createNode("Args",temp,3);}
#line 2848 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1176 "syntax.y" /* yacc.c:1646  */
    {struct node*temp[MAX_SIZE];temp[0]=(yyvsp[0].n); (yyval.n) = createNode("Args",temp,1);}
#line 2854 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1177 "syntax.y" /* yacc.c:1646  */
    {hasError=1;printf("at line %d : COMMA instead of SEMI\n", (yyvsp[-2].n)->line);}
#line 2860 "syntax.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1178 "syntax.y" /* yacc.c:1646  */
    {hasError=1;printf("at line %d : Missing COMMA\n", (yyvsp[-1].n)->line);}
#line 2866 "syntax.tab.c" /* yacc.c:1646  */
    break;


#line 2870 "syntax.tab.c" /* yacc.c:1646  */
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
#line 1180 "syntax.y" /* yacc.c:1906  */


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
    struct symTab* param[MAX_SIZE];
    
    insertfunc("int","read",1,0,param,funHead);
    insertfunc("int","write",1,1,param,funHead);
    arrHead=(struct arrTab*)malloc(sizeof (struct arrTab));
    arrHead->name="header";
    arrHead->next=NULL;

    strHead=(struct strTab*)malloc(sizeof(struct strTab));
    strHead->name="header";
    strHead->next=NULL;

    varHead=(struct varTab*)malloc(sizeof(struct varTab));
    varHead->name="header";
    varHead->num=0;
    varHead->next=NULL;

    resHead=(struct resTab*)malloc(sizeof(struct resTab));
    resHead->opera="header";
    resHead->num=0;
    resHead->next=NULL;

    //lookup("test",head);
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(-1);
    }
    else if(!(yyin = fopen(argv[1], "r"))) {
        perror(argv[1]);
        exit(-1);
    }
    if(debug){
        // printf("%s",argv[1]);
        
        // char* filepath=argv[1];
        // char* fileExt;
        // char* ptr,c='.';
        // ptr = strrchr(filepath,c);
        // int pos = ptr- filepath;
        // fileExt=substr(filepath,pos+1,strlen(filepath));
        // printf("%s",fileExt);
        // char* outpath="./test/output.out";
        // if(strcmp(fileExt,"spl")==0){
        //     int i= strlen(filepath);
        //     char* fn1=filepath+i;
        //     while(fn1>filepath){
        //         if(*fn1=='.'){
        //             *fn1=0;
        //             break;
        //         }
        //         fn1--;
        //     }
        //     outpath=strcat(filepath,".out");
        // }
        // printf("out %s",outpath);
        // if(freopen(outpath,"w",stdout)==NULL)
        //     printf("redirect fail");
    
    }
    else{
        char* filepath=argv[1];
        char* fileExt;
        char* ptr,c='.';
        ptr = strrchr(filepath,c);
        int pos = ptr- filepath;
        fileExt=substr(filepath,pos+1,strlen(filepath));
        //printf("%s",fileExt);
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
            outpath=strcat(filepath,".ir");
        }
        printf("out: %s",outpath);
        if(freopen(outpath,"w",stdout)==NULL)
            printf("redirect fail");
    }
    yyparse();
    return 0;
}
