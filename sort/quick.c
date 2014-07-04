/*quick sorting.
 *
 *xuc@dsp.ac.cn   09.10
 *
 * */

#include <stdio.h>
#include <math.h>
/*
void quicksort(int num[],int p,int r);
int partition(int num[],int p,int r);
void swap(int *s,int *t);
*/

#define LEN 1000

main()
{
int num[LEN];
int i;
/*randomize();*/
for(i=0;i<LEN;i++)
	{
	num[i]=rand()%65500;
	printf("num[%d]=%d\n", i, num[i]);
	}

quicksort(num,0,LEN-1);
printf("\n");
for(i=0;i<LEN;i++)
        {
        printf("new num[%d]=%d\n", i, num[i]);
        }

}

quicksort(int num[],int p,int r)
{
	int q;
	if(p < r)
	{
		q = partition(num,p,r);
		quicksort(num, p, q-1);
		quicksort(num, q+1, r);
	}

}
partition(int num[],int p,int r)  /*find the index of the middle number.*/
{
	int i = p, j = r+1;
	int x = num[p];        /*select the first number as the middle number*/
	
	while(1)
	{
		while(num[++i] < x);
		while(num[--j] > x);
		if(i >= j) break;
		swap(num+i, num+j);
	}

	num[p] = num[j];
	num[j] = x;
	return j;

}

swap(int *s,int *t)
{
	int temp;
	temp = *s;
	*s = *t;
	*t = temp;
}

















