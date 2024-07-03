#include <iostream>
using namespace std;

template <typename T>           //template function swap
void mswap(T* a,T* b)           //take pointers as parameters
{
    T temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{
    int a=10,b=20;                  //integer values
    double c=10.5,d=20.5;           //double values
    
    cout<<"Before Swap: "<<a<<" "<<b<<endl;
    cout<<"Before Swap: "<<c<<" "<<d<<endl;
   
    mswap(&a,&b);               //call swap function for integer type
    mswap(&c,&d);               //call swap function for double type
   
    cout<<"After Swap: "<<a<<" "<<b<<endl;
    cout<<"After Swap: "<<c<<" "<<d<<endl;
    
    
    return 0;
}