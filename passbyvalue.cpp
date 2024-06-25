
#include <iostream>
using namespace std;


void addTen(int num) {              //addten function
    num += 10;
    cout<<"Inside function: num = " <<num<<endl;
}

int main() {
    int value = 5;          //initialize value to 5

    
    cout<<"Original value before calling addTen: "<<value<<endl;

    addTen(value);          //call function addTen

    cout<<"Original value after calling addTen: " <<value<<endl;

    return 0;
}

