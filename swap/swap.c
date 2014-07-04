#include <stdio.h>

int main(void)
{
	int a =7,b =12;
	printf("a=%d,b=%d\n",a,b);
	a = a+b;
	b = a-b;
	a = a-b;
	printf("a=%d,b=%d\n",a,b);

	int c =8,d =5;
	printf("c=%d,d=%d\n",c,d);
	c = c ^ d;
	d = c ^ d;
	c = c ^ d;
	printf("c=%d,d=%d\n",c,d);
/*xuc:( c ^ d )^d = c.*/

return 0;
}
