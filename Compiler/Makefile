.PHONY: all
all: cflat

cflat:
	cd src; \
	yacc -d yacc.y; \
	lex lex.l; \
	gcc -o ../../cflat y.tab.c lex.yy.c music.c node.c operations.c compiler.c -lopenal; \
	gcc -o ../../cflat_basic y.tab.c lex.yy.c alt_music.c node.c operations.c compiler.c; \
	echo "\nIf you saw an error just now, just use cflat_basic to compile your code without music!!!\n"

.PHONY: clean
clean:
	rm -f ../cflat; \
	rm -f ../cflat_basic; \
	cd ./src; \
	rm -f lex.yy.c; \
	rm -f y.tab.c; \
	rm -f y.tab.h;
