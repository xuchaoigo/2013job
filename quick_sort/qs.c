#include <iostream>
using namespace std;

void swap(int *a,int *b)
{
	int tmp=*b;
	*b = *a;
	*a = tmp;
}

void partition(int * a, int start,int end)
{
	int i,j;
	j=0;
	for(i=0;i<end;i++)
	{
		if(a[i] < a[end])
		{
			swap(&a[i],&a[j]);
			j++;
		}
	}
	swap(&a[j],&a[end]);
}


int main()
{
	int a[10]={1,3,7,4,2,1,6,9,8,5};
	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	partition(a,0,9);
	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}



