CFLAGS=-Wall -g

# Clean before making!
all: clean ex2 extra cleanup

# Remove the ex2 file and also the .dSYM dir.
clean:
	rm -f ex2
	rm -f extra

cleanup:
	rm -rf *.dSYM

extra_credit: extra

# Note: this is an infinite loop!
hello:
	make hello