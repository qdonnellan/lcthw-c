`make ex1` is just the same as `cc ex1.c -o ex1` when an `ex1.c` file is present.

The `#` in front of `include` is a "preprocessor directive"; the preprocessor sees these lines and then modifies the source code before handing it off to the compiler. In the case of `#include` the preprocessor replaces `#include <something>` with the text from the file located at `<something>`. For our file, `<stdio.h>` is a standard header; ostensibly you could also include other, non-standard files as long as the path points to a file that exists.

`*` in front of `*argv[]` is like saying "get the value of the pointer `argv[]`". 