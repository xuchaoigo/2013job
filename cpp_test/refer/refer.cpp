#include "iostream.h"

void get_value(int &in_value)
{
	in_value = 999;
}

void get_value_(int in_value)
{
	in_value = 999;
}

int main(void)
{
	int current_value = 0;
	for(int i =1; i<4; i++)
	{
		current_value = i;
		cout<<"before:"<<current_value<<endl;
		get_value(current_value);
		cout<<"after:"<<current_value<<endl<<endl;
	}

	for(int j =1; j<4; j++)
	{
		current_value = j;
		cout<<"before:"<<current_value<<endl;
		get_value_(current_value);
		cout<<"after:"<<current_value<<endl<<endl;
	}

	return 0;
}

