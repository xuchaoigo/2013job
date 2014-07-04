#include <stdio.h>

int main()
{
	int x = 0x80000000;
	printf("x=%d,x>>30=%d\n",x,x>>30);
	printf("x=%x,x>>30=%x\n",x,x>>30);
}
