#include <stdio.h>
#include "uthash.h"

typedef struct hashTable
{
    int id;             /* we'll use this field as the key */
    char name[10];
    UT_hash_handle hh;  /* makes this structure hashable */
}hashTable;

hashTable *users = NULL;

void add_user(hashTable *s) {
    HASH_ADD_INT(users, id, s);
}

hashTable *find_user(int user_id) {
    hashTable *s;

    HASH_FIND_INT(users, &user_id, s);
    return s;
}

void delete_user(hashTable *user) {
    HASH_DEL(users, user);
}

int main() {
    hashTable *s;
    hashTable *s1;
    char name[10] = "jack";
    char name1[10] = "belly";

    s = malloc(sizeof *s);
    s->id = 1;
    strcpy(s->name, name);
    add_user(s);
    s1 = malloc(sizeof *s1);
    s1->id = 2;
    strcpy(s1->name, name1);
    add_user(s1);
    return 0;
}