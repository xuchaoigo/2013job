6���������ܷ�����
��GCC ֧�ֵ���������ѡ�����-p��-pg�����ǻὫ������Profiling����Ϣ���뵽�������ɵĶ����ƴ����С�������Ϣ�������˸�Ϊ��ϸ�ĵ�����Ϣ��ֻ������ô���ã�����������ӿ���֤ʵ����Ҳ�����ҳ����������ƿ�����а�������Э��Linux����Ա�����������ܳ�����������ߡ��ڱ���ʱ����-pѡ��������ɵĴ����м���ͨ���������ߣ�Prof���ܹ�ʶ���ͳ����Ϣ���� -pgѡ��������ֻ��GNU�������ߣ�Gprof������ʶ���ͳ����Ϣ���������ǻ�����crash.c����ı���͵��ԣ�������ʹ��-pѡ��Գ�����Եĺô��ɡ�

�������룺
 gcc -Wall -g -p crash.c -o crash

�������ԣ�
[lyanry@lyanry crash]$ gdb -q crash
Using host libthread_db library "/lib/libthread_db.so.1".
(gdb) run
Starting program: /home/lyanry/program/c++/crash/crash
Reading symbols from shared object read from target memory...done.
Loaded system supplied DSO at 0x909000
Input an integer:11

Program received signal SIGSEGV, Segmentation fault.
0x00971667 in _IO_vfscanf_internal () from /lib/libc.so.6
(gdb) backtrace
#0  0x00971667 in _IO_vfscanf_internal () from /lib/libc.so.6
#1  0x00979337 in scanf () from /lib/libc.so.6
#2  0x08048520 in main () at crash.c:8

�������ڣ����Դ�GDB�������п������г�������кŵ�backtrace����ˣ���#2  0x08048520 in main () at crash.c:8��ʹ��frameָ��鿴������룬������£�
(gdb) frame 2
#2  0x08048520 in main () at crash.c:8
8         scanf("%d", input);

���������е�������֪�����ⷢ�������˰ɣ�

�������棬������-p��-pgѡ�����ڷ������������ƿ�������ǰ�����������һ��man�ֲ��϶�-p��-pgѡ�����ϸ˵����
-p  Generate extra code to write profile information suitable for the
    analysis program prof.  You must use this option when compiling the
    source files you want data about, and you must also use it when
    linking.

-pg Generate extra code to write profile information suitable for the
    analysis program gprof.  You must use this option when compiling
    the source files you want data about, and you must also use it when
    linking.
����
����˵�������ἰ��prof��gprof�����ǳ��������������ߣ�prof��ͨ�õģ�gprof��GNU�����ġ�������profile.c������ gprof���ڱ������ʱҪ���-gpѡ�Ҫע�⣬���ѡ��ֻ���������ڼ�������õġ�profile.c�����嵥���£�
//profile.c
#include <stdio.h>
void function1()
{
  int i=0,j;
  for(j=0;j<100000;j++)
    i+=j;
}
void function2()
{
  int i,j;
  function1();
  for(j=0;j<200000;j++)
    i=j;
}
int main(void)
{
  int i,j;
  for(i=0;i<100;i++)
    function1();
  for(j=0;i<50000;i++)
    function2();

  return 0;
}

�������룺
gcc -Wall -pg profile.c -o profile

��������profile���򣬻��ڵ�ǰĿ¼������һ��gmon.out�ļ����������ʹ��gprof���߶�profile������������ˣ�
gprof profile >gprof.txt

��������ָ��ִ��ʱ��gprof���Զ�ʹ��gmon.out�ļ������������ض���gprof.txt�ļ��С������֪��gmon.out��ʲô�����ǿ���man�ֲ���������ɣ�
 "Gprof" reads the given object file (the default is "a.out") and��establishes the relation between its symbol table and  the  call  graph��profile from gmon.out. 
����
�������ˣ�����Ҫ�������飬�����ڵ�ǰĿ¼�´�gprof.txt�������ˣ��ļ��У����Ǹ���Ȥ������ͨ����������
Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total          
 time   seconds   seconds    calls  us/call  us/call  name   
 66.92     24.44    24.44    49900   489.78   731.38  function2
 33.08     36.52    12.08    50000   241.60   241.60  function1
������
index % time    self  children    called     name
                                                 <spontaneous>
[1]    100.0    0.00   36.52                 main [1]
               24.44   12.06   49900/49900       function2 [2]
                0.02    0.00     100/50000       function1 [3]
-----------------------------------------------
               24.44   12.06   49900/49900       main [1]
[2]     99.9   24.44   12.06   49900         function2 [2]
               12.06    0.00   49900/50000       function1 [3]
-----------------------------------------------
                0.02    0.00     100/50000       main [1]
               12.06    0.00   49900/50000       function2 [2]
[3]     33.1   12.08    0.00   50000         function1 [3]
-----------------------------------------------
����
����������ϸ˵��ȥ���Լ���ĥȥ�ɡ�

