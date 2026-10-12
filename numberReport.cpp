#include <iostream>

using namespace std;

int countDigits(int num){
    int digit=0;
    do{
        num=num/10;
        digit++;
    }
    while(num!=0);
    return digit;
}

int sumDigits(int num){
    int sum=0;
    while(num!=0){
        sum=sum+(num%10);
        num=num/10;
    }
    return sum;
}

int revDigits(int num){
    int revNum=0;
    while(num!=0){
        revNum=(revNum*10)+(num%10);
        num=num/10;
    }
    return revNum;
}

int power(int digit, int digits){
    int value=1;
    while(digits>0){
        value*=digit;
        digits--;
    }
    return value;
}

void checkArm(int num, int digits){
    int digitsPowSum=0;
    int temp=num;
    while(temp!=0){
        int digit=temp%10;
        int value=power(digit, digits);
        digitsPowSum+=value;
        temp=temp/10;
    }
    cout<<"Armstrong: "<<(num==digitsPowSum ? "Yes" : "No")<<endl;
}

int main() {

    int num;
    cout<<"Enter a number: ";
    cin>>num;
    if(num<0){
        num*=-1;
    }
    cout<<"Number: "<<num<<endl;
    
    int digits=countDigits(num);
    cout<<"digits: "<<digits<<endl;
    
    int sums=sumDigits(num);
    cout<<"sum of digits: "<<sums<<endl;
    
    long long revNums=revDigits(num);
    cout<<"reverse num: "<<revNums<<endl;
    
    cout<<"Palindrome: "<<(revNums==num ? "Yes" : "No")<<endl;
    
    checkArm(num, digits);
    
    return 0;
}