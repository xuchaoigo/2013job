//heap sort(min-heap), push n -> pop n

#include <stdio.h>
#include <iostream>

#define DEBUG 0

using namespace std;

class HP
{
public:	
	HP(int k)
	{
		A = new int[k+1];
		cur = 0;//start from 1. 1->k,the index of the last number.
		max = k;//upper bound of cur
	}
	~HP()
	{
		delete []A;
		A = NULL;
	}
	bool push(int a);
	int top();
	int pop();
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
	if(cur <= max) //swap up
	{
		A[++cur] = a;
		for(int i = cur ;i/2>=1; i/=2)
		{
			if(A[i]< A[i/2])
				swap(&A[i],&A[i/2]);
		}
	}
	else  //this will not happen (swap down)
	{
		cout<<"wrong!"<<endl;
		if(a<=A[1])
			return false;
		else
		{
			A[1] = a;
			for(int i = 1;i*2<= max; i*=2)
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
				/*
				if(A[i]> A[2*i])
					swap(&A[i],&A[2*i]);
				if(A[i]> A[2*i+1])
					swap(&A[i],&A[2*i+1]);
			*/
			}
		}
	}


	for(int i = 1; i<=cur; i++)
		printf("%d ", A[i]);
	cout<<endl;
	return true;
}

int HP::top()
{
	return A[1];
}
int HP::pop()
{
	int pop = A[1];
	A[1] = A[cur--]; //copy top by last leave, then swap down 
	
	//for(int i = 1;i*2<= cur; i*=2) 
	//wrong!!! maybe left or right child!
#if DEBUG
	cout<<"----------------------------"<<endl;
	for(int i = 1; i<=cur; i++)
		printf("%d ", A[i]);
	cout<<endl;
#endif
	for(int i = 1;i*2<= cur; /*i*=2*/) 
	{
		int next_i;
		if(i*2+1 <= cur) //has 2 child
		{
#if DEBUG			
			cout<<"i="<<i<<",cur="<<cur<<endl;
#endif	
			int * small;
			if(A[2*i] < A[2*i+1])
				small = &A[2*i];
			else
				small = &A[2*i+1];
			
			if(A[i]<*small) //swap terminate. avoid useless swap :)
			{
				cout<<A[i]<<"<"<<*small<<endl;
				break;
			}
			if(A[i]>*small && small == &A[2*i])
			{
				swap(&A[i], small);
				next_i =2*i;
			}
			if(A[i]>*small && small == &A[2*i+1])
			{
				swap(&A[i], small);
				next_i =2*i+1;
			}
		}
		else //only has left child
		{
			if(A[i]> A[2*i])
			{
				swap(&A[i],&A[2*i]);
				next_i = 2*i;
			}
			else  // swap terminate
				break;
		}
#if DEBUG	
		cout<<"next_i="<<next_i<<endl;
#endif	
		i = next_i;
	}
	for(int i = 1; i<=cur; i++)
		printf("%d ", A[i]);
	cout<<endl;
#if DEBUG	
	cout<<"----------------------------"<<endl;
#endif
	return pop;
}

void sort(int * A, int len)
{
	HP heap(len);
	for(int i = 0; i <len; i++)
	{
		heap.push(A[i]);	
	}
	cout<<"sort:"<<endl;
	for(int i = 0; i <len; i++)
	{
		heap.pop();
		//cout<<heap.pop()<<" ";	
	}
	cout<<endl;
	return;
}

int main()
{	
	int len = 20;
	int A[8]={1,2,33,4,55,16,7,5};	
	int B[20]={1,2,3,4,55,6,7,8,99,10,11,12,13,144,15,16,17,18,19,20};
	
	int k=5;
	int i;
	for(i = 0; i < len;i++)
		printf("%d ",B[i]);
	printf("\nk=%d\n",k);
	
	sort(B, len);
	return 0;
}
