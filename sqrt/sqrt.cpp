#include <iostream>

using namespace std;

int sqrt(int x)
{
	if(x<=0)
		return 0;
	int base = 0;
	for(int i=1;i<x;)
	{
		cout<<"base="<<base<<endl;
		cout<<"i="<<i<<endl;
		if((base+i)*(base+i) ==x)
		{
			return base+i;
		}
		if((base+i)*(base+i) > x )
		{
			if(i==1)
				return base;
			if((base+1)*(base+1) > x)
				return base;
			i=1;
			base +=i;
			continue;
		}
		if((base+i)*(base+i) < x )
		{
			base += i;
		}
	i*=2;
	}
	return 0;

}
int main()
{
	cout<<"255:"<<sqrt(255)<<endl;
	return 0;
}
