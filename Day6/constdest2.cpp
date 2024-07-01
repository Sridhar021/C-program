

#include <iostream>
using namespace std;

class Check{
    private:
    int data;
    public:
    
    Check(){
        data= 0;
        cout<<"Default Constructor Value: "<<data<<endl;
    }
    
    Check(int value){
        data=value;
        cout<<"Parameterized Constructor Value: "<<data<<endl;
    }
    
    Check(const Check& other){
        data=other.data;
        cout<<"Copy constructor Value: "<<data<<endl;
    }
    
    ~Check(){
        cout<<"Destructor called Value: "<<data<<endl;
    }
    
    
    void print(){
        cout<<"Value: "<<data<<endl;
    }
    
};
int main()
{
   Check c1;
   Check c2(30);
   Check c3=c2;
   c3.print();
    return 0;
}