.PHONY: all
all: server compiler

server:
	cd Server ; make all
compiler:
	cd Compiler ; make all

.PHONY: clean
clean:
	cd Server ; make clean
	cd Compiler ; make clean