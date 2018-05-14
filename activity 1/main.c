#include <stdio.h>
#include <stdlib.h>

/*Estructura de datos*/
#include "hash.h"
#include "linkedList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

    HashTable_t *ht = ht_create(101);
    
    /* Probadno la tabla de hash */
    
    //insert 

    ht_insert(ht, "pelicula 1", "cancion x");
    ht_insert(ht, "pelicula 2", "cancion y");
    ht_insert(ht, "pelicula 3", "cancion z");

	// printf table
	
    printf("%s\n", ht_index(ht, "pelicula 1"));
    printf("%s\n", ht_index(ht, "pelicula 2"));
    printf("%s\n", ht_index(ht, "pelicula 3"));
    
    //Limpiamos la tabla
    
    ht_free(ht);
    
    /* Probando la lista */
    
    //Creamos lista
    List * list = emptylist();
    
    //Add
	add("cancion 1", list);
	add("cancion 2", list);
	add("cancion 3", list);
	
	//show
	display(list);
	
	//delete
	delete("cancion 1", list);
	
	//show
	display(list);
	
	//reversed
	reverse(list);
	printf("Reversed: ");
	display(list);
	
	//limpiamos lista
	destroy(list);
	return 0;
}

