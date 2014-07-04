#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>



int main()
{
	pid_t pid;
	pid =  fork();
	printf("prefix:");
	int c1=100,c2=100;
	int value=0;
	char cmd[10];
	
	if(pid == 0)
	{
		while(c1--)
		{
			printf("i'm child,value = %d\n",value);
			value++;
			sleep(1);
		}
	exit(0);
	}
	else
	{
		while(c2--)
		{
			printf("i'm father,value = %d\n",value);
			sprintf(cmd,"ps Tjx");
			system(cmd);
			sleep(1);
		}
	exit(0);
	}
	return 0;
}

