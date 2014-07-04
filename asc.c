#include <stdio.h>
#define NDS_PORTING_READ32BIG(buf) ((unsigned int)((buf)[0] << 24 | (buf)[1] << 16 | (buf)[2] << 8 | (buf)[3]))

main()
{
char i = 0x30;
char o = 0x33;

printf("%c,%c\n",i,o);

char dst[20];
char four[4];
four[0] = '0';
four[1] = '1';
four[2] = '2';
four[3] = '3';


sprintf(dst,"03%010d",NDS_PORTING_READ32BIG(four));
printf("%s\n",dst);

long lala = 1234567890;
sprintf(dst,"%009d",lala);
printf("%s\n",dst);

}
