#include <iostream>
using namespace std;


int main()
{
	while(1)
	{
		int x,y;
		char op;
		float res=0;
		cout << "Please input an expression:";
		cin >> x >> op >> y;
		int correct=1;
		
		if(cin.eof()) break;
		switch(op)
	    {
		case'+': 
				res=x+y;
				break;
		case'-': 
				res=x-y;
				break;
		case'*': 
				res=x*y;
				break;
		case'/': 
				if (y==0)
				{
				cout << "Wrong operator!";
				correct=0;
				}
				else{
					res=x/y;
				}
				break;
		default:
			cout << "Wrong operator!\n";
			correct=0;
	    }
	    
	    while(op!='\n')
	    {
	    	op=cin.get();
	    	int z=0;
			switch(op)
			{
				case'+': 
						cin>>z;
						res=res+z;
						break;
				case'-': 
						cin>>z;
						res=res-z;
						break;
				case'*': 
						cin>>z;
						res=res*z;
						break;
				case'/': 
				    cin>>z;
					if (z==0)
					{
					cout << "Wrong operator!";
					correct=0;
					}
					else{
						res/=z;
						}
					break;	
				case '\n':
					break;
				default:
					cout << "Wrong operator!\n";
					correct=0;
					break;
			}	
			
		}
		if(correct==1)
			cout<<"="<<res<<endl;	
		
		
		
	}
	
	
	
	return 0;
}

