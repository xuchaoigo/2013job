#include<iostream.h>

class a{};
class b{
	char x;
};
class c:public a{
	virtual void fun()=0;
};
class d:public b,public c{};
int main()
{
	cout<<"sizeof(a)"<<sizeof(a)<<endl;
	cout<<"sizeof(b)"<<sizeof(b)<<endl;
	cout<<"sizeof(c)"<<sizeof(c)<<endl;
	cout<<"sizeof(d)"<<sizeof(d)<<endl;
	return  0;
}
