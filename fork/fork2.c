#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
/* 
int main(void)
{
   int i;
   for(i=0; i<2; i++){
      fork();
      printf("-");
      fflush(stdout);
}
   return 0;
}
*/

int main(void)
{
   int i;
   for(i=0; i<2; i++){
      fork();
     
       printf("ppid=%d, pid=%d, i=%d \n", getppid(), getpid(), i);
   }
   sleep(10); //...............pstree.......
   return 0;
}

 
