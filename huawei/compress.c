#include <stdio.h>
#include <string.h>

void stringZip(const char *pInputStr, long lInputLen, char *pOutputStr)
{
	char *pi = pInputStr;
	char *po = pOutputStr;
	int cnt = 0;

	if(!pInputStr || !pOutputStr)
		return;
	
	if(*(pi+1)=='\0')
	{
		strcpy(pOutputStr, pInputStr);
		return;
	}

	while(*pi != '\0' && *(pi+1) != '\0')
	{
		if(*(pi+1)== *pi)
		{
			cnt = 1;
			for(;*(pi+1)== *pi; pi++)
			{
				cnt++;
			}
			sprintf(po, "%d%c", cnt, *(pi-1));
			po+=2;
		}
		else
		{
			*po = *pi;
			po++;
		}
		pi++;
	}
	if(*pi == '\0')
		*po='\0';
	else
	{
		*po = *pi;
		*(po+1)='\0';
	}
	return;
}

int main(void)
{
	char str_in[20]={0};
	char str_out[20]={0};
	
	printf("input a string:\n");
	scanf("%s", str_in);

	stringZip(str_in,strlen(str_in),str_out);
	printf("in=%s\n",str_in);
	printf("out=%s\n",str_out);
	return 0;
}
