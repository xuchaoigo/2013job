//机器人走M*N的迷宫
#include <stream.h>
#include <memory.h>
#include <vector>

using namespace std;

void travel(int m,int n,vector<char> &out)
{
	if(m==0&&n==0)
	{
		for(vector<char>::iterator it=out.begin();it!=out.end();it++)
			cout<<*it;
		cout<<endl;
		out.pop_back();
		return;
	}
	if(m<0||n<0)
	{
		out.pop_back();
		return;
	}
	//障碍点
	/*
	if(m==2&&n==1)
	{
		out.pop_back();
		return;
	}*/
	out.push_back('L');
	travel(m-1,n,out);
	out.push_back('R');
	travel(m,n-1,out);

	out.pop_back();
	return;
}


int mainy()
{
	cout<<"start travel"<<endl;
	int m=3;
	int n=2;
	vector<char> out;
	travel(m,n,out);

	return 0;
}
