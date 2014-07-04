//find the sum of a subset that most close to a given value.
//
#include <stdio.h>

#define NUM 10

int find(const int * a, int sum)
{
	int dp[NUM+1][sum+1]; //from 1 to NUM,sum
	int i,j;

	for(i=1;i<NUM+1;i++)
	{
		dp[i][0]=0;
		for(j=1;j<sum+1;j++)
		{
			if(1 == i)//fill the first line. only 1 item.
			{
				if(j >= a[1])
					dp[i][j]=a[1];
				else
					dp[i][j]=0;
			
				continue;
			}

			if(j-a[i] < 0)//item too big, do not pick
			{
				dp[i][j]= dp[i-1][j];
				continue;
			}
				
			if(dp[i-1][j]> dp[i-1][j-a[i]]+a[i])  //two a[i]. may be w[i] and c[i].
				dp[i][j]= dp[i-1][j];
			else
				dp[i][j]= dp[i-1][j-a[i]]+a[i];

			//printf("%d ",dp[i][j]);
		}

	}

	for(i=1;i<NUM+1;i++)
	{
		printf("i=%d: ",i);
		for(j=1;j<sum+1;j++)
		{
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return dp[NUM][sum]; // !!!!!!!!!!
}


int main (void)
{
	int a[NUM+1]={0,1,11,6,20,2,1,18,3,4,0};
	int sum = 9;
	
	int ret = -1;
	ret = find(a,sum);
	printf("the ret = %d\n",ret);
	return 0;
}
