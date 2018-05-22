#include "libreria.h"

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
        
    //create a Empty List
    te->val = emptylist();
    
    //add element to the list
    add (v,te->val);

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
	
	if( lookup(ht, k) == NULL )
	{

		te = new(k,v);
		
		unsigned hashval = hash(ht, k);
		 
        /* insert at beginning of linked list */
        te->next = ht->tab[hashval]; 
        ht->tab[hashval] = te;

	}
	
	else
	{	

		// For resize
		if (v == NULL) return NULL;

		//Strutc
		te = lookup(ht, k);
		
		//Buscamos la lista
		List *l = te->val;

		
		if(already(l,v)) {
			return NULL;
		}
			
		else{	
			//Agremamos el valor a la lista

			add(v, l);
		}

		
	}
	
	return te;

}

/* retrive value from key */
List *ht_index(HashTable_t *ht, char *k)
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
    {
	
        /* loop through linked list */
        for (te = oht->tab[i]; te != NULL; te = te->next)
        {
    		List * list = te->val;
  			Node * current = list->head;
  			
  			if(list->head == NULL) /*pass*/;
  			
  			else{
  				
  				while(current->next != NULL){
    				
    				if (ht_insert(nht, te->key, current->data) == NULL) return NULL;
    				ht_free(oht);
    				return nht;
    				current = current->next;
    				
    			}
			}
		}
	}
}

Node * createnode(char *data);

Node * createnode(char *data){
  Node * newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

List * emptylist(){
  List * list = malloc(sizeof(List));
  list->head = NULL;
  return list;
}

void display(List * list, int limit) {
  int counter = 0;
  int exit = 1;
  Node * current = list->head;
  if(list->head == NULL) 
    return;
  while(current->next != NULL && (counter!=(limit-1))){
  	counter++;
    printf("%s,", current->data);
    current = current->next;
  }
  printf("%s\n", current->data); 
}

void add(char *data, List * list){
  Node * current = NULL;
  if(list->head == NULL){
    list->head = createnode(data);
  }
  else {
    current = list->head; 
    while (current->next!=NULL){
      current = current->next;
    }
    current->next = createnode(data);
  }
}

void delete(char *data, List * list){
  Node * current = list->head;            
  Node * previous = current;           
  while(current != NULL){           
    if(current->data == data){      
      previous->next = current->next;
      if(current == list->head)
        list->head = current->next;
      free(current);
      return;
    }                               
    previous = current;             
    current = current->next;        
  }                                 
}                                   

void reverse(List * list){
  Node * reversed = NULL;
  Node * current = list->head;
  Node * temp = NULL;
  while(current != NULL){
    temp = current;
    current = current->next;
    temp->next = reversed;
    reversed = temp;
  }
  list->head = reversed;
}

void destroy(List * list){
  Node * current = list->head;
  Node * next = current;
  while(current != NULL){
    next = current->next;
    free(current);
    current = next;
  }
  free(list);
}

int already(List * list, char *element){


	int exist = 0;

	Node * current = list->head;
	if(list->head == NULL) 
		return;

	if(strcmp(current->data, element) == 0) {

		//first compare
		exist = 1;
		return exist;
	}
	while(current->next != NULL ){
	
		if(strcmp(current->data, element) == 0) {
			exist = 1;
			return exist;
			
		}
		
		current = current->next;
	}
	
	if(strcmp(current->data, element) == 0) {

		//last compare
		exist = 1;
		return exist;
	}
	
	return exist;
}