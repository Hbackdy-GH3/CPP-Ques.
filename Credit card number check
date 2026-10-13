#include <iostream>
#include <limits>

using namespace std;

void checkCreditNum(const long long creditNum);

int main() {

        long long creditNum;
        cout<<"Please enter your credit card number: ";
    do{
        cin>>creditNum;
        double checkDigits=(double)creditNum/10000000000000000;
        if(cin.fail() or checkDigits<0.0 or checkDigits>1.0){
            cin.clear();
            cout<<"Please enter valid credit card number: ";
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            continue;
    }
        break;
    }while(true);
    checkCreditNum(creditNum);
    
    return 0;
}

void checkCreditNum(const long long creditNum){
    long long temp=creditNum;
    int arr[16];
    int sumDoudigit=0;
    int sumOddnum=0;
    for(int i=15;i>=0;i--){
        arr[i]=temp%10;
        temp/=10;
    }
    for(int i=15;i>=0;i--){
        if(i%2==0){
            arr[i]*=2;
            sumDoudigit += (arr[i] >= 10) ? (arr[i] - 9) : arr[i];
        }else{
            sumOddnum+=arr[i];
        }
    }
    cout<<sumDoudigit<<'\n';
    cout<<sumOddnum<<'\n';
    if((sumDoudigit+sumOddnum)%10==0){
        cout<<"This is a valid credit card number!!"<<'\n';
    }else{
        cout<<"This is not a valid credit card number!!"<<'\n';
    }
        
}




