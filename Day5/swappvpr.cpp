/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

void Swap(int a,int b){
    int temp=a;
    a=b;
    b=temp;
}
void Swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
int main()
{
    int a=10;
    int b=20;
    cout<<"Before Swap: "<<a<<b;
    Swap(a,b);
    Cout<<"After swap: "<<a<<b;
    cout<<a<<b;

    return 0;
}