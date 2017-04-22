
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 6 "src/gramm.y"

// #include "calc.h"  /* Contains definition of `symrec'        */
#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gramm.h"

#define DEFAULT_OUT "int.out"

int vtype;
FILE *outfile;

int next_quad;
int label_no;
int patches[MAX_NEST_DEPTH];
int patch_idx;

struct pair cur_loop;

struct bigop {
    int op;
    char str[3];
};

int BIGOPS_NUM;
struct list *nested;
struct scope_type scope;

// Builtin type info.
void init_globals();



/* Line 189 of yacc.c  */
#line 109 "gen/y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     OR_OP = 258,
     AND_OP = 259,
     EQ_OP = 260,
     NE_OP = 261,
     LE_OP = 262,
     GE_OP = 263,
     LSHFT_OP = 264,
     RSHFT_OP = 265,
     INC_OP = 266,
     DEC_OP = 267,
     TYPEDEF = 268,
     EXTERN = 269,
     STATIC = 270,
     AUTO = 271,
     REGISTER = 272,
     CHAR = 273,
     SHORT = 274,
     INT = 275,
     LONG = 276,
     SIGNED = 277,
     UNSIGNED = 278,
     FLOAT = 279,
     DOUBLE = 280,
     CONST = 281,
     VOLATILE = 282,
     VOID = 283,
     STRUCT = 284,
     UNION = 285,
     ENUM = 286,
     ELLIPSIS = 287,
     CASE = 288,
     DEFAULT = 289,
     SWITCH = 290,
     WHILE = 291,
     DO = 292,
     FOR = 293,
     GOTO = 294,
     CONTINUE = 295,
     BREAK = 296,
     RETURN = 297,
     SIZEOF = 298,
     CONSTANT = 299,
     IDENTIFIER = 300,
     ALIAS_NAME = 301,
     DEREF = 302,
     UMINUS = 303,
     IF = 304,
     ELSE = 305
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 41 "src/gramm.y"

double  val;  /* For returning numbers.                   */  
char *id_name;
char *t_name;
symrec *sym;
struct {
  char *name;
  struct type type;
} sym_npt; // stands for name and pointer types
struct {
  int type;
  int val;
} constant;
struct expr_type e;
struct type type;
int patch;
struct pair dual_patch;
struct loop_type loop;
int ttype;
struct memb_list *tlist;
struct list *l;
struct type *alias_type;



/* Line 214 of yacc.c  */
#line 221 "gen/y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 233 "gen/y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   743

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNRULES -- Number of states.  */
#define YYNSTATES  160

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,     2,     2,     2,    58,    49,     2,
      72,    60,    56,    55,    47,    54,    64,    57,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    68,    71,
      52,    48,    53,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    73,    50,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    69,    51,    70,    62,     2,     2,     2,
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
      45,    46,    59,    63,    66,    67
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    28,    34,    35,    36,    39,    42,
      48,    51,    53,    55,    57,    58,    60,    63,    64,    66,
      70,    72,    76,    80,    83,    85,    88,    91,    95,    97,
     100,   105,   108,   113,   118,   120,   124,   128,   130,   133,
     135,   140,   143,   147,   149,   151,   153,   155,   157,   160,
     161,   163,   165,   169,   171,   174,   178,   181,   184,   187,
     190,   193,   198,   201,   205,   209,   213,   217,   221,   225,
     229,   233,   237,   241,   245,   249,   253,   257,   261,   265,
     269,   273,   277
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      75,     0,    -1,    -1,    75,    76,    -1,    99,    -1,    92,
      -1,    91,    -1,     1,    -1,    96,    -1,    93,    -1,    78,
      -1,    77,    -1,    81,    -1,    45,    68,    -1,    79,    69,
      75,    70,    80,    -1,    -1,    -1,    90,    71,    -1,    82,
      71,    -1,    83,    85,    69,    86,    70,    -1,    83,    84,
      -1,    29,    -1,    30,    -1,    45,    -1,    -1,    84,    -1,
      88,    87,    -1,    -1,    86,    -1,   103,    89,    71,    -1,
      45,    -1,    45,    47,    89,    -1,    13,   103,    45,    -1,
     106,    71,    -1,    71,    -1,    40,    71,    -1,    41,    71,
      -1,    39,    45,    71,    -1,    94,    -1,    95,    76,    -1,
      36,    72,   106,    60,    -1,    97,    76,    -1,    97,    76,
      98,    76,    -1,    66,    72,   106,    60,    -1,    67,    -1,
     103,   100,    71,    -1,   101,    47,   100,    -1,   101,    -1,
     102,   104,    -1,    45,    -1,   102,    65,    44,    73,    -1,
      56,   102,    -1,    72,   102,    60,    -1,    20,    -1,    24,
      -1,    18,    -1,    82,    -1,    46,    -1,    48,   106,    -1,
      -1,    44,    -1,    45,    -1,    72,   106,    60,    -1,   105,
      -1,   106,   107,    -1,   106,    64,    45,    -1,    61,   106,
      -1,    62,   106,    -1,    54,   106,    -1,    11,   106,    -1,
      12,   106,    -1,    72,   103,    60,   106,    -1,    56,   106,
      -1,   106,    56,   106,    -1,   106,    57,   106,    -1,   106,
      58,   106,    -1,   106,    55,   106,    -1,   106,    54,   106,
      -1,   106,     9,   106,    -1,   106,    10,   106,    -1,   106,
      53,   106,    -1,   106,    52,   106,    -1,   106,     7,   106,
      -1,   106,     8,   106,    -1,   106,     5,   106,    -1,   106,
       6,   106,    -1,   106,    51,   106,    -1,   106,    50,   106,
      -1,   106,    49,   106,    -1,   106,     4,   106,    -1,   106,
       3,   106,    -1,   105,    48,   106,    -1,    65,   106,    73,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   123,   123,   124,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   140,   145,   149,   160,   168,   169,   176,
     190,   209,   210,   213,   220,   221,   226,   238,   239,   242,
     256,   260,   266,   280,   281,   285,   292,   298,   301,   306,
     316,   326,   331,   340,   347,   354,   390,   391,   395,   416,
     425,   443,   452,   459,   464,   469,   474,   475,   478,   479,
     483,   488,   495,   542,   543,   554,   555,   556,   557,   558,
     568,   578,   587,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   615,   623
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OR_OP", "AND_OP", "EQ_OP", "NE_OP",
  "LE_OP", "GE_OP", "LSHFT_OP", "RSHFT_OP", "INC_OP", "DEC_OP", "TYPEDEF",
  "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR", "SHORT", "INT", "LONG",
  "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID",
  "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE", "DEFAULT", "SWITCH",
  "WHILE", "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "SIZEOF",
  "CONSTANT", "IDENTIFIER", "ALIAS_NAME", "','", "'='", "'&'", "'^'",
  "'|'", "'<'", "'>'", "'-'", "'+'", "'*'", "'/'", "'%'", "DEREF", "')'",
  "'!'", "'~'", "UMINUS", "'.'", "'['", "IF", "ELSE", "':'", "'{'", "'}'",
  "';'", "'('", "']'", "$accept", "input", "statement", "label_stmt",
  "block_statement", "begin_sub", "end_sub", "type_definition",
  "compound_type", "type_type", "ctype_name", "opt_ctype_name",
  "member_decl_list", "opt_member_decl_list", "member_decl", "id_list",
  "aliasing", "expression_statement", "jump_statement",
  "iterative_statement", "while_loop", "while_clause",
  "selection_statement", "if_clause", "else_clause",
  "declaration_statement", "var_dlist", "var_definition", "symbol_name",
  "type_name", "opt_init", "primary_expr", "expr", "indexing", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,    44,    61,    38,
      94,   124,    60,    62,    45,    43,    42,    47,    37,   302,
      41,    33,   126,   303,    46,    91,   304,   305,    58,   123,
     125,    59,    40,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    75,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    77,    78,    79,    80,    81,    81,    82,
      82,    83,    83,    84,    85,    85,    86,    87,    87,    88,
      89,    89,    90,    91,    91,    92,    92,    92,    93,    94,
      95,    96,    96,    97,    98,    99,   100,   100,   101,   102,
     102,   102,   102,   103,   103,   103,   103,   103,   104,   104,
     105,   105,   105,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   107
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     5,     0,     0,     2,     2,     5,
       2,     1,     1,     1,     0,     1,     2,     0,     1,     3,
       1,     3,     3,     2,     1,     2,     2,     3,     1,     2,
       4,     2,     4,     4,     1,     3,     3,     1,     2,     1,
       4,     2,     3,     1,     1,     1,     1,     1,     2,     0,
       1,     1,     3,     1,     2,     3,     2,     2,     2,     2,
       2,     4,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     7,     0,     0,     0,    55,    53,    54,
      21,    22,     0,     0,     0,     0,    60,    61,    57,     0,
       0,     0,     0,     0,    34,     0,     3,    11,    10,     0,
      12,    56,    24,     0,     6,     5,     9,    38,     0,     8,
       0,     4,     0,    63,     0,    61,    69,    70,    56,     0,
       0,     0,    35,    36,    13,    68,    72,    66,    67,     0,
       0,     0,     2,    18,    23,    20,     0,    17,    39,    41,
      49,     0,     0,     0,    47,    59,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,    64,    32,
       0,    37,     0,     0,    62,     0,     0,    44,     0,    51,
       0,    45,     0,     0,     0,    48,    91,    90,    89,    84,
      85,    82,    83,    78,    79,    88,    87,    86,    81,    80,
      77,    76,    73,    74,    75,    65,     0,    40,    43,    71,
      16,     0,    27,     0,    42,    52,    46,    58,     0,    92,
      14,    19,    28,    26,    30,     0,    50,     0,    29,    31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,    27,    28,    29,   150,    30,    31,    32,
      65,    66,   141,   153,   142,   155,    33,    34,    35,    36,
      37,    38,    39,    40,   108,    41,    73,    74,    75,    42,
     115,    43,    44,    98
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -60
static const yytype_int16 yypact[] =
{
     -60,   109,   -60,   -60,    -3,    -3,     8,   -60,   -60,   -60,
     -60,   -60,   -59,   -30,   -46,   -40,   -60,   -39,   -60,    -3,
      -3,    -3,    -3,   -38,   -60,   559,   -60,   -60,   -60,   -34,
     -60,   -35,    -2,   -31,   -60,   -60,   -60,   -60,   233,   -60,
     233,   -60,   -42,    -4,   328,   -60,   -53,   -53,   -60,     5,
      -3,   -14,   -60,   -60,   -60,   -53,   -53,   -53,   -53,    -3,
     -21,   397,   -60,   -60,   -60,    -1,     4,   -60,   -60,    -7,
     -60,   -42,   -42,     3,    18,   -32,    -3,    -3,    -3,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,
      -3,    -3,    -3,    -3,    -3,    21,    -3,   -60,   -60,   -60,
     414,   -60,   431,    -3,   -60,   171,     8,   -60,   233,    10,
     -55,   -60,   -42,    -3,    23,   -60,   494,   511,   585,   104,
     104,   164,   164,    -9,    -9,   601,   617,   678,   164,   164,
       6,     6,   -53,   -53,   -53,   -60,   303,   -60,   -60,   -53,
     -60,     7,     8,    31,   -60,   -60,   -60,   494,    24,   -60,
     -60,   -60,   -60,   -60,    52,    32,   -60,    31,   -60,   -60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -60,    40,   -36,   -60,   -60,   -60,   -60,   -60,    -6,   -60,
     -60,   -60,   -26,   -60,   -60,   -51,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,   -60,    -8,   -60,   -54,    -5,
     -60,   -60,     2,   -60
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -26
static const yytype_int16 yytable[] =
{
      48,    49,    68,    70,    69,   145,    46,    47,     4,     5,
     114,    95,    96,    50,    71,    51,   113,   109,   110,    48,
      60,    55,    56,    57,    58,    52,     7,    61,     8,    54,
      72,    53,     9,   114,    59,    62,    63,    10,    11,   103,
      67,    16,    45,    64,    76,    90,    91,    92,    93,    94,
      99,    19,   100,    20,    18,    95,    96,   101,    21,    22,
     107,   102,    92,    93,    94,   112,   135,   148,   -25,    25,
      95,    96,   144,   106,   111,   114,   154,   151,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   156,   136,   157,
      48,   143,   105,   158,   146,   139,   159,     0,     0,     2,
       3,    81,    82,    83,    84,   147,   152,     0,     0,     0,
       4,     5,     6,     0,     0,     0,     0,     7,     0,     8,
       0,     0,     0,     9,     0,     0,    48,   143,    10,    11,
       0,     0,     0,     0,     0,    12,     0,     0,    13,    14,
      15,     0,     0,    16,    17,    18,    88,    89,    90,    91,
      92,    93,    94,    19,     0,    20,     0,     0,    95,    96,
      21,    22,     3,    83,    84,    23,     0,     0,   -15,     0,
      24,    25,     4,     5,     6,     0,     0,     0,     0,     7,
       0,     8,     0,     0,     0,     9,     0,     0,     0,     0,
      10,    11,     0,     0,     0,     0,     0,    12,     0,     0,
      13,    14,    15,     0,     0,    16,    17,    18,    90,    91,
      92,    93,    94,     0,     0,    19,     0,    20,    95,    96,
       0,     0,    21,    22,     3,     0,     0,    23,     0,     0,
     -15,   140,    24,    25,     4,     5,     6,     0,     0,     0,
       0,     7,     0,     8,     0,     0,     0,     9,     0,     0,
       0,     0,    10,    11,     0,     0,     0,     0,     0,    12,
       0,     0,    13,    14,    15,     0,     0,    16,    17,    18,
       0,     0,     0,     0,     0,     0,     0,    19,     0,    20,
       0,     0,     0,     0,    21,    22,     0,     0,     0,    23,
       0,     0,   -15,     0,    24,    25,    77,    78,    79,    80,
      81,    82,    83,    84,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,     0,     0,     0,     0,     0,    95,    96,     0,
       0,     0,     0,     0,     0,     0,   149,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,     0,     0,     0,
       0,     0,    95,    96,     0,     0,     0,     0,     0,    97,
      77,    78,    79,    80,    81,    82,    83,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,    78,    79,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,     0,     0,     0,     0,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,     0,   104,     0,     0,
       0,    95,    96,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,     0,   137,     0,     0,     0,    95,    96,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
       0,   138,     0,     0,     0,    95,    96,    77,    78,    79,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,    79,    80,    81,    82,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,     0,     0,     0,     0,     0,    95,    96,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
       4,     5,     0,     0,     0,    95,    96,     7,     0,     8,
       0,     0,     0,     9,     0,     0,     0,     0,    10,    11,
      79,    80,    81,    82,    83,    84,     0,     0,     0,     0,
       0,     0,     0,    16,    45,    18,    79,    80,    81,    82,
      83,    84,     0,    19,     0,    20,     0,     0,     0,     0,
      21,    22,    79,    80,    81,    82,    83,    84,     0,     0,
       0,    25,     0,     0,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,     0,     0,     0,     0,     0,    95,
      96,    86,    87,    88,    89,    90,    91,    92,    93,    94,
       0,     0,     0,     0,     0,    95,    96,     0,    87,    88,
      89,    90,    91,    92,    93,    94,     0,     0,     0,     0,
       0,    95,    96,    79,    80,    81,    82,    83,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,    92,    93,    94,     0,     0,     0,
       0,     0,    95,    96
};

static const yytype_int16 yycheck[] =
{
       6,     6,    38,    45,    40,    60,     4,     5,    11,    12,
      65,    64,    65,    72,    56,    45,    48,    71,    72,    25,
      25,    19,    20,    21,    22,    71,    18,    25,    20,    68,
      72,    71,    24,    65,    72,    69,    71,    29,    30,    60,
      71,    44,    45,    45,    48,    54,    55,    56,    57,    58,
      45,    54,    50,    56,    46,    64,    65,    71,    61,    62,
      67,    59,    56,    57,    58,    47,    45,    44,    69,    72,
      64,    65,   108,    69,    71,    65,    45,    70,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    73,    96,    47,
     106,   106,    62,    71,   112,   103,   157,    -1,    -1,     0,
       1,     7,     8,     9,    10,   113,   142,    -1,    -1,    -1,
      11,    12,    13,    -1,    -1,    -1,    -1,    18,    -1,    20,
      -1,    -1,    -1,    24,    -1,    -1,   142,   142,    29,    30,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    39,    40,
      41,    -1,    -1,    44,    45,    46,    52,    53,    54,    55,
      56,    57,    58,    54,    -1,    56,    -1,    -1,    64,    65,
      61,    62,     1,     9,    10,    66,    -1,    -1,    69,    -1,
      71,    72,    11,    12,    13,    -1,    -1,    -1,    -1,    18,
      -1,    20,    -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,
      39,    40,    41,    -1,    -1,    44,    45,    46,    54,    55,
      56,    57,    58,    -1,    -1,    54,    -1,    56,    64,    65,
      -1,    -1,    61,    62,     1,    -1,    -1,    66,    -1,    -1,
      69,    70,    71,    72,    11,    12,    13,    -1,    -1,    -1,
      -1,    18,    -1,    20,    -1,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    -1,    39,    40,    41,    -1,    -1,    44,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    56,
      -1,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    66,
      -1,    -1,    69,    -1,    71,    72,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    -1,    64,    65,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    -1,    64,    65,    -1,    -1,    -1,    -1,    -1,    71,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,    60,    -1,    -1,
      -1,    64,    65,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    60,    -1,    -1,    -1,    64,    65,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    60,    -1,    -1,    -1,    64,    65,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    -1,    -1,    -1,    -1,    -1,    64,    65,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      11,    12,    -1,    -1,    -1,    64,    65,    18,    -1,    20,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,    29,    30,
       5,     6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,     5,     6,     7,     8,
       9,    10,    -1,    54,    -1,    56,    -1,    -1,    -1,    -1,
      61,    62,     5,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    72,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    -1,    -1,    -1,    -1,    -1,    64,
      65,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    64,    65,    -1,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      -1,    64,    65,     5,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    53,    54,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    -1,    64,    65
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    75,     0,     1,    11,    12,    13,    18,    20,    24,
      29,    30,    36,    39,    40,    41,    44,    45,    46,    54,
      56,    61,    62,    66,    71,    72,    76,    77,    78,    79,
      81,    82,    83,    90,    91,    92,    93,    94,    95,    96,
      97,    99,   103,   105,   106,    45,   106,   106,    82,   103,
      72,    45,    71,    71,    68,   106,   106,   106,   106,    72,
     103,   106,    69,    71,    45,    84,    85,    71,    76,    76,
      45,    56,    72,   100,   101,   102,    48,     3,     4,     5,
       6,     7,     8,     9,    10,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    64,    65,    71,   107,    45,
     106,    71,   106,    60,    60,    75,    69,    67,    98,   102,
     102,    71,    47,    48,    65,   104,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,    45,   106,    60,    60,   106,
      70,    86,    88,   103,    76,    60,   100,   106,    44,    73,
      80,    70,    86,    87,    45,    89,    73,    47,    71,    89
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:

/* Line 1455 of yacc.c  */
#line 128 "src/gramm.y"
    {;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 129 "src/gramm.y"
    {;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 130 "src/gramm.y"
    {;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 131 "src/gramm.y"
    { yyerrok; ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 132 "src/gramm.y"
    {;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 133 "src/gramm.y"
    {;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 134 "src/gramm.y"
    {;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 135 "src/gramm.y"
    {;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 140 "src/gramm.y"
    { fprintf(outfile, "%s: ", (yyvsp[(1) - (2)].id_name)); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 149 "src/gramm.y"
    {
                scope.label = label_no;
                // Push scope info onto stack
                list_prepend_elem(&nested, 
                  list_create_elem((void *)label_no));
                scope.level++;
                out_label();
              ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 160 "src/gramm.y"
    {
                list_pop_front(&nested);
                scope.label = (int) nested->data;
                delsym_scope(scope.level);
                scope.level--;
              ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 177 "src/gramm.y"
    { 
                      printf("nam1e %s\n", (yyvsp[(2) - (5)].t_name));
                      if (get_struct((yyvsp[(2) - (5)].t_name)))
                        error("Redefinition of struct");
                      /* TODO: Differentiate b/w STRUCT and
                       * UNION */
                      (yyval.type).val.stype = create_struct((yyvsp[(2) - (5)].t_name), (yyvsp[(4) - (5)].tlist), false);
                      (yyval.type).ttype = COMPOUND_TYPE;
                      SET_NOT_ARRAY((yyval.type));
                      // If it is not null string
                      if ((yyvsp[(2) - (5)].t_name)[0])
                        free((yyvsp[(2) - (5)].t_name));
                    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 191 "src/gramm.y"
    {
                    printf("name2 %s\n", (yyvsp[(2) - (2)].t_name));

                    struct struct_type *s = get_struct((yyvsp[(2) - (2)].t_name));
                    if (!s)  {
                      // Forward declaration
                      (yyval.type).val.stype = create_struct((yyvsp[(2) - (2)].t_name), NULL, true);
                      (yyval.type).ttype = INCOMPL_TYPE;                      
                    }
                    else {
                      (yyval.type).ttype = COMPOUND_TYPE;
                      (yyval.type).val.stype = s;                    
                    }
                    SET_NOT_ARRAY((yyval.type));
                    free((yyvsp[(2) - (2)].t_name));
                  ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 209 "src/gramm.y"
    { (yyval.ttype) = STRUCT_TAG; ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 210 "src/gramm.y"
    { (yyval.ttype) = UNION_TAG; ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 214 "src/gramm.y"
    {
                copy_name(&(yyval.t_name), (yyvsp[(1) - (1)].id_name));
                printf("%s\n", (yyval.t_name));
              ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 220 "src/gramm.y"
    { (yyval.t_name) = ""; ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 221 "src/gramm.y"
    { (yyval.t_name) = (yyvsp[(1) - (1)].t_name); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 227 "src/gramm.y"
    {
                // Join the two lists. 
                struct memb_list *mem = (yyvsp[(1) - (2)].tlist);
                while (mem->next)
                  mem = mem->next;
                mem->next = (yyvsp[(2) - (2)].tlist);
                (yyval.tlist) = (yyvsp[(1) - (2)].tlist);
              ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 238 "src/gramm.y"
    { (yyval.tlist) = NULL; ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 239 "src/gramm.y"
    { (yyval.tlist) = (yyvsp[(1) - (1)].tlist); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 243 "src/gramm.y"
    {
                // Set types for all members
                struct memb_list *mem = (yyvsp[(2) - (3)].tlist);
                if (size_of((yyvsp[(1) - (3)].type)) == -1)
                  error("member has incomplete type");
                while (mem) {
                  mem->type = (yyvsp[(1) - (3)].type);
                  mem = mem->next; 
                }
                (yyval.tlist) = (yyvsp[(2) - (3)].tlist);
              ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 257 "src/gramm.y"
    {
                    (yyval.tlist) = create_member((yyvsp[(1) - (1)].id_name), NULL);
                  ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 261 "src/gramm.y"
    {
                    (yyval.tlist) = create_member((yyvsp[(1) - (3)].id_name), (yyvsp[(3) - (3)].tlist)); 
                  ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 267 "src/gramm.y"
    { 
              struct type *t;
              if (t = get_alias((yyvsp[(3) - (3)].id_name)))  {
                // Check type equivalence properly
                if (!is_equiv(*t, (yyvsp[(2) - (3)].type)))
                  error("Conflicting types for typedef");
              }
              else 
                create_alias((yyvsp[(3) - (3)].id_name), (yyvsp[(2) - (3)].type));
            ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 286 "src/gramm.y"
    { 
                    printf("%d", cur_loop.label);
                    if (cur_loop.label == -1)
                      error("continue statement not within a loop");
                    out_jmp(NULL, &cur_loop.label, JUMP_LABEL_NUMBER); 
                  ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 293 "src/gramm.y"
    { 
                    if (cur_loop.label == -1)
                      error("break statement not within a loop or a switch");
                    out_jmp(NULL, &cur_loop.patch, JUMP_PATCH); 
                  ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 298 "src/gramm.y"
    { out_jmp(NULL, (void *)(yyvsp[(2) - (3)].id_name), JUMP_LABEL_NAME); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 307 "src/gramm.y"
    {
                        out_jmp(NULL, &((yyvsp[(1) - (2)].loop).this.label), JUMP_LABEL_NUMBER);
                        int label = label_no;
                        out_label();
                        backpatch(label, (yyvsp[(1) - (2)].loop).this.patch);
                        cur_loop = (yyvsp[(1) - (2)].loop).prev;
                      ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 317 "src/gramm.y"
    {
                        (yyval.loop).prev = cur_loop; 
                        (yyval.loop).this.label = label_no;
                        out_label();
                        (yyval.loop).this.patch = out_jmp(&(yyvsp[(3) - (4)].e), (void *)NULL, 0);
                        cur_loop = (yyval.loop).this;
                      ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 326 "src/gramm.y"
    {
                          int l_no = label_no;
                          out_label();
                          backpatch(l_no, (yyvsp[(1) - (2)].patch)); 
                        ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 332 "src/gramm.y"
    {
                          int l_no = label_no;
                          out_label();
                          backpatch((yyvsp[(3) - (4)].dual_patch).label, (yyvsp[(1) - (4)].patch));
                          backpatch(l_no, (yyvsp[(3) - (4)].dual_patch).patch);
                       ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 340 "src/gramm.y"
    {
                // returns patch number
                (yyval.patch) = out_jmp(&(yyvsp[(3) - (4)].e), (void *)NULL, 0);
                printf("If clause done\n");
              ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 347 "src/gramm.y"
    {
                    (yyval.dual_patch).patch = out_jmp(NULL, NULL, 0);
                    (yyval.dual_patch).label = label_no;
                    out_label();
                 ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 355 "src/gramm.y"
    {
                          struct list *node = (yyvsp[(2) - (3)].l);
                          struct symrec *sym;
                          /* TODO: Check for completeness of 
                            type here */
                          if ((yyvsp[(1) - (3)].type).ttype == UNDEF_TYPE)
                            error("incomplete type");

                          // Backpatch
                          while (node) {
                            sym = (symrec *) node->data;
                            struct array_type arr = sym->type.array;
                            if (sym->type.ttype == INCOMPL_TYPE) {
                              if ((yyvsp[(1) - (3)].type).ttype == INCOMPL_TYPE)
                                error("incomplete type for varibale");
                              sym->type = (yyvsp[(1) - (3)].type);
                            }
                            else if (sym->type.ttype == PTR_TYPE) {
                              struct type *t = sym->type.val.ptr_to;
                              // Travese the list of ptr types
                              while (t->ttype == PTR_TYPE)
                                t = t->val.ptr_to;
                              // Set the type of the last node to the basic
                              // or compound type that is type_name
                              if (t->ttype == INCOMPL_TYPE)
                                *t = (yyvsp[(1) - (3)].type);
                            }
                            sym->type.array = arr;
                            // TODO: Relloc in the entire ptr_to linked list
                            sym->type.array.dimen = realloc(sym->type.array.dimen, sym->type.array.n * sizeof(int));
                            node = node->next;
                          }
                        ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 390 "src/gramm.y"
    { list_prepend_elem(&(yyvsp[(3) - (3)].l), (yyvsp[(1) - (3)].l)); (yyval.l) = (yyvsp[(3) - (3)].l); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 391 "src/gramm.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 396 "src/gramm.y"
    {
                    symrec *rec = getsym((yyvsp[(1) - (2)].sym_npt).name, scope);
                    if (rec) {
                      error("Redefinition of symbol");
                    }
                    rec = putsym((yyvsp[(1) - (2)].sym_npt).name, (yyvsp[(1) - (2)].sym_npt).type, scope);
                    (yyval.l) = list_create_elem(rec);            
                    
                    // Assign result of expr to vaiable
                    // This is should be delayed to after the 
                    // type backpatch to check coercibility
                    if ((yyvsp[(2) - (2)].e).type.ttype != UNDEF_TYPE) {
                        out_assign((yyvsp[(1) - (2)].sym_npt).name, (yyvsp[(2) - (2)].e));
                    }
                    free((yyvsp[(1) - (2)].sym_npt).name);
                  ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 417 "src/gramm.y"
    {
                copy_name(&(yyval.sym_npt).name, (yyvsp[(1) - (1)].id_name));
                // Create a new symbol table record
                // and assign it the thing from the old record  
                (yyval.sym_npt).type.ttype = INCOMPL_TYPE; 
                SET_NOT_ARRAY((yyval.sym_npt).type);
              ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 426 "src/gramm.y"
    {
                struct type *t = &((yyvsp[(1) - (4)].sym_npt).type);
                if (const_type((yyvsp[(3) - (4)].e).val.const_str) != INT_TYPE)
                  error("size of array has non-integer type");
                int size = const_val((yyvsp[(3) - (4)].e).val.const_str);
                if (!is_array(*t)) {
                  t->array.dimen = malloc(MAX_ARRAY_DIMEN * sizeof(int));
                  t->array.n = 1;
                }
                else
                  t->array.n++;
                if (t->array.n == MAX_ARRAY_DIMEN)
                  error("Can't have more than 256 dimension array");
                t->array.dimen[t->array.n - 1] = size;
                t->array.size *= size;
                (yyval.sym_npt) = (yyvsp[(1) - (4)].sym_npt);
              ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 444 "src/gramm.y"
    {
                struct type *to = malloc(sizeof(struct type));
                *to = (yyvsp[(2) - (2)].sym_npt).type; // TYPE COPYING
                (yyval.sym_npt).type.ttype = PTR_TYPE;
                (yyval.sym_npt).type.val.ptr_to = to;
                SET_NOT_ARRAY((yyval.sym_npt).type);
                (yyval.sym_npt).name = (yyvsp[(2) - (2)].sym_npt).name;
              ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 452 "src/gramm.y"
    { (yyval.sym_npt) = (yyvsp[(2) - (3)].sym_npt); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 460 "src/gramm.y"
    { 
              (yyval.type).ttype = BASIC_TYPE;
              (yyval.type).val.btype = INT_TYPE;
            ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 465 "src/gramm.y"
    { 
              (yyval.type).ttype = BASIC_TYPE;
              (yyval.type).val.btype = FLOAT_TYPE;
            ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 470 "src/gramm.y"
    { 
              (yyval.type).ttype = BASIC_TYPE;
              (yyval.type).val.btype = CHAR_TYPE;
            ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 474 "src/gramm.y"
    { (yyval.type) = (yyvsp[(1) - (1)].type); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 475 "src/gramm.y"
    { (yyval.type) = *(yyvsp[(1) - (1)].alias_type); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 478 "src/gramm.y"
    { printf("In opt_init"); (yyval.e) = (yyvsp[(2) - (2)].e); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 479 "src/gramm.y"
    { (yyval.e).type.ttype = UNDEF_TYPE; ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 483 "src/gramm.y"
    { 
                  char *temp;
                  copy_name(&temp, (yyvsp[(1) - (1)].e).val.const_str);
                  (yyval.e) = create_const_expr(temp);
                ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 488 "src/gramm.y"
    { 
                  symrec *rec = getsym((yyvsp[(1) - (1)].id_name), scope);
                  if (!rec) {
                    error("Undefined symbol\n");
                  }
                  (yyval.e) = create_sym_expr(rec);
                ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 495 "src/gramm.y"
    { (yyval.e) = (yyvsp[(2) - (3)].e); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 542 "src/gramm.y"
    { (yyval.e) = (yyvsp[(1) - (1)].e); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 544 "src/gramm.y"
    {
              /* TODO: Add the check for pointer here */
            if (!is_array((yyvsp[(1) - (2)].e).type) || !is_pointer((yyvsp[(1) - (2)].e).type))
              error("subscripted value is neither array nor pointer nor vector");
            (yyval.e).val.quad_no = next_quad;
            (yyval.e).ptr = QUAD_PTR;
            (yyval.e).type = arr_reduce_dimen((yyvsp[(1) - (2)].e).type);
            out_index((yyvsp[(1) - (2)].e), (yyvsp[(2) - (2)].e));

          ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 554 "src/gramm.y"
    { out_member_ref((yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].id_name)); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 555 "src/gramm.y"
    { parse_unary_expr(&(yyval.e), (yyvsp[(2) - (2)].e), '!'); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 556 "src/gramm.y"
    { parse_unary_expr(&(yyval.e), (yyvsp[(2) - (2)].e), '~'); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 557 "src/gramm.y"
    { parse_unary_expr(&(yyval.e), (yyvsp[(2) - (2)].e), '-'); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 559 "src/gramm.y"
    { 
            struct expr_type e = create_const_expr("1");
            parse_expr(&(yyval.e), (yyvsp[(2) - (2)].e), e, '+');
            if ((yyvsp[(2) - (2)].e).ptr != SYM_PTR) {
              printf("%d\n", (yyvsp[(2) - (2)].e).type);
              error("lvalue required as increment operand");
            }
            out_assign((yyvsp[(2) - (2)].e).val.sym->name, (yyval.e));
          ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 569 "src/gramm.y"
    { 
            struct expr_type e = create_const_expr("1");
            parse_expr(&(yyval.e), (yyvsp[(2) - (2)].e), e, '-');
            /* TODO: Think about how pointers behave here */
            if ((yyvsp[(2) - (2)].e).ptr != SYM_PTR) {
              error("lvalue required as increment operand");
            }
            out_assign((yyvsp[(2) - (2)].e).val.sym->name, (yyval.e));
          ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 579 "src/gramm.y"
    {
            if (!is_coercible((yyvsp[(2) - (4)].type), (yyvsp[(4) - (4)].e).type))
              error("types are not coercible");
            (yyval.e).type = (yyvsp[(2) - (4)].type);
            (yyval.e).val.quad_no = next_quad;
            (yyval.e).ptr = QUAD_PTR;
            out_gen_quad((yyvsp[(4) - (4)].e));
          ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 588 "src/gramm.y"
    {
            if (!is_array((yyvsp[(2) - (2)].e).type) || !is_pointer((yyvsp[(2) - (2)].e).type))
              error("Attempting to dereference non-pointer");
            (yyval.e).val.quad_no = next_quad;
            (yyval.e).ptr = QUAD_PTR;
            (yyval.e).type = pointer_deref((yyvsp[(2) - (2)].e).type);
            out_deref((yyvsp[(2) - (2)].e));
          ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 596 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), '*'); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 597 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), '/'); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 598 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), '%'); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 599 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), '+'); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 600 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), '-'); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 601 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), LSHFT_OP); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 602 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), RSHFT_OP); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 603 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), '>'); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 604 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), '<'); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 605 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), LE_OP); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 606 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), GE_OP); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 607 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), EQ_OP); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 608 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), NE_OP); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 609 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), '|'); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 610 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), '^'); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 611 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), '&'); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 612 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), AND_OP); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 613 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e),  OR_OP); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 615 "src/gramm.y"
    { 
            if ((yyvsp[(1) - (3)].e).ptr != SYM_PTR) {
              error("Assignment should have an assignable on the left");
            }
            out_assign((yyvsp[(1) - (3)].e).val.sym->name, (yyvsp[(3) - (3)].e));
          ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 624 "src/gramm.y"
    {
              (yyval.e) = (yyvsp[(2) - (3)].e);
              if (!is_int_expr((yyvsp[(2) - (3)].e))) // or convertible to int
                error("array subscript is not an integer");
            ;}
    break;



/* Line 1455 of yacc.c  */
#line 2528 "gen/y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 631 "src/gramm.y"


struct bigop bigops[] = {
    {OR_OP, "||"},
    {AND_OP, "&&"},
    {EQ_OP, "=="},
    {NE_OP, "!="},
    {LE_OP, "<="},
    {GE_OP, ">="},
    {LSHFT_OP, "<<"},
    {RSHFT_OP, ">>"},
    {INC_OP, "++"},
    {DEC_OP, "--"}
};

int
main ()
{
  printf("In main");
  /* TODO: Parse args properly */
  outfile = fopen(DEFAULT_OUT, "w+");
  if (!outfile) {
    printf("Error opening output file\n");
    exit(1);
  }

  init_globals();
  init_tables();

  yyparse ();
}

void
init_globals() {
  int i;
  BIGOPS_NUM = sizeof(bigops);
  // Current loop information
  cur_loop.patch = cur_loop.label = -1;
  // temporary number
  next_quad = 0;
  // label and patch system
  label_no = 1; patch_idx = 0;
  nested = NULL;
  for (i = 0; i< MAX_NEST_DEPTH; ++i)
    patches[i] = 0;
  scope.level = scope.label = scope.over = 0;
}

yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s\n", s);
}

void
error (char *msg) {
  printf("%s\n", msg);
  exit(1);
}

struct init
{
  char *fname;
  double (*fnct)();
};


void
out_assign(char *name, struct expr_type expr) {
  char *s;
  int mf = assign_name_to_buf(&s, expr);

  fprintf(outfile, "%s = %s\n", name, s);

  if (mf) free(s);
  return;
}

void 
out_gen_quad (struct expr_type e) {
  char *temp = malloc(10 * sizeof(int));
  temp_var_name(next_quad++, temp);
  out_assign(temp, e);

  free(temp);
  return;
}

int
out_jmp(struct expr_type *e, void *label, int type) {
  char *ltext, *cond, *name; int i = -1;
  int mf1 = 0, mf2 = 0;
  if (!label) {
    // 5 spaces, temporarily so that label name can be accomodated
    mf1 = 1;
    i = 0;
    while(i < MAX_NEST_DEPTH && i < patches[i])
      i++;

    if (i == MAX_NEST_DEPTH)
      error("Can't nest more than 256 levels");

    make_patch_text(&ltext, i);
    patches[i] = 1;
  }
  else {
    if (type == JUMP_LABEL_NUMBER) {
      mf1 = 1;
      make_label_text(&ltext, *((int *)label));
    }
    else if (type == JUMP_LABEL_NAME)
      ltext = (char *)label;
    else {
      // Jump to patch number
      mf1 = 1;
      make_patch_text(&ltext, *((int *) label));

    }
  }

  if (e) {
    cond = malloc(100 * sizeof(char));
    mf2 = assign_name_to_buf(&name, *e);
    printf("Befor cond print\n");
    snprintf(cond, 100, "if ( %s == 0 )\n", name);
    printf(cond);
  }
  else 
    cond = "";

  fprintf(outfile, "%s goto %s\n", cond, ltext);

  if (mf1)  free(ltext);
  if (e) free(cond);
  if (mf2) free(name);

  return i;
}

void backpatch(int label, int patch) {
  int tp; int write_pos; int temp_pos;
  int cur_pos = ftell(outfile); 
  char c;
  char *ltext; 

  make_label_text(&ltext, label);
  fseek(outfile, 0, SEEK_SET);
  printf("before loop%d\n", ftell(outfile));
  while ((c = getc(outfile)) != EOF) {
    if (c != '$')
      continue;
    write_pos = ftell(outfile) - 1;
    fscanf(outfile, "%d", &tp);
    temp_pos = ftell(outfile);
    if (tp == patch) {
      fseek(outfile, write_pos, SEEK_SET);
      fprintf(outfile, "%s", ltext);
    }
    fseek(outfile, temp_pos, SEEK_SET);
  } 
  printf("after loop\n");


  fseek(outfile, cur_pos, SEEK_SET);
  patches[patch] = 0;
  free(ltext);
}


void
parse_unary_expr (struct expr_type *result, 
              struct expr_type e1, int op) {
    // Check for coercibility here
    int qno = next_quad;
    make_two_quad(e1, op);
    result->ptr = QUAD_PTR; result->val.quad_no = qno;
    // $$.type = MAX($1.type, $3.type);
}


void
parse_expr (struct expr_type *result, struct expr_type e1,
          struct expr_type e2, int op) {
    // Check for coercibility here
    int qno = next_quad;
    make_quad(e1, e2, op);
    result->ptr = QUAD_PTR; result->val.quad_no = qno;
    // $$.type = MAX($1.type, $3.type);
}

void
make_two_quad (struct expr_type e1, int op) {
    // Store line number in quad table if needed
    char tname[10]; temp_var_name(next_quad, tname);    
        
    char *s1; int mf1 = 0;
    mf1 = assign_name_to_buf(&s1, e1);

    fprintf(outfile, "%s = %c %s \n", tname, (char)op, s1);
    next_quad++;

    if (mf1) free(s1);
    return;
}

void
make_quad (struct expr_type e1, struct expr_type e2, int op) {
    // Store line number in quad table if needed
    char tname[10]; temp_var_name(next_quad, tname);   
    int idx = -1, i;
    for (i = 0; i < BIGOPS_NUM; ++i) {
      if (bigops[i].op == op)
        idx = i;
    }     
        
    char *s1, *s2; int mf1 = 0, mf2 = 0;
    mf1 = assign_name_to_buf(&s1, e1);
    mf1 = assign_name_to_buf(&s2, e2);   

    if (idx == -1)
      fprintf(outfile, "%s = %s %c %s\n", tname, s1, (char)op, s2);
    else
      fprintf(outfile, "%s = %s %s %s\n", tname, s1, bigops[idx].str, s2);

    next_quad++;

    if (mf1) free(s1);
    if (mf2) free(s2);

    return;
}


struct expr_type
out_member_ref (struct expr_type e, char *mem) {
  struct expr_type ret;
  if (e.type.ttype != COMPOUND_TYPE)
    error("request for member in something not a structure or union");
  int oft = struct_calc_offset(e.type.val.stype, mem);
  if (oft == -1)
    error("struct has no member named this");
  ret.type = struct_get_elem(e.type.val.stype, oft);
  ret.val.quad_no = next_quad;
  ret.ptr = QUAD_PTR;

  out_const_index(e, oft);
  return ret;
}

void
out_index (struct expr_type e, struct expr_type idx) {
  char *name, *iname, tname[10]; int mf, imf;
  imf = assign_name_to_buf(&iname, idx);
  mf = assign_name_to_buf(&name, e);
  temp_var_name(next_quad++, tname);
  fprintf(outfile, "%s = %s [%s]\n", tname, name, iname);

  if (mf) free(name);
  if (imf) free(iname);
}

void 
out_const_index (struct expr_type e, const int c) {
  /* TODO: Take care of sizes (10 here) by allocating
   * global buffers maybe */
  char *const_str = malloc(10 * sizeof(int));
  snprintf(const_str, 10, "%d", c);
  out_index(e, create_const_expr(const_str));
  free(const_str);
}

void 
out_deref (struct expr_type e) {
  if (is_array(e.type))
    out_const_index(e, 0); // Index at offset 0
  char *temp, *name; int mf;
  mf = assign_name_to_buf(&name, e);
  temp = malloc(10 * sizeof(char));
  temp_var_name(next_quad++, temp);

  fprintf(outfile, "%s = * %s\n", temp, name);
  free(temp);
  if (mf) free(name);
}

void out_label () {
  char *ltext; 
  make_label_text(&ltext, label_no++);
  printf("In outlabel %d\n", label_no - 1);
  fprintf(outfile, "%s: ", ltext);
  free(ltext);
  printf("At end\n");
}
