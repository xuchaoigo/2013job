#include <iostream>
using namespace std;
/*
 * 无相同的数字
int bisearch(int v,int *a,int len)
{
	if(!a)
		return -1;
	int l,r,m;
	l=0;
	r=len-1;
	while(l<=r)
	{
		cout<<"m="<<m<<endl;
		m = (l+r)>>1;
		if(a[m]==v)
			return m;
		if(a[m]<v)
			l=m+1;
		else
			r=m-1;
	}
	return m;
}
*/

//有相同的数字，返回最后一个数字
int bisearch(int v,int *a,int len)
{
	if(!a)
		return -1;
	int l,r,m;
	l=0;
	r=len-1;
	while(l<=r)
	{
		cout<<"m="<<m<<endl;
		m = (l+r)>>1;
		if(a[m]==v)
		{
			if(a[m+1]==v)
				r=m;
			else
				return m;
		}
		if(a[m]<v)
			l=m+1;
		else
			r=m-1;
	}
	return m;
}

int bmain(void)
{
	int a[10]={1,2,4,4,4,9,11,13,15,20};
	int len =0;
	len=bisearch(4,a,10);
	cout<<"pos="<<len<<endl;
	return 0;
}

