#include <stdio.h>



main()
{
void * vp;
int a = 10;

vp  = (void *)&a;

*((int *)vp) = 7;
printf("vp = %d\n",*((int *)vp));

}
