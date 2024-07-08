
#include <iostream>
using namespace std;

int main()
{
    int x=5;
    auto square=[x](){
        return x*x;
    };
    int result=square();
    cout<<"The square is "<<result<<endl;

    return 0;
}