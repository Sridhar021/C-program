

#include <iostream>
using namespace std;

template <typename T>           //template function to find minimum value in array
T findmin(T arr[],int n)
{
    T min=arr[0];               //initialize min to first value of array
    
    for(int i=1;i<n;++i)
    {                           //loop to find minimum value
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    
    return min;
}
int main()
{
    int arri[]={3,4,5,6,7};     //integer values
    
    double arrd[]={3.1,4.2,5.3,6.4,7.5};        //double values
    
    char arrch[]={'h','e','l','l','o'};         //char values
    
    int sizei=sizeof(arri)/sizeof(arri[0]);     //size of array
    int sized=sizeof(arrd)/sizeof(arrd[0]);
    int sizec=sizeof(arrch)/sizeof(arrch[0]);
    
    cout<<"Minimum in int array "<<findmin(arri,sizei)<<endl;
    cout<<"Minimum in double array "<<findmin(arrd,sized)<<endl;
     cout<<"Minimum in char array "<<findmin(arrch,sizec)<<endl;
    
    

    return 0;
}