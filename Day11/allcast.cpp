
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
    double num=3.14159;
    int integer_part=static_cast<int>(num);
    cout<<"Original value "<<num<<endl;
    cout<<"Integer part "<<integer_part<<endl;
    
    Base* base_ptr;
    Derived* derived_ptr=static_cast<Derived*>(base_ptr);
    
    if(dynamic_cast<Derived*>(base_ptr)!=nullptr)
    {
        derived_ptr=static_cast<Derived*>(base_ptr);
        derived_ptr->whoami();
    }
    else{
        cout<<"Warning Base object might not be of type derived "<<endl;
    }
    
    Base* actual_derived_ptr= new Derived;
     derived_ptr= dynamic_cast<Derived*>(actual_derived_ptr);
    
    if(derived_ptr!=nullptr){
        derived_ptr->whoami();
    }
    else{
        cout<<"cast failed: base object is not derived ";
    }
    
    delete actual_derived_ptr;
    
    int value=10;
    float* float_ptr= reinterpret_cast<float*>(&value);
    cout<<*float_ptr<<endl;
    
    return 0;
}
