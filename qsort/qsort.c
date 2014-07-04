#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define NUM 1000

int timer_start();
int timer_end();
int run_time();
int cmp ( const void *a , const void *b )
{
	return *(int *)a > *(int *)b ? 1:-1;
//	return *(int *)a - *(int *)b; 
}

int main(void)
{
	int num[NUM];
	int i;
	for(i = 0; i < NUM; i++)
	{
		num[i] = rand()%NUM;
		printf("%d ",num[i]);
	}
	printf("\n\n");
	

	timer_start();
	qsort(num,NUM,sizeof(num[0]),cmp);
	timer_end();
	run_time();
	getchar();
	
	
	
	for(i = 0; i < NUM; i++)
	{
		printf("%d ",num[i]);
	}
	printf("\n\n");
	return 0;

}
