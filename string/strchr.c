#include <stdio.h>
int main(void)
{
	char ret_code[4] = {'\0'};
	char *ptr;
	char * rx_buffer = "RTSP/1.0 200 OK\r\n";

	ptr = strchr(rx_buffer,' ');
	strncpy(ret_code, ptr+1, 3);
	printf("rx_buffer = %s\n",rx_buffer);
	printf("ret_code = %s\n",ret_code);
	printf("cmp = %d\n",strcmp(ret_code,"200"));


	return 0;
}
