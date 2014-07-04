#include <stdio.h>
//print all valid combi of pars
#define NUM 3
void printpar(int l, int r, char *a, int cnt)
{
	printf("%d,%d  \n",l,r);
	if(l<0 || r<l)
	{

		printf("back<-\n");
		return;
	}
	//output
	if(l==0&& r==0)
	{
		printf("out:");
		int i;
		for(i=0;i<NUM*2;i++)
			printf("%c ", a[i]);
		printf("\n");
		return;
	}

	if(l>0)
	{
		a[cnt]='(';
		printpar(l-1,r,a,cnt+1);
	}
	if(r>l)
	{
		 a[cnt]=')';
		 printpar(l,r-1,a,cnt+1);
	}
}

void doit(int cnt)
{
	char str[cnt*2];
	printpar(cnt,cnt,str,0);
}

int main()
{
	doit(3);
	return 0;
}
