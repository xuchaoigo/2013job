#include <stdio.h>


int up_CB(int id)
{
	printf("timer %d -> callback called!\n",id);
}


int main(void)
{
	int id;
	int i;
	mid_init();

	for(i = 1; i<10; i++)
	{
		id = mid_create();
		if(id != -1)			
			mid_start(id,i,up_CB);
		else 
		{
			printf("create failed\n");
			break;
		}	
	}
	return 0;
}



