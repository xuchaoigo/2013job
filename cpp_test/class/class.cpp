#include <iostream>
#include <string>

using namespace std;
class student
{
public:
	string name;
	int number;
};
student g_no_arr[5];

student* set_num(int index, int num)
{
	g_no_arr[index].number = num;
	return &g_no_arr[index];
}

int main()
{
	student no1,no2;
	student no_arr[5];
	no1.number =101;
	no2.number = 102;
	no_arr[0] = no1;
	no_arr[1] = no2;
	cout<<"no_arr[0].number="<<no_arr[0].number<<endl;
	cout<<"no_arr[1].number="<<no_arr[1].number<<endl;

	cout<<"no_arr[0].number="<<no_arr[0].number<<endl;
	cout<<"no_arr[1].number="<<no_arr[1].number<<endl;
	
	int i =5;
	while(i--)
		no_arr[i] = *(set_num(i , i*2));
	i = 5;
	while(i--)
		cout<<"g_no_arr[i].number="<<no_arr[i].number<<endl;

	return 0;
}
