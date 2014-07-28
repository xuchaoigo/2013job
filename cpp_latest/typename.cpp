
#include <stream.h>
#include <memory.h>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

template <typename T>
T foo(T a,T b)
{
	return a+b;
}

int hmain()
{
    float a=1.2;
    float b=1.3;

    cout<<a<<"+"<<b<<"="<<foo(a,b)<<endl;

    //·ºÐÍËã·¨
    vector<int> vec;
    int i=10;
    while(i--)
    	vec.push_back(i);
    vector<int>::iterator it;
    it=find(vec.begin(),vec.end(),12);
    cout<<(it==vec.end()?"no":"yes")<<endl;

    //iterÔËËã
    list<int> lst;
    i=5;
    while(i--)
    	lst.push_back(i);
    list<int>::iterator it2=lst.begin();
    cout<<*(++it2)<<endl;

	return 0;
}
