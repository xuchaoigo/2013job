//º¯Êı¶ÔÏó
#include <string.h>
#include <iostream>

using namespace std;

class GenericNegate
{
public:
template < typename T>
T operator() (T t) const {return -t;}
};

int jmain()
{
	GenericNegate negate;
	cout<< negate(53333)<<endl; // int
	cout<< negate(5.3333); // double
	return 0;
}
