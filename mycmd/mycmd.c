#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h> 
#include <memory.h> 

/**
 * ...system.......system.....
 *
 * @param[in] cmdstring .............
 * @param[out] buf .............
 * @param[in] len ...buf...
 *
 * @return 0: ..; -1: .. 
 */
int mysystem(char* cmdstring, char* buf, int len)
{
	int      fd[2];
	pid_t pid;
	int      n, count; 
	memset(buf, 0, len);
	if (pipe(fd) < 0)
		return -1;
	if ((pid = fork()) < 0)
		return -1;
	else if (pid > 0)        /* parent process */
	{
		close(fd[1]);        /* close write end */
		count = 0;
		while ((n = read(fd[0], buf + count, len)) > 0 && count < len)
			count += n;
		printf("read exit\n");
		close(fd[0]);
		if (waitpid(pid, NULL, 0) < 0)
		{
			printf("waitpid err\n");
			return -1;	
		}
		printf("parent exit\n");
	}
	else                     /* child process */
	{
		close(fd[0]);        /* close read end */
		if (fd[1] != STDOUT_FILENO)
		{
			if (dup2(fd[1], STDOUT_FILENO) != STDOUT_FILENO)
			{
				return -1;
			}
			close(fd[1]);
		} 
		if (execl("/bin/sh", "sh", "-c", cmdstring, (char*)0) < 0)
			printf("execl err\n");
		sleep(2);
		printf("child exit\n");
	} 
	return 0;
}

int main(void)
{
	char * cmd = "ping -c 3  192.168.129.123";
//	 char * cmd = "ls";
	char result[1000];
	
	mysystem(cmd,result, 1000);
	printf("result=\n");
	printf("%s",result);
	return 0;
}
