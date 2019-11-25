sound:
	gcc -o sound sound.c -L./openal-soft/build -lopenal
openal:
	cd openal-soft 
	cd build
	cmake ..
	make
	cd ..
	cd ..
all:
	openal sound
clean:
	rm -rf sound