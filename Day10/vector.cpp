
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

void assign(int& v)
{
    static int n=1; v=n++;
}

void print(int v)
{
    cout<<v<<" ";
}

int main()
{
    vector<int>vec(10);
    
    for_each(vec.begin(),vec.end(),print);
    cout<<endl;
    
    for_each(vec.begin(),vec.end(),assign);
    
    for_each(vec.begin(),vec.end(),print);
    
    return 0;
}