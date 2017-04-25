OS = $(shell uname)
CC = gcc
YACC = bison
LEX = flex
src = ${CURDIR}/src

SUCC = \033[1;32m
FAILU = \033[1;31m
NC = \033[0m

succ_msg = ${SUCC}====================BUILD SUCCESSFULL====================${NC}
fail_msg = ${FAILU}====================BUILD FAILED====================${NC}

ifeq (,$(findstring _NT,$(OS)))
  ext = 
  win = False
else
  ext = .exe
  evar = lastExitCode
  win = True
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
	@$(CC) -I"$(src)" -o cyacc$(ext) gen/y.tab.c gen/lex.yy.c src/calc.c src/utils.c src/func.c ;\
	if [ $$? -eq 0 ] ; then echo -e "$(succ_msg)" ; else echo -e "$(fail_msg)"; fi

debug: lexer parser
	@$(CC) -I"$(src)" -g -o cyacc$(ext) gen/y.tab.c gen/lex.yy.c src/calc.c src/utils.c src/func.c ;\
	if [ $$? -eq 0 ] ; then echo -e "$(succ_msg)" ; else echo -e "$(fail_msg)"; fi


non3:
	echo -e ${FAILU} ===failes ${SUCC}
	echo $$lastExitCode
	echo NULL