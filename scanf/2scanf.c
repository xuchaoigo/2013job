#include <stdio.h>
int main(int argc, char **argv)
{
	int i;
	int array[20]={0};

	for(i=0;i<5;i++)
	{
		scanf("%d",&array[i]);
	}
		printf("input is:\n");
	for(i=0;i<5;i++)
		printf("%d\n",array[i]);
	printf("input end\n");

	return 0;
}

