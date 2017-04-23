
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
#include "func.h"
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

struct func_rec *active_func;

// Builtin type info.
void init_globals();



/* Line 189 of yacc.c  */
#line 112 "gen/y.tab.c"

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
#line 44 "src/gramm.y"

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
#line 224 "gen/y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 236 "gen/y.tab.c"

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
#define YYLAST   745

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNRULES -- Number of states.  */
#define YYNSTATES  195

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
      70,    60,    56,    55,    47,    54,    64,    57,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    68,    69,
      52,    48,    53,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    73,    50,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    71,    51,    72,    62,     2,     2,     2,
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
       0,     0,     3,     4,     7,     9,    11,    13,    16,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    38,
      42,    45,    48,    55,    56,    57,    60,    62,    63,    65,
      69,    72,    78,    79,    80,    83,    86,    92,    95,    97,
      99,   101,   102,   104,   107,   108,   110,   114,   116,   120,
     124,   127,   129,   132,   135,   139,   141,   144,   149,   152,
     157,   162,   164,   168,   172,   174,   177,   179,   184,   187,
     191,   193,   195,   197,   199,   201,   203,   206,   207,   209,
     211,   215,   217,   222,   224,   226,   227,   229,   233,   235,
     238,   242,   245,   248,   251,   254,   257,   262,   265,   269,
     273,   277,   281,   285,   289,   293,   297,   301,   305,   309,
     313,   317,   321,   325,   329,   333,   337,   341
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      75,     0,    -1,    -1,    75,    76,    -1,   110,    -1,    92,
      -1,    81,    -1,    78,    77,    -1,    -1,   110,    -1,   103,
      -1,   102,    -1,     1,    -1,   107,    -1,   104,    -1,    89,
      -1,    79,    -1,    80,    -1,    45,    68,    -1,    42,   121,
      69,    -1,    42,    69,    -1,    82,    89,    -1,    85,    83,
      70,    86,    60,    84,    -1,    -1,    -1,   114,    45,    -1,
      87,    -1,    -1,    88,    -1,    88,    47,    87,    -1,   114,
     113,    -1,    90,    71,    77,    72,    91,    -1,    -1,    -1,
     101,    69,    -1,    93,    69,    -1,    94,    96,    71,    97,
      72,    -1,    94,    95,    -1,    29,    -1,    30,    -1,    45,
      -1,    -1,    95,    -1,    99,    98,    -1,    -1,    97,    -1,
     114,   100,    69,    -1,    45,    -1,    45,    47,   100,    -1,
      13,   114,    45,    -1,   121,    69,    -1,    69,    -1,    40,
      69,    -1,    41,    69,    -1,    39,    45,    69,    -1,   105,
      -1,   106,    78,    -1,    36,    70,   121,    60,    -1,   108,
      78,    -1,   108,    78,   109,    78,    -1,    66,    70,   121,
      60,    -1,    67,    -1,   114,   111,    69,    -1,   112,    47,
     111,    -1,   112,    -1,   113,   115,    -1,    45,    -1,   113,
      65,    44,    73,    -1,    56,   113,    -1,    70,   113,    60,
      -1,    20,    -1,    24,    -1,    18,    -1,    28,    -1,    93,
      -1,    46,    -1,    48,   121,    -1,    -1,    44,    -1,    45,
      -1,    70,   121,    60,    -1,   117,    -1,   118,    70,   119,
      60,    -1,    45,    -1,   120,    -1,    -1,   121,    -1,   121,
      47,   120,    -1,   116,    -1,   121,   122,    -1,   121,    64,
      45,    -1,    61,   121,    -1,    62,   121,    -1,    54,   121,
      -1,    11,   121,    -1,    12,   121,    -1,    70,   114,    60,
     121,    -1,    56,   121,    -1,   121,    56,   121,    -1,   121,
      57,   121,    -1,   121,    58,   121,    -1,   121,    55,   121,
      -1,   121,    54,   121,    -1,   121,     9,   121,    -1,   121,
      10,   121,    -1,   121,    53,   121,    -1,   121,    52,   121,
      -1,   121,     7,   121,    -1,   121,     8,   121,    -1,   121,
       5,   121,    -1,   121,     6,   121,    -1,   121,    51,   121,
      -1,   121,    50,   121,    -1,   121,    49,   121,    -1,   121,
       4,   121,    -1,   121,     3,   121,    -1,   121,    48,   121,
      -1,    65,   121,    73,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   127,   127,   128,   131,   132,   133,   136,   137,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   152,   155,
     156,   161,   170,   177,   179,   182,   197,   198,   201,   202,
     205,   241,   245,   256,   264,   265,   272,   286,   305,   306,
     309,   316,   317,   322,   334,   335,   338,   352,   356,   362,
     376,   377,   381,   388,   394,   397,   402,   412,   422,   427,
     436,   443,   450,   488,   489,   493,   514,   523,   541,   550,
     557,   558,   559,   560,   561,   562,   565,   566,   570,   576,
     584,   585,   589,   622,   624,   625,   626,   632,   643,   644,
     645,   646,   647,   648,   649,   659,   669,   678,   687,   688,
     689,   690,   691,   692,   693,   694,   695,   696,   697,   698,
     699,   700,   701,   702,   703,   704,   706,   709
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
  "'!'", "'~'", "UMINUS", "'.'", "'['", "IF", "ELSE", "':'", "';'", "'('",
  "'{'", "'}'", "']'", "$accept", "input", "global_statement", "body",
  "body_statement", "label_stmt", "return_statement",
  "function_definition", "func_head", "begin_params", "end_params",
  "res_id", "param_decl_list", "param_list", "param_decl",
  "block_statement", "begin_sub", "end_sub", "type_definition",
  "compound_type", "type_type", "ctype_name", "opt_ctype_name",
  "member_decl_list", "opt_member_decl_list", "member_decl", "id_list",
  "aliasing", "expression_statement", "jump_statement",
  "iterative_statement", "while_loop", "while_clause",
  "selection_statement", "if_clause", "else_clause",
  "declaration_statement", "var_dlist", "var_definition", "symbol_name",
  "type_name", "opt_init", "primary_expr", "function_call", "func_name",
  "actual_params_list", "actual_params", "expr", "indexing", 0
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
      41,    33,   126,   303,    46,    91,   304,   305,    58,    59,
      40,   123,   125,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    75,    76,    76,    76,    77,    77,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    79,    80,
      80,    81,    82,    83,    84,    85,    86,    86,    87,    87,
      88,    89,    90,    91,    92,    92,    93,    93,    94,    94,
      95,    96,    96,    97,    98,    98,    99,   100,   100,   101,
     102,   102,   103,   103,   103,   104,   105,   106,   107,   107,
     108,   109,   110,   111,   111,   112,   113,   113,   113,   113,
     114,   114,   114,   114,   114,   114,   115,   115,   116,   116,
     116,   116,   117,   118,   119,   119,   120,   120,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   122
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     2,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       2,     2,     6,     0,     0,     2,     1,     0,     1,     3,
       2,     5,     0,     0,     2,     2,     5,     2,     1,     1,
       1,     0,     1,     2,     0,     1,     3,     1,     3,     3,
       2,     1,     2,     2,     3,     1,     2,     4,     2,     4,
       4,     1,     3,     3,     1,     2,     1,     4,     2,     3,
       1,     1,     1,     1,     1,     1,     2,     0,     1,     1,
       3,     1,     4,     1,     1,     0,     1,     3,     1,     2,
       3,     2,     2,     2,     2,     2,     4,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,    72,    70,    71,    73,    38,    39,
      75,     3,     6,    32,    23,     5,    74,    41,     0,     4,
       0,    74,     0,    21,     0,     0,    35,    40,    37,     0,
      34,    66,     0,     0,     0,    64,    77,    49,     0,    27,
       0,    66,    68,     0,    62,     0,     0,     0,    65,    12,
       0,     0,     0,     0,     0,     0,     0,    78,    79,     0,
       0,     0,     0,     0,    51,     0,     0,     0,    16,    17,
      15,    11,    10,    14,    55,     0,    13,     0,     9,     0,
      88,    81,     0,     0,     0,    26,    28,     0,     0,    44,
       0,    69,    63,    79,    76,     0,    94,    95,     0,     0,
      52,    53,    20,     0,    18,    93,    97,    91,    92,     0,
       0,     0,    33,     7,    56,    58,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,    89,
      24,     0,    30,    36,    45,    43,    47,     0,    67,     0,
      54,    19,     0,     0,    80,    31,    61,     0,     0,    84,
      86,   115,   114,   109,   110,   107,   108,   103,   104,   116,
     113,   112,   111,   106,   105,   102,   101,    98,    99,   100,
      90,     0,    22,    29,     0,    46,    57,    60,    96,    59,
      82,     0,   117,    48,    87
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    11,    66,    67,    68,    69,    12,    13,    25,
     182,    14,    84,    85,    86,    70,    24,   155,    15,    21,
      17,    28,    29,    88,   145,    89,   147,    18,    71,    72,
      73,    74,    75,    76,    77,   157,    78,    34,    35,    36,
      79,    48,    80,    81,    82,   158,   159,    83,   139
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -67
static const yytype_int16 yypact[] =
{
     -67,   159,   -67,     9,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -66,   -24,   -29,   -67,
     -34,   -67,    -1,   -67,   -59,   -16,   -67,   -67,   -11,    -9,
     -67,    22,    53,    53,    27,    50,   -31,   -67,    92,     9,
       9,   -67,    34,   -30,   -67,    53,    57,    61,   -67,   -67,
      57,    57,    36,    63,    46,    48,    -3,   -67,   -25,    57,
      57,    57,    57,    54,   -67,   675,    58,    92,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   156,   -67,   156,   -67,    53,
     -67,   -67,    55,   251,    66,   -67,    82,    53,    72,     9,
      90,   -67,   -67,    77,   503,    78,    30,    30,    57,    83,
     -67,   -67,   -67,   318,   -67,    30,    30,    30,    30,    57,
      95,   340,   -67,   -67,   -67,    89,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,   115,    57,   -67,   -67,
     -67,     9,    34,   -67,   -67,   -67,   118,   100,   -67,   403,
     -67,   -67,   421,    57,   -67,   -67,   -67,   156,   110,   -67,
     440,   520,   537,   277,   277,    -8,    -8,    85,    85,   503,
     598,   613,   627,    -8,    -8,   -33,   -33,    30,    30,    30,
     -67,   225,   -67,   -67,    90,   -67,   -67,   -67,    30,   -67,
     -67,    57,   -67,   -67,   -67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -67,   -67,   -67,   104,   -57,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,    32,   -67,   162,   -67,   -67,   -67,   177,
     -67,   -67,   -67,    93,   -67,   -67,     6,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   180,   146,   -67,   -26,
      25,   -67,   -67,   -67,   -67,   -67,     2,   -46,   -67
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -84
static const yytype_int16 yytable[] =
{
      94,   123,   124,    26,    96,    97,    42,    43,    50,    51,
     103,    31,    38,   105,   106,   107,   108,    46,   114,   111,
     115,    27,    32,   133,   134,   135,    20,     4,    22,     5,
      91,   136,   137,     6,    47,    47,    33,     7,     8,     9,
      30,    57,    93,   104,    37,   -83,   131,   132,   133,   134,
     135,    59,   149,    60,    39,    10,   136,   137,    61,    62,
     -42,   142,    40,   152,    87,    90,   102,    65,    50,    51,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     110,   181,   -25,    49,   136,   137,    44,    45,    41,    47,
     189,    57,    93,    50,    51,    95,    98,   188,    99,    32,
       4,    59,     5,    60,    90,   100,     6,   101,    61,    62,
       7,     8,     9,    33,   109,   116,   140,    65,    52,   141,
     112,    53,    54,    55,    56,   146,    57,    58,    10,   131,
     132,   133,   134,   135,   143,   160,    59,   -83,    60,   136,
     137,   148,   150,    61,    62,   153,   156,    49,    63,     2,
     180,    64,    65,   -32,    -8,   184,    87,    50,    51,   185,
     190,   113,     3,   183,     4,    23,     5,     4,    16,     5,
       6,    19,   144,     6,     7,     8,     9,     7,     8,     9,
     193,    92,    52,   194,     0,    53,    54,    55,    56,     0,
      57,    58,    10,     0,     0,    10,     0,     0,     0,     0,
      59,     0,    60,     0,     0,     0,     0,    61,    62,     0,
       0,     0,    63,     0,     0,    64,    65,   -32,   117,   118,
     119,   120,   121,   122,   123,   124,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   117,   118,   119,   120,   121,   122,
     123,   124,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   121,   122,   123,   124,     0,   136,
     137,     0,     0,     0,     0,     0,     0,     0,   192,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
       0,     0,     0,     0,     0,   136,   137,     0,     0,     0,
     138,   117,   118,   119,   120,   121,   122,   123,   124,   129,
     130,   131,   132,   133,   134,   135,     0,     0,     0,     0,
       0,   136,   137,   117,   118,   119,   120,   121,   122,   123,
     124,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,     0,     0,     0,
       0,     0,   136,   137,     0,     0,     0,   151,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
     154,     0,     0,     0,   136,   137,   117,   118,   119,   120,
     121,   122,   123,   124,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   117,   118,   119,   120,   121,   122,
     123,   124,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,     0,   186,     0,     0,     0,   136,   137,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
       0,   187,     0,     0,     0,   136,   137,   191,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,     0,     0,     0,   136,   137,   117,   118,   119,   120,
     121,   122,   123,   124,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   118,   119,   120,   121,   122,   123,
     124,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   119,   120,   121,   122,   123,   124,     0,     0,
       0,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,     0,     0,     0,     0,     0,   136,   137,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,     0,
       0,     0,     0,     0,   136,   137,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,     0,     0,     0,     0,
       0,   136,   137,   119,   120,   121,   122,   123,   124,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   119,   120,
     121,   122,   123,   124,     0,     0,     0,     0,     0,     0,
       0,     0,   119,   120,   121,   122,   123,   124,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   127,   128,
     129,   130,   131,   132,   133,   134,   135,     0,     0,     0,
       0,     0,   136,   137,   128,   129,   130,   131,   132,   133,
     134,   135,     0,     0,     0,     0,     0,   136,   137,   129,
     130,   131,   132,   133,   134,   135,    50,    51,     0,     0,
       0,   136,   137,     4,     0,     5,     0,     0,     0,     6,
       0,     0,     0,     7,     8,     9,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
      93,    10,     0,     0,     0,     0,     0,     0,     0,    59,
       0,    60,     0,     0,     0,     0,    61,    62,     0,     0,
       0,     0,     0,     0,     0,    65
};

static const yytype_int16 yycheck[] =
{
      46,     9,    10,    69,    50,    51,    32,    33,    11,    12,
      56,    45,    71,    59,    60,    61,    62,    48,    75,    65,
      77,    45,    56,    56,    57,    58,     1,    18,     3,    20,
      60,    64,    65,    24,    65,    65,    70,    28,    29,    30,
      69,    44,    45,    68,    45,    70,    54,    55,    56,    57,
      58,    54,    98,    56,    70,    46,    64,    65,    61,    62,
      71,    87,    71,   109,    39,    40,    69,    70,    11,    12,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
      65,   137,    70,     1,    64,    65,    69,    47,    45,    65,
     157,    44,    45,    11,    12,    44,    70,   153,    45,    56,
      18,    54,    20,    56,    89,    69,    24,    69,    61,    62,
      28,    29,    30,    70,    70,    70,    60,    70,    36,    47,
      72,    39,    40,    41,    42,    45,    44,    45,    46,    54,
      55,    56,    57,    58,    72,   191,    54,    70,    56,    64,
      65,    73,    69,    61,    62,    60,    67,     1,    66,     0,
      45,    69,    70,    71,    72,    47,   141,    11,    12,    69,
      60,    67,    13,   141,    18,    13,    20,    18,     1,    20,
      24,     1,    89,    24,    28,    29,    30,    28,    29,    30,
     184,    45,    36,   191,    -1,    39,    40,    41,    42,    -1,
      44,    45,    46,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      54,    -1,    56,    -1,    -1,    -1,    -1,    61,    62,    -1,
      -1,    -1,    66,    -1,    -1,    69,    70,    71,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,     7,     8,     9,    10,    -1,    64,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    64,    65,    -1,    -1,    -1,
      69,     3,     4,     5,     6,     7,     8,     9,    10,    52,
      53,    54,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      -1,    64,    65,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    -1,    64,    65,    -1,    -1,    -1,    69,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      60,    -1,    -1,    -1,    64,    65,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    60,    -1,    -1,    -1,    64,    65,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      -1,    60,    -1,    -1,    -1,    64,    65,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    64,    65,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,     6,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     5,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    -1,    64,    65,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    -1,
      -1,    -1,    -1,    -1,    64,    65,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    -1,    -1,    -1,    -1,
      -1,    64,    65,     5,     6,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     5,     6,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    -1,    -1,
      -1,    -1,    64,    65,    51,    52,    53,    54,    55,    56,
      57,    58,    -1,    -1,    -1,    -1,    -1,    64,    65,    52,
      53,    54,    55,    56,    57,    58,    11,    12,    -1,    -1,
      -1,    64,    65,    18,    -1,    20,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    28,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      -1,    56,    -1,    -1,    -1,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    75,     0,    13,    18,    20,    24,    28,    29,    30,
      46,    76,    81,    82,    85,    92,    93,    94,   101,   110,
     114,    93,   114,    89,    90,    83,    69,    45,    95,    96,
      69,    45,    56,    70,   111,   112,   113,    45,    71,    70,
      71,    45,   113,   113,    69,    47,    48,    65,   115,     1,
      11,    12,    36,    39,    40,    41,    42,    44,    45,    54,
      56,    61,    62,    66,    69,    70,    77,    78,    79,    80,
      89,   102,   103,   104,   105,   106,   107,   108,   110,   114,
     116,   117,   118,   121,    86,    87,    88,   114,    97,    99,
     114,    60,   111,    45,   121,    44,   121,   121,    70,    45,
      69,    69,    69,   121,    68,   121,   121,   121,   121,    70,
     114,   121,    72,    77,    78,    78,    70,     3,     4,     5,
       6,     7,     8,     9,    10,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    64,    65,    69,   122,
      60,    47,   113,    72,    97,    98,    45,   100,    73,   121,
      69,    69,   121,    60,    60,    91,    67,   109,   119,   120,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   121,   121,   121,
      45,   121,    84,    87,    47,    69,    60,    60,   121,    78,
      60,    47,    73,   100,   120
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
#line 131 "src/gramm.y"
    {;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 132 "src/gramm.y"
    {;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 133 "src/gramm.y"
    {;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 136 "src/gramm.y"
    {;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 140 "src/gramm.y"
    {;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 141 "src/gramm.y"
    {;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 142 "src/gramm.y"
    {;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 143 "src/gramm.y"
    { yyerrok; ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 144 "src/gramm.y"
    {;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 145 "src/gramm.y"
    {;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 146 "src/gramm.y"
    {;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 147 "src/gramm.y"
    {;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 148 "src/gramm.y"
    {;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 152 "src/gramm.y"
    { fprintf(outfile, "%s: ", (yyvsp[(1) - (2)].id_name)); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 155 "src/gramm.y"
    { out_return(&(yyvsp[(2) - (3)].e)); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 156 "src/gramm.y"
    { out_return(NULL); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 162 "src/gramm.y"
    {
              active_func = NULL;
              scope.level--;

              out_end_func();        
            ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 171 "src/gramm.y"
    {
              active_func->label = label_no;
              out_begin_func();
            ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 177 "src/gramm.y"
    { scope.level++; scope.label = label_no; ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 179 "src/gramm.y"
    { scope.level--; ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 183 "src/gramm.y"
    {
            struct func_rec *func;
            if (func = search_func((yyvsp[(2) - (2)].id_name))) {
              if (func->defined)
                error("Redefinition of function");
              /* Check if the prot. is not consistent with head */
              active_func = func;
            }
            else {
              active_func = create_func((yyvsp[(2) - (2)].id_name), (yyvsp[(1) - (2)].type));
            }
          ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 206 "src/gramm.y"
    {
                struct array_type arr;
                symrec *sym = getsym(active_func, (yyvsp[(2) - (2)].sym_npt).name);
                if (sym && sym->scope.level == scope.level)
                  error("Redefinition of parameter");
                sym = putsym(active_func, (yyvsp[(2) - (2)].sym_npt).name, (yyvsp[(1) - (2)].type), scope);
                create_param(active_func, sym);

                if (sym->type.ttype == INCOMPL_TYPE) {
                  arr = (yyvsp[(2) - (2)].sym_npt).type.array;
                  if ((yyvsp[(1) - (2)].type).ttype == INCOMPL_TYPE)
                    error("incomplete type for varibale");
                  sym->type = (yyvsp[(1) - (2)].type);
                  sym->type.array = arr;
                }
                else if (sym->type.ttype == PTR_TYPE) {
                  struct type *t = sym->type.val.ptr_to;
                  // Travese the list of ptr types
                  while (t->ttype == PTR_TYPE)
                    t = t->val.ptr_to;
                  // Set the type of the last node to the basic
                  // or compound type that is type_name
                  if (t->ttype == INCOMPL_TYPE) {
                    arr = (*t).array;
                    *t = (yyvsp[(1) - (2)].type);
                    (*t).array = arr;
                  }
                }
                  // TODO: Relloc in the entire ptr_to linked list
                  // sym->type.array.dimen = realloc(sym->type.array.dimen, sym->type.array.n * sizeof(int));
              ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 245 "src/gramm.y"
    {
                scope.label = label_no;
                // Push scope info onto stack
                list_prepend_elem(&nested, 
                  list_create_elem((void *)label_no));
                scope.level++;
                out_label();
              ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 256 "src/gramm.y"
    {
                list_pop_front(&nested);
                scope.label = (int) nested->data;
                delsym_scope(scope.level);
                scope.level--;
              ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 273 "src/gramm.y"
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

  case 37:

/* Line 1455 of yacc.c  */
#line 287 "src/gramm.y"
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

  case 38:

/* Line 1455 of yacc.c  */
#line 305 "src/gramm.y"
    { (yyval.ttype) = STRUCT_TAG; ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 306 "src/gramm.y"
    { (yyval.ttype) = UNION_TAG; ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 310 "src/gramm.y"
    {
                copy_name(&(yyval.t_name), (yyvsp[(1) - (1)].id_name));
                printf("%s\n", (yyval.t_name));
              ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 316 "src/gramm.y"
    { (yyval.t_name) = ""; ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 317 "src/gramm.y"
    { (yyval.t_name) = (yyvsp[(1) - (1)].t_name); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 323 "src/gramm.y"
    {
                // Join the two lists. 
                struct memb_list *mem = (yyvsp[(1) - (2)].tlist);
                while (mem->next)
                  mem = mem->next;
                mem->next = (yyvsp[(2) - (2)].tlist);
                (yyval.tlist) = (yyvsp[(1) - (2)].tlist);
              ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 334 "src/gramm.y"
    { (yyval.tlist) = NULL; ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 335 "src/gramm.y"
    { (yyval.tlist) = (yyvsp[(1) - (1)].tlist); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 339 "src/gramm.y"
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

  case 47:

/* Line 1455 of yacc.c  */
#line 353 "src/gramm.y"
    {
                    (yyval.tlist) = create_member((yyvsp[(1) - (1)].id_name), NULL);
                  ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 357 "src/gramm.y"
    {
                    (yyval.tlist) = create_member((yyvsp[(1) - (3)].id_name), (yyvsp[(3) - (3)].tlist)); 
                  ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 363 "src/gramm.y"
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

  case 52:

/* Line 1455 of yacc.c  */
#line 382 "src/gramm.y"
    { 
                    printf("%d", cur_loop.label);
                    if (cur_loop.label == -1)
                      error("continue statement not within a loop");
                    out_jmp(NULL, &cur_loop.label, JUMP_LABEL_NUMBER); 
                  ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 389 "src/gramm.y"
    { 
                    if (cur_loop.label == -1)
                      error("break statement not within a loop or a switch");
                    out_jmp(NULL, &cur_loop.patch, JUMP_PATCH); 
                  ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 394 "src/gramm.y"
    { out_jmp(NULL, (void *)(yyvsp[(2) - (3)].id_name), JUMP_LABEL_NAME); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 403 "src/gramm.y"
    {
                        out_jmp(NULL, &((yyvsp[(1) - (2)].loop).this.label), JUMP_LABEL_NUMBER);
                        int label = label_no;
                        out_label();
                        backpatch(label, (yyvsp[(1) - (2)].loop).this.patch);
                        cur_loop = (yyvsp[(1) - (2)].loop).prev;
                      ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 413 "src/gramm.y"
    {
                        (yyval.loop).prev = cur_loop; 
                        (yyval.loop).this.label = label_no;
                        out_label();
                        (yyval.loop).this.patch = out_jmp(&(yyvsp[(3) - (4)].e), (void *)NULL, 0);
                        cur_loop = (yyval.loop).this;
                      ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 422 "src/gramm.y"
    {
                          int l_no = label_no;
                          out_label();
                          backpatch(l_no, (yyvsp[(1) - (2)].patch)); 
                        ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 428 "src/gramm.y"
    {
                          int l_no = label_no;
                          out_label();
                          backpatch((yyvsp[(3) - (4)].dual_patch).label, (yyvsp[(1) - (4)].patch));
                          backpatch(l_no, (yyvsp[(3) - (4)].dual_patch).patch);
                       ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 436 "src/gramm.y"
    {
                // returns patch number
                (yyval.patch) = out_jmp(&(yyvsp[(3) - (4)].e), (void *)NULL, 0);
                printf("If clause done\n");
              ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 443 "src/gramm.y"
    {
                    (yyval.dual_patch).patch = out_jmp(NULL, NULL, 0);
                    (yyval.dual_patch).label = label_no;
                    out_label();
                 ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 451 "src/gramm.y"
    {
                          struct list *node = (yyvsp[(2) - (3)].l);
                          struct symrec *sym;
                          /* TODO: Check for completeness of 
                            type here */
                          if ((yyvsp[(1) - (3)].type).ttype == UNDEF_TYPE)
                            error("incomplete type");
                          if (is_void_type((yyvsp[(1) - (3)].type)))
                            error("Void type varible declaration");

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

  case 63:

/* Line 1455 of yacc.c  */
#line 488 "src/gramm.y"
    { list_prepend_elem(&(yyvsp[(3) - (3)].l), (yyvsp[(1) - (3)].l)); (yyval.l) = (yyvsp[(3) - (3)].l); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 489 "src/gramm.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 494 "src/gramm.y"
    {
                    symrec *rec = getsym((yyvsp[(1) - (2)].sym_npt).name, scope);
                    if (rec && rec->scope.level == scope.level) {
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

  case 66:

/* Line 1455 of yacc.c  */
#line 515 "src/gramm.y"
    {
                copy_name(&(yyval.sym_npt).name, (yyvsp[(1) - (1)].id_name));
                // Create a new symbol table record
                // and assign it the thing from the old record  
                (yyval.sym_npt).type.ttype = INCOMPL_TYPE; 
                SET_NOT_ARRAY((yyval.sym_npt).type);
              ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 524 "src/gramm.y"
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

  case 68:

/* Line 1455 of yacc.c  */
#line 542 "src/gramm.y"
    {
                struct type *to = malloc(sizeof(struct type));
                *to = (yyvsp[(2) - (2)].sym_npt).type; // TYPE COPYING
                (yyval.sym_npt).type.ttype = PTR_TYPE;
                (yyval.sym_npt).type.val.ptr_to = to;
                SET_NOT_ARRAY((yyval.sym_npt).type);
                (yyval.sym_npt).name = (yyvsp[(2) - (2)].sym_npt).name;
              ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 550 "src/gramm.y"
    { (yyval.sym_npt) = (yyvsp[(2) - (3)].sym_npt); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 557 "src/gramm.y"
    { (yyval.type) = basic_types[INT_TYPE].t; ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 558 "src/gramm.y"
    { (yyval.type) = basic_types[FLOAT_TYPE].t; ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 559 "src/gramm.y"
    { (yyval.type) = basic_types[CHAR_TYPE].t; ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 560 "src/gramm.y"
    { (yyval.type) = basic_types[VOID_TYPE].t; ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 561 "src/gramm.y"
    { (yyval.type) = (yyvsp[(1) - (1)].type); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 562 "src/gramm.y"
    { (yyval.type) = *(yyvsp[(1) - (1)].alias_type); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 565 "src/gramm.y"
    { printf("In opt_init"); (yyval.e) = (yyvsp[(2) - (2)].e); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 566 "src/gramm.y"
    { (yyval.e).type.ttype = UNDEF_TYPE; ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 570 "src/gramm.y"
    { 
                  char *temp;
                  copy_name(&temp, (yyvsp[(1) - (1)].e).val.const_str);
                  (yyval.e) = create_const_expr(temp);
                  SET_NOT_DEREF((yyval.e));
                ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 576 "src/gramm.y"
    { 
                  symrec *rec = getsym((yyvsp[(1) - (1)].id_name), scope);
                  if (!rec) {
                    error("Undefined symbol\n");
                  }
                  (yyval.e) = create_sym_expr(rec);
                  SET_NOT_DEREF((yyval.e));
                ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 584 "src/gramm.y"
    { (yyval.e) = (yyvsp[(2) - (3)].e); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 585 "src/gramm.y"
    { (yyval.e) = (yyvsp[(1) - (1)].e); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 590 "src/gramm.y"
    {
                  struct func_rec *func = search_func((yyvsp[(1) - (4)].id_name));
                  if (!func)
                    error("Undefined function");

                  struct list *fp = func->param_list;
                  struct list *ap = (yyvsp[(3) - (4)].l);

                  struct type t;
                  struct expr_type *e; int arg_num = 0;

                  while (fp && ap) {
                    arg_num++;
                    t = ((symrec *)fp->data)->type;
                    e = (struct expr_type *)ap->data;
                    if (!is_equiv(t, e->type) && !is_coercible(t, e->type))
                      error("incompatible type for argument");
                    out_param(*e);
                  }

                  if (!fp || !ap)
                    error("argument number mismatch");

                  (yyval.e).ptr = QUAD_PTR; (yyval.e).val.quad_no = next_quad;
                  (yyval.e).type = func->ret_type;
                  SET_NOT_DEREF((yyval.e));
                  out_call(func);

                  /*TODO: Free every shit*/
                ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 622 "src/gramm.y"
    { copy_name(&(yyval.id_name), (yyvsp[(1) - (1)].id_name)); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 624 "src/gramm.y"
    { (yyval.l) = (yyvsp[(1) - (1)].l); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 625 "src/gramm.y"
    { (yyval.l) = NULL; ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 627 "src/gramm.y"
    {
                  struct expr_type *e = malloc(sizeof(struct expr_type));
                  *e = (yyvsp[(1) - (1)].e);
                  (yyval.l) = list_create_elem(e);
                ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 633 "src/gramm.y"
    {
                  struct expr_type *e = malloc(sizeof(struct expr_type));
                  *e = (yyvsp[(1) - (3)].e);
                  list_prepend_elem(&(yyvsp[(3) - (3)].l), list_create_elem(e));
                  (yyval.l) = (yyvsp[(3) - (3)].l);
                ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 643 "src/gramm.y"
    { (yyval.e) = (yyvsp[(1) - (1)].e); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 644 "src/gramm.y"
    { (yyval.e) = parse_indexed_expr((yyvsp[(1) - (2)].e), (yyvsp[(2) - (2)].e)); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 645 "src/gramm.y"
    { out_member_ref((yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].id_name)); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 646 "src/gramm.y"
    { parse_unary_expr(&(yyval.e), (yyvsp[(2) - (2)].e), '!'); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 647 "src/gramm.y"
    { parse_unary_expr(&(yyval.e), (yyvsp[(2) - (2)].e), '~'); ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 648 "src/gramm.y"
    { parse_unary_expr(&(yyval.e), (yyvsp[(2) - (2)].e), '-'); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 650 "src/gramm.y"
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

  case 95:

/* Line 1455 of yacc.c  */
#line 660 "src/gramm.y"
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

  case 96:

/* Line 1455 of yacc.c  */
#line 670 "src/gramm.y"
    {
            if (!is_coercible((yyvsp[(2) - (4)].type), (yyvsp[(4) - (4)].e).type))
              error("types are not coercible");
            (yyval.e).type = (yyvsp[(2) - (4)].type);
            (yyval.e).val.quad_no = next_quad;
            (yyval.e).ptr = QUAD_PTR;
            out_gen_quad((yyvsp[(4) - (4)].e));
          ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 679 "src/gramm.y"
    {
            /* Delayed eval */
            if (is_indexed((yyvsp[(2) - (2)].e)) || is_derefd((yyvsp[(2) - (2)].e)))
              (yyval.e) = get_vector_elem((yyvsp[(2) - (2)].e));
            if (!is_array((yyval.e).type) && !is_pointer((yyval.e).type))
              error("Attempting to dereference non-pointer");
            /* deref'd whenever used */
          ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 687 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), '*'); ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 688 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), '/'); ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 689 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), '%'); ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 690 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), '+'); ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 691 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), '-'); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 692 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), LSHFT_OP); ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 693 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), RSHFT_OP); ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 694 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), '>'); ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 695 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), '<'); ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 696 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), LE_OP); ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 697 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), GE_OP); ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 698 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), EQ_OP); ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 699 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), NE_OP); ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 700 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), '|'); ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 701 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), '^'); ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 702 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), '&'); ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 703 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e), AND_OP); ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 704 "src/gramm.y"
    { parse_expr(&(yyval.e), (yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e),  OR_OP); ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 706 "src/gramm.y"
    { parse_assignment((yyvsp[(1) - (3)].e), (yyvsp[(3) - (3)].e)); (yyval.e) = (yyvsp[(1) - (3)].e); ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 710 "src/gramm.y"
    {
              if (is_indexed((yyvsp[(2) - (3)].e)) || is_derefd((yyvsp[(2) - (3)].e)))
                (yyval.e) = get_vector_elem((yyvsp[(2) - (3)].e));
              else
                (yyval.e) = (yyvsp[(2) - (3)].e);
              if (!is_int_expr((yyval.e))) // or convertible to int
                error("array subscript is not an integer");
            ;}
    break;



/* Line 1455 of yacc.c  */
#line 2781 "gen/y.tab.c"
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
#line 720 "src/gramm.y"


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
  printf("error: %s\n", msg);
  exit(1);
}

void
warning (char *msg) {
  printf("warning: %s\n", msg);
}

struct init
{
  char *fname;
  double (*fnct)();
};


void
out_assign(char *name, struct expr_type expr) {
  char *s = NULL;
  assign_name_to_buf(&s, expr);

  fprintf(outfile, "%s = %s\n", name, s);

  free(s);
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
  char *ltext, *cond, *name = NULL; int i = -1;
  int mf1;
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
    assign_name_to_buf(&name, *e);
    printf("Befor cond print\n");
    snprintf(cond, 100, "if ( %s == 0 )\n", name);
    printf(cond);
  }
  else 
    cond = "";

  fprintf(outfile, "%s goto %s\n", cond, ltext);

  if (mf1)  free(ltext);
  if (e) free(cond);
  free(name);

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
    if (is_indexed(e1) || is_derefd(e1))
      e1 = get_vector_elem(e1);
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
  if (is_indexed(e1) || is_derefd(e1))
    e1 = get_vector_elem(e1);
  if (is_indexed(e2) || is_derefd(e2))
    e2 = get_vector_elem(e2);
  int qno = next_quad;
  make_quad(e1, e2, op);
  result->ptr = QUAD_PTR; result->val.quad_no = qno;
  SET_NOT_DEREF((*result));
  // $$.type = MAX($1.type, $3.type);
}

void
make_two_quad (struct expr_type e1, int op) {
    // Store line number in quad table if needed
    char tname[10]; temp_var_name(next_quad, tname);    
        
    char *s1 = NULL;
    assign_name_to_buf(&s1, e1);

    fprintf(outfile, "%s = %c %s \n", tname, (char)op, s1);
    next_quad++;

    free(s1);
    return;
}

void
make_quad_by_name (char *e1, char *e2, int op) {
  char tname[10]; temp_var_name(next_quad++, tname);
  int i, idx;
  for (i = 0; i < BIGOPS_NUM; ++i) {
    if (bigops[i].op == op)
      idx = i;
  }
  if (idx == -1)
    fprintf(outfile, "%s = %s %c %s\n", tname, e1, (char)op, e2);
  else
    fprintf(outfile, "%s = %s %s %s\n", tname, e1, bigops[idx].str, e2);
  return;
}

void
make_quad_with_const (struct expr_type e, char *const_str, int op) {
  char *name = NULL; int mf;
  assign_name_to_buf(&name, e);
  make_quad_by_name(name, const_str, op);

  free(name);
}

void
make_quad (struct expr_type e1, struct expr_type e2, int op) {        
    char *s1 = NULL, *s2 = NULL;
    assign_name_to_buf(&s1, e1);
    assign_name_to_buf(&s2, e2);   

    make_quad_by_name(s1, s2, op);

    free(s1); free(s2);
    return;
}

/* TODO: Change */
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
out_vector_offset (struct expr_type e, struct expr_type idx) {
  char *const_str; char *mname = NULL; 
  int oft_temp = next_quad++;
  int sz_target;
  if (is_pointer(e.type))
    sz_target = size_of(*e.type.val.ptr_to);
  else {
    struct array_type *t = &e.type.array;
    sz_target = t->size - t->dimen[0];
  }
  int d = digits(sz_target);
  const_str = malloc(d * sizeof(int));
  snprintf(const_str, d, "%d", sz_target);
  assign_name_to_buf(&mname, idx);
  make_quad_by_name(mname, const_str, '*');

  free(mname);
  return;
}

void
out_index (struct expr_type e) {
  int oft_temp = next_quad, mf;
  char *name = NULL;
  out_vector_offset(e, *e.deref.idx);

  char tname[10], oft_name[10]; 
  assign_name_to_buf(&name, e);

  temp_var_name(next_quad++, tname);
  temp_var_name(oft_temp, oft_name);

  fprintf(outfile, "%s = %s [%s]\n", tname, name, oft_name);

  free(name);
}

void
out_const_index (struct expr_type e, const int c) {
  /* TODO: Take care of sizes (10 here) by allocating
   * global buffers maybe */
  char *name = NULL;
  assign_name_to_buf(&name, e);
  struct type *t = &e.type;
  int oft = (t->array.size / t->array.dimen[0]) * base_size_of(*t);
  // struct type redd = out_index(e, create_const_expr(const_str));
  fprintf(outfile, "_t%d = %s[%d]", next_quad++, name, c);

  free(name);
  return;
}

/* Called only for pointer dereferencing */
void
out_deref (struct expr_type e) {
  char *temp, *name = NULL;
  assign_name_to_buf(&name, e);
  temp = malloc(10 * sizeof(char));
  temp_var_name(next_quad++, temp);

  fprintf(outfile, "%s = * %s\n", temp, name);

  free(temp);  free(name);
}

/* Generated just above, for exmaple: int *p;
 * a = p[5] becomes _t0 = 5 * sizeof(*p);
 * _t1 = p + _t0; a = *_t1; */
void
out_deref_by_index (struct expr_type e) {
  struct expr_type final_ptr; 
  /* Get offset in bytes _t0 = 5 * sizeof(*p) */
  int oft_temp = next_quad;
  out_vector_offset(e, *e.deref.idx);

  /* Add offset to base address _t1 = p + _t0 */
  char oft[10]; char *base = NULL; 
  int final_addr = next_quad;
  assign_name_to_buf(&base, e);
  temp_var_name(oft_temp, oft);
  make_quad_by_name(base, oft, '+');

  /* Dereference the final address */
  final_ptr.type = e.type; 
  final_ptr.ptr = QUAD_PTR;
  final_ptr.val.quad_no = next_quad;
  final_ptr.deref = e.deref;

  out_deref(final_ptr);

  free(base);
}

/* e contains the details of the dereference */
struct expr_type
get_vector_elem (struct expr_type e) {
  struct expr_type ret;
  SET_NOT_DEREF(ret);
  ret.ptr = QUAD_PTR;
  ret.val.quad_no = next_quad; 
  if (is_array(e.type)) {
    if (is_derefd(e)) 
      out_const_index(e, 0);
    else
      out_index(e);
    ret.type = arr_reduce_dimen(e.type);
  }
  else {
    /* expr is a pointer type */
    if (is_derefd(e))
      out_deref(e);
    else {
      ret.val.quad_no += 2;
      out_deref_by_index(e);
    }
    ret.type = *(e.type.val.ptr_to);
  }
  return ret;
}

void out_label () {
  char *ltext; 
  make_label_text(&ltext, label_no++);
  printf("In outlabel %d\n", label_no - 1);
  fprintf(outfile, "%s: ", ltext);
  free(ltext);
  printf("At end\n");
}


struct expr_type
compound_indexing (struct expr_type e, struct expr_type idx) {
  struct expr_type ret = e;
  int incr_size = e.type.array.size - e.type.array.dimen[0];
  char const_str[MAX_INT_SIZE];  snprintf(const_str, MAX_INT_SIZE, "%d", incr_size);

  make_quad_with_const(*(e.deref.idx), const_str, '*');
  int t = next_quad; char temp[20];
  temp_var_name(t, temp);
  make_quad_with_const(idx, temp, '+');

  ret.type = arr_reduce_dimen(ret.type);
  ret.deref.idx->ptr = QUAD_PTR;
  ret.deref.idx->val.quad_no = t;

  return ret;
}

struct expr_type
parse_indexed_expr (struct expr_type e, struct expr_type idx) {
  struct expr_type ret;
  if (is_indexed(e)) {
    if (e.type.array.n <= 1)
      error("subscripted value is neither array nor pointer nor vector");
    return compound_indexing(e, idx);
  }
  if (is_derefd(e))
    e = get_vector_elem(e);
  if (!is_array(e.type) && !is_pointer(e.type))
    error("subscripted value is neither array nor pointer nor vector");
  ret = e; ret.deref.type = INDEX_EXPR;
  ret.deref.idx = malloc(sizeof(struct expr_type));
  *(ret.deref.idx) = idx;

  return ret;
}

int 
sout_expr_with_deref (char *buf, struct expr_type e) {
  int t1 = next_quad; char *name = NULL;
  assign_name_to_buf(&name, e);
  if (is_derefd(e)) {
    return sprintf(buf, "*%s ", name);
  }
  else {
    out_vector_offset(e, *e.deref.idx);
    return sprintf(buf, "%s[_t%d] ", name, t1);
  }

}

void
out_assign_expr (struct expr_type lval, struct expr_type rval) {
  char *assign = malloc(2 * MAX_IDENTIFIER_SIZE * sizeof(char));
  int pos = 0;
  pos += sout_expr_with_deref(assign, lval);
  assign[pos++] = '='; assign[pos++] = ' ';
  pos += sout_expr_with_deref(assign + pos, rval);
  assign[pos - 1] = '\n';
  fprintf(outfile, assign);

  free(assign);
  return;
}

void
parse_assignment (struct expr_type lval, struct expr_type rval) {
  struct expr_type result; 
  if (is_void_type(rval.type))
    error("void value not ignored as it ought to be");

  if (!is_assignable(lval))
    error("error: lvalue required as left operand of assignment");
  if (is_equiv(lval.type, rval.type)) {
    out_assign_expr(lval, rval);
    return;
  }
  if (is_coercible(lval.type, rval.type)) {
    /* Warning goes here */
    out_assign_expr(lval, rval);
    return;
  } 
  
  /* Inconvertible, eg. incompatible types when assigning
   * to type 'float' from type 'int *' */
  error("Incompatible types for assignment");

}

void
out_begin_func () {
  fprintf(outfile, "FUNCTION BEGIN:\n");
}

void
out_end_func () {
  fprintf(outfile, "FUNCTION END\n");
}

void
out_return (struct expr_type *e) {
  if (!e) {
    if (!is_void_type(active_func->ret_type))
      warning("'return' with no value, in function returning non-void");
    fprintf(outfile, "return\n");
    return;
  }

  if (is_void_type(active_func->ret_type)) 
    warning("'return' with a value, in function returning void");

  else if (!is_equiv(e->type, active_func->ret_type)) {
    if (!is_coercible(e->type, active_func->ret_type))
      error("incompatible types when returning type");
  }

  char *name = NULL; assign_name_to_buf(&name, *e);
  fprintf(outfile, "return %s\n", name);

  free(name);
}


void
out_param (struct expr_type e) {
  char *name = NULL;
  assign_name_to_buf(&name, e);

  fprintf(outfile, "param %s", name);
  free(name);
}

void
out_call (struct func_rec *f) {
  if (!is_void_type(f->ret_type))
    fprintf(outfile, "param _result\n");
  fprintf(outfile, "call %s, %d\n", f->name, f->num_param);
  if (!is_void_type(f->ret_type))
    fprintf(outfile, "_t%d = _result\n", next_quad++);

  return;
}
