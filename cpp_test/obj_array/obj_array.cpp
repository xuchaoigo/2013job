#include <iostream.h>

class IP
{
public:
	int ip;


};

IP IP_a[10];

int delete_o(short index)
{
int i ;
	for(i = index; i<10-1; i++)
		IP_a[i]=IP_a[i+1];
	IP_a[i].ip=0;
	return 0;
}



int main(void)
{
	int i,j=5;
	for(i = 0; i<10; i++)
		IP_a[i].ip = i+100; 
	delete_o(j);
	for(i = 0; i<10; i++)
		cout<<i<<" "<<IP_a[i].ip<<endl;
	
	return 0 ;
}
