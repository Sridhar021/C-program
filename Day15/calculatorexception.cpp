#include <iostream>
#include<stdexcept>
using namespace std;

class Calculator{
    public:
    double add(double x,double y)
    {
        return x+y;
    }
    double sub(double x,double y)
    {
        return x-y;
    }
    double mul(double x,double y)
    {
        return x*y;
    }
    double divide(double x,double y)
    {
        if(y==0){
            throw runtime_error("Attempted to divide by zero");
        }
        return x/y;
    }
};
int main()
{
    Calculator cal;
    double n1,n2,result;
    char ch;
    bool test=true;
    
    while(test){
        try{
            cout<<"Enter 1 value: ";
            cin>>n1;
            cout<<"Enter 2 value: ";
            cin>>n2;
            cout<<"Enter operation: ";
            cin>>ch;
            
            switch(ch){
                case '+':result=cal.add(n1,n2);
                break;
                case '-':result=cal.sub(n1,n2);
                break;
                case '*':result=cal.mul(n1,n2);
                break;
                case '/':result=cal.divide(n1,n2);
                break;
                default:
                throw invalid_argument("Invalid operator");
            }
            cout<<"result: "<<result<<endl;
        }catch(const runtime_error& e){
            cerr<<e.what()<<endl;
        }catch(const invalid_argument& e){
            cerr<<e.what()<<endl;
        }
        
        char cont;
        cout<<"Do you want to continue: "<<endl;
        cin>>cont;
        if(cont!='y' && cont!='Y'){
            test=false;
        }
    }

    return 0;
}