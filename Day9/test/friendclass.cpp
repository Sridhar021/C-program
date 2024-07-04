/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

class Beta;

class Alpha{
    private:
    int pdata;
    
    public:
    Alpha(int data):pdata(data){}
    
    friend class Beta;
    
    void displayalpha() const{
        cout<<"Alpha private data "<<pdata<<endl;
    }
};

class Beta{
    public:
    void modify(Alpha& alpha,int newdata){
        alpha.pdata=newdata;
    }
};
int main()
{
    Alpha aobj(10);
    Beta bobj;
    
    cout<<"Before modify "<<endl;
    aobj.displayalpha();
    
    bobj.modify(aobj,20);
    
    cout<<"After modify "<<endl;
    aobj.displayalpha();

    return 0;
}