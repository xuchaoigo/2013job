#include <stdio.h>
int main(void)
{
	const char *string = "whosyourdaddy";
	const char *match = "your";
	char * ret;
	ret = strstr(string, match);
	printf("%s , %s\nret = %s\n",string,match, ret);
	return 0;
}
