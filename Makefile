all:
	gcc -o sound sound.c -L./openal-soft/build -lopenal
clean:
	rm -rf sound