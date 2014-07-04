#include <iostream.h>

int square(int i)
{
	return i*i;
}

float square(float f)
{
	return f*f;
}

float square(int i, float j)
{
	return i*j;
}

int main(void)
{
	int i =11;
	float f = 12;
	cout<<i<<'*'<<i<<'='<<square(i)<<endl;
	cout<<f<<'*'<<f<<'='<<square(f)<<endl;
	cout<<i<<'*'<<f<<'='<<square(i,f)<<endl;
	return 0;
}
