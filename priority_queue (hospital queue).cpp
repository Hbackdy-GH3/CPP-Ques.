#include <iostream>
#include <bits/stdc++.h>

using namespace std;

enum Status { yes, no }; 
enum Status does = yes;

class Patients{
public:
    string Name;
    int Severity;

    Patients(){
        Name="AMBIGOUS";
        Severity=0;
    }
    Patients(string name, int severity){
        Name=name;
        if(severity>10){
            Severity=10;
        }else{
            Severity= severity <=0 ? 0 : severity;
        }
    }
};

class Hospital{
    static priority_queue<pair<int,string>>pq;
public:
    void getter(string name,int severity){
        cout<<"Name of the patient: "<<name<<"\n";
        cout<<"Severity level: "<<severity<<"\n";
    }
    void addP(Patients p){
        pq.push({p.Severity, p.Name});
        cout << "Patient " << p.Name << " added successfully\n";
    }
    void treatN(){
        if(!pq.empty()){
            auto it=pq.top();
            if(does==yes){
                cout<<"+-----Most severe patient-----+\n";
            }else if(does==no){
                cout<<"+-----Next severe patient-----+\n";
            }
            getter(it.second,it.first);
            if(does==yes){
                pq.pop();
            }
            cout<<"+-------------------------+\n";
        }else{
            cout<<"No patients left in the queue!\n";
        }
    }
    void showN(){
        does=no;
        treatN();
        does=yes;
    }
    void totalP(){
        cout<<"Total patients: "<<pq.size()<<"\n";
    }
    void allP(){
        if(!pq.empty()){
            priority_queue<pair<int,string>>temp=pq;
            cout<<"+-----All patients list-----+\n";
            while(!temp.empty()){
                auto it=temp.top();
                getter(it.second,it.first);
                temp.pop();
            }
            cout<<"+-------------------------+\n";
        }
        else{
        cout<<"No patients left in the queue!\n";
        }
    }
};
priority_queue<pair<int, string>> Hospital::pq;

int main() {
    Hospital p;
    Patients p1;
    Patients p2("ankit",3);
    Patients p3("sharique",7);
    Patients p4("aman",50);
    Patients p5("anas",6);
    p.addP(p1);
    p.addP(p2);
    p.addP(p3);
    p.addP(p4);
    p.addP(p5);
    p.treatN();
    p.showN();
    p.totalP();
    p.allP();
    return 0;
}
