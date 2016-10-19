CFLAGS = -Wall -g

all: clean ex7

clean:
	rm -rf *dSYM
	rm -f ex7-assembler
	rm -f ex7


# Discovered that the -S option on the compiler actually
# compiles it to assempler instead of to a binary.
assembler:
	cc -S ex7.c -o ex7-assembler