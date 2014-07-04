#include <sys/time.h>
#include <iostream>
using namespace std;
static struct timeval start_time;
static struct timeval end_time;
static long long  f_st,f_et;

int timer_start(void)
{
	cout<<"timer_start"<<endl;
	gettimeofday(&start_time,NULL);
	f_st = (long long)start_time.tv_sec*1000+(long long)start_time.tv_usec/1000;
	return 0;
}

int timer_end(void)
{
	cout<<"timer_end"<<endl;
	gettimeofday(&end_time,NULL);
	f_et = (long long)end_time.tv_sec*1000+(long long)end_time.tv_usec/1000;
	return 0;
}

int run_time(void)
{
	//cout<<"f_st = "<<f_st<<endl;
	//cout<<"f_et = "<<f_et<<endl;
	cout<<"run_time = "<<f_et-f_st<<" ms"<<endl;
	return 0;
}
