#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

char getUserChoice();
char getCompChoice();
void showChoice(char choice);
void winner(char player,char computer);


int main() {
    srand(time(NULL));
    char player;
    char computer;
    while(true){
        player=getUserChoice();
        if(player=='0'){
            exit(0);
        }
        cout<<"Your choice: ";
        showChoice(player);
        computer=getCompChoice();
        cout<<"Computer choice: ";
        showChoice(computer);
        winner(player,computer);
    }
    return 0;
}
char getUserChoice(){
        char choice;
    do{
        cout<<"*******************"<<endl;
        cout<<"ROCK-PAPER-SCISSORS GAME"<<endl;
        cout<<"*******************"<<endl;
        cout<<"r for ROCK"<<endl;
        cout<<"p for PAPER"<<endl;
        cout<<"s for SCISSORS"<<endl;
        cout<<"To exit enter '0'"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
    }while(choice!='r' && choice!='p' && choice!='s' && choice!='0');

    return choice;
}
char getCompChoice(){
    
    int num=((rand()%3)+1);
    char choice;
    if(num==1){
        choice='r';
    } else if(num==2){
        choice='p';
    }else{
        choice='s';
    }

    return choice;
}
void showChoice(char choice){
    switch  (choice){
        case 'r': cout<<"Rock\n";
                break;
        case 'p':cout<<"Paper\n";
                break;
        case 's':cout<<"Scissors\n";
                break;
        default: break;
    }
}
void winner(char player,char computer){
    if(player==computer){
        cout<<"Match tied!!!\n";
    }else if(player=='r' && computer=='s'){
        cout<<"You wins!!\n";
    }else if(player=='s' && computer=='p'){
        cout<<"You wins!!\n";
    }else if(player=='p' && computer=='r'){
        cout<<"You wins!!\n";
    }else{
        cout<<"Computer wins!!\n";
    }
}
