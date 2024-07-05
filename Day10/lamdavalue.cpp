
#include <iostream>
using namespace std;

void lamda_value_capture(){
    
    int value=1;
    auto copy_value=[value]{
        return value;
    
};

value=100;
auto stored_value=copy_value();

cout<<"Stored value = "<<stored_value<<endl;
}
int main()
{
    lamda_value_capture();
    
    return 0;
}