#include <stdio.h>

int scmp(char * a, char *b)
{

	int i=0;
	if(a== NULL && b ==NULL)
		return 0;
	if(a == NULL || b == NULL)
		return 1;
	else
	{
		while(*(a+i)!= '\0' && *(b+i) != '\0')
		{
			if(*(a+i) != *(b+i))
			{
				return 1;
			}	
			i++;
		}
		if(*(a+i)== '\0' && *(b+i) == '\0')	
			return 0;
		else
			return 1;
	
	}

}

int icmp(char *a, char * b)
{
		return 666;
}


int main (void)
{

	char * a,*b;
	
	int (*pcmp)(char *a,char *b);
	pcmp = scmp;
	
	a=NULL;b=NULL;
	printf("NULL,NULL=%d\n",pcmp(a,b));
	a=NULL;b="123";
	printf("NULL,123=%d\n",pcmp(a,b));
	a="12";b="123";
	printf("12,123=%d\n",pcmp(a,b));
	a="123";b="123";
	printf("123,123=%d\n",pcmp(a,b));
	
	pcmp = icmp;
	
	a=NULL;b=NULL;
	printf("NULL,NULL=%d\n",pcmp(a,b));
	a=NULL;b="123";
	printf("NULL,123=%d\n",pcmp(a,b));
	a="12";b="123";
	printf("12,123=%d\n",pcmp(a,b));
	a="123";b="123";
	printf("123,123=%d\n",pcmp(a,b));










	return 0;
}
