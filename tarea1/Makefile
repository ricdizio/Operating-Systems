main: main.o libreria.o
	gcc -o main main.o libreria.o -g

main.o: main.c libreria.h
	gcc -c main.c -g

libreria.o: libreria.c libreria.h
	gcc -c libreria.c -g

