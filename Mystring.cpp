#include <iostream>
#include <cstring>

using namespace std;

class Mystring{
public:
    char* text;
    int length;
    Mystring(){
        text= new char[1];
        text[0]='\0';
        length=1;
    }
    Mystring(const char* s){
        length=strlen(s)+1;
        text=new char[length];
        strcpy(text,s);
    }

    Mystring(const Mystring& other){
        length=other.length;
        text=new char[length];
        strcpy(text,other.text);
    }
    Mystring& operator=(const Mystring& other){
        if(text==other.text){
            cout<<"Assigning self!!!"<<"\n";
            return *this;
        }
        delete[] text;
        length=other.length;
        text=new char[length];
        strcpy(text,other.text);

        return *this;
    }

    int len(){
        return (length-1);
    }

    void append(const Mystring& other){
        int len=length+other.length;
        char* temp=new char[len];
        strcpy(temp,text);
        strcat(temp," ");
        delete[] text;
        strcat(temp,other.text);
        text=temp;
        length=len;
    }
    void append(const char* other){
        int len=length+strlen(other)+1;
        char* temp=new char[len];
        strcpy(temp,text);
        strcat(temp," ");
        delete[] text;
        strcat(temp,other);
        text=temp;
        length=len;
    }
    Mystring& upper(){
        for(int i=0;i<length;i++){
            text[i]=toupper(text[i]);
        }
        return *this;
    }

    
    ~Mystring(){
        cout<<"DESTROYING!!!->"<<text<<"\n";
        delete[] text;
    }
    friend ostream& operator<<(ostream& COUT,const Mystring& other);
    
};

ostream& operator<<(ostream& COUT,const Mystring& other){
        COUT<<other.text;

        return COUT;
    }


int main() {

    Mystring s1("hello");
    Mystring s2=s1;
    // cout<<s2.upper()<<"\n";
    Mystring s3("World");
    s3=s1;
    s1=s1;
    Mystring s4("World");
    s1.append("world");
    cout<<s1.text<<"\n";
    cout<<s2.text<<"\n";
    cout<<s3.text<<"\n";
    cout<<s4.text<<"\n";
    s3.append(s4);
    cout<<s3.text<<"\n";
    // cout<<s1.len()<<"\n";
    // cout<<s2.len()<<"\n";
    // cout<<s3.text<<"\n";
    // cout<<s3.len()<<"\n";
    // s3.append(s1);
    // cout<<s3.len()<<"\n";
    
    
    return 0;
}
