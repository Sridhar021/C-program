

#include <iostream>
#include<queue> 
using namespace std;
int main()
{
    queue<int> myqueue;
    myqueue.push(0);
    myqueue.push(1);
    myqueue.push(2);
    
    while(!myqueue.empty())
    {
        cout<<' '<<myqueue.front();
        myqueue.pop();
    }
    

    return 0;
}