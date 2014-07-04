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
	vc.push_back("6");
	vc.push_back("end");

	cout<<"<< cout"<<endl;
	for(vector<string>::const_iterator it = vc.begin(); it < vc.end(); ++it)
		cout<<*it<<endl;
	cout<<"<< endl"<<endl;

	int i;
	
	cout<<"with index"<<endl;
	   for( i = 0 ; i < vc.size() ; i++)
	   {
	   cout << vc[i] <<endl;
	   }
	 cout<<"size = "<<vc.size()<<endl;

	vector <string>::const_iterator it_find;
	it_find = find(vc.begin() , vc.end() ,"end") ;
	cout<<"value="<<*it_find<<endl;

	string out;
	while(1)
	{
		if(true == vc.empty())
			break;
		out = vc.back();
		cout<<"out ="<<out<<endl;
		vc.pop_back();
		cout<<"<< cout"<<endl;
		for(vector<string>::const_iterator it = vc.begin(); it < vc.end(); ++it)
			cout<<*it<<endl;
		cout<<"<< endl"<<endl;
		sleep(1);	
	}
	return 0;
	no1.number = 1;
	no1.name = "xuc";
	no2.number = 2;
	no2.name = "lux";
	vector<student> vs (5);
	vs.push_back(no1);
	vs.push_back(no2);

	cout<<"> Before operation"<<endl;
	for(vector<student>::const_iterator it2 = vs.begin(); it2 < vs.end(); ++it2)
		cout<<(*it2).name<<endl;
	cout<<"> Before operation"<<endl;
	for( i = 0 ; i < 2 ; i++)
	{
		cout << vs[i].name<<endl;
	}



	return 0;
}
