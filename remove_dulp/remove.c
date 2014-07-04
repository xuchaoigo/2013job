//remove all duplicate char --> add new unique char (1 -> tail).

#include <stdio.h>

void removeDuplicates(char* str) 
{
	if (!str) 
		return;
	int len = strlen(str);
	if (len < 2) 
		return;

	int tail = 1;
	int i;
	for ( i = 1; i < len; ++i)
	{
		int j;
		//if use hit[256]to save the result,instead of "tail", then O(n^2)->O(n)
		for (j = 0; j < tail; ++j)
		{
			if (str[i] == str[j])
				break;
		}
		if (j == tail) //new char, add
		{
			str[tail] = str[i];
			++tail;
		}
	}
	str[tail] = 0;
}

int main()
{
	char a[10] ="aabbcdeab"; 	
	printf("%s\n",a);
	removeDuplicates(a);
	printf("%s\n",a);
}
