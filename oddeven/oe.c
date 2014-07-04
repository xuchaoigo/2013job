#include <stdio.h>

void swap(int * a,int *b)
{
	int tmp = *b;
	*b=*a;
	*a=tmp;
}

void oe(int * a, int len)
{
	int front,back;
	front = 0;
	back = len-1;
	while(front <= back)
	{
		if(a[front] %2 == 0 && a[back] %2 ==1)
		{
			swap(&a[front++],&a[back--]);
			continue;
		}
		if(a[front] %2 == 1 && a[back] %2 ==0)
		{
			front++;back--;
			continue;
		}
		if(a[front]%2 == 0 && a[back] %2 ==0)
		{
			back--;
			continue;
		}
		if(a[back]%2 == 1 && a[back] %2 ==1)
		{
			front++;
			continue;
		}
	}
}

void oe2(int * a, int len)
{
	int j = 0;
	int i;
	for(i = 0; i < len -1; i++)
	{
		if(a[i]%2 == 1)
		{
			swap(&a[i], &a[j]);
			j++;
		}
	}
}

int main()
{
	int a[10]={1,2,1,4,5,6,8,9,3};
	int b[10]={1,2,1,4,5,6,8,9,3};
	int len = sizeof(a)/sizeof(int);
	int i;
	printf("orig array:\n");	
	for(i =0;i<len;i++)
		printf("%d ",a[i]);
	printf("\n");	
	oe(a,len);
	oe2(b,len);
	printf("oe1 array:\n");	
	for(i =0;i<len;i++)
		printf("%d ",a[i]);
	printf("\n");	
	printf("oe2 array:\n");	
	for(i =0;i<len;i++)
		printf("%d ",b[i]);
	printf("\n");	
	return 0;
}
