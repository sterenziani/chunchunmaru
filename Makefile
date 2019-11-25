all:
	cd ./Compiler; \
	yacc -d yacc.y; \
	lex lex.l; \
	gcc -o ../cflat y.tab.c lex.yy.c music.c node.c operations.c compiler.c -L./Libraries/openal-soft/build -lopenal

openal:
	cd Libraries/openal-soft; cd build; cmake ..; make; cd ..; cd ..

clean:
	rm -f cflat; \
	cd ./Compiler; \
	rm -f lex.yy.c; \
	rm -f y.tab.c; \
	rm -f y.tab.h;