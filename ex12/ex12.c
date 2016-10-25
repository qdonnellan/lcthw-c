#include <stdio.h>

int main(int argc, char *argv[])
{
    int areas[] = { 10, 12, 13, 14, 20 };
    char name[] = "Zed";
    char full_name[] = {
        'Z', 'e', 'd', ' ', 'A', '.', ' ', 'S', 'h', 'a', 'w', '\0'
    };

    // Note to self; size is already allocated befor there are any values.
    int another_area[4];
    printf("The size of another_area: %ld\n", sizeof(another_area));

    // This is just gibberish...
    printf("The first area is %d: the second %d\n", another_area[0], another_area[1]);


    // Warning: on some systems you may have to change the 
    // %ld to in this code to a %u since it will use unsigned ints
    printf("The size of an int %ld\n", sizeof(int));
    printf("The size of areas (int[]): %ld\n", sizeof(areas));
    printf("The number of ints in areas: %ld\n", sizeof(areas) / sizeof(int));
    printf("The first area is %d: the second %d\n", areas[0], areas[1]);
    printf("The size of a char: %ld\n", sizeof(char));
    printf("The size of name (char[]): %ld\n", sizeof(name));
    printf("The number of chars: %ld\n", sizeof(name) / sizeof(char));
    printf("The size of full_name: %ld\n", sizeof(full_name));
    printf("The numberof chars: %ld\n", sizeof(full_name) / sizeof(char));
    printf("name = \"%s\" and full_name = \"%s\"\n", name, full_name);

    printf("int: %ld\n", sizeof(int));
    printf("float: %ld\n", sizeof(float));
    printf("double: %ld\n", sizeof(double));
    printf("long: %ld\n", sizeof(long));
    printf("unsigned long: %ld\n", sizeof(unsigned long));

    return 0;
}