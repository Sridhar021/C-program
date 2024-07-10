
#include <bits/stdc++.h>
using namespace std;

void print(queue<int>& Queue)
{
    while(!Queue.empty())
    {
        cout<<Queue.front()<<" ";
        Queue.pop();
    }
}
void reverse(queue<int>& Queue)
{
    stack<int> Stack;
    while(!Queue.empty())
    {
        Stack.push(Queue.front());
        Queue.pop();
    }
    while(!Stack.empty())
    {
        Queue.push(Stack.top());
        Stack.pop();
    }
}


int main()
{
    queue<int> Queue;
     Queue.push(10);
     Queue.push(20);
     Queue.push(30);
     Queue.push(40);
     Queue.push(50);
    
    reverse(Queue);
    print(Queue);

    return 0;
}