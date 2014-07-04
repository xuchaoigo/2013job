#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/resource.h>

#define doit(name) print_rl(#name, name)




int print_rl(char * name, int resource)
{
	struct rlimit limit;
	
	if(getrlimit(resource, &limit)<0)
	{
		fprintf(stderr,"getrlimit error\n");
		exit(1);
	}
	printf("%s cur:%d max:%d\n",name, limit.rlim_cur,  limit.rlim_max);
	
	return 0;
}


int main(void)
{
	printf("RLIM_INFINITY=%d\n", RLIM_INFINITY);
	doit(RLIMIT_CORE);
	doit(RLIMIT_CPU);
	doit(RLIMIT_DATA);
	doit(RLIMIT_STACK);
#ifdef RLIMIT_VMEM
	doit(RLIMIT_VMEM);
#endif
	return 0;
}

