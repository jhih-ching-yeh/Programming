#include <stdio.h>
#include <iostream>
using namespace std;


int main()
{
 int x,y,z,max,mid,min,sum;
 cout <<"Please input three integers: ";
 cin >> x >> y >> z;
if(x<y && x<z)
 min = x ;
 else if (y<x && y<z)
 min = y ;
 else if (z<x && z<y)
 min = z ;
 if(x>y && x>z)
 max = x ;
 else if (y>x && y>z)
 max = y ;
 else if (z>x && z>y)
 max = z ;
 if ((x>y && z>x) || (x>z && y>x))
 mid = x;
 else if ((y>x && z>y) || (y>z && x>y))
 mid = y;
 else if ((z>x && y>z)|| (z>y && x>z))
 mid = z;
 sum = x+y+z;
 cout << "The largest is " << max <<endl; 
 cout << "The median is " << mid <<endl;
 cout << "The smallest is " << min <<endl;
 cout << "The sum is " << sum <<endl; 
 return 0;
}
 

