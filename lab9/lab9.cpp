//HW9_0613144 


#include <iostream>
using namespace std;

class RationalO {
	friend ostream &operator<<(ostream &, const RationalO &);
public:
    RationalO(long=0,long=1);
    void setNumerator(long);
	void setDenominator(long);
	long getNumerator();
	long getDenominator();
    RationalO operator+(const RationalO &r);
    RationalO operator-(const RationalO &r);
    RationalO operator*(const RationalO &r);
    RationalO operator/(const RationalO &r);
	void Reduce();
    void print();
    long Gcd(long,long);
	int gcd;
    long lcm;
private:
    long Numerator;
    long Denominator;
};

RationalO::RationalO(long num,long den){
    Numerator=num;
    Denominator=den;
}


long RationalO::Gcd(long x,long y){
    if(x%y!=0)  return Gcd(y,x%y);
    else        return y;
}

RationalO RationalO::operator+(const RationalO &r){
    gcd=Gcd(Denominator,r.Denominator);
    lcm=(Denominator*r.Denominator)/gcd;
    RationalO z(Numerator*(r.Denominator/gcd)+r.Numerator*(Denominator/gcd),lcm);
    return z;
}

RationalO RationalO::operator-(const RationalO &r){
    gcd=Gcd(Denominator,r.Denominator);
    lcm=(Denominator*r.Denominator)/gcd;
    RationalO z(Numerator*(r.Denominator/gcd)-r.Numerator*(Denominator/gcd),lcm);
    return z;
}

RationalO RationalO::operator*(const RationalO &r){
    gcd=Gcd(Numerator*r.Numerator,Denominator*r.Denominator);
    if(gcd!=1){
        RationalO z(Numerator*r.Numerator/gcd,Denominator*r.Denominator/gcd);
        return z;
    }
    else{
        RationalO z(Numerator*r.Numerator,Denominator*r.Denominator);
        return z;
    }
}

RationalO RationalO::operator/(const RationalO &r){
    gcd=Gcd(Numerator*r.Denominator,Denominator*r.Numerator);
    if(gcd!=1){
        RationalO z(Numerator*r.Denominator/gcd,Denominator*r.Numerator/gcd);
        return z;
    }
    else{
        RationalO z(Numerator*r.Denominator,Denominator*r.Numerator);
        return z;
    }
}

void RationalO::print(){
   cout<<Numerator<<"/"<<Denominator<<endl;
}

int main() {
	int A,B;
	char operation;

	start:
		cin.clear();
		cin.sync();
	
	cout<<"Please input an expression:"<<endl;
	cin>>A>>operation>>B;
	while(cin.fail()||A<0||A>999||B<0||B>999)
	{   cout<<"Wrong input, try again!"<<endl;
        goto start;
	}
	RationalO a(A,1);
	RationalO b(B,1);
	RationalO ans;
	
	switch(operation)
	{   case '+': ans=a+b; break;
	    case '-': ans=a-b; break;
	    case '*': ans=a*b; break;
		case '/': ans=a/b; break;
		default: cout<<"Wrong input, try again!"<<endl; goto start; break;
	}
	operation=cin.get();
	while(operation!='\n')
	{   int C;
	    
	    cin>>C;
	     while(cin.fail()||C<0||C>999)
	    {   cout<<"Wrong input, try again!"<<endl;
            goto start;
	    }
		RationalO c(C,1);
	    switch(operation)
	    {   case '+': ans=ans+c; break;
	        case '-': ans=ans-c; break;
	        case '*': ans=ans*c; break;
		    case '/': ans=ans/c; break;
		    case '\n': break;
		    default: cout<<"Wrong input, try again!"<<endl; goto start; break;
	    }
	    operation=cin.get();
	}
	
    ans.print();
    
	system("pause");
	return 0;
}
