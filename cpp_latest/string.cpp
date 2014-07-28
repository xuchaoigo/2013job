#include<string.h>
#include <iostream>
#include <stdio.h>
#include <utility>
#include <assert.h>

using namespace std;

class str
{
public:
	str(void);

	str(const char *p);
	str(const str& in);
	virtual ~str(){delete p_data;/*p_data=NULL;*/}

	str& operator =(const str& in);
	bool operator ==(const str& in);
	str operator +(const str &in);

	bool find(const str &in);

	int getlen()const{return strlen(p_data);}
    void print(void) { for(unsigned int i=0;i<strlen(p_data);i++)printf("%c",p_data[i]);printf("\n"); }

private:
	char * p_data;
};

str::str(const char * p)
	{
		if(p)
		{
			p_data = new char[strlen(p)+1];
			strcpy(p_data,p);
		}
		else
			p_data=NULL;
	}
str::str(void)
{
	p_data = NULL;
}
str::str(const str& in)
{
	if(in.p_data)
	{
		p_data = new char[strlen(in.p_data)+1];
		strcpy(p_data,in.p_data);
	}
	else
		p_data=NULL;
}

str& str::operator =(const str& rhs)
{
	if(&rhs!=this)
	{
		//方法一：copy and swap技术。
	    //优点：1.可防止自我赋值（不需判断）2.异常安全
		str tmp(rhs);
		//swap the value of "this" and "rhs"
		{
			char * p;
			p=tmp.p_data;
			tmp.p_data=p_data;
			p_data=p;
		}
		//方法二：手动拷贝。注意，不是异常安全的。
/*
			delete [] p_data;
			p_data = new char[rhs.getlen()+1];
			strcpy(p_data,rhs.p_data);
*/

		return *this;
	}
	return *this;
}
bool str::operator ==(const str& in)
{
	if(!in.p_data||strlen(in.p_data)!= strlen(p_data))
		return false;
	else
	{
		if(strcmp(in.p_data, p_data)!=0)
			return false;
	}
	return true;
}

str str::operator +(const str &in)
	{

		if(!in.p_data)
			return *this;
		else if(!p_data)
			return in;
		else
		{
			str news;
			news.p_data=new char[strlen(p_data)+strlen(in.p_data)+1];//在类的成员函数内可以访问同种对象的私有成员（同种类则是友元关系）
			strcpy(news.p_data,p_data);
			strcat(news.p_data,in.p_data);
			return news;
		}
	}
bool str::find(const str &in)
{
	if(strstr(p_data,in.p_data)!= NULL)
		return true;
	else
		return false;
}
int maino()
{
	cout<<"hi"<<endl;
	str s1="abc";
	str s2=s1;
	str s3="de";
	str s4="b";

    s1.print();
    s2.print();
    s3.print();
    bool if1=(s1==s2);
    cout<<"s1=s2?"<<if1<<endl;

    s2=s1+s3;
    s2.print();

    cout<<"find(s1,s3)"<<s1.find(s3)<<endl;
    cout<<"find(s1,s4)"<<s1.find(s4)<<endl;
	return 0;
}
