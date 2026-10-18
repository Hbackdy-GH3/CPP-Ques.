#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string title(string str){
    string titles="";
    size_t pos;
    for(int i=0;i<str.length();i++){
        str[i]=tolower(str[i]);
    }
    while((pos=str.find(' '))!=string::npos){
        if(pos>0){
            str[0]=toupper(str[0]);
            titles.append(str,0,pos+1);
        }
        str.erase(0,pos+1);
    } 
    if(!str.empty()){
        str[0]=toupper(str[0]);
        titles.append(str);
    }
    return titles;
}

string revSen(string str){
    string rev="";
    size_t pos;
    while((pos=str.find(' '))!=string::npos){
        if(pos>0){
            rev.insert(0,str,0,pos+1);
        }
        str.erase(0,pos+1);
    }
    if(!str.empty()){
        rev.insert(0,str+" ");
    }
    return rev;
}

int checkPalindrome(string str){
    string front="";
    string back="";
    for(int i=0;i<str.length();i++){
        if(isalpha(str[i])){
            str[i]=tolower(str[i]);
            front.push_back(str[i]);
        }
    }
    for(int i=str.length()-1;i>=0;i--){
        if(isalpha(str[i])){
            str[i]=tolower(str[i]);
            back.push_back(str[i]);
        }
    }
    return front==back;
}

void frequency(string str){
    char letter;
    char best;
    string checked;
    int most=0;
    int curr=0;
    for(int i=0;i<str.length();i++){
        str[i]=tolower(str[i]);
        if(isalpha(str[i]) && (checked.find(str[i])== string::npos)){
            letter=str[i];
            checked.push_back(letter);
            curr=0;
            for(int j=0;j<str.length();j++){    
                str[j]=tolower(str[j]);
                if(letter==str[j]){
                    curr++;
                }
            }   
            if(most<curr){
                most=curr;
                best=letter;
            }
        }
    }
    cout<<"Most frequent letter: "<<best <<"( "<<most<<" times)"<<endl;
}

int main() {
    
    string str="";

    cout<<"Enter a sentence: ";
    getline(cin,str);
    
    cout<<"Sentence: "<<str<<endl;

    string titles=title(str);
    cout<<"Title: "<<titles<<endl;
    
    string rev=revSen(str);
    cout<<"Reverse: "<<rev<<endl;
    
    int palindrome=checkPalindrome(str);
    if (palindrome){
        cout<<"Palindrome: Yes"<<endl;
    }else{
        cout<<"Palindrome: No"<<endl;
    }

    frequency(str);
    
    
    return 0;
}
