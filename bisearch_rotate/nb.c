#include <stdio.h>

int Search(int A[],int n, int num)
{
	int left = 0 ;
	int right = n - 1 ;
	int mid = 0 ;
	int pos = -1 ;    

	while(left <= right)
	{
		mid = (left + right)/2 ;

		if (A[mid] == num)
		{   
			pos = mid ; 
			break;     
		}
		if (A[left] <= A[mid])    
		{
			if(A[left] <= num && num  < A[mid] )
			{
				right = mid - 1 ;
			}
			else
			{
				left = mid + 1 ;
			} 
		}
		else   
		{
			if ( A[mid] < num && num <= A[right])
			{
				left = mid + 1 ;
			}
			else
			{
				right = mid - 1 ;
			}
		}
	}
	return pos;
}

int main()
{
	int a[12]={15,16,19,20,22,1,3,4,5,7,10,14};
	int pos;
	pos = Search(a, 12, 5);
	printf("pos=%d\n",pos);
	return 0;
}
