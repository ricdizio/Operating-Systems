#include "linkedlist.h"

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







