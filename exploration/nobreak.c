#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char letter = toupper(argv[1][0]);

    // Without any breaks, it will start at the first letter
    // below, and then hit every case until it finishes the entire
    // switch, including the default.
    switch (letter) {
        case 'A':
            printf("The letter 'A'\n");
        case 'E':
            printf("The letter 'E'\n");
        case 'I':
            printf("The letter 'I'\n");
        case 'O':
            printf("The letter 'O'\n");
        case 'U':
            printf("The letter 'U'\n");
        default:
            printf("I don't recognize that letter.\n");

    }
}