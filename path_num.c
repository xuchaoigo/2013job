#include <stdio.h>
#define MAX_X 3
#define MAX_Y 3

long long  Recursion()
{
	int i,j,i1;
	long long a[MAX_X][MAX_Y] ;
	for(i=0;i<=MAX_X-1;i++)
	{
		a[MAX_X-1][i]=1;
		a[i][MAX_Y-1]=1;
	}
	for (j=MAX_X-2;j>=0;--j)
		for(i1=MAX_Y-2;i1>=0;i1--)
			a[j][i1]=a[j+1][i1]+a[j][i1+1];

	return a[0][0];
}
int main()
{
	printf("%lld\n",Recursion());
	return 0;
}
