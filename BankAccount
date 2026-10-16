#include <iostream>
#include <string>
using namespace std;
class BankAccount{
private:
    string AccName;
    string AccNum;
    double Balance;
public:
    BankAccount(string AccName, string AccNum){
        this->AccName=AccName;
        this->AccNum=AccNum;
        Balance=0;
    }
    BankAccount(string AccName, string AccNum, double Balance){
        
        this->AccName=AccName;
        this->AccNum=AccNum;
        if(Balance<0){
            cout<<"We can't create account with negative amount"<<"\n";
        this->Balance=0;
            
        }else{
         this->Balance=Balance;   
        }
    }
    void deposit(double amount){
        if(amount<=0){
            cout<<"Please enter valid amount"<<"\n";
            return;
        }
        Balance+=amount;
        cout<<"Your latest balance: "<<Balance<<endl;
    }
    void withdrawn(double amount){
        if(amount<=0){
            cout<<"Please enter valid amount"<<"\n";
            return;
        }else if(Balance<amount){
            cout<<"Insufficient Balance"<<"\n";
            cout<<"your current balance: "<<Balance<<"\n";
            return;
        }
        Balance-=amount;
        cout<<"your latest balance is: "<<Balance<<"\n";
    }
    double getBalance(){
        return Balance;
    }
    void printinfo(){
        cout<<"Account holder name: "<<AccName<<"\n";
        cout<<"Account Number: "<<AccNum<<"\n";
        cout<<"Balance: "<<Balance<<"\n";
    }
};


int main() {

    BankAccount p1("Shahab", "44112717173");
    BankAccount p2("Raj", "4400000173", -500);
    p1.deposit(10000);
    p1.withdrawn(999999);
    cout<<"your current balance is: "<<p1.getBalance()<<"\n";
    
    p2.printinfo();
    
    
    return 0;
}
