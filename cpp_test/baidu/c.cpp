#include <iostream>
using namespace std;

typedef struct queue
{
	int value;
	int id;
};
int g_num;
int v1[1000],v2[1000];

void findmax1(int *value,  int *id)
{
	int max = 0;
	int max_index;
	for(int i = 0; i< g_num; i++)
	{
		if(v1[i] > max)
		{
			max  = v1[i];
			max_index =i;
		}
	}
	*value = max;
	*id = max_index;		
}
void findmax2(int *value,  int *id)
{
	int max = 0;
	int max_index;
	for(int i = 0; i< g_num; i++)
	{
		if(v2[i] > max)
		{
			max  = v2[i];
			max_index =i;
		}
	}
	*value = max;
	*id = max_index;		
}



int main(void)
{
	queue q1[1000],q2[1000];

	int fr_num;
	cin>>fr_num;
	g_num = fr_num;
	int fr_x[1000];
	int fr_y[1000];
	for(int i =0; i< fr_num; i++)
	{
		cin>>fr_x[i]>>fr_y[i];
	}
	int gf1_num,gf3_num;
	int gf1_x,gf1_y,gf2_x,gf2_y;
	cin>>gf1_num>>gf1_x>>gf1_y;
	cin>>gf3_num>>gf2_x>>gf2_y;
	

	for(int i = 0; i< fr_num; i++)
	{
		v1[i] = fr_x[i]*gf1_x+fr_y[i]*gf1_y;
		v2[i] = fr_x[i]*gf2_x+fr_y[i]*gf2_y;
	}	
	int sum = 0;
	for(int i = 0; i< fr_num; i++)
	{
		if(v1[i] >  v2[i])
			sum += v1[i];
		else
			sum += v2[i];	
	}
	cout<<sum<<endl;
/*
	for(int i = 0; i< fr_num; i++)
	{
		cout<<v1[i]<<"  "<<v2[i]<<endl;	
	}
*/
/*
	for(int i = 0; i< fr_num; i++)
	{
		findmax1(&(q1[i].value), &(q1[i].id));
		findmax2(&(q2[i].value), &(q2[i].id));
	}

	
	cout<<" q1 "<<endl;	
	for(int i = 0; i< fr_num; i++)
	{
		cout<<q1[i].id<<"  "<<q1[i].value<<endl;	
	}
*/	

	return 0;
}
