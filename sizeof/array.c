#include <stdio.h>

main()
{
	const int length = 10;
	char char_array[length];
	int int_array[length];
	double db_array[length];
	char *pchar_array[length];
	char achar= 'a';  
	char *pchar = char_array+1;
	int *pint = int_array+1;

	short ss;
       	printf("length of short = %d\n",sizeof(ss));

	printf("length of char_array = %d\n",sizeof(char_array));
	printf("length of int_array = %d\n",sizeof(int_array));
       	printf("length of db_array = %d\n",sizeof(db_array));
       	printf("length of pchar_array = %d\n\n",sizeof(pchar_array));
	
	/* not recommand . */

        printf("sizeof 'a'= %d. sizeof achar = %d\n",sizeof('a'),sizeof(achar));
	
        printf("sizeof pointer = %d.\n",sizeof(pchar));
        printf("sizeof pointer = %d.\n",sizeof(pint));
	return 0;

}
