
/*this is merge sorting.
 *
 * xuc@dsp.ac.cn  09.10 
 *
 * */


#include <stdio.h>
#include <math.h>


#define LEN 1000

/*
   void mergesort(int a[],int l,int r);

   void merge(int c[],int d[],int l,int m,int r);

   void copy(int a[],int b[],int l,int r);
 */

main()
{
	int a[LEN];
	int i;
	/*randomize();*/
	for(i=0;i<LEN;i++)
	{
		a[i]=rand()%65500;
		printf("num[%d]=%d\n",i,a[i]);
	}
	mergesort(a,0,LEN-1);

	for(i=0;i<LEN;i++)
	{
		printf("new num[%d]=%d\n",i,a[i]);
	}

	printf("done\n");
}

mergesort(int a[],int l,int r)
{
	int i,b[LEN];
	if(l<r)
	{
		i=(l+r)/2;
		mergesort(a,l,i);
		mergesort(a,i+1,r);
		merge(a,b,l,i,r);
		copy(a,b,l,r);	
	}

}

merge(int c[],int d[],int l,int m,int r)
{
	int i=l;
	int j=m+1;
	int k=l;
	int q;
	while((i<=m)&&(j<=r))
	{
		if(c[i]<=c[j])d[k++]=c[i++];
		else d[k++]=c[j++];	
	}
	if(i>m)
	{
		for(q=j;q<=r;q++)
			d[k++]=c[q];	
	}
	else
	{
		for(q=i;q<=m;q++)
			d[k++]=c[q];
	}
}

copy(int a[],int b[],int l,int r)
{
	int i ;
	for(i=l;i<=r;i++)
		a[i]=b[i];
}












