sound:
	gcc -o sound sound.c -L./openal-soft/build -lopenal
openal:
	cd openal-soft;	cd build; cmake ..;	make; cd ..; cd ..
.PHONY: all
.PHONY: clean
all: openal sound
clean:
	rm -rf sound