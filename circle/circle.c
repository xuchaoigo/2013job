#include <stdio.h>

void do_loop(void)
{
	static int loop = 0;
	printf("-- %d --\n",loop);
	
	switch(loop)
	{
		case 7:
			loop = 0;
			break;
		default:
			loop++;
			break;
	}
}

int main(void)
{
	while(1)
	{
	do_loop();
	sleep(1);
	}
}
