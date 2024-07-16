#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string toLower(const string& str)
{
    string result=str;
    
    transform(result.begin(),result.end(),result.begin(),::tolower);
    return result;
}

void startstory();
void scene1();
void scene2();
void scene3();
void scene4();

void startstory()
{
    cout<<"Welcome to the interactive story";
    cout<<"\nYour choices will influence the story";
    scene1();
}

void scene1()
{
    cout<<"\nScene 1: You are standind at the starting point.\n";
    cout<<"Do you go left or right ? (Enter 'left' or 'right')\n";
    string ch;
    cin>>ch;
    ch=toLower(ch);
    
    if(ch=="left"){
        scene2();
    }else if(ch=="right"){
        scene3();
    }else{
        cout<<"Invalid choice. Try again ";
        scene1();
    }
}

void scene2()
{
    cout<<"\nScene 2: You encounter a swamp.\n";
    cout<<"Do you swim across or build a raft ? (Enter 'swim' or 'raft')\n";
    string ch;
    cin>>ch;
    ch=toLower(ch);
    
    if(ch=="swim"){
        cout<<"\nYou try to swim but there are crocodiles in the swamp and you died.";
        cout<<"\nGAME OVER!\n";
    }else if(ch=="raft"){
        cout<<"\nYou build a raft and safely cross the swamp \n";
        cout<<"Congratulations! YOU WIN ";
    }else{
        cout<<"Invalid choice. Try again ";
        scene2();
    }
}

void scene3()
{
    cout<<"\nScene 3: You encounter a cave.\n";
    cout<<"Do you enter or leave it ? (Enter 'enter' or 'leave')\n";
    string ch;
    cin>>ch;
    ch=toLower(ch);
    
    if(ch=="enter"){
        cout<<"\nYou go inside the cave.";
        scene4();
    }else if(ch=="leave"){
        cout<<"\nYou leave the cave and move forward";
        cout<<"\nYou continue on your journey but always wonder what was in the cave \n";
        cout<<"GAME OVER ";
    }else{
        cout<<"Invalid choice. Try again ";
        scene3();
    }
}

void scene4()
{
    cout<<"\nScene 4: You encounter a monster in the cave.\n";
    cout<<"Do you fight  or run from it ? (Enter 'fight' or 'run')\n";
    string ch;
    cin>>ch;
    ch=toLower(ch);
    
    if(ch=="fight"){
        cout<<"\nYou fought the monster and killed the monster with great difficulty.";
        cout<<"\nCongratulations! YOU WIN";
    }else if(ch=="run"){
        cout<<"\nYou run from the monster but the monster catch upto you and kill you.\n";
        cout<<"GAME OVER ";
    }else{
        cout<<"Invalid choice. Try again ";
        scene4();
    }
}
int main()
{
    startstory();
    return 0;
}