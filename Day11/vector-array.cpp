
#include <iostream>
#include<vector>
using namespace std;

void simple_example()
{
    const int n=10;
    vector<int> ivec(n);
    for(int i=0;i<10;++i){
        cin>>ivec[i];
    }
    int ia[n];
    for(int j=0;j<n;++j){
        ia[j]=ivec[j];
    }
    for(int k=0;k<10;++k){
        cout<<ia[k]<<"\t";
    }
    
}
int main()
{
   simple_example();
   
   

    return 0;
}