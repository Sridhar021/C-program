

#include <iostream>
using namespace std;

class Mathutil{
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
        if(b==0){
            throw invalid_argument("Error division by zero");
        }
        return static_cast<double>(a)/b;
    }
};
int main()
{
    double n1,n2;
    char operation;
    cout<<"Enter the values "<<endl;
    cin>>n1>>n2;
    cout<<"Operation to be performed ( +, -, *, /)"<<endl;
    cin>>operation;
    try{
        switch(operation){
            case '+':
            cout<<"Addition = "<<Mathutil::add(n1,n2);
            break;
            case '-':
            cout<<"Subtraction = "<<Mathutil::sub(n1,n2);
            break;
            case '*':
            cout<<"Multiplication = "<<Mathutil::mul(n1,n2);
            break;
            case '/':
            cout<<"Division = "<<Mathutil::div(n1,n2);
            break;
            default:
            cout<<"Invalid option";
            break;
        }
    }
    catch(const invalid_argument& e){
        cerr<<e.what();
    }

    return 0;
}