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
    struct Address rows[MAX_ROWS];
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

void Database_load(struct Connection *conn)
{
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    if (rc != 1) {
        die("Failed to load database.");
    }
}

struct Connection *Database_open(const char *filename, char mode) 
{
    struct Connection *conn = malloc(sizeof(struct Connection));
    if (!conn) {
        die("Memory error.");
    }

    conn->db = malloc(sizeof(struct Database));
    if (!conn->db) {
        die("Memory error.");
    }

    if (mode == 'c') {
        conn->file = fopen(filename, "w");
    } else {
        conn->file = fopen(filename, "r+");

        if (conn->file) {
            Database_load(conn);
        }
    }

    if (!conn->file) {
        die("Faile to open file.");
    }

    return conn;
}

void Database_close(struct Connection *conn)
{
    if (conn) {
        if (conn->file) {
            fclose(conn->file);
        }
        if (conn->db) {
            free(conn->db);
        }

        free(conn);
    }
}

void Database_write(struct Connection *conn)
{
    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    if (rc != 1) {
        die("Failed to write database.");
    }

    rc = fflush(conn->file);
    if (rc == -1) {
        die("Cannot flush database.");
    }

}

void Database_create(struct Connection *conn)
{
    int i = 0;

    for (i = 0; i < MAX_ROWS; i++) {
        // make a prototype to initialize it.
        struct Address addr = {.id = 1, .set = 0};
        conn->db->rows[i] = addr;
    }
}

void Database_set(struct Connection *conn, int id, const char *name, 
    const char *email)
{
    struct Address *addr = &conn->db->rows[id];
    if (addr->set) {
        die("Address is already set!");
    }

    addr->set = 1;

    // WARNING: bug! Read "How to break this" to fix it.
    char *res = strcpy(addr->name, name, MAX_DATA);

    // deomonstrate the strcpy bug
    if (!res) {
        die("Name copy fail");
    }

    res = strcpy(addr->email, email, MAX_DATA);
    if (!res) {
        die("Email copy fail");
    }
}

void Database_get(struct Connection *conn, int id)
{
    struct Address *addr = &conn->db->rows[id];
    if (addr->set) {
        Address_print(addr);
    } else {
        die("ID is not set.");
    }
}

void Database_delete(struct Connection *conn, int id)
{
    struct Address addr = {.id = id, .set = 0};
    conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
    int i = 0;
    struct Database *db = conn->db;

    for (i = 0; i < MAX_ROWS; i++) {
        struct Address *cur = &db->rows[i];
        if (cur->set) {
            Address_print(cur);
        }
    }
}


int main(int argc, char *argv[])
{

    if (argc < 3) {
        die("USAGE: ex17 <dbfile> <action> [action params]");
    }

    char *filename = argv[1];
    char action = argv[2][0];
    struct Connection *conn = Database_open(filename, action);

    int id = 0;

    if (argc > 3) id = atoi(argv[3]);
    if (id >= MAX_ROWS) die("There's not that many records.");

    switch (action) {
        case 'c':
            Database_create(conn);
            Database_write(conn);
            break;
        case 'g':
            if (argc != 4) {
                die("Need an id to get!");
            }

            Database_get(conn, id);
            break;

        // HERE I AM.

    }



    struct Address joe = {.id=1, .name="Joe", .email="Dude"};
    struct Address *joeptr = &joe;
    Address_print(joeptr);
    return 0;
}
