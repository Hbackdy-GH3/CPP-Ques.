#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int main() {

    map<string,int>word;
    map<char,int>letter;
    unordered_map<string,int>uword;
    string sen;
    cout<<"Enter a sentence: ";
    getline(cin,sen);
    cout<<sen<<'\n';
    size_t pos;
    int p=0;
    while((pos=sen.find(' ',p))!=string::npos){
        if(pos>p){
            string temp = sen.substr(p, pos-p);
            // tolower(temp.substr(p,pos-p));
            for(int i=0;i<temp.length();i++){
                temp[i]=tolower(temp[i]);
            }
            word[temp]++;
            uword[temp]++;
        }
        p=pos+1;
    }
    string temp=sen.substr(p);
    for(int i=0;i<temp.length();i++){
         temp[i]=tolower(temp[i]);
    }
    word[temp]++;
    uword[temp]++;
    for(auto w:word){
        cout<<w.first<<": "<<w.second<<'\n';
    }
    // for(auto w:uword){
    //     cout<<w.first<<": "<<w.second<<'\n';
    // }

    for(int i=0;i<sen.length();i++){
        sen[i]=tolower(sen[i]);
        letter[sen[i]]++;
    }
    auto max_word=max_element(word.begin(),word.end(),[](const auto& a, const auto& b){ return a.second < b.second;});

    cout<<"Most frequent: '"<<max_word->first<<"' appears "<<max_word->second<<" times\n";

    string check;
    cout<<"search a word: ";
    cin>>check;
    auto it=word.find(check);
    if(it!=word.end()){
        cout<<"Found!! frequency of this '"<<it->first<<"' is: "<<it->second<<'\n';
    }else{
        cout<<"Not found!!\n"; 
    }

    return 0;
}
