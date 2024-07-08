
#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    int c;
    cout<<"Enter the temp in celsius "<<endl;
    cin>>c;
    
    double f=(c*9.0/5.0)+ 32;
    
    int roundf=static_cast<int>(round(f));
    
    cout<<"The temp. in farenheit is "<<roundf;

    return 0;
}