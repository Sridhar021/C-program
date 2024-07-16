#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<functional>

using namespace std;


string toLower(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}


typedef function<void()> Scene;


void startStory();
void scene1();
void scene2();
void scene3();
void gameOver();
void youWin();


map<string, Scene> scenes;

void startStory() {
    cout<<"Welcome to the interactive story!";
    cout<<"\nYour choices will influence the story.";
    scene1();
}

void scene1() {
    cout<<"\n\nScene 1: You are standing at a crossroads.\n";
    cout<<"Do you go left or right? (Enter 'left' or 'right')\n";
    string choice;
    cin>>choice;
    choice=toLower(choice);

    if(scenes.find(choice) != scenes.end()) {
        scenes[choice]();
    }else{
        cout<<"Invalid choice. Try again.";
        scene1();
    }
}

void scene2() {
    cout<<"\n\nScene 2: You encounter a river.\n";
    cout<<"Do you swim across or build a raft? (Enter 'swim' or 'raft')\n";
    string choice;
    cin>>choice;
    choice=toLower(choice);

    if(choice == "swim") {
        cout<<"\nYou try to swim but the current is too strong and you drown.";
        gameOver();
    } else if(choice == "raft") {
        cout<<"\nYou build a raft and safely cross the river.";
        youWin();
    } else{
        cout<<"Invalid choice. Try again.";
        scene2();
    }
}

void scene3() {
    cout<<"\n\nScene 3: You find a treasure chest.\n";
    cout<<"Do you open it or leave it? (Enter 'open' or 'leave')\n";
    string choice;
    cin>>choice;
    choice=toLower(choice);

    if(choice == "open") {
        cout<<"\nThe chest contains a pile of gold! You are rich!";
        youWin();
    } else if(choice == "leave") {
        cout<<"\nYou decide to leave the chest alone and walk away.";
        gameOver();
    } else{
        cout<<"Invalid choice. Try again.";
        scene3();
    }
}

void gameOver() {
    cout<<"\nGAME OVER!\n";
    
}

void youWin() {
    cout<<"\nCongratulations! YOU WIN!\n";
    
}

int main() {
    
    scenes["left"]= scene2;
    scenes["right"]= scene3;

    
    startStory();
    return 0;
}
