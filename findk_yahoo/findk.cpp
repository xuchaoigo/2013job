#include <iostream>
using namespace std;
//find the k-th big element

void swap(int *a,int *b)
{
	int tmp=*b;
	*b = *a;
	*a = tmp;
}

int partition(int * a, int len)
{
	int i,j;
	j=0;
	for(i=0;i<len-1;i++)
	{
		if(a[i] > a[len-1])
		{
			swap(&a[i],&a[j]);
			j++;
		}
	}
	swap(&a[j],&a[len-1]);
	return j;
}

int findk(int *a, int len, int k)
{
	int pos;
	cout<<"_______________________"<<endl;
	cout<<"len="<<len<<" ,to find k="<<k<<endl;
	for(int i=0;i<len;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	pos = partition(a,len);
	for(int i=0;i<len;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	cout<<"pos="<<pos<<endl;
	if(pos+1 == k)  //pos+1: the number of bigs.
		return a[pos];
	if(pos+1 < k)
	{
		return findk(a+(pos+1), len-(pos+1) ,k-(pos+1));
	}
	if(pos+1 > k)
	{
		return findk(a, pos ,k); //!!!!!not include the a[pos]!!!!!
	}
}

int main()
{
	int a[10]={1,3,7,4,2,3,6,9,8,5};
	int b[10]={1,3,7,4,2,3,6,9,8,5};
	int c[10]={1,3,7,4,2,3,6,9,8,5};
	
	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<endl;
/*
	partition(a,10);
	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";
	cout<<endl;
*/
	cout<<"the 3-th big number ="<<findk(a,10,3)<<endl;
	cout<<"the 4-th big number ="<<findk(b,10,4)<<endl;
	cout<<"the 7-th big number ="<<findk(c,10,7)<<endl;
	return 0;
}



