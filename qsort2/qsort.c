#include <stdio.h>
#include <math.h>

#define NUM 12

int cmp ( const void *a , const void *b )
{
	return *(int *)a > *(int *)b ? 1:-1;
//	return *(int *)a - *(int *)b; 
}
void swap(int * a, int * b)
{
	int mid;
	mid = *a;
	*a = *b;
	*b = mid;
}

int  partition(int * num, int p, int r)
{
	int i,q,j;
	//j:small end. finally the partition index.
	j = p;
	for(i = p; i < r; i++)
	{
		if(num[i] < num[r])//switch
		{
			swap(&num[j],&num[i]);
			j++;
		}
	}
	swap(&num[j],&num[r]);
	q = j;
	return q;
}

void qsort(int * num, int p, int r)   // from p -> r
{
	int i,q;
	if(p < r) //!!!!!!!!!!!!!
	{
		q = partition(num, p, r);
		qsort(num, p, q-1);
		qsort(num, q+1, r);
	}
}

int main(void)
{
	int num[NUM]={1,5,7,3,6,5,7,9,11,3,2,6};
	int i;
	for(i = 0; i < NUM; i++)
	{
		printf("%d ",num[i]);
	}
	printf("\nstart\n");
	qsort(num, 0, NUM-1);
	printf("end\n");
	
	for(i = 0; i < NUM; i++)
	{
		printf("%d ",num[i]);
	}
	printf("\n\n");
	return 0;

}
