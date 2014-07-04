#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int atoi(const char *str) {

	if(!str)
		return 0;
	if(strcmp(str,"")==0)
		return 0;

	int out=0;
	bool if_ne=false;
	int len = strlen(str);
	char s[len];
	memset(s,0,len);
	strcpy(s,str);
	char *p=s;

	if(s[0]=='-')
	{
		if_ne=true;
		p++;
		len--;
	}   

	int mul=1;
	//p+=len-1;
	while(--len>=0)
	{
		out=(p[len]-48) * mul;
		mul*=10;
		p--;
	}

	if(if_ne)
		out=0-out;
	return out;
}

int main()
{
	const char *in="1";
	cout<<atoi(in)<<endl;
	return 0;
}

