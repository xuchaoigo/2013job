#include <iostream>
#include <stdlib.h>
using namespace std;
typedef enum
{
	HP_SUCCESS,
	HP_FAILED
}HP_RET;

int timer_start();
int timer_end();
int run_time();
#define INIT_NUM 20000
class HP
{
	public:
		HP(const int size);
		~HP();
		HP_RET HP_print();
		HP_RET HP_build();
		HP_RET HP_insert(const int insert_value);
		HP_RET HP_delete(int &delete_value);

		int * p_heap;
		int heap_size;   //total heap size
		int heap_index;  //last member index
	private:
		HP_RET HP_create();
		HP_RET HP_destroy();
		bool HP_is_full();
		bool HP_is_empty();
};

HP::HP(const int size)
{
	p_heap = NULL;
	heap_size = size;
	heap_index = 0;
	HP_create();
}

HP::~HP()
{
	HP_destroy();
}

bool HP::HP_is_full()
{
	if(heap_index == heap_size)
		return true;
	else 
		return false;
}
bool HP::HP_is_empty()
{
	if(heap_index == 0)
		return true;
	else 
		return false;
}

HP_RET HP::HP_print()
{
	cout<<"--heap print--"<<endl;
	for(int i = 0; i<heap_size ;i++)
		cout<<"heap["<<i<<"] =" <<*(p_heap+i)<<endl;
	return HP_SUCCESS;
}
HP_RET HP::HP_create()
{
	int init[INIT_NUM]={3,14,45,4,2,1,6,34,20,5};
	//int init[INIT_NUM]={3,14,45,4,2};
	
	p_heap = new int[heap_size];
	if(p_heap)
	{

		//	for(int i = 0; i<heap_size ;i++)
		//	*(p_heap+i) = i;
		p_heap[0] = -1;
		for(int i = heap_size ; i>0; i--)
		{
			HP_insert(i);
		}
		/*	for(int i = 1; i <= INIT_NUM; i++)
		{
			HP_insert(init[i-1]);
			HP_print();
		}
	*/	return HP_SUCCESS;
	}
	else
	{
		cout<<"HP_create error"<<endl;
		return HP_FAILED;
	}
}

HP_RET HP::HP_destroy()
{
	if(p_heap)
		delete [] p_heap;
	else
	{
		cout<<"HP_destroy error"<<endl;
		return HP_FAILED;
	}
	cout<<"HP_destroyed"<<endl;
	return HP_SUCCESS;
}
	
HP_RET HP::HP_insert(const int insert_value)
{
	int i;
	if(HP_is_full())
	{
		cout<<"heap is full!"<<endl;
		return HP_FAILED;
	}
	else
	{
	//	cout<<"--insert "<<insert_value<<"--"<<endl;
		p_heap[++heap_index] = insert_value;
		for(i = heap_index; p_heap[i/2] > insert_value ; i/=2)//index
		{
			p_heap[i] = p_heap[i/2];
		}
		p_heap[i] = insert_value;
		
		return HP_SUCCESS;
	}
}

HP_RET HP::HP_delete(int &delete_value)
{
	int i,last_value;
	if(HP_is_empty())
	{
		cout<<"heap is empty!"<<endl;
		return HP_FAILED;
	}
	else
	{
		delete_value = p_heap[1];
		
		//find small child
		int child;
		last_value = p_heap[heap_index];
		for(i = 1; i*2 <= heap_index ;i = child)  
		{
			child = 2*i;
			if(child!=heap_index && p_heap[2*i+1] < p_heap[2*i])//not only left
				child++;
			
			if(last_value > p_heap[child])		
				p_heap[i]=p_heap[child];
			else                             //find place to insert last_value 
				break;
		}
		p_heap[i] = last_value;

		p_heap[heap_index--] = 0;

	//	cout<<"--delete "<<delete_value<<"--"<<endl<<endl;
	//	HP_print();
	}
	return HP_SUCCESS;
}


int main(void)
{
	int out[INIT_NUM];
	timer_start();
	HP heap(INIT_NUM);
	for(int i=0; i< INIT_NUM; i++)
	{
		heap.HP_delete(out[i]);
	}
	for(int i=0; i< INIT_NUM; i++)
	{
		cout<<out[i]<<","<<endl;
	}

	timer_end();
	run_time();
	cout<<"good"<<endl;
	return HP_SUCCESS;
}
