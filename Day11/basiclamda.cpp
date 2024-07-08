
#include<iostream>
using namespace std;

int main()
{
    auto sum=[](int a,int b){
        return a+b;
    };
    int result=sum(3,4);
    cout<<"The sum is "<<result<<endl;

    return 0;
}