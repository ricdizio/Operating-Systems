#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	int pipefd[2];
	int x= pipe(pipefd);
	int p=fork();
	if(p<0) //Error
	{
		printf("Error");
		return 0;
	}
	else if(p==0) //hijo
	{
		char *s;
		s=(char *)malloc(sizeof(char)*10)
		close(&pipefd[1]);
		int y= read(&pipefd[0],s,10);
		if(y==0) //No recibí nada
		{
			printf("No recibi nada");
		}
		else
		{
			printf("Soy hijo %d y recibi %s",getid(),y);
		}
	}
	else if(p<0) //padre
	{
		close(&pipefd);
		printf("Soy padre y mi id es %d \n", getid());
	}
}