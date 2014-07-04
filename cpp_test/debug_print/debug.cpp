#include <iostream>
#include <stdio.h>


using namespace std;
#define C_DEBUG(args...)\ 
do{\
printf("[C_DEBUG] %s:%s(). ", __FILE__, __FUNCTION__); printf("" args);}\
while(0)

#define CPP_DEBUG(args...) cout<<args<<endl;


int main()
{
	int a =123;
	char *b = "abc";
	string c = "xyz";
	//C_DEBUG("this is c debug, %d %s %s",a,b,c);
	//CPP_DEBUG(a,b,c);

	cerr<<a<<endl<<b<<endl<<c<<endl;
}
