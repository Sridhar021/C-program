/*
#include <iostream>
using namespace std;
int main()
{
    double d=21.563;
    int i= static_cast<int>(d);
    
    cout<<"The value of i after casting is "<<i;

    return 0;
}
*/

#include <iostream>
#include<limits>

using namespace std;
int main()
{
    double d=21.563;
    int i;
 if(d>=numeric_limits<int>::min() && d<=numeric_limits<int>::max()){
        i=static_cast<int>(d);
        cout<<"The value of i after casting is "<<i;
    }
    else{
        cerr<<"Error value out of range ";
    }
    
    return 0;
}