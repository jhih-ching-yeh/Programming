#include<iostream>
using namespace std;

int main()
{
	int num;
	cout<<"Please input an integer:";
	cin>>num;
	if(num<2||num>32767)
	{
		cout<<"Wromg Input!";
		return 0;
	}
	if(2<=num<=32767)
	cout<<"The prime factorization of "<<num<<":"<<endl;
	cout<<num<<"=";
	
	for(int i=2;i<=num;i++)
	{
		while(num%i==0){
		num=num/i;
		cout<<i;
		if(num>1)
		cout<<"*";
		}
	}
	
	
	
	return 0;
}
