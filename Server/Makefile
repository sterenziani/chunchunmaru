.PHONY: all
all: cflat.server

cflat.server:
	gcc -o ../cflat.server src/TCPEchoServer4.c src/AddressUtility.c src/DieWithMessage.c src/TCPServerUtility.c src/music.c -lopenal

.PHONY: clean
clean:
	rm -rf ../cflat.server
