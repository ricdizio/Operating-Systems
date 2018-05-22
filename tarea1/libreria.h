#define LINKEDLIST_HEADER
#define HASH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
TABLA DE HASH
*/

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

/*
LINKED LIST
*/

typedef struct node {
  char *data;
  struct node * next;
} Node;

typedef struct list {
  Node * head; 
} List;

List * emptylist();
void add(char *data, List * list);
void delete(char *data, List * list);
void display(List * list, int limit);
void reverse(List * list);
void destroy(List * list);
int already(List * list, char * element);
