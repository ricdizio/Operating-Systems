#include <stdio.h>
#include <stdlib.h>

/*Estructura de datos*/
#include "hash.h"
#include "linkedList.h"

int main(int argc, char *argv[]) {
	int lenPelicula = 1024;
	int lenCancion = 1024;
	int lenPrintCancion = 16;
	int eficiencia = 16;

	while(true){

		Console.WriteLine("Introduzca el nombre de la pelicula:");
		String texto;
		texto=Console.ReadLine();

		if(texto.compare("---")==0){
			while(true){
				int num;
				printf("%s\n","Configuracion de busqueda:\n\n
				1. Longitud máxima del nombre de la película (por defecto, 1024 caracteres)\n
				2. Longitud máxima del nombre de la canción (por defecto, 1024 caracteres)\n
				3. Número máximo de canciones a imprimir (por defecto 16 canciones)\n
				4. Eficiencia (por defecto 16 buckets)\n
				5. Cancelar cambio de configuración\n
				6. Salir del programa\n");

				num=Console.ReadInt();
				if(0<num<7){
					int num1;
					if(num==1){
						Console.WriteLine("Introduzca la longitud maxima del nombre de la pelicula");
						num1=Console.ReadInt();
						lenPelicula = num1;
					}
					if(num==2){
						Console.WriteLine("Introduzca la longitud maxima del nombre de la cancion");
						num1=Console.ReadInt();
						lenCancion = num1;
					}
					if(num==3){
						Console.WriteLine("Introduzca la longitud maxima canciones a escribir");
						num1=Console.ReadInt();
						lenPrintCancion = num1;
					}
					if(num==4){
						Console.WriteLine("Introduzca la eficiencia");
						num1=Console.ReadInt();
						eficiencia = num1;
					}
					if(num==5){
						int lenPelicula = 1024;
						int lenCancion = 1024;
						int lenPrintCancion = 16;
						int eficiencia = 16;
						Console.WriteLine("Se ha cancelado el cambio de configuracion y todos los valores estan por defecto");
					}
					if(num==6){
						exit(0);
					}
				}
			}
			
		}
	
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
	
}

