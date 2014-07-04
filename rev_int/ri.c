#include <stdio.h>
// judge if a int number is Palindrome.
int rev_int(int x)
{
	int l=1,r=1;
	while(x/l > 0)
		l*=10;
	l/=10;
	while(l>=r)
	{
		printf("l=%d,r=%d\n",l,r);
		int left,right;  //single number
		left = x/l;
		right = (x%(10*r))/r;
		printf("left=%d,right=%d\n",left,right);
		if(left != right)
			return 0;
		x-=left*l;
		x-=r*right;
		l/=10;
		r*=10;
		printf("x=%d\n",x);
	}
	return 1;
}

int main()
{
	int a= 1234321;
	printf("a=%d, result=%d\n",a,rev_int(a));
	return 0;
}
