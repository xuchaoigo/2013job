#include <iostream>
#include <stdlib.h>
using namespace std;
typedef enum
{
	HP_SUCCESS,
	HP_FAILED
}HP_RET;

#define INIT_NUM 895
int timer_start();
int timer_end();
int run_time();
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
	//int init[INIT_NUM]={3,14,45,4,2,1,6,34,20,5};
	//int init[INIT_NUM]={3,14,45,4,2};
	
	p_heap = new int[heap_size];
	if(p_heap)
	{
		p_heap[0] = -1;
		for(int i = heap_size ; i>0; i--)
		{
			HP_insert(i);//rand()%heap_size);
		}
		return HP_SUCCESS;
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
	{
		delete [] p_heap;
		p_heap = NULL;
	}
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
		
		//find small child and pop up
		for(i = 1; p_heap[2*i]!=0 && p_heap[2*i+1]!=0;)
		{
			if(p_heap[2*i+1] == 0)
			{
				p_heap[i] = p_heap[2*i];
				break;
			}
			else
			{
				if(p_heap[2*i] < p_heap[2*i+1])
				{
					p_heap[i] = p_heap[2*i];
					i*=2;
				}
				else
				{
					p_heap[i] = p_heap[2*i+1];
					i= i*2+1;
				}
			}
		}
		

		//move the last_value to the empty
		last_value = p_heap[heap_index];
		p_heap[i] = last_value;

		for(; p_heap[i/2] > last_value ; i/=2)
		{
			p_heap[i] = p_heap[i/2];
		}
		p_heap[i] = last_value;
		p_heap[heap_index] = 0;
		heap_index--;

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
	return HP_SUCCESS;
}
