//合并两个无序链表(小米面试题)
#include <string.h>
#include <iostream>
#include <list>

using namespace std;

list<int>::iterator findmin(list<int> &lin)
{
	if(lin.empty())
		return NULL;
	list<int>::iterator it,itmin;
	itmin = lin.begin();
	for(it=lin.begin();it!=lin.end();it++)
	{
		if(*it<*itmin)
			itmin=it;
	}
	return itmin;
}

list<int> mergell(list<int> l1,list<int>l2)
{
	list<int> lout;
	list<int>::iterator it1,it2;
	while(!l1.empty()||!l2.empty())
	{
		if(!l1.empty())
		{
			it1=findmin(l1);
		}
		else
		{
			while(!l2.empty())
			{
				it2=findmin(l2);
				cout<<"add "<<*it2<<"from l2"<<endl;
				lout.push_back(*it2);
				l2.erase(it2);
			}
			return lout;
		}
		if(!l2.empty())
		{
			it2=findmin(l2);
		}
		else
		{
			while(!l1.empty())
			{
				it1=findmin(l1);
				cout<<"add "<<*it1<<"from l1"<<endl;
				lout.push_back(*it1);
				l1.erase(it1);
			}
			return lout;
		}
		//l1 and l2 both is not empty, compare it1 and it2
		if(*it1<*it2)
		{
			lout.push_back(*it1);
			cout<<"add "<<*it1<<"from l1"<<endl;
			l1.erase(it1);
		}
		else
		{
			lout.push_back(*it2);
			cout<<"add "<<*it2<<"from l2"<<endl;
			l2.erase(it2);
		}
	}
	return lout;
}

int imain()
{
	list<int> l1;
	l1.push_back(3);
	l1.push_back(2);

	list<int> l2;
	l2.push_back(4);
	l2.push_back(1);
	l2.push_back(3);
	l2.push_back(6);
	l2.push_back(9);

	list<int> lout;

	lout=mergell(l1,l2);

	list<int>::iterator it;
	cout<<"start"<<endl;
	for(it=lout.begin();it!=lout.end();it++)
		cout<<*it;

	return 0;
}
