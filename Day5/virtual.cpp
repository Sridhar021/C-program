/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
class A{
    int x=5;
    public:
    virtual void display(){
        cout<<"Value of x is "<<x<<endl;
    }
};
class B:public A{
    int y=10;
    public:
    void display(){
        cout<<"Value of y is "<<y<<endl;
    }
};
int main()
{
  A *a;
  B b;
  a=&b;
  a->display();

    return 0;
}