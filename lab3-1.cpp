#include<iostream>
using namespace std;

int main() 
{
	int num,sum,n,i;
	cout<<"Please input an integer n:";
	cin>>num;
	if(num>10000||num<2)
	{
	cout<<"Wrong Input!"<<endl;
	return 0;
	}
	if(10000>num>2)
	cout<<"Perfect number is between 2 and "<<num<<endl;
	
	
	
		for(n=1; n<num; n++)
	{
			sum=0;
			for(i=1; i<n; i++)
			{
				if(n%i==0)
				sum+=i;
			}
			if(n==sum)
			{
				cout<<n<<"=1";
				for(int i=2;i<n;i++)
				{
					if(n%i==0)
					cout<<"+"<<i;
				}
			cout<<endl;
			}
			
	}	
	}
	
	
	
	
