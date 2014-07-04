#include <stdio.h>
//print a combination number.
//select m out of n

int num_left = 2; // 2,1,0 three number

void f(const char * pin, char * pout, int number_last)
{
	int i;
	if(num_left < 0)
	{
		num_left++;   //reach the last number, output, free 1 numberand return.
		for(i=0;i<3;i++)
			printf("%d ", pout[i]);
		printf("\n\n");
		return;
	}
	
	for(i = number_last; i>=0; i--)
	{
		pout[num_left--] =  pin[i];
		f(pin, pout, i-1);
	}

	num_left++; //finish this the loop of this level, free 1 number
}

int main(void)
{
	char in[5]={1,2,3,4,5};
	char out[3]={0};
		
	f(in, out, 4);  //index
	return 0;
}
