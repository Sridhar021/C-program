
#include <iostream>
#include<string>
using namespace std;
int main()
{
    string str="Program";
    
    auto addprefix=[&str](){
        string prefix="Cpp ";
        str=prefix+str;
        return str;
    };
    
    string result=addprefix();
    
    cout<<"Modified string is "<<result;

    return 0;
}