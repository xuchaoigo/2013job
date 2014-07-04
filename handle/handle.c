#include <stdio.h>

#define HANDLE void*

int create_handle(void **handle)
{

	int id = 1234;
	/*static    is correct because it's static!*/ char data[3];
	data[0] = 123;

	printf("in: %d\n",**(int **)handle);

	**(int **)handle  = id;  //directly rewrite value, ok. 
	
	//*handle = &id;  //this can work,but dangerous! must malloc id.
	
	//*handle = &data[0];
	return 0;
}

int main(void)
{
	/*
	void **in_handle;
	int *p;
	int a =1000;
	p=&a;
	in_handle = (void **)&p;
	create_handle(in_handle);

	//must point to sth.

	printf("handle = %d, *handle = %d, **handle = %d\n",
			in_handle,
			*in_handle, 
			**(int**)in_handle);
	printf("a=%d\n",a);
	return 0;
*/
	int a =1111;
	HANDLE in_handle;
	in_handle = &a;	 /*must point to sth first!*/
	create_handle(&in_handle);
	printf("normal usage: handle = %d\n",*(int *)in_handle );

	}


