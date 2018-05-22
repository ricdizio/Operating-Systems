#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	printf("Empece\n");
	int pipefd[2];
	printf("Cree Pipefd\n");
	int x= pipe(pipefd);
	int p=fork();
	if(p<0) //Error
	{
		printf("Error\n");
		return 0;
	}
	else if(p==0) //hijo
	{
		int leidos;
		char *s;
		s=(char *)malloc(sizeof(char)*10);
		do{
			leidos=read(pipefd[0],s,10);
			if(leidos>0){
				printf("Recibiendo %s\n",s);
			} 
		}while(leidos>0);
	}
	else //padre
	{
		char *s = malloc(10);
		for(int i=0;i<10;i++){
			sprintf(s,"%d\n",i); //ineso: ato
			write(pipefd[1],s,i/(10+1));
		}
		close(pipefd[1]);
		//wait(NULL);
	}
}