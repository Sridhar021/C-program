#include <iostream>
using namespace std;
int main() 
{
    int x = 42;
    int& refx = x;

    float& refF = reinterpret_cast<float&>(refx);

    cout<<"Value of x: "<<x<<endl;
    cout<<"Value of refX: "<<refx<<endl;
    cout<<"Value of refF: "<<refF<<endl;

    return 0;
}