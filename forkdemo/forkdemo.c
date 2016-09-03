#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int count = 0;
	pid_t pid = 0;
	pid = fork();
	if(pid>0)
	{
		count = wait(NULL);
		printf("count = %d,pid = %d\n",count,pid);
		printf("this is farther process \n");
		return 0;
	}
	else
	{
		execl("/bin/ls","ls","/home",NULL);
		printf("this is child\n");
		exit(0);
	}
}
