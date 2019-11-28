PULSE_DIR=$(shell pwd)/pulseaudio

all:
	cd ./Compiler; \
	yacc -d yacc.y; \
	lex lex.l; \
	gcc -o ../cflat y.tab.c lex.yy.c music.c node.c operations.c compiler.c -L./Libraries/openal-soft/build -lopenal; \
	gcc -o ../cflat_basic y.tab.c lex.yy.c alt_music.c node.c operations.c compiler.c -L./Libraries/openal-soft/build; \
	echo "\nIf you saw an error just now, just use cflat_basic to compile your code without music!!!\n"


pulseaudio:
	mkdir .tmp
	cd .tmp; \
	git clone https://gitlab.freedesktop.org/pulseaudio/pulseaudio.git; \
	cd pulseaudio; \
	NOCONFIGURE=1 ./bootstrap.sh; \
	./configure --prefix=$(PULSE_DIR) --with-udev-rules-dir='${prefix}/lib/udev/rules.d' --with-systemduserunitdir='${prefix}/etc/systemd/user'
	cd .tmp/pulseaudio; make install
	rm -rf tmp

openal:
	cd Libraries/openal-soft; cd build; cmake ..; make; cd ..; cd ..

clean:
	rm -f cflat; \
	rm -f cflat_basic; \
	cd ./Compiler; \
	rm -f lex.yy.c; \
	rm -f y.tab.c; \
	rm -f y.tab.h;
