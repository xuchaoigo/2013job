#include <stdio.h>
void function1()
{
	int i=0,j;
	for(j=0;j<100000;j++)
		i+=j;
}
void function2()
{
	int i,j;
	function1();
	for(j=0;j<200000;j++)
		i=j;
}
int main(void)
{
	int i,j;
	for(i=0;i<100;i++)
		function1();
	for(j=0;i<50000;i++)
		function2();

	return 0;
}
