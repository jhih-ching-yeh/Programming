#include<iostream>
using namespace std;

int GCD(int m,int n)
{
	int r=0;
	while(n>0)
	{
		r=m%n;
		m=n;
		n=r;
	}
	return m;
}
int main()
{
	int num,i;
	cout<<"Please input an integer:";
	cin>>num;
	if(num<2||num>32767)
	cout<<"Wrong Input!";
	

	int count=0;
	for(i=1;i<num;i++)
	{
		if(GCD(num,i)==1)
		{
			//cout<<"where gcd("<<num<<","<<i<<")"<<endl;
			count+=1;
		}
	}
	cout<<"Euler's phi function of "<<num<<" is "<<count<<","<<endl;
	for(i=1;i<num;i++)
	{
		if(GCD(num,i)==1)
		{
			cout<<"where gcd("<<num<<","<<i<<")"<<endl;
			//count+=1;
		}
	}
	return 0;
}
