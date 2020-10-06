#include <iostream>
using namespace std;

int main()
{
	int num, a, b, c, d,e;
	cout << "Please input one 5-digit integer:";
	cin >> num;
	a = num/10000;
	b = (num-a*10000)/1000;
	c = (num-a*10000-b*1000)/100;
	d = (num-a*10000-b*1000-c*100)/10;
	e = (num-a*10000-b*1000-c*100-d*10);
	cout << a << "\n" << b << "\n" << c << "\n" << d << "\n" << e;
	return 0;
}
