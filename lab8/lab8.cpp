#include <iostream>
using namespace std;

int main(){
	int a,b,numerator,commondivisor;
	int denominator=1,negative=0;
	char operation;
	
	start:
		cin.clear();
		cin.sync();
		
	cout<<"Please input an expression:"<<endl;
	cin>>a>>operation>>b;
	while(cin.fail()||a<0||a>999||b<0||b>999)
	{   cout<<"Wrong input!Input again!"<<endl;
        goto start;
	}
	switch(operation)
	{   case '+': numerator=a+b; break;
	    case '-': numerator=a-b; break;
	    case '*': numerator=a*b; break;
		case '/':
			if(b!=0) {numerator=a; denominator=denominator*b;} break;
		default: cout<<"Wrong input!Input again!"<<endl; goto start; break;
	}
	
	while(operation!='\n')
	{   int c;
	    while(cin.fail()||c<0||c>999)
	    {   cout<<"Wrong input!Input again!"<<endl;
            goto start;
	    }
	    operation=cin.get();
	        switch(operation)
	    {   case '+': cin>>c; numerator=numerator+denominator*c; break;
	        case '-': cin>>c; numerator=numerator-denominator*c; break;
	        case '*': cin>>c; numerator=numerator*c; break;
		    case '/':
		    	cin>>c; 
		    	if(c!=0) {denominator=denominator*c;}
				else {cout<<"Wrong input!Input again!"<<endl; goto start;} break;
		    case '\n': break;
		    default: cout<<"Wrong input!Input again!"<<endl; goto start; break;
	    }
	}
	
	if(numerator<0) {negative++; numerator=(-1)*numerator;}
	if(denominator<0) {negative++; denominator=(-1)*denominator;}
	
	for(int i=1;(i<=numerator)&&(i<=denominator);i++)
	    if((numerator%i==0)&&(denominator%i==0)) commondivisor=i;
    numerator=numerator/commondivisor;
    denominator=denominator/commondivisor;
	
	if(negative==1) numerator=(-1)*numerator;
	cout<<numerator<<"/"<<denominator<<'\n';	

	
	return 0;
}
