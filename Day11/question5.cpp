
#include <iostream>
using namespace std;
int main()
{
    int num=21;
    float fval=3.14;
    
    int* iptr=&num;
    float* fptr=&fval;
    
    float* cptr=reinterpret_cast<float*>(iptr);
    
    cout<<"Value of num: "<<num<<endl;
    cout<<"Value of fval: "<<num<<endl;
    cout<<"Value of iptr: "<<*iptr<<endl;
    cout<<"Value of fptr: "<<*fptr<<endl;
    cout<<"Value of cptr: "<<*cptr<<endl;

    return 0;
}