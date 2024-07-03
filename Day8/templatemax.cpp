#include <iostream>
using namespace std;

template <typename T>                    //template function to find maximum value in array
T findmax(T arr[],int n)
{
    T max=arr[0];                       //initialize max to first value of array
    
    for(int i=1;i<n;++i)                //loop to find maximum value
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    
    return max;
}
int main()
{
    int arri[]={3,4,5,6,7};                         //integer values
    
    double arrd[]={3.1,4.2,5.3,6.4,7.5};            //double values
    
    char arrch[]={'h','e','l','l','o'};             //char values
    
    int sizei=sizeof(arri)/sizeof(arri[0]);         //size of array
    int sized=sizeof(arrd)/sizeof(arrd[0]);
    int sizec=sizeof(arrch)/sizeof(arrch[0]);
    
    cout<<"Maximum in int array "<<findmax(arri,sizei)<<endl;
    cout<<"Maximum in double array "<<findmax(arrd,sized)<<endl;
    cout<<"Maximum in char array "<<findmax(arrch,sizec)<<endl;
    
    

    return 0;
}