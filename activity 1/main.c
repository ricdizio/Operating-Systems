#include <stdio.h>
#include <stdlib.h>

/*Estructura de datos*/
#include "hash.h"
#include "linkedList.h"

int main(int argc, char *argv[]) {
	
	//Tamaño tabla
    HashTable_t *ht = ht_create(101);
    
    ht_insert(ht, "coco", "A Blessing and a Fessing");
    ht_insert(ht, "Avengers: Infinity War", "cancion y");
    ht_insert(ht, "Moana", "cancion j");
    ht_insert(ht, "coco", "Cave Dwelling on the Past");
    ht_insert(ht, "Avengers: Infinity War", "End Credits");
    ht_insert(ht, "coco", "Cave Dwelling on the Past");
    ht_insert(ht, "Avengers: Infinity War", "End Credits");


	// printf table
	
	//Esto retorna un linkedList
    List * lOne = ht_index(ht, "coco");
    
    printf("-----Pelicula coco-------");
    
    //imprimimos
    display(lOne,16);
    
    //Esto retorna un linkedList
    List * lTwo = ht_index(ht, "Avengers: Infinity War");
    
    printf("-----Pelicula Avengers: Infinity War-------");
    
    //imprimimos
    display(lTwo,16);
    
    //Esto retorna un linkedList
    List * lTree = ht_index(ht, "Moana");
    
    printf("-----Pelicula Moana-------");
    
    //imprimimos
    display(lTree,16);
    
    ht_free(ht);
  
	system("pause");
	return 0;
	
}

