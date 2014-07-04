#include <stdio.h>

int re(int in)
{
	if(in==1)
		return 1;	
	else
		return in*re(in-1);
}

int main()
{
	printf("ret = %d\n",re(6));
return 0;

}


