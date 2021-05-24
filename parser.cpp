/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <iostream>

    #include "ast.hpp"
    
    #define YYDEBUG 1
    #define YYINITDEPTH 10000
    int yylex(void);
    void yyerror(const char *);
    
    extern ASTNode* astRoot;

#line 85 "parser.cpp"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
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
    T_OPENBRACKET = 258,
    T_CLOSEBRACKET = 259,
    T_COMMA = 260,
    T_OPENPAREN = 261,
    T_CLOSEPAREN = 262,
    T_SEMICOLON = 263,
    T_PLUS = 264,
    T_MINUS = 265,
    T_MULTIPLY = 266,
    T_DIVIDE = 267,
    T_GREATER = 268,
    T_GREQ = 269,
    T_PERIOD = 270,
    T_LARROW = 271,
    T_EQUALS = 272,
    T_AND = 273,
    T_OR = 274,
    T_PRINT = 275,
    T_RETURN = 276,
    T_ASSIGNMENT = 277,
    T_IF = 278,
    T_ELSE = 279,
    T_WHILE = 280,
    T_NEW = 281,
    T_INT = 282,
    T_NONE = 283,
    T_TRUE = 284,
    T_FALSE = 285,
    T_NOT = 286,
    T_BOOL = 287,
    T_EXTENDS = 288,
    T_DO = 289,
    T_INTLITERAL = 290,
    T_NAME_IDENTIFIER = 291
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */



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
typedef yytype_uint8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   295

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  155

#define YYUNDEFTOK  2
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
static const yytype_uint8 yyrline[] =
{
       0,    70,    70,    73,    74,    76,    79,    80,    81,    82,
      85,    86,    87,    90,    91,    94,    98,    99,   102,   103,
     106,   110,   111,   114,   115,   118,   119,   120,   121,   122,
     123,   124,   125,   128,   129,   132,   133,   136,   139,   140,
     143,   144,   145,   146,   147,   148,   151,   152,   155,   156,
     159,   162,   166,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   191,   192,   195,   196,   199,   200
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_OPENBRACKET", "T_CLOSEBRACKET",
  "T_COMMA", "T_OPENPAREN", "T_CLOSEPAREN", "T_SEMICOLON", "T_PLUS",
  "T_MINUS", "T_MULTIPLY", "T_DIVIDE", "T_GREATER", "T_GREQ", "T_PERIOD",
  "T_LARROW", "T_EQUALS", "T_AND", "T_OR", "T_PRINT", "T_RETURN",
  "T_ASSIGNMENT", "T_IF", "T_ELSE", "T_WHILE", "T_NEW", "T_INT", "T_NONE",
  "T_TRUE", "T_FALSE", "T_NOT", "T_BOOL", "T_EXTENDS", "T_DO",
  "T_INTLITERAL", "T_NAME_IDENTIFIER", "$accept", "Start", "Class",
  "ClassB", "Type", "Members", "Member", "ReturnType", "Methods", "Method",
  "Parameters", "ParametersB", "Body", "Declaration", "DeclarationB",
  "Return", "Statement", "StatementB", "Assignment", "If", "While",
  "DoWhile", "print", "Expression", "MethodCall", "Arguments",
  "ArgumentsB", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

#define YYPACT_NINF (-105)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -105,    19,    -9,  -105,     5,    46,    -3,  -105,  -105,    -5,
      42,    35,    46,  -105,    41,  -105,    62,    48,  -105,    82,
    -105,    41,    -5,  -105,    46,  -105,    56,    87,    97,  -105,
     100,  -105,    91,    48,  -105,    69,    78,  -105,  -105,   113,
    -105,    49,   111,   111,   111,   111,   124,     1,    94,   128,
      49,  -105,   153,  -105,  -105,  -105,  -105,  -105,  -105,   126,
     111,   111,   108,  -105,  -105,   111,  -105,    29,   210,  -105,
     222,   140,   152,   157,   111,   109,   111,  -105,   118,  -105,
      94,  -105,   153,     1,  -105,  -105,  -105,   185,  -105,   130,
    -105,   112,  -105,   111,   111,   111,   111,   111,   111,   111,
     111,   111,  -105,   157,   157,     6,   257,   149,   155,    12,
     234,   131,  -105,   120,  -105,  -105,   111,   162,   127,   127,
    -105,  -105,    39,    39,    39,   278,   268,    75,    95,   147,
    -105,   111,   111,   111,  -105,  -105,  -105,   168,   159,  -105,
     173,   257,   174,   246,  -105,   181,   111,  -105,  -105,   157,
     198,    99,   177,  -105,  -105
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     2,     1,     0,     9,     0,    12,    11,    10,
       0,     0,     7,    14,     8,    19,     0,    22,     3,     0,
      13,     6,     0,    18,     9,    10,     0,     0,    21,    15,
       0,    24,     0,     0,     4,     0,     0,    17,    16,     0,
      23,    32,     0,     0,     0,     0,     0,    10,     0,     0,
      29,    31,    30,    39,    40,    41,    43,    44,    45,     0,
       0,     0,     0,    69,    70,     0,    68,    64,     0,    66,
       0,     0,     0,     0,    76,     0,     0,    36,     0,    20,
       0,    27,    26,     0,    28,    38,    42,     0,    63,    71,
      62,     0,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,    78,     0,    75,     0,
       0,     0,    34,     0,    25,    67,    76,    65,    53,    54,
      55,    56,    57,    58,    59,    60,    61,     0,     0,     0,
      73,     0,    76,     0,    46,    35,    33,     0,    49,    50,
       0,    77,     0,     0,    72,     0,     0,    74,    47,     0,
       0,     0,     0,    48,    51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -105,  -105,  -105,   164,   -11,  -105,   178,  -105,   188,    31,
    -105,  -105,  -105,  -105,   106,   -35,   -36,   -39,  -105,  -105,
    -105,  -105,  -105,   -40,   -41,  -104,  -105
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    10,    11,    12,    13,    39,    14,    15,
      27,    28,    49,    50,    78,    51,    52,    53,    54,    55,
      56,    57,    58,   106,    69,   107,   108
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      59,    17,    68,    70,    71,    72,    26,    74,     5,    59,
     129,    59,   137,    85,    82,    81,    75,    84,   132,     3,
      87,    88,    36,    76,    38,    90,    42,     4,   142,    44,
      48,    45,    59,    16,   133,    74,   110,   105,     6,    80,
      46,    59,    83,    85,    91,    23,    18,   114,    93,    94,
      95,    96,    23,   118,   119,   120,   121,   122,   123,   124,
     125,   126,    59,    59,    59,    24,    85,   127,   128,    42,
      43,    19,    44,     7,    45,     7,     7,    22,     8,   138,
       8,     8,     9,    46,    25,    47,    59,    59,    85,    85,
      29,   141,    31,   143,    32,    42,     7,    37,    44,   139,
      45,     8,    33,   153,    34,    25,   150,    35,    59,    46,
      59,    83,    85,   151,    40,    42,    41,    60,    44,    42,
      45,    61,    44,   111,    45,   111,   112,    73,   136,    46,
      77,    83,    79,    46,    86,    83,   116,    62,    95,    96,
      63,    64,    65,   103,    89,   109,    66,    67,   117,    93,
      94,    95,    96,    97,    98,   104,   130,    99,   100,   101,
     131,    93,    94,    95,    96,    97,    98,   135,   132,    99,
     100,   101,   140,    42,    43,   144,    44,    42,    45,   146,
      44,   147,    45,   145,   149,   154,   113,    46,    30,    83,
      20,    46,   115,    83,    93,    94,    95,    96,    97,    98,
      21,     0,    99,   100,   101,   152,     0,    93,    94,    95,
      96,    97,    98,     0,     0,    99,   100,   101,    92,    93,
      94,    95,    96,    97,    98,     0,     0,    99,   100,   101,
     102,    93,    94,    95,    96,    97,    98,     0,     0,    99,
     100,   101,   134,    93,    94,    95,    96,    97,    98,     0,
       0,    99,   100,   101,   148,    93,    94,    95,    96,    97,
      98,     0,     0,    99,   100,   101,    93,    94,    95,    96,
      97,    98,     0,     0,    99,   100,   101,    93,    94,    95,
      96,    97,    98,     0,     0,    99,   100,    93,    94,    95,
      96,    97,    98,     0,     0,    99
};

static const yytype_int16 yycheck[] =
{
      41,     6,    42,    43,    44,    45,    17,     6,     3,    50,
       4,    52,   116,    52,    50,    50,    15,    52,     6,     0,
      60,    61,    33,    22,    35,    65,    20,    36,   132,    23,
      41,    25,    73,    36,    22,     6,    76,    73,    33,    50,
      34,    82,    36,    82,    15,    14,     4,    82,     9,    10,
      11,    12,    21,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   103,   104,   105,     3,   105,   103,   104,    20,
      21,    36,    23,    27,    25,    27,    27,    36,    32,     4,
      32,    32,    36,    34,    36,    36,   127,   128,   127,   128,
       8,   131,    36,   133,     7,    20,    27,    28,    23,     4,
      25,    32,     5,     4,     4,    36,   146,    16,   149,    34,
     151,    36,   151,   149,    36,    20,     3,     6,    23,    20,
      25,    10,    23,     5,    25,     5,     8,     3,     8,    34,
      36,    36,     4,    34,     8,    36,     6,    26,    11,    12,
      29,    30,    31,     3,    36,    36,    35,    36,    36,     9,
      10,    11,    12,    13,    14,     3,     7,    17,    18,    19,
       5,     9,    10,    11,    12,    13,    14,    36,     6,    17,
      18,    19,    25,    20,    21,     7,    23,    20,    25,     6,
      23,     7,    25,    24,     3,     8,    80,    34,    24,    36,
      12,    34,     7,    36,     9,    10,    11,    12,    13,    14,
      12,    -1,    17,    18,    19,     7,    -1,     9,    10,    11,
      12,    13,    14,    -1,    -1,    17,    18,    19,     8,     9,
      10,    11,    12,    13,    14,    -1,    -1,    17,    18,    19,
       8,     9,    10,    11,    12,    13,    14,    -1,    -1,    17,
      18,    19,     8,     9,    10,    11,    12,    13,    14,    -1,
      -1,    17,    18,    19,     8,     9,    10,    11,    12,    13,
      14,    -1,    -1,    17,    18,    19,     9,    10,    11,    12,
      13,    14,    -1,    -1,    17,    18,    19,     9,    10,    11,
      12,    13,    14,    -1,    -1,    17,    18,     9,    10,    11,
      12,    13,    14,    -1,    -1,    17
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    39,     0,    36,     3,    33,    27,    32,    36,
      40,    41,    42,    43,    45,    46,    36,     6,     4,    36,
      43,    45,    36,    46,     3,    36,    41,    47,    48,     8,
      40,    36,     7,     5,     4,    16,    41,    28,    41,    44,
      36,     3,    20,    21,    23,    25,    34,    36,    41,    49,
      50,    52,    53,    54,    55,    56,    57,    58,    59,    61,
       6,    10,    26,    29,    30,    31,    35,    36,    60,    61,
      60,    60,    60,     3,     6,    15,    22,    36,    51,     4,
      41,    52,    53,    36,    52,    54,     8,    60,    60,    36,
      60,    15,     8,     9,    10,    11,    12,    13,    14,    17,
      18,    19,     8,     3,     3,    53,    60,    62,    63,    36,
      60,     5,     8,    51,    52,     7,     6,    36,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    53,    53,     4,
       7,     5,     6,    22,     8,    36,     8,    62,     4,     4,
      25,    60,    62,    60,     7,    24,     6,     7,     8,     3,
      60,    53,     7,     4,     8
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    39,    40,    40,    40,    40,
      41,    41,    41,    42,    42,    43,    44,    44,    45,    45,
      46,    47,    47,    48,    48,    49,    49,    49,    49,    49,
      49,    49,    49,    50,    50,    51,    51,    52,    53,    53,
      54,    54,    54,    54,    54,    54,    55,    55,    56,    56,
      57,    58,    59,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    61,    61,    62,    62,    63,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     5,     7,     0,     2,     1,     1,     0,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     1,
       9,     1,     0,     4,     2,     3,     2,     2,     2,     1,
       1,     1,     0,     4,     3,     3,     1,     3,     2,     1,
       1,     1,     2,     1,     1,     1,     4,     6,     9,     5,
       5,     9,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     1,     3,     1,     3,     1,     1,
       1,     2,     5,     4,     6,     1,     0,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 2:
#line 70 "parser.y"
              {(yyval.program_ptr) = new ProgramNode((yyvsp[0].class_list_ptr)); astRoot=(yyval.program_ptr);}
#line 1471 "parser.cpp"
    break;

  case 3:
#line 73 "parser.y"
                                                                    { (yyvsp[-1].class_ptr)->identifier_1 = new IdentifierNode((yyvsp[-3].base_char_ptr)); free((yyvsp[-3].base_char_ptr)); (yyval.class_list_ptr)=(yyvsp[-4].class_list_ptr); (yyval.class_list_ptr)->push_back((yyvsp[-1].class_ptr));}
#line 1477 "parser.cpp"
    break;

  case 4:
#line 75 "parser.y"
      { (yyvsp[-1].class_ptr)->identifier_1 = new IdentifierNode((yyvsp[-5].base_char_ptr)); free((yyvsp[-5].base_char_ptr)); (yyvsp[-1].class_ptr)->identifier_2 = new IdentifierNode((yyvsp[-3].base_char_ptr)); free((yyvsp[-3].base_char_ptr)); (yyval.class_list_ptr)=(yyvsp[-6].class_list_ptr); (yyval.class_list_ptr)->push_back((yyvsp[-1].class_ptr));}
#line 1483 "parser.cpp"
    break;

  case 5:
#line 76 "parser.y"
               {(yyval.class_list_ptr) = new std::list<ClassNode*>;}
#line 1489 "parser.cpp"
    break;

  case 6:
#line 79 "parser.y"
                         {(yyval.class_ptr) = new ClassNode(NULL,NULL,(yyvsp[-1].declaration_list_ptr),(yyvsp[0].method_list_ptr));}
#line 1495 "parser.cpp"
    break;

  case 7:
#line 80 "parser.y"
                 {(yyval.class_ptr) = new ClassNode(NULL,NULL,(yyvsp[0].declaration_list_ptr),NULL);}
#line 1501 "parser.cpp"
    break;

  case 8:
#line 81 "parser.y"
                 {(yyval.class_ptr) = new ClassNode(NULL,NULL,NULL,(yyvsp[0].method_list_ptr));}
#line 1507 "parser.cpp"
    break;

  case 9:
#line 82 "parser.y"
                {(yyval.class_ptr) = new ClassNode(NULL,NULL,NULL,NULL);}
#line 1513 "parser.cpp"
    break;

  case 10:
#line 85 "parser.y"
                         {(yyval.type_ptr) = new ObjectTypeNode(new IdentifierNode((yyvsp[0].base_char_ptr)));}
#line 1519 "parser.cpp"
    break;

  case 11:
#line 86 "parser.y"
              {(yyval.type_ptr) = new BooleanTypeNode();}
#line 1525 "parser.cpp"
    break;

  case 12:
#line 87 "parser.y"
             {(yyval.type_ptr) = new IntegerTypeNode();}
#line 1531 "parser.cpp"
    break;

  case 13:
#line 90 "parser.y"
                         {(yyval.declaration_list_ptr) = (yyvsp[-1].declaration_list_ptr) ; (yyval.declaration_list_ptr)->push_back((yyvsp[0].declaration_ptr));}
#line 1537 "parser.cpp"
    break;

  case 14:
#line 91 "parser.y"
                 {(yyval.declaration_list_ptr) = new std::list<DeclarationNode*>() ; (yyval.declaration_list_ptr)->push_back((yyvsp[0].declaration_ptr));}
#line 1543 "parser.cpp"
    break;

  case 15:
#line 95 "parser.y"
         {std::list<IdentifierNode*>* t = new std::list<IdentifierNode*>();t->push_back(new IdentifierNode((yyvsp[-1].base_char_ptr))); (yyval.declaration_ptr) = new DeclarationNode((yyvsp[-2].type_ptr),t);}
#line 1549 "parser.cpp"
    break;

  case 16:
#line 98 "parser.y"
                  {(yyval.type_ptr) = (yyvsp[0].type_ptr);}
#line 1555 "parser.cpp"
    break;

  case 17:
#line 99 "parser.y"
              {(yyval.type_ptr) = new NoneNode();}
#line 1561 "parser.cpp"
    break;

  case 18:
#line 102 "parser.y"
                          {(yyval.method_list_ptr) = (yyvsp[-1].method_list_ptr); (yyval.method_list_ptr)->push_back((yyvsp[0].method_ptr));}
#line 1567 "parser.cpp"
    break;

  case 19:
#line 103 "parser.y"
                 {(yyval.method_list_ptr) = new std::list<MethodNode*>();(yyval.method_list_ptr)->push_back((yyvsp[0].method_ptr));}
#line 1573 "parser.cpp"
    break;

  case 20:
#line 107 "parser.y"
         {(yyval.method_ptr) = new MethodNode(new IdentifierNode((yyvsp[-8].base_char_ptr)),(yyvsp[-6].parameter_list_ptr),(yyvsp[-3].type_ptr),(yyvsp[-1].methodbody_ptr));}
#line 1579 "parser.cpp"
    break;

  case 21:
#line 110 "parser.y"
                         {(yyval.parameter_list_ptr) = (yyvsp[0].parameter_list_ptr);}
#line 1585 "parser.cpp"
    break;

  case 22:
#line 111 "parser.y"
                   {(yyval.parameter_list_ptr) = new std::list<ParameterNode*>();}
#line 1591 "parser.cpp"
    break;

  case 23:
#line 114 "parser.y"
                                                         {(yyval.parameter_list_ptr) = (yyvsp[-3].parameter_list_ptr) ; (yyval.parameter_list_ptr)->push_back(new ParameterNode((yyvsp[-1].type_ptr),new IdentifierNode((yyvsp[0].base_char_ptr))));}
#line 1597 "parser.cpp"
    break;

  case 24:
#line 115 "parser.y"
                                    {(yyval.parameter_list_ptr) = new std::list<ParameterNode*>() ; (yyval.parameter_list_ptr)->push_back(new ParameterNode((yyvsp[-1].type_ptr),new IdentifierNode((yyvsp[0].base_char_ptr))));}
#line 1603 "parser.cpp"
    break;

  case 25:
#line 118 "parser.y"
                                    {(yyval.methodbody_ptr) = new MethodBodyNode((yyvsp[-2].declaration_list_ptr),(yyvsp[-1].statement_list_ptr),(yyvsp[0].returnstatement_ptr));}
#line 1609 "parser.cpp"
    break;

  case 26:
#line 119 "parser.y"
                             {(yyval.methodbody_ptr) = new MethodBodyNode((yyvsp[-1].declaration_list_ptr),(yyvsp[0].statement_list_ptr),NULL);}
#line 1615 "parser.cpp"
    break;

  case 27:
#line 120 "parser.y"
                          {(yyval.methodbody_ptr) = new MethodBodyNode((yyvsp[-1].declaration_list_ptr),NULL,(yyvsp[0].returnstatement_ptr));}
#line 1621 "parser.cpp"
    break;

  case 28:
#line 121 "parser.y"
                        {(yyval.methodbody_ptr) = new MethodBodyNode(NULL,(yyvsp[-1].statement_list_ptr),(yyvsp[0].returnstatement_ptr));}
#line 1627 "parser.cpp"
    break;

  case 29:
#line 122 "parser.y"
                   {(yyval.methodbody_ptr) = new MethodBodyNode((yyvsp[0].declaration_list_ptr),NULL,NULL);}
#line 1633 "parser.cpp"
    break;

  case 30:
#line 123 "parser.y"
                 {(yyval.methodbody_ptr) = new MethodBodyNode(NULL,(yyvsp[0].statement_list_ptr),NULL);}
#line 1639 "parser.cpp"
    break;

  case 31:
#line 124 "parser.y"
              {(yyval.methodbody_ptr) = new MethodBodyNode(NULL,NULL,(yyvsp[0].returnstatement_ptr));}
#line 1645 "parser.cpp"
    break;

  case 32:
#line 125 "parser.y"
              {(yyval.methodbody_ptr) = new MethodBodyNode(NULL,NULL,NULL);}
#line 1651 "parser.cpp"
    break;

  case 33:
#line 128 "parser.y"
                                                        {(yyval.declaration_list_ptr)=(yyvsp[-3].declaration_list_ptr),(yyval.declaration_list_ptr)->push_back(new DeclarationNode((yyvsp[-2].type_ptr),(yyvsp[-1].identifier_list_ptr)));}
#line 1657 "parser.cpp"
    break;

  case 34:
#line 129 "parser.y"
                                          {(yyval.declaration_list_ptr) = new std::list<DeclarationNode*>();(yyval.declaration_list_ptr)->push_back(new DeclarationNode((yyvsp[-2].type_ptr),(yyvsp[-1].identifier_list_ptr)));}
#line 1663 "parser.cpp"
    break;

  case 35:
#line 132 "parser.y"
                                                      {(yyval.identifier_list_ptr) = (yyvsp[-2].identifier_list_ptr); (yyval.identifier_list_ptr)->push_back(new IdentifierNode((yyvsp[0].base_char_ptr)));}
#line 1669 "parser.cpp"
    break;

  case 36:
#line 133 "parser.y"
                               {(yyval.identifier_list_ptr) = new std::list<IdentifierNode*>();(yyval.identifier_list_ptr)->push_back(new IdentifierNode((yyvsp[0].base_char_ptr)));}
#line 1675 "parser.cpp"
    break;

  case 37:
#line 136 "parser.y"
                                         {(yyval.returnstatement_ptr) = new ReturnStatementNode((yyvsp[-1].expression_ptr));}
#line 1681 "parser.cpp"
    break;

  case 38:
#line 139 "parser.y"
                                 {(yyval.statement_list_ptr) = (yyvsp[-1].statement_list_ptr); (yyval.statement_list_ptr)->push_back((yyvsp[0].statement_ptr));}
#line 1687 "parser.cpp"
    break;

  case 39:
#line 140 "parser.y"
                       {(yyval.statement_list_ptr) = new std::list<StatementNode*>();(yyval.statement_list_ptr)->push_back((yyvsp[0].statement_ptr));}
#line 1693 "parser.cpp"
    break;

  case 40:
#line 143 "parser.y"
                        { (yyval.statement_ptr) = (yyvsp[0].assignment_ptr); }
#line 1699 "parser.cpp"
    break;

  case 41:
#line 144 "parser.y"
                { (yyval.statement_ptr) = (yyvsp[0].ifelse_ptr); }
#line 1705 "parser.cpp"
    break;

  case 42:
#line 145 "parser.y"
                                    {(yyval.statement_ptr) = new CallNode((yyvsp[-1].methodcall_ptr));}
#line 1711 "parser.cpp"
    break;

  case 43:
#line 146 "parser.y"
                   { (yyval.statement_ptr) = (yyvsp[0].while_ptr); }
#line 1717 "parser.cpp"
    break;

  case 44:
#line 147 "parser.y"
                     { (yyval.statement_ptr) = (yyvsp[0].dowhile_ptr); }
#line 1723 "parser.cpp"
    break;

  case 45:
#line 148 "parser.y"
                   { (yyval.statement_ptr) = (yyvsp[0].print_ptr); }
#line 1729 "parser.cpp"
    break;

  case 46:
#line 151 "parser.y"
                                                                   {(yyval.assignment_ptr) = new AssignmentNode(new IdentifierNode((yyvsp[-3].base_char_ptr)),NULL,(yyvsp[-1].expression_ptr));}
#line 1735 "parser.cpp"
    break;

  case 47:
#line 152 "parser.y"
                                                                                              {(yyval.assignment_ptr) = new AssignmentNode(new IdentifierNode((yyvsp[-5].base_char_ptr)),new IdentifierNode((yyvsp[-3].base_char_ptr)),(yyvsp[-1].expression_ptr));}
#line 1741 "parser.cpp"
    break;

  case 48:
#line 155 "parser.y"
                                                                                                          { (yyval.ifelse_ptr) = new  IfElseNode((yyvsp[-7].expression_ptr),(yyvsp[-5].statement_list_ptr),(yyvsp[-1].statement_list_ptr));}
#line 1747 "parser.cpp"
    break;

  case 49:
#line 156 "parser.y"
                                                            { (yyval.ifelse_ptr) = new  IfElseNode((yyvsp[-3].expression_ptr),(yyvsp[-1].statement_list_ptr),NULL);}
#line 1753 "parser.cpp"
    break;

  case 50:
#line 159 "parser.y"
                                                                  { (yyval.while_ptr) = new  WhileNode((yyvsp[-3].expression_ptr),(yyvsp[-1].statement_list_ptr));}
#line 1759 "parser.cpp"
    break;

  case 51:
#line 163 "parser.y"
          {(yyval.dowhile_ptr) = new DoWhileNode((yyvsp[-6].statement_list_ptr),(yyvsp[-2].expression_ptr));}
#line 1765 "parser.cpp"
    break;

  case 52:
#line 166 "parser.y"
                                       {(yyval.print_ptr) = new PrintNode((yyvsp[-1].expression_ptr));}
#line 1771 "parser.cpp"
    break;

  case 53:
#line 169 "parser.y"
                                          {(yyval.expression_ptr) = new PlusNode((yyvsp[-2].expression_ptr),(yyvsp[0].expression_ptr));}
#line 1777 "parser.cpp"
    break;

  case 54:
#line 170 "parser.y"
                                           {(yyval.expression_ptr) = new MinusNode((yyvsp[-2].expression_ptr),(yyvsp[0].expression_ptr));}
#line 1783 "parser.cpp"
    break;

  case 55:
#line 171 "parser.y"
                                              {(yyval.expression_ptr) = new TimesNode((yyvsp[-2].expression_ptr),(yyvsp[0].expression_ptr));}
#line 1789 "parser.cpp"
    break;

  case 56:
#line 172 "parser.y"
                                            {(yyval.expression_ptr) = new DivideNode((yyvsp[-2].expression_ptr),(yyvsp[0].expression_ptr));}
#line 1795 "parser.cpp"
    break;

  case 57:
#line 173 "parser.y"
                                             {(yyval.expression_ptr) = new GreaterNode((yyvsp[-2].expression_ptr),(yyvsp[0].expression_ptr));}
#line 1801 "parser.cpp"
    break;

  case 58:
#line 174 "parser.y"
                                          {(yyval.expression_ptr) = new GreaterEqualNode((yyvsp[-2].expression_ptr),(yyvsp[0].expression_ptr));}
#line 1807 "parser.cpp"
    break;

  case 59:
#line 175 "parser.y"
                                            {(yyval.expression_ptr) = new EqualNode((yyvsp[-2].expression_ptr),(yyvsp[0].expression_ptr));}
#line 1813 "parser.cpp"
    break;

  case 60:
#line 176 "parser.y"
                                         {(yyval.expression_ptr) = new AndNode((yyvsp[-2].expression_ptr),(yyvsp[0].expression_ptr));}
#line 1819 "parser.cpp"
    break;

  case 61:
#line 177 "parser.y"
                                        {(yyval.expression_ptr) = new OrNode((yyvsp[-2].expression_ptr),(yyvsp[0].expression_ptr));}
#line 1825 "parser.cpp"
    break;

  case 62:
#line 178 "parser.y"
                              {(yyval.expression_ptr) = new NotNode((yyvsp[0].expression_ptr));}
#line 1831 "parser.cpp"
    break;

  case 63:
#line 179 "parser.y"
                                            {(yyval.expression_ptr) = new NegationNode((yyvsp[0].expression_ptr));}
#line 1837 "parser.cpp"
    break;

  case 64:
#line 180 "parser.y"
                               {(yyval.expression_ptr) = new VariableNode(new IdentifierNode((yyvsp[0].base_char_ptr)));}
#line 1843 "parser.cpp"
    break;

  case 65:
#line 181 "parser.y"
                                                          {(yyval.expression_ptr) =  new MemberAccessNode(new IdentifierNode((yyvsp[-2].base_char_ptr)),new IdentifierNode((yyvsp[0].base_char_ptr)));}
#line 1849 "parser.cpp"
    break;

  case 66:
#line 182 "parser.y"
                        {(yyval.expression_ptr) = (yyvsp[0].methodcall_ptr);}
#line 1855 "parser.cpp"
    break;

  case 67:
#line 183 "parser.y"
                                                 {(yyval.expression_ptr) = (yyvsp[-1].expression_ptr);}
#line 1861 "parser.cpp"
    break;

  case 68:
#line 184 "parser.y"
                          {(yyval.expression_ptr) = new IntegerLiteralNode(new IntegerNode((yyvsp[0].base_int)));}
#line 1867 "parser.cpp"
    break;

  case 69:
#line 185 "parser.y"
                    {(yyval.expression_ptr) = new BooleanLiteralNode(new IntegerNode(1));}
#line 1873 "parser.cpp"
    break;

  case 70:
#line 186 "parser.y"
                     {(yyval.expression_ptr) = new BooleanLiteralNode(new IntegerNode(0));}
#line 1879 "parser.cpp"
    break;

  case 71:
#line 187 "parser.y"
                                     {(yyval.expression_ptr) = new NewNode(new IdentifierNode((yyvsp[0].base_char_ptr)),NULL);}
#line 1885 "parser.cpp"
    break;

  case 72:
#line 188 "parser.y"
                                                                         {(yyval.expression_ptr) = new NewNode(new IdentifierNode((yyvsp[-3].base_char_ptr)),(yyvsp[-1].expression_list_ptr));}
#line 1891 "parser.cpp"
    break;

  case 73:
#line 191 "parser.y"
                                                                  {(yyval.methodcall_ptr) = new MethodCallNode(new IdentifierNode((yyvsp[-3].base_char_ptr)),NULL,(yyvsp[-1].expression_list_ptr));}
#line 1897 "parser.cpp"
    break;

  case 74:
#line 192 "parser.y"
                                                                                             {(yyval.methodcall_ptr) = new MethodCallNode(new IdentifierNode((yyvsp[-5].base_char_ptr)),new IdentifierNode((yyvsp[-3].base_char_ptr)),(yyvsp[-1].expression_list_ptr));}
#line 1903 "parser.cpp"
    break;

  case 75:
#line 195 "parser.y"
                       {(yyval.expression_list_ptr) = (yyvsp[0].expression_list_ptr);}
#line 1909 "parser.cpp"
    break;

  case 76:
#line 196 "parser.y"
                   {(yyval.expression_list_ptr) = new std::list<ExpressionNode*>();}
#line 1915 "parser.cpp"
    break;

  case 77:
#line 199 "parser.y"
                                           {(yyval.expression_list_ptr) = (yyvsp[-2].expression_list_ptr); (yyval.expression_list_ptr)->push_back((yyvsp[0].expression_ptr));}
#line 1921 "parser.cpp"
    break;

  case 78:
#line 200 "parser.y"
                        {(yyval.expression_list_ptr) = new std::list<ExpressionNode*>();(yyval.expression_list_ptr)->push_back((yyvsp[0].expression_ptr));}
#line 1927 "parser.cpp"
    break;


#line 1931 "parser.cpp"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 202 "parser.y"


extern int yylineno;

void yyerror(const char *s) {
  fprintf(stderr, "%s at line %d\n", s, yylineno);
  exit(0);
}
