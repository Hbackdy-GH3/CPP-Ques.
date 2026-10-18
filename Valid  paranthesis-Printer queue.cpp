#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void validParen(){
    stack<char>st;
    string bracket;
    cout<<"Enter your combo of brackets: ";
    cin.ignore();
    getline(cin,bracket);
    if(bracket.length()%2!=0){
        cout<<"This is not balanced\n";
        return;
    }
    for(int i=0;i<bracket.length();i++){
        if(bracket[i]=='(' or bracket[i]=='{' or bracket[i]=='['){
            st.push(bracket[i]);
        }else{
            if(!st.empty() && ((st.top()=='(' && bracket[i]==')') or (st.top()=='{' && bracket[i]=='}') or (st.top()=='[' && bracket[i]==']'))) st.pop();
            else{
                cout<<"This is not balanced\n";
                return;
            }
        }
    }
    if(!st.empty()){
        cout<<"This is not balanced\n";
        return;
    }
    cout<<"This is balanced\n";
}

void queuefiles(){
    queue<string>pq;
    int choice;
    do{
        cout<<"1. Add document\n";
        cout<<"2. Print next\n";
        cout<<"3. Show next\n";
        cout<<"4. Count\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice){
        case 1:{
            string name;
            cout<<"Please enter document name: ";
            cin.ignore();
            getline(cin,name);
            pq.push(name);
            break;
        }
        case 2:
            if(!pq.empty()){
                cout<<"Printing: "<<pq.front()<<"\n";
                pq.pop();
            }else{
                cout<<"Sorry yet there is not items\n";
            }
            break;
        case 3:
            if(!pq.empty()){
                cout<<"Next: "<<pq.front()<<"\n";
            }else{
                cout<<"Sorry yet there is not items\n";
            }
            break;
        case 4:
            cout<<"No of items: "<<pq.size()<<"\n";
            break;
        case 5:
            cout<<"Program end!!!\n";
            break;
        default:
            cout<<"Please enter valid choice\n";
            break;
        }
    }while(choice!=5);
}

int main() {

    int choice;
    while(1){
        cout<<"1. Paranthesis check\n";
        cout<<"2. files system\n";
        cout<<"3. To exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice){
            case 1:
                validParen();
                break;
            case 2:
                queuefiles();
                break;
            case 3:
                exit(0);
                break;
            default:
                cout<<"Please enter valid choice\n";
                break;
            }
        }
    return 0;
}
