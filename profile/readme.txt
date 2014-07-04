6、程序性能分析　
　GCC 支持的其它调试选项还包括-p和-pg，它们会将剖析（Profiling）信息加入到最终生成的二进制代码中。剖析信息即包含了更为详细的调试信息（只是我这么觉得，由下面的例子可以证实），也对于找出程序的性能瓶颈很有帮助，是协助Linux程序员开发出高性能程序的有力工具。在编译时加入-p选项会在生成的代码中加入通用剖析工具（Prof）能够识别的统计信息，而 -pg选项则生成只有GNU剖析工具（Gprof）才能识别的统计信息。下面我们还是以crash.c程序的编译和调试，来看看使用-p选项对程序调试的好处吧。

　　编译：
 gcc -Wall -g -p crash.c -o crash

　　调试：
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

　　现在，可以从GDB输出结果中看到带有出错代码行号的backtrace结果了，即#2  0x08048520 in main () at crash.c:8，使用frame指令，查看出错代码，结果如下：
(gdb) frame 2
#2  0x08048520 in main () at crash.c:8
8         scanf("%d", input);

　　现在有点清晰地知道问题发生在哪了吧！

　　下面，来测试-p或-pg选项用于分析程序的性能瓶颈，结合前面的叙述，看一下man手册上对-p和-pg选项的详细说明：
-p  Generate extra code to write profile information suitable for the
    analysis program prof.  You must use this option when compiling the
    source files you want data about, and you must also use it when
    linking.

-pg Generate extra code to write profile information suitable for the
    analysis program gprof.  You must use this option when compiling
    the source files you want data about, and you must also use it when
    linking.
　　
　　说明中所提及的prof和gprof，都是程序性能剖析工具，prof是通用的，gprof是GNU开发的。以例程profile.c来测试 gprof，在编译程序时要添加-gp选项。要注意，这个选项只是在连接期间产生作用的。profile.c代码清单如下：
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

　　编译：
gcc -Wall -pg profile.c -o profile

　　运行profile程序，会在当前目录中生成一个gmon.out文件，下面可以使用gprof工具对profile程序进行剖析了：
gprof profile >gprof.txt

　　上面指令执行时，gprof会自动使用gmon.out文件，将输出结果重定向到gprof.txt文件中。如果想知道gmon.out是什么，还是看看man手册里的描述吧：
 "Gprof" reads the given object file (the default is "a.out") and　establishes the relation between its symbol table and  the  call  graph　profile from gmon.out. 
　　
　　好了，现在要做的事情，就是在当前目录下打开gprof.txt，看看了，文件中，我们感兴趣的内容通常有两处：
Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total          
 time   seconds   seconds    calls  us/call  us/call  name   
 66.92     24.44    24.44    49900   489.78   731.38  function2
 33.08     36.52    12.08    50000   241.60   241.60  function1
　　与
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
　　
　　不想再细说下去，自己琢磨去吧。

