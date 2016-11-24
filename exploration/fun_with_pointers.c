#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 1;
    int *ptr = &i;

    printf("%d\n", i);
    printf("%p\n", ptr);


    // On my computer, the size of int is 4
    printf("%ld\n", sizeof(int));

    // So each one of these is 4 more bytes away from ptr
    printf("%p\n", ptr+1);
    printf("%p\n", ptr+2);
    printf("%p\n", ptr+3);

    char c = 'A';

    // The size of a char is 1
    printf("%ld\n", sizeof(char));

    // So each one of these is just 1 unit away...
    printf("%p\n", &c);
    printf("%p\n", &c+1);
    printf("%p\n", &c+2);
    printf("%p\n", &c+3);

}