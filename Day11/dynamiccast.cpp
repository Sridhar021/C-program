
#include <iostream>
#include<typeinfo>
using namespace std;


class Base{
    public:
    virtual void whoami(){
        cout<<"I am a Base class object\n";
    }
};
    
class Derived:public Base{
    public:
    void whoami() override{
        cout<<"I am a Derived class object \n";
    }
};
    
    
int main()
{
    Base* base_ptr= new Derived;
    Derived* derived_ptr= dynamic_cast<Derived*>(base_ptr);
    
    if(derived_ptr!=nullptr){
        derived_ptr->whoami();
    }
    else{
        cout<<"cast failed: base object is not derived ";
    }
    
    delete base_ptr;
    
    return 0;
}
