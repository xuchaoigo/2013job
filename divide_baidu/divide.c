#include <stdio.h>
//calc integer divede without "/"
//
//
int divide(int M, int N)
{
	if(M==0||N==0)
		return 0;
	//set the multi, N *Multi = M. e.g. 3*(4+1)=15
	//bisearch the result -> add exponentially
	int mul = 1;
	int left = M;
	int sum = 0;
	while(left>=N)
	{
		printf("mul=%d,left=%d\n",mul,left);
		if(mul*N <= left)
		{
			mul = mul<<1;
		}
		else //end this time of find. 
		{
			left = left - (mul>>1)*N;
			sum += mul>>1;
			mul = 1; //reset multi.
		}
	}
	return sum;
}


int main ()
{
	int ret;
	ret = divide(450, 3);
	printf("div= %d\n",ret);

	return 0;
}
