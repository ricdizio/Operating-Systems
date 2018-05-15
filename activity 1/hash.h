/* a hash-table implementation in c */
/*
hashing algorithm: hashval = *s + 31 * hashval
resolves collisions using linked lists
*/

#include "linkedList.h"

#ifndef HASH
#define HASH

typedef struct TableEntry /* hashtab entry */
{
    struct TableEntry *next;
    char *key;
    List *val;
} TableEntry_t;

typedef struct HashTable
{
    size_t size;
    struct TableEntry **tab;
} HashTable_t;

/* inserts the key-val pair */
TableEntry_t *ht_insert(HashTable_t *ht, char *k, char *v);

/* creates hashtable */
/* NOTE: dynamically allocated, remember to ht_free() */
HashTable_t *ht_create(size_t size);

/* frees hashtable created from ht_create() */
void ht_free(HashTable_t *ht);

/* retrive value from key */
List *ht_index(HashTable_t *ht, char *k);

/* resizes hashtable, returns new hashtable and frees old*/
HashTable_t *ht_resize(HashTable_t *oht, size_t size);

#endif

