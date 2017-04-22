
D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%{
#include <stdio.h>
#include "calc.h"
#include "utils.h"
#include "y.tab.h"
#include "gramm.h"
#include <stdlib.h>
#include <string.h>

char id_name[200];

int check_type();

void count();
%}

%%
"/*"			{ comment(); }

"auto"			{ count(); return(AUTO); }
"break"			{ count(); return(BREAK); }
"case"			{ count(); return(CASE); }
"char"			{ count(); return(CHAR); }
"const"			{ count(); return(CONST); }
"continue"		{ count(); return(CONTINUE); }
"default"		{ count(); return(DEFAULT); }
"do"			{ count(); return(DO); }
"double"		{ count(); return(DOUBLE); }
"else"			{ count(); return(ELSE); }
"enum"			{ count(); return(ENUM); }
"extern"		{ count(); return(EXTERN); }
"float"			{ count(); return(FLOAT); }
"for"			{ count(); return(FOR); }
"goto"			{ count(); return(GOTO); }
"if"			{ count(); return(IF); }
"int"			{ count(); return(INT); }
"long"			{ count(); return(LONG); }
"register"		{ count(); return(REGISTER); }
"return"		{ count(); return(RETURN); }
"short"			{ count(); return(SHORT); }
"signed"		{ count(); return(SIGNED); }
"sizeof"		{ count(); return(SIZEOF); }
"static"		{ count(); return(STATIC); }
"struct"		{ count(); return(STRUCT); }
"switch"		{ count(); return(SWITCH); }
"typedef"		{ count(); return(TYPEDEF); }
"union"			{ count(); return(UNION); }
"unsigned"		{ count(); return(UNSIGNED); }
"void"			{ count(); return(VOID); }
"volatile"		{ count(); return(VOLATILE); }
"while"			{ count(); return(WHILE); }

{L}({L}|{D})*		{ 
					  count();
					  return(check_type());
					}

0[xX]{H}+{IS}?		{ count();  yylval.e.val.const_str = yytext; return(CONSTANT);}
0{D}+{IS}?		{ count();  yylval.e.val.const_str = yytext; return(CONSTANT);}
{D}+{IS}?		{ count();  yylval.e.val.const_str = yytext; return(CONSTANT);}
L?'(\\.|[^\\'])+'	{ count();  yylval.e.val.const_str = yytext; return(CONSTANT);} 

{D}+{E}{FS}?		{ count();  yylval.e.val.const_str = yytext; return(CONSTANT);}
{D}*"."{D}+({E})?{FS}?	{ count();  yylval.e.val.const_str = yytext; return(CONSTANT);}
{D}+"."{D}*({E})?{FS}?	{ count();  yylval.e.val.const_str = yytext; return(CONSTANT);}

"&&"		{ return (AND_OP);}
"||"		{ return (OR_OP);}
"<="		{ return (LE_OP);}
">="		{ return (GE_OP);}
"=="		{ return (EQ_OP);}
"!="		{ return (NE_OP);}
"<<"		{ return (LSHFT_OP);}
">>"		{ return (RSHFT_OP);}
"++"		{ return (INC_OP);}
"--"		{ return (DEC_OP);}

";"			{ count(); return(';'); }
("{"|"<%")		{ count(); return('{'); }
("}"|"%>")		{ count(); return('}'); }
","			{ count(); return(','); }
":"			{ count(); return(':'); }
"="			{ count(); return('='); }
"("			{ count(); return('('); }
")"			{ count(); return(')'); }
("["|"<:")		{ count(); return('['); }
("]"|":>")		{ count(); return(']'); }
"."			{ count(); return('.'); }
"&"			{ count(); return('&'); }
"!"			{ count(); return('!'); }
"~"			{ count(); return('~'); }
"-"			{ count(); return('-'); }
"+"			{ count(); return('+'); }
"*"			{ count(); return('*'); }
"/"			{ count(); return('/'); }
"%"			{ count(); return('%'); }
"<"			{ count(); return('<'); }
">"			{ count(); return('>'); }
"^"			{ count(); return('^'); }
"|"			{ count(); return('|'); }
"?"			{ count(); return('?'); }

[ \t\v\n\f]		{ count(); }
.			{ /* ignore bad characters */ }

%%

yywrap()
{
	return(1);
}


comment()
{
	char c, c1;

loop:
	while ((c = input()) != '*' && c != 0)
		putchar(c);

	if ((c1 = input()) != '/' && c != 0)
	{
		unput(c1);
		goto loop;
	}

	if (c != 0)
		putchar(c1);
}


int column = 0;

void count()
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;

	ECHO;
}


int check_type()
{
	struct type *alias_type;
	if (alias_type = get_alias(yytext)) {
		yylval.alias_type = alias_type;
		return (ALIAS_NAME);
	}

	int len = strlen(yytext);
	// printf("yytext: %s\n", yytext);
	strcpy(id_name, yytext);
	yylval.id_name = id_name;

	return(IDENTIFIER);
}
