

#include <iostream>
using namespace std;

class Math{
    public:
    static int add(int a,int b){
        return a+b;
    }
    static int sub(int a,int b){
        return a-b;
    }
    static int mul(int a,int b){
        return a*b;
    }
    static double div(int a,int b){
        if(b!=0){
            return static_cast<double> (a)/b;
        }else{
            cerr<<"Not divisable by zero";
            return 0.0;
        }
    }
};
int main()
{
    int a=15,b=10;
    
    cout<<"Addition: "<<Math::add(a,b)<<endl;
    cout<<"Subtraction: "<<Math::sub(a,b)<<endl;
    cout<<"Multiplication: "<<Math::mul(a,b)<<endl;
    cout<<"Division: "<<Math::div(a,b);
    return 0;
}