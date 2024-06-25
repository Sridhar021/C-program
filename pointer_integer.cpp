
#include <iostream> //header file

using namespace std;

void increment(int *ptr){       //increment function 
    if(ptr!=NULL){              //pointer not equal to null
        (*ptr)++;               //increment pointer
    }
}
int main()
{
    int num=21;
    
    cout<<"original value: "<<num<<endl;
    
    increment(&num);        //call increment with num address
    
    cout<<"Increment value: "<<num<<endl;
    
    return 0;
}