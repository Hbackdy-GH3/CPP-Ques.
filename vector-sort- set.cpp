#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void print(auto type){
    for(int v:type){
        cout<<v<<" ";
    }
    cout<<"\n";
}

bool comp(int a, int b){
    if(a > b) return true;
    return false;
}

int main() {

    vector<int>vec;
    // int n,temp;
    // cout<<"How many number? ";
    // cin>>n;
    // for(int i=0;i<n;i++){
    //     cout<<"Enter "<<i+1<<" no.: ";
    //     cin>>temp;
    //     vec.push_back(temp);
    // }
    vec.push_back(54);
    vec.push_back(1);
    vec.push_back(69);
    vec.push_back(52);
    vec.push_back(6);
    sort(vec.begin(),vec.end());
    print(vec);
    // sort(vec.begin(),vec.end(),greater<int>());
    sort(vec.begin(),vec.end(),comp);
    print(vec);
    set<int>s(vec.begin(), vec.end());
    print(s);
    
    cout<<"Max: "<<*max_element(vec.begin(),vec.end())<<'\n';
    cout<<"Min: "<<*min_element(vec.begin(),vec.end())<<'\n';
    int sum=0;
    for(int v:vec){
        sum+=v;
    }
    cout<<"Sum: "<<sum<<'\n';
    int check;
    cout<<"Enter a number to check their frequency? \n";
    cin>>check;
    cout<<check<<" appears "<<count(vec.begin(),vec.end(),check)<<" times\n";
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    print(vec);
    return 0;
}
