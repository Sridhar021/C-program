/*
#include <iostream>
using namespace std;
int main()
{
    int x=256;
    char y=static_cast<char>(x);
    
    cout<<"the value of y is "<<static_cast<int>(y);

    return 0;
}
*/

#include<iostream>
#include<limits>
using namespace std;

int main()
{
    int x=256;
    char y;
    
    if(x>=numeric_limits<char>::min() && x<=numeric_limits<char>::max()){
        y=static_cast<char>(x);
    }
    else{
        cerr<<"Error value out of range ";
        return 1;
    }
    
    cout<<"The value of y is "<<static_cast<int>(y);
    return 0;
}