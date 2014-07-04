#include <stdio.h>

/*signed is only a display method. they are the same in memory.*/
main()
{
	unsigned long l;
	l = 0xffffffff;
	printf("%ld\n%u\n",l,l);

	unsigned long n;
	long m;
	n = (unsigned long)-1;
	m = 0xffffffff;
	printf("%ld,%ld\n",n,m);
	printf("%u,%u\n",n,m);
	if(n==m)
		printf("equal\n");
}
