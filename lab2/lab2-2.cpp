#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int main()
{  
	
	int a,res=0;
    cout<<"Please input a binary number:"; 
    cin>>a;
    if(a>=1024)
    {
		cout<< "Wrong input!"<<endl;
		return 0;
	}
	
    int count=0;
    while(a!=0)
    {
		if(a%10 !=1 && a%10!=0)
			cout<< "Wrong input!"<<endl;
		else{ 
		if(a%10 == 1)
		res+=pow(2,count);
		a = a / 10 ;
		}	
		count += 1 ;
	}
	cout<<"The answer is "<<res<<endl;
}



