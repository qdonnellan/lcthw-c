CFLAGS=-Wall -g

# Clean before making!
all: clean
	make ex1

# Remove the ex1 file and also the .dSYM dir.
clean:
	rm -f ex1
	rm -rf ex1.dSYM

	# Also remove the extra credit file
	rm -f extra
	rm -rf extra.dSYM

extra_credit:
	make extra

# Note: this is an infinite loop!
hello:
	make hello