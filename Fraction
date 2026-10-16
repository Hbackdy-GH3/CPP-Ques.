#include <iostream>
#include <cstdlib>

using namespace std;

class Fraction{
private:
    int N;
    int D;

    int gcd(int a, int b){
        a=abs(a);
        b=abs(b);
        while(b!=0){
            int rem=a%b;
            a=b;
            b=rem;
        }
        return a;
    }

    void simplify(){
        if(D<0){
            N=-N;
            D=-D;
        }
        int g=gcd(N,D);
        if(g!=0){
            N/=g;
            D/=g;
        }
    }

public:
    Fraction(){
        N=0;
        D=1;
    }

    Fraction(int n, int d){
        if(d==0){
            cout<<"Denominator can't be 0, using 1"<<"\n";
            d=1;
        }
        N=n;
        D=d;
        simplify();
    }

    Fraction operator+(const Fraction& fv) const{
        return Fraction(N*fv.D+fv.N*D, D*fv.D);
    }

    Fraction operator-(const Fraction& fv) const{
        return Fraction(N*fv.D-fv.N*D, D*fv.D);
    }

    Fraction operator*(const Fraction& fv) const{
        return Fraction(N*fv.N, D*fv.D);
    }

    Fraction operator/(const Fraction& fv) const{
        if(fv.N==0){
            cout<<"Cannot divide by zero"<<"\n";
            return Fraction();
        }
        return Fraction(N*fv.D, D*fv.N);
    }

    bool operator==(const Fraction& fv) const{
        return N==fv.N && D==fv.D;
    }

    friend ostream& operator<<(ostream& out, const Fraction& fv);
};

ostream& operator<<(ostream& out, const Fraction& fv){
    out<<fv.N<<"/"<<fv.D;
    return out;
}

int main(){
    Fraction a(1,2);
    Fraction b(3,4);

    cout<<"a = "<<a<<", b = "<<b<<"\n";
    cout<<"a + b = "<<a+b<<"\n";
    cout<<"a - b = "<<a-b<<"\n";
    cout<<"a * b = "<<a*b<<"\n";
    cout<<"a / b = "<<a/b<<"\n";
    cout<<"6/8 simplified = "<<Fraction(6,8)<<"\n";

    if(Fraction(1,2)==Fraction(2,4)){
        cout<<"1/2 == 2/4 ? Yes"<<"\n";
    } else{
        cout<<"1/2 == 2/4 ? No"<<"\n";
    }

    cout<<"3/-4 = "<<Fraction(3,-4)<<"\n";
    cout<<"-9/0 = "<<Fraction(-9,0)<<"\n";
    cout<<"a / 0 = "<<a/Fraction(0,5)<<"\n";

    return 0;
}
