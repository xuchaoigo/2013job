#include <stdio.h>

int main(int argc, char **argv)

{
	/*str overflow*/
	if(argc != 2)
	{
		printf("please input 1 para(src len),dest len = 10\n");
		return -1;
	}
	printf("src len = %d\n",atoi(argv[1]));
	printf("src len = 10\n");
	
	char src[atoi(argv[1])] ;
	char dest[10];
        int i;

	for(i = 0; i<atoi(argv[1]); i++)
		src[i]= 's';
	
	strcpy(dest,"ddddddddd");
	
	
	printf("dest = %s\n",dest);
	strcpy(dest, src);
	printf("dest = %s\n",dest);
	
}
