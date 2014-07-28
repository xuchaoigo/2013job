//输出和为定值的正整数
#include <stream.h>
#include <memory.h>

int result[10];


void show(int pos,int sum)
{

	if(sum==0)
	{
		for(int i=0;i<pos;i++)
			cout<<result[i];
		cout<<endl;
	}

	for(int i=1;i<=sum;i++)
	{
		result[pos]=i;
		//only output increment seq
		if(pos>0 && result[pos]<result[pos-1])
			continue;
		show(pos+1,sum-i);
	}
}

void inc(int &in)
{
	in++;
}

int maink()
{
	cout<<"start!"<<endl;
	memset(result, 0, 10);
	int num=6;
	show(0,num);
	int a=3;
	cout<<a<<"+1="<<endl;
	inc(a);
	cout<<a;
	return 0;
}
