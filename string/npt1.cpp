#include <iostream>
#include <string>
using namespace std;

int parseNPT(string str_npt, int * start_time, int * end_time)
{
	size_t fstart;
	if(str_npt.find("-") != string::npos)
	{
		fstart = str_npt.find("-");
		*start_time = atoi(str_npt.substr(0, fstart).c_str());
		*end_time =  atoi(str_npt.substr(fstart+1, str_npt.size()).c_str());
		return 0;
	}
	else
	{
		cout<<"npt format error\n"<<endl;
		return 1;
	}
}
int parseNPT(string str_npt, int * start_time, int * end_time);
int main(void)

{
	string npt = "1021-";
	int st,et;
	parseNPT(npt, &st, &et);

	cout<<"st="<<st<<endl;
	cout<<"et="<<et<<endl;
	return 0;
}
