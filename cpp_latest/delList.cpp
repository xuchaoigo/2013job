//泛型算法：删除容器的偶数位

#include <stdio.h>
#include <iostream.h>
#include <list>
#include <vector>

using namespace std;
//disaster:不支持模板的模板？
/*
template <typename T> bool delEven(T &l)
{
	int flag=0;
	for(T::iterator it=l.begin();it!=l.end();)
	{
		if(flag)
		{
			it=l.erase(it);
			flag=0;
		}
		else
		{
			it++;
			flag=1;
		}
	}
	return true;
}*/


bool delEvenl(list<int> &l)
{
	int flag=0;
	for(list<int>::iterator it=l.begin();it!=l.end();)
	{
		if(flag)
		{
			it=l.erase(it);
			flag=0;
		}
		else
		{
			it++;
			flag=1;
		}
	}
	return true;
}

bool delEvenv(vector<int> &v)
{

	for(vector<int>::iterator it=v.begin();it!=v.end();)
	{
		if((it-v.begin())%2==1)
		{
			it=v.erase(it);
		}
		else
		{
			it++;
		}
	}
	return true;
}

int mains()
{
	int a[7]={1,2,3,4,5,6,7};
	list<int> mylist(a,a+7);
	vector<int> myvec(a,a+7);

	for(list<int>::iterator it=mylist.begin(); it!=mylist.end();)
	{
			cout<<*it;
			if((it++)!=mylist.end())
				cout<<" ";
	}
	cout<<endl;

	delEvenl(mylist);

	for(list<int>::iterator it=mylist.begin(); it!=mylist.end();)
	{
			cout<<*it;
			if((it++)!=mylist.end())
				cout<<" ";
	}
	cout<<endl;

	for(vector<int>::iterator it=myvec.begin(); it!=myvec.end();)
	{
			cout<<*it;
			if((it++)!=myvec.end())
				cout<<" ";
	}
	cout<<endl;

	delEvenv(myvec);

	for(vector<int>::iterator it=myvec.begin(); it!=myvec.end();)
	{
			cout<<*it;
			if((it++)!=myvec.end())
				cout<<" ";
	}
	cout<<endl;
	return 0;
}

