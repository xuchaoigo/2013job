#include <stdio.h>

int ways =0;

int make(int n)
{
	printf("make1(%d)\n", n);
	if(n==0)
	{
		ways++;
		return;
	}
	if(n-25>=0)
		make(n-25);
	if(n-10>=0)
		make(n-10);
	if(n-5>=0)
		make(n-5);
	if(n-1>=0)
		make(n-1);

}
//x.  only  25->10->5->1, otherwise computation repeated.

int make2(int n, int cur)
{
	printf("make2(%d)\n", n);
	int next = 0;
	switch(cur)
	{
	case 25:
		next =10;
		break;
	case 10:
		next = 5;
		break;
	case 5:
		next =1;
		break;
	case 1:
		return 1;
	}
	int ways2 = 0,i;
	for(i=0; i*cur<=n;i++)
		ways2+= make2(n-i*cur, next);
	
	return ways2;
}


int main()
{
	int w;
	make(15);
	printf("ways = %d\n", ways);
	
	w=make2(15,25);
	printf("ways2 = %d\n", w);
	return 0;
}
