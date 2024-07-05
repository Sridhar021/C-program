
#include <iostream>
using namespace std;

int multiply(int a,int b);

int main()
{
    cout<<multiply(4,5)<<endl;
    
    
    cout<<[](int a,int b){return a*b;} (4,5)<<endl;
    
    auto f=[](int a,int b){return a*b; };
    cout<<f(4,5)<<endl;

    
}
int multiply(int a,int b){
    return a*b;
}