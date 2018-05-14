#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash.h"

/* creates hashtable */
/* NOTE: dynamically allocated, remember to ht_free() */

HashTable_t *ht_create(size_t size)
{
    HashTable_t *ht = NULL;
    if ((ht = malloc(sizeof(HashTable_t))) == NULL)
        return NULL;
    /* allocate ht's table */
    if ((ht->tab = malloc(sizeof(TableEntry_t) * size)) == NULL)
        return NULL;
    /* null-initialize table */
    int i;
    for (i = 0; i < size; i++)
        ht->tab[i] = NULL;
    ht->size = size;
    return ht;
}

/* creates hash for a hashtab */
unsigned hash(HashTable_t *ht, char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % ht->size;
}

/* creates a key-val pair */
TableEntry_t *new(char *k, char *v)
{
    TableEntry_t *te = NULL;
    if ((te = malloc(sizeof(TableEntry_t))) == NULL)
        return NULL;
    if ((te->key = strdup(k)) == NULL)
        return NULL;
    if ((te->val = strdup(v)) == NULL)
        return NULL;
    te->next = NULL;
    return te;
}

TableEntry_t *lookup(HashTable_t *ht, char *k)
{
    TableEntry_t *te;
    /* step through linked list */
    for (te = ht->tab[hash(ht, k)]; te != NULL; te = te->next)
        if (strcmp(te->key, k) == 0)
            return te; /* found */
    return NULL; /* not found */
}

/* inserts the key-val pair */
TableEntry_t *ht_insert(HashTable_t *ht, char *k, char *v)
{
    TableEntry_t *te;
    /* unique entry */
    if ((te = lookup(ht, k)) == NULL)
    {
        te = new(k, v);
        unsigned hashval = hash(ht, k);
        /* insert at beginning of linked list */
        te->next = ht->tab[hashval]; 
        ht->tab[hashval] = te;
    }
    /* replace val of previous entry */
    else
    {
        free(te->val);
        if ((te->val = strdup(v)) == NULL)
            return NULL;
    }
    return te;
}

/* retrive value from key */
char *ht_index(HashTable_t *ht, char *k)
{
    TableEntry_t *te;
    if ((te = lookup(ht, k)) == NULL)
        return NULL;
    return te->val;
}

/* recursively frees table entriy chains, starting with last one added */
void te_free(TableEntry_t *te)
{
    if (te->next != NULL) 
    {
        te_free(te->next);
        free(te->next);
    }
    free(te->key);
    free(te->val);
}

/* frees hashtable created from ht_create() */
void ht_free(HashTable_t *ht)
{
    int i;
    for (i = 0; i < ht->size; i++)
        if (ht->tab[i] != NULL)
            te_free(ht->tab[i]);
    free(ht);
}

/* resizes hashtable, returns new hashtable and frees old*/
HashTable_t *ht_resize(HashTable_t *oht, size_t size)
{
    HashTable_t *nht; /* new hashtable */
    nht = ht_create(size);
    /* rehash */
    int i;
    TableEntry_t *te;
    /* loop through hashtable */
    for (i = 0; i < oht->size; i++)
        /* loop through linked list */
        for (te = oht->tab[i]; te != NULL; te = te->next)
            if (ht_insert(nht, te->key, te->val) == NULL)
                return NULL;
    ht_free(oht);
    return nht;
}
