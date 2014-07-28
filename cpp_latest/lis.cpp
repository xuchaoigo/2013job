//the longest incremental seq

#include <stdio.h>
#include <iostream.h>

using namespace std;

void printa(int *a, int len)
{
	for(int i=0;i<len;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int lis(int *a, int len)
{
	int b[11]={0}; //record the smallest tail number of the len of index.
	for(int i=1;i < len;i++)
		b[i] = -1;

	for(int i=0;i < len;i++)
	{
		for(int j=0; j<i; j++)
		{
			if(b[j]<a[i]&& b[j]!=-1) //len==j, only update if the j len LIS exists
			{
				if(a[i]<b[j+1] || b[j+1]==-1)//perhaps update the number of j+1 len
					b[j+1]=a[i];
			}
			
		}
		printa(a,len);
		printa(b,len);
		cout<<"-------------"<<endl;
	}

	//get len
	int k;
	for(k=1;k<len;k++)
	{
		if(b[k]== -1)
			break;
	}
	if(k == len)
		return len;

	return k-1;
}

int emain()
{
	int a[10] = {3,1,5,9,4,7,8,9,3,6};
	//int a[10] = {1,2,3,4,5,6,7,8,9,10};
	//int a[10] = {9,8,7,6,5,4,3,2,1,0};
	cout<<lis(a, 10)<<endl;
	return 0;
}

