#include <stdio.h>

main()
{
long time;
unsigned char time16; 
int i;
for(i=0;i<61;i++)
{
	time = i;
	time16 = time/10*16 + time %10;

printf("time16 = 0x%x\n",time16);
}



}
