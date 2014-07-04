//find the k-th big number in an array
//by heap

#include <stdio.h>
#include <iostream>

using namespace std;

class HP
{
public:	
	HP(int k)
	{
		A = new int[k+1];
		cur = 1;//start from 1. 1->k
		max = k;
	}
	~HP()
	{
		delete []A;
		A = NULL;
	}
	bool push(int a);
	int top();
	void swap(int *a,int *b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}
private:
	int * A;
	int cur,max;
};

//if the heap is not full: insert to the last; switch up.
//if the heap is full: if a <= top, throw a
//                     else change the top to a, switch down.
bool HP::push(int a)
{
	if(cur <= max)
	{
		A[cur++] = a;
		for(int i = cur -1;i/2>=1; i/=2)
		{
			if(A[i]< A[i/2])
				swap(&A[i],&A[i/2]);
		}
	}
	else
	{
		if(a<=A[1])
			return false;
		else
		{
			A[1] = a;
			for(int i = 1;i*2<= max; i*=2)// not correct. 2i or 2i+1. refer to heapsort.c :)
			{
				{
					int * small;
					if(A[2*i] < A[2*i+1])
						small = &A[2*i];
					else
						small = &A[2*i+1];
					if(A[i]>*small)
						swap(&A[i], small);
					
				}
		}
	}


	for(int i = 1; i<cur; i++)
		printf("%d ", A[i]);
	cout<<endl;
	return true;
}

int HP::top()
{
	return A[1];
}

int find(int * A, int len, int k)
{
	HP heap(k);
	for(int i = 0; i <len; i++)
	{
		heap.push(A[i]);	
	}
	return heap.top();
}

int main()
{	
	int len = 20;
	int A[20]={1,2,3,4,55,6,7,8,99,10,11,12,13,144,15,16,17,18,19,20};	
	int num;
	int k=5;
	int i;
	for(i = 0; i < len;i++)
		printf("%d ",A[i]);
	printf("\nk=%d\n",k);
	num = find(A, len, k);
	cout<<num<<endl;
}
