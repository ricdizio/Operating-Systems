#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Estructura de datos*/
#include "hash.h"
#include "linkedList.h"

#define true 1
int main(int argc, char *argv[]) {
	int lenPelicula = 1024;
	int lenCancion = 1024;
	int lenPrintCancion = 16;
	int eficiencia = 16;

	while(true){

		printf("%s\n","Introduzca el nombre de la pelicula:");
		char texto [lenPelicula];
  	scanf("%s", texto);
		printf("Esto es texto: %s\n", texto);

		if(strcmp(texto, "---")==0){
			while(true){
				int num;
				printf("%s\n","Configuracion de busqueda:\n\n\
				1. Longitud máxima del nombre de la película (por defecto, 1024 caracteres)\n\
				2. Longitud máxima del nombre de la canción (por defecto, 1024 caracteres)\n\
				3. Número máximo de canciones a imprimir (por defecto 16 canciones)\n\
				4. Eficiencia (por defecto 16 buckets)\n\
				5. Cancelar cambio de configuración\n\
				6. Salir del programa\n");

				scanf("%d", &num);
				if(0<num<7){
					int num1;
					if(num==1){
						printf("%s\n","Introduzca la longitud maxima del nombre de la pelicula");
						scanf("%d", &num1);
						lenPelicula = num1;
					}
					if(num==2){
						printf("%s\n","Introduzca la longitud maxima del nombre de la cancion");
						scanf("%d", &num1);
						lenCancion = num1;
					}
					if(num==3){
						printf("%s\n","Introduzca la longitud maxima canciones a escribir");
						scanf("%d", &num1);
						lenPrintCancion = num1;
					}
					if(num==4){
						printf("%s\n","Introduzca la eficiencia");
						scanf("%d", &num1);
						eficiencia = num1;
					}
					if(num==5){
						int lenPelicula = 1024;
						int lenCancion = 1024;
						int lenPrintCancion = 16;
						int eficiencia = 16;
						printf("%s\n","Se ha cancelado el cambio de configuracion y todos los valores estan por defecto");
						break;
					}
					if(num==6){
						exit(0);
					}
				}
			}

		}
	printf("%s\n", "Ya pase por config");
	//Tabla
	char *cancion;
	cancion = (char *)malloc(sizeof(char)*lenCancion);
	printf("%s\n", "Ya cree cancion");
	printf("%s\n", cancion);
	char *pelicula;
	pelicula = (char *)malloc(sizeof(char)*lenPelicula);
	printf("%s\n", "Ya cree pelicula");
	printf("%s\n", pelicula);
	HashTable_t *ht = ht_create(eficiencia);
	char linea[(lenPelicula+lenCancion+4)];
	FILE *archivo;
	printf("%s\n", "Archivo listo");
	archivo = fopen(argv[0],"r");
	printf("%s\n", "Archivo ABIERTO");
	while(fgets(linea,(lenPelicula+lenCancion+4),archivo)!=NULL){
		printf("%s\n", "Entre al while");
		printf(" linea: %s\n", linea);
		char *token = strtok(linea,"\t");
		unsigned i=0;
		unsigned j=0;
		while(token!=NULL){
			if(i==0){
				token = strtok(NULL,"\t");
				for(j=0;j<lenCancion;j++){
					cancion[j]=token[j];
					printf("%c", cancion[j]);

				}
				printf("\n");
				i=1;
			}
			if(i==1){
				token = strtok(NULL,"\t");
				for(j=0;j<lenPelicula;j++){
					pelicula[j]=token[j];
					printf("%c", cancion[j]);

				}

				break;
			}
		}
		printf("%s\n", cancion);
		//ht_insert(ht, pelicula, cancion);
	}


		// printf table

		//Esto retorna un linkedList
			List * lReal = ht_index(ht, texto);

			printf("-----Pelicula: %s-------\n",texto);

			//imprimimos
			display(lReal,lenPrintCancion);

	    List * lOne = ht_index(ht, "Coco");

	    printf("-----Pelicula coco-------");

	    //imprimimos
	    display(lOne,lenPrintCancion);

	    //Esto retorna un linkedList
	    List * lTwo = ht_index(ht, "Avengers: Infinity War");

	    printf("-----Pelicula Avengers: Infinity War-------");

	    //imprimimos
	    display(lTwo,lenPrintCancion);

	    //Esto retorna un linkedList
	    List * lTree = ht_index(ht, "Moana");

	    printf("-----Pelicula Moana-------");

	    //imprimimos
	    display(lTree,lenPrintCancion);

	    ht_free(ht);

		system("pause");
		return 0;
	}
}
