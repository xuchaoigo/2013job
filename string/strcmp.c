#include <stdio.h>
int main()

{
char str[10];
char str2[1];
short i=0;
for(i=0; i<10; i++)
	*(str+i) = '\0';
str2[0]='\0';

if (strcmp(str , str2) == 0 )
	printf("str==str2.\n");
else
	printf("str!=str2.\n");
	
return 0;

}
