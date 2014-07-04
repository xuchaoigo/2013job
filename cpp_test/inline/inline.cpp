#include <iostream.h>

inline float area(float r)
{
	int k = 10;
	return 3.14*r+10;
}
int main(void)
{
	for(float i = 1; i< 4; i++)
		cout<<"r ="<<i<<" area ="<<area(i)<<endl;
	return 0;
}
