#include <iostream>
using namespace std;

void swap(int &a,int &b) {      //function swap
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int num1 = 5;       //initialize the values
    int num2 = 10;

    cout<<"Before swapping:"<<endl;
    cout<<"num1 = "<<num1<<", num2 = "<<num2<<endl;

    // Call the swap function
    swap(num1,num2);

    
    cout<< "After swapping:" <<endl;
    cout<<"num1 = "<<num1<<", num2 = "<<num2<<endl;

    return 0;
}

