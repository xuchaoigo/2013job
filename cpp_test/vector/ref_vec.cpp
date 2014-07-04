#include <iostream>
#include <string>
#include <vector>

using std::vector;
using namespace std;

class student
{
public:
int number;
string name;
};

student no1;
student no2;

int main(void)
{
	vector <string> vc(5,"hello");
	vc.push_back("end");

	cout<<"<< cout"<<endl;
	for(vector<string>::const_iterator it = vc.begin(); it < vc.end(); ++it)
		cout<<*it<<endl;
	cout<<"<< endl"<<endl;

	string out1;
	out1 = vc.front();
	cout<<"out1="<<out1<<endl;	

	vc.front() = "lala";
	cout<<"out1="<<out1<<endl;
	cout<<"<< cout"<<endl;
	for(vector<string>::const_iterator it = vc.begin(); it < vc.end(); ++it)
		cout<<*it<<endl;
	cout<<"<< endl"<<endl;

	return 0;
}
