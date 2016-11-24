#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("ERROR: You need one argument.\n");
        return 1;
    }

    int i = 0;
    for (i = 0; argv[1][i] != '\0'; i++ ) {
        char letter = argv[1][i];

        switch (letter) {
            case 'a':
            case 'A':
                printf("%d: 'A'\n", i);
                break;

            case 'e':
            case 'E':
                printf("%d: 'E'\n", i);
                break;

            case 'i':
            case 'I':
                printf("%d: 'I'\n", i);
                break;

            case 'o':
            case 'O':
                printf("%d: 'O'\n", i);
                break;

            case 'u':
            case 'U':
                printf("%d: 'U'\n", i);
                break;

            case 'y':
            case 'Y':
                // Technically, Y can't be the first letter in
                // any syllable, so we'd need to split the word
                // up into syllables and detect if each starts with a Y.
                if (i > 1) {
                    // it's only sometimes Y.
                    printf("%d: 'Y'\n", i);
                    break;
                }
                
            default:
                printf("%d: %c is not a vowel.\n", i, letter);
        }
    }
}