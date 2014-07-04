#include <stdio.h>
#include <stdlib.h>

char* clockwise(int size) {
	char **a;	
	//char a[5][5];
	int nc=size/2;           /*circle number*/
	int i,j,k,v;
	int x,y;

	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	a = (char **)malloc(size*sizeof(char *)); //char * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!! tragic!!!!!!!!!!!!!!!!!!!!!!!!!!
	for(i=0;i<size;i++)
	{
		a[i]=(char *)malloc(size*sizeof(char));
	}
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	x=size/2;
	y=size/2;
	v=1;
	a[x][y]= v++;
	y++;
	a[4][4]=1;
	for(i=2;i<nc+2;i++)
	{
		printf("nc=%d\n",i);

		for(j=0; j<4; j++) /*every row*/
		{
			printf("row=%d\n",j);

			if(j==0)
			{
				for(k=0;k<2*(i-1);k++)
				{
					a[x++][y]=v++;
					printf("a[%d][%d]=%d\n",x-1,y,v-1);
					if(k==2*(i-1)-1)
					{
						y--;
						x--;
					}
				}
			}
			if(j==1)
			{
				for(k=0;k<2*(i-1);k++)
				{
					a[x][y--]=v++;
					printf("a[%d][%d]=%d\n",x,y+1,v-1);
					if(k==2*(i-1)-1)
					{
						y++;
						x--;
					}
				}
			
			}
			if(j==2)
			{
				for(k=0;k<2*(i-1);k++)
				{
					a[x--][y]=v++;
					printf("a[%d][%d]=%d\n",x+1,y,v-1);
					if(k==2*(i-1)-1)
					{
						y++;
						x++;
					}
				}
			
			}
			if(j==3)
			{
				for(k=0;k<2*(i-1);k++)
				{
					a[x][y++]=v++;
					printf("a[%d][%d]=%d\n",x,y-1,v-1);
				//	if(k==2*(i-1)-1)
				}
			}
		}
	}

	for(i=0; i<size; i++)
	{
		for(j=0; j< size; j++)
		{
			if(j!=size-1)
				printf("%d*", a[i][j]);
			else
				printf("%d\n", a[i][j]);
		}
	}
	return (char *)a;
}


int main()
{
	char * p;
	int i,j,num;
	num=5;
	p=clockwise(num);


	/*
	for(i=0; i<num; i++)
	{
		for(j=0; j< num; j++)
			printf("%d*", *(*((char **)p+i)+j));
		printf("\n");

	}
*/

	return 0;
}
