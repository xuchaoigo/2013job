//recode and judge
#include <iostream>
#include <vector>
#include <string>
#include <set>

#define NUM 10
using namespace std;

string gf(string s)
{
	int pos = s.find(" ");
	string name = s.substr(0,pos);
	return 	name;
}
string gl(string s)
{
	int pos = s.find(" ");
	int end = s.find("\n");
	string name = s.substr(pos+1,end);
	return 	name;
}

int divide(int pair_num, string * pair)
{
	set <string> mob1,mob2;
	for(int i = 0; i< pair_num; i++)
	{
		int fin1,fin2,lin1,lin2;
		if(mob1.find(gf(pair[i]))!=mob1.end())
			fin1 = 1;
		else
			fin1 = 0;
		if(mob2.find(gf(pair[i]))!=mob2.end())
			fin2 = 1;
		else
			fin2 = 0;
		if(mob1.find(gl(pair[i]))!=mob1.end())
			lin1 = 1;
		else
			lin1 = 0;
		if(mob2.find(gl(pair[i]))!=mob2.end())
			lin2 = 1;
		else
			lin2 = 0;



		if(fin1 ==1 && lin1 ==1 || fin2 ==1 && lin2 ==1)
			return 1;
		if(fin1 ==1 && lin2 ==1 || fin2 ==1 && lin1 ==1)
			continue;
		if(fin1 ==0 && lin1 ==0 && fin2 ==0 && lin2 ==0)
		{
			mob1.insert(gf(pair[i]));
			mob2.insert(gl(pair[i]));
		}
		if(fin1 ==1 && lin2 ==0)
		{
			mob2.insert(gl(pair[i]));
		}
		if(lin1 ==1 && fin2 ==0)
		{
			mob2.insert(gf(pair[i]));
		}
		if(fin2 ==1 && lin1 ==0)
		{
			mob1.insert(gl(pair[i]));
		}
		if( lin2 ==1 && fin1 ==0)
		{
			mob1.insert(gf(pair[i]));
		}
	}

	return 0;
}

int main(void)
{
	int pair_num = NUM;
	int ret = -1;
	string str_pair[NUM];
	str_pair[0]="xuc guozc";
	str_pair[1]="guozc hanr";
	str_pair[2]="hanr zhangw";
	str_pair[3]="xuc zhangw";
	str_pair[4]="xuc guozc";
	str_pair[5]="xuc guozc";
	str_pair[6]="xuc guozc";
	str_pair[7]="xuc guozc";
	str_pair[8]="xuc guozc";
	str_pair[9]="xuc guozc";

	ret = divide(pair_num, str_pair);
	cout<<ret<<endl;
}

