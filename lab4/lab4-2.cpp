#include<iostream>
using namespace std;

int main()
{
	int num;
	cout<<"Please input an integer:";
	cin>>num;
	if(num<1||num>32767)
	{
		cout<<"Wrong Input!";
		return 0;
	}
	int A[num][2];
	if(num>=1&&num<=32767)
	{
	cout<<"Please input "<<num<<" points :"<<endl;
	}
	for(int x=0;x<num;x++)
	{
		for(int y=0;y<2;y++)
		cin>>A[x][y];
	}
	
	int count=0;
	for(int i=0;i<num;i++)
	{
		count=0;
		for(int j=0;j<num;j++)
		{
			if(i!=j)
			{
				if(A[i][0]>A[j][0]&&A[i][1]>A[j][1])
				count+=1;
			}
		}
	cout<<"The rank of point ("<<A[i][0]<<","<<A[i][1]<<")"<<":"<<count<<endl;	
	}

return 0;	
}

