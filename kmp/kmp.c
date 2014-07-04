#include <stdio.h>

int main(void)
{
	char a[]="abbaaaabbbabaabbaab";
	char b[]="abaa";	
	printf("size = %d, %d\n",sizeof(b),strlen(b));
	int i,j;
	
	i=j=strlen(b);
	for(;i< strlen(a); i++)
	{
		while(a[i]!= b[j+1])
		{
			j--;	
		}
		if(j==strlen(b))
		{
			printf("%d!\n",i-strlen(b));
			break;
		}
	}



	return 0;
}
