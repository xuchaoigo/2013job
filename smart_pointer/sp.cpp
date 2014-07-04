#include <iostream>
#include <string>

using namespace std;


class comp
{
public: 
	explicit comp(int r, int v)
	:real(r), virt(v)
	{
		//real = r;
		//virt = v;
	}
	~comp()
	{
		cout<<"release comp"<<endl;
	}
	int get_real()
	{
		return real;	
	}
	int get_virt()
	{
		return virt;	
	}
private:
	int real;
	int virt;
};


template <typename T> 
class sp
{
public:
	//construct
	explicit sp(T * pin)
	{
		ref = pin;
		cnt = new unsigned;
		*cnt = 1;
		cout<<"new sp,cnt="<<*cnt<<",this="<<this<<endl;
	}
	explicit sp(const sp<T>& spin)
	{
		ref = spin.ref;
		cnt = spin.cnt;
		(*cnt)++;
		cout<<"new sp,cnt="<<*cnt<<",this="<<this<<endl;
	}
	//operator =
	sp<T> & operator=(sp<T> & sptr)
	{
		if(this != &sptr)
		{
			//update left value
			if(--*cnt == 0)
			{
				cout<<"release class,cnt="<<*cnt<<",this="<<this<<endl;
				delete ref;
				delete cnt;
			}	
			ref = sptr.ref;
			cnt = sptr.cnt;
			(*cnt)++;
		}
		return *this;
	}
	//dereference
	T& operator*()
	{
		return *ref;
	}
	T* operator->()
	{
		return ref;
	}
	//destruct
	~sp()
	{
		cout<<"release sp,cnt="<<*cnt<<",this="<<this<<endl;
		(*cnt)--;
		if(*cnt == 0)
		{
			delete ref;
			delete cnt;
		}	
	}
private:
	T * ref;
	unsigned * cnt;
};

int main()
{
	int *a = new int;
	comp * c = new comp(12,34);
	comp * d = new comp(56,78);

	//sp<int>  sptr(a);
	//sp<int>  sptr2(sptr);
	sp<comp>  sptr3(c);
	//sp<comp>  sptr4(sptr3);
	sp<comp>  sptr5(d);

	cout<<"real of ptr3 = "<<(*sptr3).get_real()<<endl;
	cout<<"real of ptr5 = "<<(*sptr5).get_real()<<endl;
	sptr3 = sptr5;
	cout<<"real of ptr3 = "<<(*sptr3).get_real()<<endl;
	cout<<"real of ptr5 = "<<(*sptr5).get_real()<<endl;

	//cout<<"real of ptr3 = "<<(*sptr3).get_real()<<endl;
	//cout<<"real of ptr4 = "<<sptr4->get_real()<<endl;

	//sptr3.~sp();
	//sptr4.~sp();
	return 0;
}
