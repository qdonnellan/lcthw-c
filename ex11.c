#include <stdio.h>

void print_numbers(int numbers[])
{
    printf("numbers: %d %d %d %d \n", 
        numbers[0], numbers[1], numbers[2], numbers[3]);
}

void print_name(char name[])
{
    printf("name each: %c %c %c %c\n",
        name[0], name[1], name[2], name[3]);

    printf("name: %s\n", name);
}

int main(int argc, char *argv[])
{
    int numbers[4] = {0, 1, 2, '\0'}; // null byte read as a zero


    char name[4] = {'a', 'b', 'c', 'd'}; // broken (no null byte terminator)

    // first, print them out raw
    // self-edit; let's experiment with functions :)
    print_numbers(numbers);
    print_name(name);

    int other_numbers[4] = {0, 1, 2, '4'}; // '4' is converted to 52
    print_numbers(other_numbers);

    int more_numbers[4] = {0, 1, 2, 'b'}; // '2' is converted to 98
    print_numbers(more_numbers);


    char other_name[4] = {'a', '\0', 'c', 'd'}; // 'c' and 'd' are ignored!!!
    print_name(other_name);

    // setup the numbers
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;

    // setup the name
    name[0] = 'Q';
    name[1] = 'A';
    name[2] = 'D';
    name[3] = 'a'; // broken here!

    // first, print them out raw
    print_numbers(numbers);
    print_name(name);

    // another way to use name
    char *another = "Zed";
    printf("another: %s\n", another);
    print_name(another);

    return 0;
}