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

	vector<int> vec(1000);
	cout << vec.capacity() << endl;
	//vector<int>().swap(vec); 
	//cout << vec.capacity() << endl;

	return 0;
}
