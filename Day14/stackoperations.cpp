#include<iostream>
#include<stack>
#include<string>
using namespace std;


int perform(int operand1,int operand2,char operation)
{
    switch(operation)
    {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        default: 
        return 0;
    }
}

int evaluate(const string& expr)
{
    stack<int> stack;
    
    for(char c: expr)
    {
        if(isdigit(c)){
            stack.push(c - '0');
        }
        else{
            int operand2=stack.top();stack.pop();
            int operand1=stack.top();stack.pop();
            
            int result=perform(operand1,operand2,c);
            stack.push(result);
        }
    }
    return stack.top();
}


int main()
{
    string expression="73*4+";
    
    int result= evaluate(expression);
    
    cout<<"Result of postfix expression "<<expression<<" is "<<result;
    
    return 0;
}