When I tried to change the null byte at the end of my first name, I got an interesting code:

```c
char first_name[] = Quentin;

first_name[8] = 'A';

# Abort trap: 6
```

Discovered that the -S option on the compiler actually compiles it to assempler instead of to a binary.

```
# Makefile

assembler:
    cc -S ex7.c -o ex7-assembler
```