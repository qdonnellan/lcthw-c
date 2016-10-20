#include <stdio.h>

int main(int argc, char *argv[])
{
    // Flipped it backwards.
    int i = 25;

    while (i > 0) {
        printf("%d\n", i);
        i--;
    }

    // Just adding a final newline.
    printf("\n");

    return 0;
}