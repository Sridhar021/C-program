
#include <iostream>
using namespace std;

int &staticVariable() {
    static int num = 10; // Static variable initialized to 10
    return num;
}

int main() {
                                    //reference to the static variable
    int &ref = staticVariable();

    cout<<"Initial value of static variable: " <<ref<<endl; //print initial value
    
    ref=20;   //modify static variable

    cout<<"Modified value of static variable: "<<staticVariable()<<endl;    //print modified value

    return 0;
}

