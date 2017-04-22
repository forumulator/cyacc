OS = $(shell uname)
CC = gcc
YACC = bison
LEX = flex
src = ${CURDIR}/src

ifeq (,$(findstring _NT,$(OS)))
  ext = 
else
  ext = .exe
endif

all: parser lexer compile

parser:
	$(YACC) -d -v -o gen/y.tab.c src/gramm.y

testfile:
	$(CC) test/a.c -o a$(ext)
	./a$(ext)

lexer:
	$(LEX) src/lex.l
	mv lex.yy.c gen/

assemble:
	$(CC) -S -I"$(src)" gen/y.tab.c -o gen/y.tab.s
	$(CC) -S -I"$(src)" gen/lex.yy.c -o gen/lex.yy.s
	$(CC) -S -I"$(src)" src/calc.c -o gen/calc.s
	$(CC) -S -I"$(src)" src/utils.c -o gen/utils.s

cyacc: lexer parser
	$(CC) -I"$(src)" -o cyacc$(ext) gen/y.tab.c gen/lex.yy.c src/calc.c src/utils.c

non2:
	echo $(CC)
	echo $(ext)
	echo $(libs)
	echo $(outfile)
	echo $(a)
	echo $(shell uname)[1:] 
	echo ${CURDIR}