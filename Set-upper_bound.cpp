#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main() {

    set<int>s;
    int num;
    while(true){
        cout<<"Enter your num: ";
        cin>>num;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Please enter valid number\n";
            continue;
        }else{
            if(num==-1){
                break;
            }
            if(s.count(num)==0){
                s.insert(num);
            }else{
                cout<<"Already seen\n";
            }
            auto it=s.upper_bound(num);
            cout<<"Next bigger of "<<num<<" is ";
            if(it!=s.end()){
                cout<<*it<<"\n";
            }else{
                cout<<"None\n";
            }
        }   
    }
    for(int val:s){
        cout<<val<<" ";
    }
    cout<<"( "<<s.size()<<" numbers)\n";

    
    return 0;
}
