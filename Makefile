.PHONY: all
all: compiler

compiler:
	cd Compiler ; make all;

.PHONY: clean
clean:
	rm -f a.out; \
	cd Compiler ; make clean;
