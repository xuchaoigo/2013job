#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	if (daemon(0, 0)) 
	{   
		perror("daemon");
		return -1;
	}
	while(1)
	{
		sleep(1);
		printf("alive");
		system("mkdir /home/xuc/aa");
	}
	return 0;
}
