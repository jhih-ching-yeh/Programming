#include<iostream>
using namespace std;

int main()
{
	int n,m,x,y;
	if(cin.eof()) 
	return 0;
	cout<<"Please input n and m:";
	cin>>n>>m;
	if(n<2||n>100||m<2||m>100)
	{
	cout<<"Wrong Input!"<<endl;
	return 0;
	}
	int A[n][m];
	if(n>=2&&n<=100&&m>=2&&m<=100)
	cout<<"Please input the elements of matrix "<<n<<"*"<<m<<" by row mayor:"<<endl;
	
	for(x=0;x<n;x++)
	{
		for(y=0;y<m;y++)
		cin>>A[x][y];
	}
	
	int search,sum=0;
	cout<<"Please input a target to search: ";
	cin>>search;
	for(x=0;x<n;x++)
	{
		for(y=0;y<m;y++)
		if(A[x][y]==search)
		{
		cout<<"At row "<<x<<" and column "<<y<<".";
		sum=sum+1;
		}
		if(sum==0)
		cout<<"Not found";
		if(cin.eof())
		break;
	}




return 0;
}
