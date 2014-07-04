#include <stdio.h>


#define MAX 3
typedef int(* pCB)(int id);


int list[MAX];
void down_init(void)
{
	memset(list, 0,sizeof(list));
}
int down_create_timer(void)
{
	int i = 0;
	while(list[i] != 0)
		i++;
	if(i > MAX)
		return -1;
	list[i] = 1;
	printf("create %d timers\n",i+1);
	return i;
}

int down_start_timer(int id,int time,pCB pcb)
{
	printf("timer %d begin\n",id);
	sleep(time);
	printf("timer %d end\n",id);
	(* pcb)(id);
	return 0;
}




