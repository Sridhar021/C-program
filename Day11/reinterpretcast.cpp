
#include <iostream>
using namespace std;
int main()
{
    int value=10;
    float* float_ptr= reinterpret_cast<float*>(&value);
    
    cout<<*float_ptr<<endl;

    return 0;
}