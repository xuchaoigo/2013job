//find the max sum or multiple value of the substring(continueous)
//dp -> O(n) loop


#include <stdio.h>

int big(int a,int b, int c)
{
	int big1 = a>b?a:b;
	int big2 = b>c?b:c;
	return big1>big2?big1:big2;
}

int small(int a,int b, int c)
{
	int s1 = a<b?a:b;
	int s2 = b<c?b:c;
	return s1<s2?s1:s2;
}
int maxm(const int * a, int len)
{
	int i,max=1,max_bac=1;
	int min=1;

	for(i = 0;i<len;i++)
	{
		if(a[i]==0)
		{
			if(max > max_bac)
				max_bac = max; //update max
			max = min = 1;
			//printf("save = %d\n", max_bac);
			continue;
		}

		max = big(max, max*a[i], min*a[i]);
		min = small(min, max*a[i], min*a[i]);
	}
	if(max>max_bac)
		return max;
	else
		return max_bac;
}


int maxs(const int * a, int len)
{
	int i,max=0,max_bac=0;
	for(i = 0;i<len;i++)
	{
		if(a[i]+max>=0)
			max+=a[i];
		else
		{	
			if(max > max_bac)
				max_bac = max;//update max_bac
			max = 0;
		}
	}
	if(max>max_bac)
		return max;
	else
		return max_bac;
}



int main()
{
	int a[10]={1,-1,3,5,0,2,-100,1,0,40};
	int b[10]={0,1,3,5,0,2,-5,-3,0,2};
	int max_sum,max_mul;
	int i;

	max_sum = maxs(a, 10);
	max_mul = maxm(b, 10);

	printf("max_sum = %d\n", max_sum);
	printf("max_mul = %d\n", max_mul);
	return 0;
}
