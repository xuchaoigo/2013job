#include <stdio.h>
int main()
{
	const int n=(1<<5)-1;
	int i,j;
	for (i=0; i<=n; i++)
	{
		for (j=0; j<=n; j++)
			 // printf( (i|j)==n ? "#" : " ");
			printf( (i&j)==j ? "#" : " ");
		printf("\n");
	}    
	getchar();
	return 0;
}
