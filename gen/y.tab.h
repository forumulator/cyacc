/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_GEN_Y_TAB_H_INCLUDED
# define YY_YY_GEN_Y_TAB_H_INCLUDED
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 44 "src/gramm.y" /* yacc.c:1909  */

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

#line 129 "gen/y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GEN_Y_TAB_H_INCLUDED  */
