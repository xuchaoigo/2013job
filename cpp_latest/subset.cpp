//打印集合的所有子集
#include <stream.h>
#include <memory.h>
#include <set>
#include <vector>

using namespace std;

vector<set<int> > findSubset(set<int>& myset)
{
	set<int>::iterator iter = myset.begin();
	if(iter==myset.end())
	{
		vector<set<int> > tmp;
		set<int> null;
		tmp.push_back(null);
		return tmp;
	}
	int num=*iter;
	myset.erase(iter);
	vector<set<int> > subset=findSubset(myset);
	vector<set<int> > subset_bac=subset;

	vector<set<int> >::iterator it2;
	for(it2=subset.begin();it2!=subset.end();it2++)
		(*it2).insert(num);

	subset_bac.insert(subset_bac.end(),subset.begin(),subset.end());
	return subset_bac;
}


int mainc()
{

	set<int> myset;
	myset.insert(2);
	myset.insert(3);
	myset.insert(5);
	myset.insert(7);
	vector<set<int> >result = findSubset(myset);

	for(vector<set<int> >::iterator it=result.begin();it!=result.end();it++)
	{
		set<int>::iterator it2;
		for(it2=(*it).begin();it2!=(*it).end();it2++)
			cout<<*it2;
		cout<<endl;
	}

	return 0;
}
