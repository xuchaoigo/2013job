#include <iostream>

using namespace std;

int sqrt(int x)
{
	if(x<=0)
		return 0;
	if(x==1)
		return 1;
	int low,high;
	low = 0;
	//high = x/2;
	high = 1<<16;
	int mid;
	while(1)
	{
		mid=(high+low)>>1;
		unsigned long long tmp = mid*mid;
		cout<<mid<<"^2="<<tmp<<endl;
		if(tmp == x)
			return mid;
		if(tmp > x)
			high = mid-1;
		if(tmp < x)
		{
			if((mid+1)*(mid+1)>x)
				return mid;
			low = mid+1;
		}			
	}
	return 0;

}
int main()
{
	//cout<<"255:"<<sqrt(255)<<endl;
	//cout<<"2:"<<sqrt(2)<<endl;
	cout<<"2147395599:"<<sqrt(2147395599)<<endl;
	return 0;
}
