#include <stdio.h>
#include <string.h>

int minValue(int a,int b, int c)
{
	int tmp;
	if(a < b)
		tmp = a;
	else
		tmp = b;
	if(c < tmp)
		return c;
	else
		return tmp;
}


int CalculateStringDistance(const char *strA, int pABegin, int pAEnd,    
		const char * strB, int pBBegin, int pBEnd)     
{    
	if(pABegin > pAEnd)    
	{    
		if(pBBegin > pBEnd)    
			return 0;     
		else    
			return pBEnd- pBBegin + 1;    
	}    

	if(pBBegin > pBEnd)    
	{    
		if(pABegin > pAEnd)    
			return 0;    
		else    
			return pAEnd-pABegin + 1;    
	}    

	if(strA[pABegin] == strB[pBBegin])    
	{    
		return CalculateStringDistance(strA, pABegin + 1, pAEnd,    
				strB, pBBegin + 1, pBEnd);    
	}    
	else    
	{    
		int t1 = CalculateStringDistance(strA, pABegin, pAEnd, strB,     
				pBBegin + 1, pBEnd);    
		int t2 = CalculateStringDistance(strA, pABegin + 1, pAEnd,     
				strB,pBBegin, pBEnd);    
		int t3 = CalculateStringDistance(strA, pABegin + 1, pAEnd,    
				strB,pBBegin + 1, pBEnd);    
		return minValue(t1,t2,t3) + 1;    
	}    
}    
int main(void)
{
	char * a="absdasdadkgc";
	char * b="aakeasdadkaaa";
	int distance = -1;
	distance = CalculateStringDistance(a,0,strlen(a),b,0,strlen(b));
	printf("e1=%d,e2=%d\n", strlen(a), strlen(b));
	printf("a=%s,b=%s\ndistance = %d\n", a,b,distance);
	return 0;
}
