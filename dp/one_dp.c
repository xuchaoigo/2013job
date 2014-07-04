//find the sum of a subset that most close to a given value.
//
#include <stdio.h>
#include <memory.h>

#define NUM 10

int find(const int * a, int sum)
{
	int dp[sum+1]; //from 1 to NUM,sum
	int i,j;

	memset(dp, 0, sizeof(int)* (sum+1));
	for(i=1;i<NUM+1;i++)
	{
		for(j=sum;j >0;j--)
		{
			if(j-a[i]>=0)              //a[i]:element 
				if(dp[j-a[i]]+a[i]> dp[j])
					dp[j] = dp[j-a[i]]+a[i];
		}
	//print current dp
	printf("i=%d: ",i);
	for(j=1;j<sum+1;j++)
	{
		printf("%d ",dp[j]);
	}
	printf("\n");
	}

	return dp[sum]; // !!!!!!!!!!
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
