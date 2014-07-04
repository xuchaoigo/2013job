#include <stdio.h>
#include <iostream>

using namespace std;

class A
{
    virtual void aaa()
    {
	    return;
    }
    //char a1[2];
    //int a2;
};

class B 
{
    //virtual void aaa()
    //{
//	    return;
  //  }
    //char a1[2];
    //int a2;
};

int main()
{
	A a;
	printf("sizeof a = %d\n", sizeof(a));
	B b;
	printf("sizeof b = %d\n", sizeof(b));
	return 0;
}
