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
#line 1 "grammar.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>

#include "defs.h"
#include "common.h"
#include "arbre.h"

/* Global variables */
static int nb_node = 0;
// à compléter

/* prototypes */
node_t make_node(node_nature nature, int nb_arg, ...);
node_t make_final_node(node_nature nature, int nb_arg, ...);
int yylex(void);
extern int yylineno;

void yyerror(char *s);

// à compléter


#line 95 "y.tab.c" /* yacc.c:339  */

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
    TOK_VOID = 258,
    TOK_INT = 259,
    TOK_INTVAL = 260,
    TOK_BOOL = 261,
    TOK_TRUE = 262,
    TOK_FALSE = 263,
    TOK_IDENT = 264,
    TOK_IF = 265,
    TOK_ELSE = 266,
    TOK_WHILE = 267,
    TOK_FOR = 268,
    TOK_PRINT = 269,
    TOK_AFFECT = 270,
    TOK_GE = 271,
    TOK_LE = 272,
    TOK_GT = 273,
    TOK_LT = 274,
    TOK_EQ = 275,
    TOK_NE = 276,
    TOK_PLUS = 277,
    TOK_MINUS = 278,
    TOK_MUL = 279,
    TOK_DIV = 280,
    TOK_MOD = 281,
    TOK_UMINUS = 282,
    TOK_SEMICOL = 283,
    TOK_COMMA = 284,
    TOK_LPAR = 285,
    TOK_RPAR = 286,
    TOK_LACC = 287,
    TOK_RACC = 288,
    TOK_STRING = 289,
    TOK_DO = 290,
    TOK_THEN = 291,
    TOK_OR = 292,
    TOK_AND = 293,
    TOK_BOR = 294,
    TOK_BXOR = 295,
    TOK_BAND = 296,
    TOK_SRL = 297,
    TOK_SRA = 298,
    TOK_SLL = 299,
    TOK_NOT = 300,
    TOK_BNOT = 301
  };
#endif
/* Tokens.  */
#define TOK_VOID 258
#define TOK_INT 259
#define TOK_INTVAL 260
#define TOK_BOOL 261
#define TOK_TRUE 262
#define TOK_FALSE 263
#define TOK_IDENT 264
#define TOK_IF 265
#define TOK_ELSE 266
#define TOK_WHILE 267
#define TOK_FOR 268
#define TOK_PRINT 269
#define TOK_AFFECT 270
#define TOK_GE 271
#define TOK_LE 272
#define TOK_GT 273
#define TOK_LT 274
#define TOK_EQ 275
#define TOK_NE 276
#define TOK_PLUS 277
#define TOK_MINUS 278
#define TOK_MUL 279
#define TOK_DIV 280
#define TOK_MOD 281
#define TOK_UMINUS 282
#define TOK_SEMICOL 283
#define TOK_COMMA 284
#define TOK_LPAR 285
#define TOK_RPAR 286
#define TOK_LACC 287
#define TOK_RACC 288
#define TOK_STRING 289
#define TOK_DO 290
#define TOK_THEN 291
#define TOK_OR 292
#define TOK_AND 293
#define TOK_BOR 294
#define TOK_BXOR 295
#define TOK_BAND 296
#define TOK_SRL 297
#define TOK_SRA 298
#define TOK_SLL 299
#define TOK_NOT 300
#define TOK_BNOT 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 30 "grammar.y" /* yacc.c:355  */

    int32_t intval;
    char* strval;
    node_t ptr;

#line 233 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 250 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   575

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  129

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   124,   124,   129,   136,   141,   146,   150,   156,   162,
     166,   170,   176,   180,   186,   190,   196,   202,   207,   212,
     216,   222,   226,   230,   234,   238,   242,   246,   250,   254,
     260,   266,   270,   274,   278,   282,   286,   290,   294,   298,
     302,   306,   310,   314,   318,   322,   326,   330,   334,   338,
     342,   346,   350,   354,   358,   362,   366,   370,   374,   380,
     384,   390,   394,   400
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_VOID", "TOK_INT", "TOK_INTVAL",
  "TOK_BOOL", "TOK_TRUE", "TOK_FALSE", "TOK_IDENT", "TOK_IF", "TOK_ELSE",
  "TOK_WHILE", "TOK_FOR", "TOK_PRINT", "TOK_AFFECT", "TOK_GE", "TOK_LE",
  "TOK_GT", "TOK_LT", "TOK_EQ", "TOK_NE", "TOK_PLUS", "TOK_MINUS",
  "TOK_MUL", "TOK_DIV", "TOK_MOD", "TOK_UMINUS", "TOK_SEMICOL",
  "TOK_COMMA", "TOK_LPAR", "TOK_RPAR", "TOK_LACC", "TOK_RACC",
  "TOK_STRING", "TOK_DO", "TOK_THEN", "TOK_OR", "TOK_AND", "TOK_BOR",
  "TOK_BXOR", "TOK_BAND", "TOK_SRL", "TOK_SRA", "TOK_SLL", "TOK_NOT",
  "TOK_BNOT", "$accept", "program", "listdecl", "listdeclnonnull",
  "vardecl", "type", "listtypedecl", "decl", "maindecl", "listinst",
  "listinstnonnull", "inst", "block", "expr", "listparamprint",
  "paramprint", "ident", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF -26

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-26)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      55,   -26,   -26,   -26,     3,    55,   -26,    39,   -26,   -26,
     -26,   -26,   -26,    62,   -26,   -13,   -26,    39,    47,    22,
     -26,    51,   -26,   -26,   -26,    47,    47,    47,    47,   325,
      53,    25,   -26,    93,   -26,   -26,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    47,    47,    55,   -26,   -26,   508,
     520,   485,   497,   445,   474,    97,    -5,   -10,    49,   -26,
     354,   365,   394,   405,   434,   531,   459,   -17,   325,    37,
      55,    39,    48,    56,    58,    64,   -26,    37,    65,    37,
     -26,   -26,   122,    47,    47,    47,     9,    83,   -26,   -26,
     -26,   151,   180,   209,   -26,    42,   -26,   -26,    69,    37,
      37,    47,     9,    73,    47,    92,   -26,   238,   -26,   -26,
     267,    37,    47,    76,   -26,   296,   -26,    37,   -26
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    11,     9,    10,     0,     0,     6,     0,     3,     1,
       7,     2,    63,     0,    12,    14,     8,     0,     0,     0,
      13,    14,    55,    56,    57,     0,     0,     0,     0,    15,
      58,     0,    38,     0,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,    16,    53,    39,
      40,    37,    36,    41,    42,    33,    34,    31,    32,    35,
      44,    43,    46,    47,    45,    48,    49,    50,    54,    18,
       4,     0,     0,     0,     0,     0,    28,     0,     0,    17,
      19,    27,     0,     0,     0,     0,     0,     0,    30,    20,
      21,     0,     0,     0,    62,     0,    60,    61,     0,     0,
       0,     0,     0,     0,     0,    23,    24,     0,    59,    29,
       0,     0,     0,     0,    22,     0,    26,     0,    25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -26,   -26,   -26,    50,    -4,     7,   -26,    90,   120,   -26,
     -26,   -25,    95,   -14,   -26,    15,    -7
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,    79,     5,     6,     7,    13,    14,     8,    88,
      89,    90,    91,    92,   105,   106,    30
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      15,    10,    18,     9,    29,    42,    43,    44,    45,    46,
      21,    32,    33,    34,    35,    45,    46,    19,    12,    44,
      45,    46,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    22,   104,    23,    24,    12,    82,    12,    83,
      84,    85,    22,    31,    23,    24,    12,    56,     1,     2,
      25,     3,    97,    81,    99,    86,    18,    26,    55,    56,
      25,   112,    87,   113,    21,    46,    10,    26,    93,   101,
     102,   103,    27,    28,   115,   116,    94,    81,    95,   107,
      16,    17,    27,    28,    96,   108,   124,   117,    98,   114,
     120,   119,   128,   121,   126,   107,    80,    20,   125,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      43,    44,    45,    46,    58,    11,    57,   118,     0,     0,
      47,    48,    49,    50,    51,    52,    53,    54,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,     0,
     100,     0,     0,     0,     0,     0,     0,     0,     0,    47,
      48,    49,    50,    51,    52,    53,    54,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,     0,     0,
       0,     0,   109,     0,     0,     0,     0,     0,    47,    48,
      49,    50,    51,    52,    53,    54,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,     0,     0,     0,
       0,   110,     0,     0,     0,     0,     0,    47,    48,    49,
      50,    51,    52,    53,    54,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,     0,   111,     0,     0,
       0,     0,     0,     0,     0,     0,    47,    48,    49,    50,
      51,    52,    53,    54,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,     0,   122,     0,     0,     0,
       0,     0,     0,     0,     0,    47,    48,    49,    50,    51,
      52,    53,    54,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,     0,     0,     0,     0,   123,     0,
       0,     0,     0,     0,    47,    48,    49,    50,    51,    52,
      53,    54,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,     0,     0,     0,     0,   127,     0,     0,
       0,     0,     0,    47,    48,    49,    50,    51,    52,    53,
      54,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    47,    48,    49,    50,    51,    52,    53,    54,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    48,    49,    50,    51,    52,    53,    54,     0,
       0,     0,     0,     0,    49,    50,    51,    52,    53,    54,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,     0,     0,    50,    51,    52,    53,    54,     0,
       0,     0,     0,     0,     0,     0,    51,    52,    53,    54,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    36,    37,    38,    39,     0,    41,    42,    43,    44,
      45,    46,     0,     0,     0,     0,    52,    53,    54,     0,
       0,    42,    43,    44,    45,    46,     0,    52,    53,    54,
      36,    37,    38,    39,     0,     0,    42,    43,    44,    45,
      46,    36,    37,    54,    39,     0,     0,    42,    43,    44,
      45,    46,     0,    36,    37,     0,    52,    53,    54,    42,
      43,    44,    45,    46,     0,    37,     0,    52,    53,    54,
      42,    43,    44,    45,    46,     0,     0,     0,     0,    52,
      53,    54,    42,    43,    44,    45,    46,     0,     0,     0,
      52,    53,    54,    42,    43,    44,    45,    46,     0,     0,
       0,     0,    52,    53,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,    54
};

static const yytype_int8 yycheck[] =
{
       7,     5,    15,     0,    18,    22,    23,    24,    25,    26,
      17,    25,    26,    27,    28,    25,    26,    30,     9,    24,
      25,    26,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,     5,    34,     7,     8,     9,    10,     9,    12,
      13,    14,     5,    31,     7,     8,     9,    32,     3,     4,
      23,     6,    87,    56,    89,    28,    15,    30,    15,    32,
      23,    29,    35,    31,    81,    26,    80,    30,    30,    93,
      94,    95,    45,    46,   109,   110,    30,    80,    30,    96,
      28,    29,    45,    46,    30,    12,   121,   111,    33,    30,
     114,    28,   127,    11,    28,   112,    56,    17,   122,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      23,    24,    25,    26,    31,     5,    31,   112,    -1,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    -1,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    16,    17,    18,    19,    -1,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    42,    43,    44,    -1,
      -1,    22,    23,    24,    25,    26,    -1,    42,    43,    44,
      16,    17,    18,    19,    -1,    -1,    22,    23,    24,    25,
      26,    16,    17,    44,    19,    -1,    -1,    22,    23,    24,
      25,    26,    -1,    16,    17,    -1,    42,    43,    44,    22,
      23,    24,    25,    26,    -1,    17,    -1,    42,    43,    44,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    -1,    42,
      43,    44,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      42,    43,    44,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    -1,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     6,    48,    50,    51,    52,    55,     0,
      51,    55,     9,    53,    54,    63,    28,    29,    15,    30,
      54,    63,     5,     7,     8,    23,    30,    45,    46,    60,
      63,    31,    60,    60,    60,    60,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    37,    38,    39,
      40,    41,    42,    43,    44,    15,    32,    59,    31,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    49,
      50,    52,    10,    12,    13,    14,    28,    35,    56,    57,
      58,    59,    60,    30,    30,    30,    30,    58,    33,    58,
      28,    60,    60,    60,    34,    61,    62,    63,    12,    31,
      31,    28,    29,    31,    30,    58,    58,    60,    62,    28,
      60,    11,    28,    31,    58,    60,    28,    31,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    49,    49,    50,    50,    51,    52,
      52,    52,    53,    53,    54,    54,    55,    56,    56,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      59,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    61,
      61,    62,    62,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     0,     1,     2,     3,     1,
       1,     1,     1,     3,     1,     3,     5,     1,     0,     1,
       2,     2,     7,     5,     5,     9,     7,     1,     1,     5,
       4,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1
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
#line 125 "grammar.y" /* yacc.c:1646  */
    {
            		(yyval.ptr) = make_node(NODE_PROGRAM, 2, (yyvsp[-1].ptr), (yyvsp[0].ptr));
            		analyse_tree((yyval.ptr));
        		}
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 130 "grammar.y" /* yacc.c:1646  */
    {
            		(yyval.ptr) = make_node(NODE_PROGRAM, 2, NULL, (yyvsp[0].ptr));
            		analyse_tree((yyval.ptr));
        		}
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 137 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = (yyvsp[0].ptr);
                }
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 141 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = NULL;
                }
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 147 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = (yyvsp[0].ptr);
                }
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 151 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_LIST, 2, (yyvsp[-1].ptr), (yyvsp[0].ptr));
                }
#line 1548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 157 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_DECLS, 2, (yyvsp[-2].ptr), (yyvsp[-1].ptr));
                }
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 163 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_final_node(NODE_TYPE, 1, TYPE_INT);
                }
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 167 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_final_node(NODE_TYPE, 1, TYPE_BOOL);
                }
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 171 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_final_node(NODE_TYPE, 1, TYPE_VOID);
                }
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 177 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = (yyvsp[0].ptr);
                }
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 181 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_LIST, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                }
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 187 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_DECL, 2, (yyvsp[0].ptr), NULL);;
                }
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 191 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_DECL, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                }
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 197 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_FUNC, 3, (yyvsp[-4].ptr), (yyvsp[-3].ptr), (yyvsp[0].ptr));
                }
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 203 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = (yyvsp[0].ptr);
                }
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 207 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = NULL;
                }
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 213 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = (yyvsp[0].ptr);
                }
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 217 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_LIST, 2, (yyvsp[-1].ptr), (yyvsp[0].ptr));
                }
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 223 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = (yyvsp[-1].ptr);
                }
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 227 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_IF, 3, (yyvsp[-4].ptr), (yyvsp[-2].ptr), (yyvsp[0].ptr));
                }
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 231 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_IF, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                }
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 235 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_WHILE, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                }
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 239 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_FOR, 4, (yyvsp[-6].ptr), (yyvsp[-4].ptr), (yyvsp[-2].ptr), (yyvsp[0].ptr));
                }
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 243 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_DOWHILE, 2, (yyvsp[-5].ptr), (yyvsp[-2].ptr));
                }
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 247 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = (yyvsp[0].ptr);
                }
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 251 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = NULL;
                }
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 255 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_PRINT, 1, (yyvsp[-2].ptr));
                }
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 261 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_BLOCK, 2, (yyvsp[-2].ptr), (yyvsp[-1].ptr));
                }
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 267 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_MUL, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                }
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 271 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_DIV, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                }
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 275 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_PLUS, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                }
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 279 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_MINUS, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                }
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 283 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_MOD, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                }
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 287 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_LT, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                }
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 291 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_GT, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                }
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 295 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_UMINUS, 1, (yyvsp[0].ptr));
                }
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 299 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_GE, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                }
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 303 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_LE, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                }
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 307 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_EQ, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                }
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 311 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_NE, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                }
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 315 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_AND, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                }
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 319 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_OR, 2 , (yyvsp[-2].ptr), (yyvsp[0].ptr));
                }
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 323 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_BAND, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                }
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 327 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_BOR, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                }
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 331 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_BXOR, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                }
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 335 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_SRL, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                }
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 339 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_SRA, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                }
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 343 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_SLL, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                }
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 347 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_NOT, 1, (yyvsp[0].ptr));
                }
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 351 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_BNOT, 1, (yyvsp[0].ptr));
                }
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 355 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = (yyvsp[-1].ptr);
                }
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 359 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_AFFECT, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                }
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 363 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_final_node(NODE_INTVAL, 1, (yyvsp[0].intval));
                }
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 367 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_final_node(NODE_BOOLVAL, 1, 1);
                }
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 371 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_final_node(NODE_BOOLVAL, 1, 0);
                }
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 375 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = (yyvsp[0].ptr);
                }
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 381 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_node(NODE_LIST, 2, (yyvsp[-2].ptr), (yyvsp[0].ptr));
                }
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 385 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = (yyvsp[0].ptr);
                }
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 391 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = (yyvsp[0].ptr);
                }
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 395 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_final_node(NODE_STRINGVAL, 1, (yyvsp[0].strval));
                }
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 401 "grammar.y" /* yacc.c:1646  */
    {
                    (yyval.ptr) = make_final_node(NODE_IDENT, 1, (yyvsp[0].strval));
                }
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2000 "y.tab.c" /* yacc.c:1646  */
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
#line 406 "grammar.y" /* yacc.c:1906  */


/* à compléter : fonctions de création des noeuds de l'arbre */

node_t make_node(node_nature nature, int nb_arg, ...)
{
    node_t nn = (node_t)malloc(sizeof(node_s));
    if(nn == NULL)
    {
        printf("Allocation error!\n");
        exit(1);
    }

    nn->lineno = yylineno;
    nn->node_num = nb_node;
    nb_node++;

    nn->nature = nature;
    nn->nops = nb_arg;
    nn->opr = (node_t*)malloc(sizeof(node_t) * nb_arg);
    if(nn->opr == NULL)
    {
        printf("Allocation error!\n");
        exit(1);
    }

    va_list va;
    va_start(va, nb_arg);

    for(int i = 0; i < nb_arg; i++)
    {
        nn->opr[i] = va_arg(va, node_t);
    }

    va_end(va);


    return nn;
}

node_t make_final_node(node_nature nature, int nb_arg, ...)
{
    node_t nn = (node_t)malloc(sizeof(node_s));
    if(nn == NULL)
    {
        printf("Allocation error!\n");
        exit(1);
    }

    nn->lineno = yylineno;
    nn->node_num = nb_node;
    nb_node++;

    nn->nature = nature;
    nn->nops = 0;
    nn->opr = NULL;

    va_list va;
    va_start(va, nb_arg);

    switch(nn->nature)
    {
        case NODE_IDENT:
            nn->ident = va_arg(va, char*);
            break;

        case NODE_TYPE:
            nn->type = va_arg(va, int);
            break;

        case NODE_INTVAL:
            nn->type = TYPE_INT;
            nn->value = va_arg(va, int64_t);
            break;

        case NODE_BOOLVAL:
            nn->type = TYPE_BOOL;
            nn->value = va_arg(va, int64_t);
            break;

        case NODE_STRINGVAL:
            nn->type = TYPE_STRING;
            nn->str = va_arg(va, char*);
            break;

        default :
            break;
    }

    va_end(va);

    return nn;
}

void yyerror(char* s)
{
    fprintf(stderr, "Grammar Error line %d: %s\n", yylineno, s);
    exit(1);
}
