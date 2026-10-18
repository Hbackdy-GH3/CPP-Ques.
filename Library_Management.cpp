#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;
int next_id=1;
int next_mem_id=1;

class Item{
protected:
    int id;
    string title;
    bool isIssued;
public:
    Item(string name){
        id=next_id++;
        title=name;
        isIssued=false;
    }
    virtual void display() const=0;
    virtual int lateFeePerDay() const=0;
    int getid() const{
        return id;
    }
    string gettitle() const{
        return title;
    }
    bool getisIssued(){
        return isIssued;
    }
    void setIssued(bool value){
        isIssued=value;
    }
    virtual ~Item(){}
    
};

class Book:public Item{
public:
    string Author;
    int Pages;
    int LateFeePerDay;
    Book(string name, string author, int pages): Item(name){
        Author=author;
        Pages=pages;
        LateFeePerDay=lateFeePerDay();
    }
    int lateFeePerDay() const override{
        return 2;
    }
    void display() const override{
        cout<<"=========="<<"\n";
        cout<<"id: "<<id<<"\n";
        cout<<"title: "<<title<<"\n";
        cout<<"Author: "<<Author<<"\n";
        cout<<"Pages: "<<Pages<<"\n";
        if(isIssued){
            cout<<"issued: Yes\n";
        }else{
            cout<<"issued: No\n";
        }
        cout<<"=========="<<"\n";
    }
};
class Magazine:public Item{
public:
    string IssueNumber;
    int LateFeePerDay;
    Magazine(string name, string issueNumber): Item(name){
        IssueNumber=issueNumber;
        LateFeePerDay=lateFeePerDay();
    }
    int lateFeePerDay() const override{
        return 1;
    }
    void display() const override{
        cout<<"=========="<<"\n";
        cout<<"id: "<<id<<"\n";
        cout<<"title: "<<title<<"\n";
        cout<<"IssueNumber: "<<IssueNumber<<"\n";
        if(isIssued){
            cout<<"issued: Yes\n";
        }else{
            cout<<"issued: No\n";
        }
        cout<<"=========="<<"\n";
    }
};

class Member{
private:
    string Name;
    string memID;
    vector<int>issuedID;
    
public:
    Member(string name){
        Name=name;
        memID="JMI/" + name.substr(0, name.length() / 2) +"/"+to_string(next_mem_id++);
        transform(memID.begin(), memID.end(), memID.begin(), ::toupper);
    }
    string getName(){
        return Name;
    }
    string getmemID(){
        return memID;
    }
    bool canIssue(){
        if(issuedID.size()<3) return true;
        return false;
    }
    void additems(int id){
        issuedID.push_back(id);
    }
    bool hasitem(int id)const{
        auto it=find(issuedID.begin(),issuedID.end(),id);
            if(it!=issuedID.end()){
                return true;
            }
        return false;
    }
    void remove(int id){
        auto it=find(issuedID.begin(),issuedID.end(),id);
            if(it!=issuedID.end()){
                issuedID.erase(it);
            }
    }
    friend ostream& operator<<(ostream& COUT, const Member& member);
};
ostream& operator<<(ostream& COUT, const Member& member){
    COUT<<"ALL ISSUED LIST OF BOOKS\n";
    for(int v:member.issuedID){
        COUT<<v<<" ";
    }
    return COUT;
}

class Library{
private:
    vector<Item*>items;
    vector<Member>members;
    Item* findItem(int id){
        for(Item* v : items){
            if(id==v->getid()){
                return v;
            }
        }
        return nullptr;
    }
    Member* findmem(string memid){
        for(Member& m:members){
            if(memid==m.getmemID()){
                return &m;
            }
        }
        return nullptr;
    }
public:
    Library(){}
    Library(const Library&)=delete;
    Library& operator=(const Library&)=delete;
    void additems(Item* b){
        items.push_back(b);
        cout<<"Item added succcesfully!!!\n";
    }
    void addmem(Member* m){
        string tempId=m->getmemID();
        if(findmem(tempId)==nullptr){
            members.push_back(*m);
            cout<<"Member added successfully!!!\n";
        }else{
            cout<<"Member already exists!!!\n";
        }
    }
    void issue(string memberId, int itemId){
        Item* item=findItem(itemId);
        Member* member=findmem(memberId);
        if(member!=nullptr && item!=nullptr && !item->getisIssued()){
            if(member->canIssue()){
                member->additems(itemId);
                item->setIssued(true);
                cout<<"Issued "<<item->gettitle()<<" to "<<member->getName()<<'\n';
            }else{
                cout<<"Sorry you have already lend 3 books\n";
            }
        }else if(item==nullptr){
            cout<<"Sorry this item is not available\n";
        }else if(member==nullptr){
            cout<<"This member doesn't exists\n";
        }else{
            cout<<"This item is already on lend\n";
        }
    }
    void returnItem(string memberId, int itemId, int daysLate){
        Item* item=findItem(itemId);
        Member* member=findmem(memberId);
        if(member==nullptr){
            cout<<"Invalid member id\n";
            return;
        }else if(item==nullptr){
            cout<<"Invalid item id\n";
            return;
        }else if(!member->hasitem(itemId)){
            cout<<member->getName()<<" doesn't have \""<<item->gettitle()<<"\"\n";
            return;
        }
        item->setIssued(false);
        member->remove(itemId);
        int fine=(item->lateFeePerDay())*(daysLate);
        cout<<"Returned \""<<item->gettitle()<<"\" by "<<member->getName()<<"\n";
if(fine>0){
    cout<<"Late fee: Rs "<<fine<<"\n";
} else{
    cout<<"Returned on time, no fee\n";
}
    }
    ~Library(){
        for(Item* v:items){
            delete v;
        }
    }
    void showAll() const{
        for(Item* v:items){
            v->display();
        }
    }
};

int main(){
    Library lib;

    lib.additems(new Book("Clean Code", "Robert Martin", 450));
    lib.additems(new Book("C++ Primer", "Lippman", 900));
    lib.additems(new Magazine("Tech Today", "42"));
    lib.additems(new Magazine("Science Weekly", "7"));

    Member m1("Raj");
    Member m2("Amy");
    cout<<"Raj id: "<<m1.getmemID()<<"\n";
    cout<<"Amy id: "<<m2.getmemID()<<"\n";

    lib.addmem(&m1);
    lib.addmem(&m2);
    lib.addmem(&m1);

    cout<<"\n--- All items ---\n";
    lib.showAll();

    cout<<"\n--- Issue ---\n";
    lib.issue(m1.getmemID(), 1);
    lib.issue(m2.getmemID(), 1);
    lib.issue(m1.getmemID(), 2);
    lib.issue(m1.getmemID(), 3);
    lib.issue(m1.getmemID(), 4);
    lib.issue("JMI/XYZ/99", 4);
    lib.issue(m2.getmemID(), 99);

    cout<<"\n--- Return ---\n";
    lib.returnItem(m1.getmemID(), 1, 5);
    lib.returnItem(m1.getmemID(), 3, 3);
    lib.returnItem(m2.getmemID(), 2, 0);
    lib.returnItem(m1.getmemID(), 2, 0);

    cout<<"\n--- All items after ---\n";
    lib.showAll();

    return 0;
}
