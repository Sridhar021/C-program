
#include <iostream>
#include<stack>
using namespace std;

class Max{
    private:
    stack<int> mstack;
    stack<int> maxstack;
    
    public:
    void push(int x){
        mstack.push(x);
        if(maxstack.empty() || x>=maxstack.top())
        {
            maxstack.push(x);
        }
    }
    void pop(){
        if(mstack.empty())
        {
            cerr<<"Stack is empty";
        }
        if(mstack.top()==maxstack.top()){
            maxstack.pop();
        }
        mstack.pop();
    }
    
    int top(){
        if(mstack.empty())
        {
            cerr<<"Stack is empty";
        }
        return mstack.top();
    }
    
    int getmax(){
        if(maxstack.empty())
        {
            cerr<<"Stack is empty ";
        }
        return maxstack.top();
    }
};
int main()
{
    Max s;
    s.push(3);
    s.push(4);
    cout<<"Max= "<<s.getmax()<<endl;
    
    s.push(5);
    s.push(6);
    cout<<"Max= "<<s.getmax()<<endl;
    
    s.pop();
    cout<<"Max= "<<s.getmax()<<endl;

    return 0;
}