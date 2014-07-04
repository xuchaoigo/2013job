#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main( void )
{
   FILE   *stream;
   FILE   *wstream;
   char   buf[1024];
     
    memset( buf, '\0', sizeof(buf) );//...buf,............
    stream = popen( "pwd", "r" ); //.“ls .l”..... .......“r”....FILE* stream
    wstream = fopen( "popen.txt", "w+"); //.........

    fread( buf, sizeof(char), sizeof(buf), stream); //...FILE* stream.......buf.
    fwrite( buf, 1, sizeof(buf), wstream );//.buf......FILE    *wstream.............
    
    pclose( stream );  
    fclose( wstream );
    
    return 0;
}   
