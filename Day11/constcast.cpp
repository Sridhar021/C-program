
#include <iostream>
using namespace std;

int main()
{
    const int value=10;
    
    int* writable_value=const_cast<int*>(&value);
    *writable_value=20;
    
    cout<<value<<endl;
    

    return 0;
}