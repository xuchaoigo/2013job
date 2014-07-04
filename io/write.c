#include <stdio.h>

main()

{
	char buf[20]= "write from dsp\n";
	
	write(1, buf,sizeof(buf));
	


}
