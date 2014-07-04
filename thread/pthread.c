#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/msg.h>
#include<string.h>

pthread_t ntid;

int msg_handle = -1;

int g_num = 0;

typedef struct student
{
	int number;
	char name[20];
}stu;

typedef struct msg 
{
	int msg_type;
	char arg[128];
	stu stu;
} msg;

void printids(const char *s){
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();
	printf("%s pid %u tid %u (0x%x)\n",s,(unsigned int)pid,(unsigned int)tid,(unsigned 
				int)tid);
}

void *thread1(void *arg){
	printids("new thread:");
	msg e_msg;
	printf("g_num = %d\n",g_num);
	//snd msg1
	e_msg.msg_type = 100;
        strcpy(e_msg.arg,"msg from thread1");
	e_msg.stu.number = 666;
	strcpy(e_msg.stu.name, "xuchao"); 
	printf("thread1 send:%d,%s\n", e_msg.msg_type,e_msg.arg);

	if (msgsnd(msg_handle, &e_msg, sizeof(msg), IPC_NOWAIT) == -1)  //not block
	{
		printf("iChannel msg queue send failed\n");
		return (void *)0;
	}

	memset(&e_msg, 0, sizeof(msg));
	
	//snd msg2
        e_msg.msg_type = 101;
        strcpy(e_msg.arg,"msg2 from thread1");
	printf("thread1 send:%d,%s\n", e_msg.msg_type,e_msg.arg);

	if (msgsnd(msg_handle, &e_msg, sizeof(msg), IPC_NOWAIT) == -1)  //not block
	{
		printf("iChannel msg queue send failed\n");
		return (void *)0;
	}
	
#if 0
	//rcv msg
	sleep(2);
	if (msgrcv(msg_handle, &e_msg, sizeof(msg), 101, IPC_NOWAIT) == -1)  /*rcv type 101 msg.*/
	{
		printf("iChannel msg queue recv failed\n");
	        return (void *)0;
	}
	printf("thread1:%d,%s\n", e_msg.msg_type,e_msg.arg);
#endif
sleep(10);
	printf("g_num = %d\n",g_num);
	return ((void *)0);
}


int main(){
	int err;

	if ((msg_handle = msgget(1000, IPC_CREAT | 0666)) == -1)  /*first arg of msgget "key" unique,and this key  will exists until the msg queue is distroyed. why it won't work if set key = 100? */
	{
		printf("create msg queue failed\n");
		return -1;
	}

	err = pthread_create(&ntid,NULL,thread1,NULL);
	if(err != 0){
		printf("can't create thread: %s\n",strerror(err));
		return 1;
	}
	printids("main thread:");
	sleep(1);

	msg m_msg;
	//rcv msg
	
	if (msgrcv(msg_handle, &m_msg, sizeof(msg), 0, IPC_NOWAIT) == -1) /*rcv the first msg of the queue.*/
	{
		printf("iChannel msg queue recv failed\n");
	        return -1;
	}
	printf("main:msg received:type = %d,msg = %s\n",m_msg.msg_type,m_msg.arg);
	printf("student number = %d, name = %s\n",m_msg.stu.number, m_msg.stu.name);
	getchar();
	
	memset(&m_msg, 0, sizeof(msg));
	printf("size of msg = %d\n",sizeof(msg));
	//rcv msg2
	g_num++;
	if (msgrcv(msg_handle, &m_msg, sizeof(msg), 0, IPC_NOWAIT) == -1) /*rcv the first msg of the queue.*/
	{
		printf("iChannel msg queue recv failed\n");
	        return -1;
	}
	printf("main:msg received:type = %d,msg = %s\n",m_msg.msg_type,m_msg.arg);
	printf("student number = %d, name = %s\n",m_msg.stu.number, m_msg.stu.name);
	getchar();
	
        msgctl(msg_handle,IPC_RMID,NULL);  /*delete. very important, or this ZZ*/
	

	return 0;
}

