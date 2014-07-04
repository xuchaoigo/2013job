#include <stdio.h>

void swap(int *i,int* j)
{
	int tmp = *i;
	*i=*j;
	*j=tmp;
}

void permu(int *a,int len)
{
	int i;
	if(len==1)
	{
		printf("permu:");
		for(i=0;i<4;i++)
		{
			printf("%d ",*(a-3+i));
		}
		printf("\n");
	}
	for(i=0;i<len;i++)
	{
		swap(&a[0],&a[i]);
		permu(a+1, len-1);
		swap(&a[0],&a[i]);
	}
}


int main()
{
	int a[4] = {1,2,3,4};
	permu(a,4);
	return 0;
}
