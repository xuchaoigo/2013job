#include <iostream>
#include <string>
using namespace std;

string f(string str_in)
{
	string ret("xuc");
	//cout<<"str_in = "<<str_in<<endl;
	str_in = "def";
	//cout<<"str_in = "<<str_in<<endl;
	return ret;
}

int main(void)
{
	 string ret;
	string a = "abcd";
	 cout<<a<<endl;
	 ret = f(a);
	 cout<<a<<endl;
	 cout<<"ret = "<<ret<<endl;
	 return 0;
}
