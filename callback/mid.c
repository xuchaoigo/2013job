#include <stdio.h>
 
#ifndef pCB
	typedef int(* pCB)(int id);
#endif
void mid_init(void)
{
	down_init();
}

int mid_create(void)
{
	return down_create_timer();
}


void mid_start(int id, int time, pCB pup_CB)
{
	down_start_timer(id,time,pup_CB);
}

