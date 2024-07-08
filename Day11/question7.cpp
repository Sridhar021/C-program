#include <iostream>
using namespace std;

int main() {
    int x = 42;
    float f = 3.14;
    int& refX = x;

    
     float& refF = reinterpret_cast<float&>(refX);  // This will cause a compilation error

    cout<<"Value of x: "<<x<<endl;
    cout<<"Value of f: " << f <<endl;
    cout<<"Value of refX: "<<refX<<endl;
    cout <<"Value of refF: "<<refF<<endl;

    return 0;
}
