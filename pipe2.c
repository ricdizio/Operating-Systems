#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int pipefd[2];
	int x = pipe(pipefd);
	int p = fork();
	if (p < 0)
		perror("AAA");
	if (p == 0)
	{
		int leidos = 0;
		char* s = malloc(10);
		do 
		{
			leidos = read(pipefd[0],s,10);
			if (leidos > 0)
				printf("recibidendo %s \n",s);
		} while (leidos > 0);
	}
	else 
	{
		char* s = malloc(10);
		for (int i = 0; i < 10; i++)
		{
			sprintf(s,"%d\n",i);
			write(pipefd[1],s,i/10+1);
		}
		close(pipefd[1]);
		wait(NULL);
	}
}