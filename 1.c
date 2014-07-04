
//#include <iostream>
#include <stdio.h>
//using namespace std;

int main()
{

	char buf[1024];
	FILE *fp;
	fp=fopen("Untitled","r");
	fgets(buf, 1024, fp);
	fclose(fp);
	printf("%s\n",buf);

}


