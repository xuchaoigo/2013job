//À¨ºÅÆ¥Åä£¨dfs+¼ôÖ¦£©
#include <stream.h>
#include <memory.h>

char out[32];
int num;

void output(int luse, int ruse)
{
	//cout<<"("<<luse<<","<<ruse<<")"<<endl;
	if(luse<ruse||luse+ruse>num)
		return;
	if(luse+ruse==num)
	{
		if(luse==ruse)
		{
			for(int i=0;i<=num;i++)
				cout<<out[i];
			cout<<endl;
			return;
		}
		if(luse>ruse)
			return;
	}
	out[luse+ruse+1]='(';
	output(luse+1,ruse);
	out[luse+ruse+1]=')';
	output(luse,ruse+1);
}

int fmain()
{
	cout<<"start!"<<endl;
	memset(out, 0, 10);
	num=10;
	output(0,0);
}
