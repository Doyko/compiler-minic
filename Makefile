EXE = minicc
UTILS = ./utils

CFLAGS = -O0 -g -std=c99 -DYY_NO_LEAKS
INCLUDE = -I$(UTILS)

all: minicc

minicc: y.tab.c lex.y.cc common.o arbre.o
	gcc $(CFLAGS) $(INCLUDE) -L$(UTILS) y.tab.c lex.yy.c common.o arbre.o -o $@ -lminiccutils

y.tab.c: grammar.y defs.h
	yacc -d $<

lex.y.cc: lexico.l defs.h
	lex $<

arbre.o: arbre.c arbre.h
	gcc $(CFLAGS) $(INCLUDE) -o $@ -c $<

common.o: common.c common.h defs.h
	gcc $(CFLAGS) $(INCLUDE) -o $@ -c $<

clean:
	rm -f *.o
