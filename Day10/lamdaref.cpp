#include <iostream>
using namespace std;

void lamda_reference_capture(){
    
    int value=1;
    auto copy_value=[&value]{
        return value;
    
};

value=100;
auto stored_value=copy_value();

cout<<"Stored value = "<<stored_value<<endl;
}
int main()
{
    lamda_reference_capture();
    
    return 0;
}