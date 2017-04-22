OS = $(shell uname)
CC = gcc
YACC = bison
LEX = flex

ifeq (,$(findstring _NT,$(OS)))
  ext = 
else
  ext = .exe
endif

all: parser lexer compile

parser:
	$(YACC) -d -v -o gen/y.tab.c gramm.y

testfile:
	$(CC) test/a.c -o a$(ext)
	./a$(ext)

lexer:
	$(LEX) lex.l
	mv lex.yy.c gen/

assemble:
	$(CC) -S -I"${CURDIR}" gen/y.tab.c -o gen/y.tab.s
	$(CC) -S -I"${CURDIR}" gen/lex.yy.c -o gen/lex.yy.s
	$(CC) -S -I"${CURDIR}" calc.c -o gen/calc.s
	$(CC) -S -I"${CURDIR}" utils.c -o gen/utils.s

cyacc:
	$(CC) -I"${CURDIR}" -o cyacc$(ext) gen/y.tab.c gen/lex.yy.c calc.c utils.c

non2:
	echo $(CC)
	echo $(ext)
	echo $(libs)
	echo $(outfile)
	echo $(a)
	echo $(shell uname)[1:] 
	echo ${CURDIR}