#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address {
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};

struct Database {
    struct Address row[MAX_ROWS];
};

struct Connection {
    FILE *file;
    struct Database *db;
};

void die(const char *message)
{
    if (errno) {
        perror(message);
    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

void Address_print(struct Address *addr)
{
    printf("%d, %s, %s\n", addr->id, addr->name, addr->email);
}


int main(int argc, char *argv[])
{

    struct Address joe = {.id=1, .name="Joe", .email="Dude"};
    struct Address *joeptr = &joe;
    Address_print(joeptr);
    return 0;
}
