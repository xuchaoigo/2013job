#include <iostream>
#include <string>

using namespace std;

int differ(string string1, string string2) 
{
	int num;
	int cnt1=0;
	int cnt2=0;
	int i,j;
	size_t fstart, fend;
	fstart = 0;
	while((fstart = string1.find(" ",fstart))!=string::npos)
		{
			fstart++;
			cnt1++;
		}
	fstart = 0;
	while((fstart = string2.find(" ",fstart))!=string::npos)
		{
			fstart++;
			cnt2++;
		}
	cnt1++;
	cnt2++;
	
	
	fstart = 0;
	int match =0;
	
	string word1[50];
	string word2[50];

	//cout<<"word1:"<<endl;
	for(i = 0; i< cnt1;i++)
	{
		fend = string1.find(" ", fstart);
		word1[i] = string1.substr(fstart,fend-fstart);
		
		fstart = fend+1;
	//	cout<<word1[i]<<endl;
	}
	fstart = 0;
	//cout<<"word2:"<<endl;
	for(i = 0; i< cnt2;i++)
	{
		fend = string2.find(" ", fstart);
		word2[i] = string2.substr(fstart,fend-fstart);
		
		fstart = fend+1;
	//	cout<<word2[i]<<endl;
	}

	
	for(i = 0; i< cnt1;i++)
	{
		for(j = 0; j< cnt2;j++)
			if(word1[i]==word2[j])
				match++;
	}
	//cout<<"match = "<<match<<endl;
	
	if(cnt1>= cnt2)
		num = cnt1-match;
	else
		num = cnt2-match;

	return num;
}

int main(void)
{
	string string1="aaa c basd cxx a b";
	string string2="aaa b cc da";
	int ret;
	ret=differ(string1,string2);
	cout<<ret<<endl;
	return 0;
}



