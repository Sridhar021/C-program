
#include <iostream>
using namespace std;
int main()
{
    int a=21;
    bool flag=true;
    
    auto conditional=[a,flag](){
        if(flag){
            return a*10;
        }
        else{
            return a%10;
        }
    };
    
    int result=conditional();
    
    cout<<"Result of conditional operation is "<<result<<endl;

    return 0;
}