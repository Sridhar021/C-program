
#include <iostream>
using namespace std;
int main()
{
    int num=21;
    int* ptr=&num;
    
    float* fptr=reinterpret_cast<float*>(ptr);
    
    cout<<"Value of num: "<<num<<endl;
    cout<<"Value of ptr: "<<*ptr<<endl;
    cout<<"Value of fptr: "<<*fptr<<endl;

    return 0;
}