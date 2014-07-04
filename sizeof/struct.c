#include <stdio.h>

struct A
{
    char a1[2];
    int a2;
}A;

int main()
{
	struct A a;
	printf("sizeof a = %d\n", sizeof(a));
	return 0;
}
