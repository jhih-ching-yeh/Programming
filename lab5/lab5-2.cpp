#include<iostream>
#include<stdio.h>
#include<algorithm> 
using namespace std;

void m_sort(int data2[][100],int n,int m,int order)
{
	int data1[10000],k=1,count=0;
	for(int i=0;i<n;i++)
	{   for(int j=0;j<m;j++)
	    {   data1[k]=data2[i][j];k++;
		}
	}
	
	if(order==1)
	    {   sort(data1+1,data1+k);
		    reverse(data1+1,data1+k);
			cout<<"The sorted matrix in the non-increasing order:"<<endl;
	    }
	if(order==2)
	    {   sort(data1+1,data1+k);
		    cout<<"The sorted matrix in the non-decreasing order:"<<endl;
		}
	if(order!=1&&order!=2)
		{
		cout<<"Wrong Input!"<<endl;
		cout<<"Select sorted order:1)non-increasing order,2)non-decreasing order(<ctrl-z to exit):";
		}
	for(int l=1;l<k;l++)
		{   cout<<data1[l]<<" ";
		    count++;
            if(count==m)
	            {   cout<<endl;
				    count=0;
				}
	    }
}

int main()
{
	int n,m,order,x,y;
	cout<<"Please input n and m:";
	cin>>n>>m;
	if(cin.eof())
	return 0;
	if(n<2||n>100||m<2||m>100)
	{
	cout<<"Wrong Input!"<<endl;
	return 0;
	}
	int data2[100][100];
	if(n>=2&&n<=100&&m>=2&&m<=100)
	cout<<"Please input the elements of matrix "<<n<<"*"<<m<<" by row mayor:"<<endl;
	
	for(x=0;x<n;x++)
	{
		for(y=0;y<m;y++)
		cin>>data2[x][y];
	}
	
	cout<<"Select sorted order:1)non-increasing order,2)non-decreasing order(<ctrl-z to exit):";
	if(cin>>order)
		m_sort(data2,n,m,order);
	
return 0;	
}


	
	

	
	
	
	
	

