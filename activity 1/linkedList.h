#ifndef LINKEDLIST_HEADER
#define LINKEDLIST_HEADER

#include <stdio.h>
#include <stdlib.h>

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

#endif
