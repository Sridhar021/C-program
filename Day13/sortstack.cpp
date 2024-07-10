#include <iostream>
#include <stack>

using namespace std;

void sortedinsert(stack<int>& s,int element)
{
    if(s.empty() || element>s.top())
    {
        s.push(element);
        return;
    }
    int topele=s.top();
    s.pop();
    sortedinsert(s,element);
    s.push(topele);
}

void sortstack(stack<int>& s)
{
    if(!s.empty())
    {
        int topele=s.top();
        s.pop();
        sortstack(s);
        sortedinsert(s,topele);
    }
}

void print(stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main()
{
    stack<int> s;
    
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(7);
    s.push(2);
    
    cout<<"Original Stack: ";
    print(s);
    
    sortstack(s);
    
    cout<<"Sorted Stack: ";
    print(s);
    return 0;
}

