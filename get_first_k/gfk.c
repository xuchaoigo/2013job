#include <stdio.h>

int get_first_k(int a[], int k, int len)
{
	int head,tail,mid;
	head = 0;
	tail = len-1;
	
	while(head <= tail)
	{
		mid = (head+tail)>>1;
		if(a[mid] < k)//must not be k
		{
			head = mid+1;
		}
		if(a[mid] > k)//must not be k
		{
			tail = mid-1;
		}
		if(a[mid] == k)//in the range
		{
			if(a[mid-1]!=a[mid])
				return mid;
			else
				tail = mid-1;//still in the range
		}
	}

	return mid;
}
int get_last_k(int a[], int k, int len)
{
	int head,tail,mid;
	head = 0;
	tail = len-1;
	
	while(head <= tail)
	{
		mid = (head+tail)>>1;
		if(a[mid] < k)//must not be k
		{
			head = mid+1;
		}
		if(a[mid] > k)//must not be k
		{
			tail = mid-1;
		}
		if(a[mid] == k)//in the range
		{
			if(a[mid+1]!=a[mid])
				return mid;
			else
				head = mid+1;//still in the range
		}
	}

	return mid;
}

int main()
{
	int a[10]={1,1,2,2,2,3,3,3,4,6};
	int first = get_first_k(a,3, 10);
	int last = get_last_k(a,3, 10);
	printf(" first 3 = %d\n", first);
	printf(" last 3 = %d\n", last);
}
