#include <stdio.h>


/* This is broken because age is set but we forget to
 * pass it into the printf program.
 */
int main(int argc, char *argv[]) 
{
    int age = 10.1;
    int height = 72;

    printf("I am %s years old.\n", age);
    printf("I am %d inches tall.\n", height);

    return 0;
}