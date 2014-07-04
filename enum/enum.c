#include <stdio.h>

typedef enum{
	TEST_1 = 100,
	TEST_2,
	TEST_3,
	TEST_4 = 200,
	TEST_5 = 666
}test;

int main(void)
{
	printf("value=%d\n",TEST_1);
	printf("value=%d\n",TEST_2);
	printf("value=%d\n",TEST_3);
	printf("value=%d\n",TEST_4);
	printf("value=%d\n",TEST_5);
	
	return 0;
}
