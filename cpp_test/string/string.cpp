#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int FindNum(string str, string sub_str)
{
	cout<<"str="<<str<<endl;
	cout<<"sub="<<sub_str<<endl;
	int num = 0;
	string::size_type fstart = 0;
	
	while(str.find(sub_str,fstart) != string::npos)
	{
		num++;
		fstart = str.find(sub_str, fstart) + sub_str.size();
	}

	return num;
}

int main(void)
{
	char char_str[10]={"0"};
	string string_str = "12345";
	strcpy(char_str,"456");
	
	cout<<string_str<<endl;
	string_str = char_str;
	cout<<string_str<<endl;

	string abc = "abc";
	if("abc" == abc)
		cout<<"abc== abc!"<<endl;

	cout<<"--find num--"<<endl;
	string str = "123dspdsdspdsp"; 
	string sub_str = "dsp";
	int ret;
	ret = FindNum(str,sub_str);
	cout<<"ret="<<ret<<endl;
	return 0;
}
