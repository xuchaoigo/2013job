#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits)
{
	vector<int> d;
	if(digits.back()!=9)
	{
		digits.back()++;
		d = digits;
		return d;
	}
	else
	{
		int i = digits.size()-1;
		while(i--)
		{
			if(digits[i] != 9)
			{
				digits[i]++;
				for(int j=i+1; j<digits.size(); j++)
					digits[j]=0;
				d = digits;
				return d;
			}
		}
		if(digits[0]==9)
		{
			d.push_back(1);
			int len = digits.size();
			while(len--)
				d.push_back(0);
			return d;
		}
	}

}

int main()
{
	vector<int> a;
	a.push_back(9);
	vector<int> &b =a;
	vector<int> c = plusOne(b);
	cout<<c[0]<<endl;
	cout<<c[1]<<endl;
	return 0;
}
