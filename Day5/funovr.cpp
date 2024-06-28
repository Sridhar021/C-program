/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

class Animal{
    public:
    void eat(){
        cout<<"Eating...";
        
    }
};
class Dog:public Animal{
    public:void eat(){
        cout<<"Eating bread...";
        
    }
};
int main()
{
    Dog d=Dog();
    d.eat();

    return 0;
}