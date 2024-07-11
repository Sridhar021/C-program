
#include <iostream>
#include<string>
#include<queue>
using namespace std;

void display(queue<string> q)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
int main()
{
    queue <string> bill;
    int cserevd=0;
    
    bill.push("Customer1");
    bill.push("Customer2");
    bill.push("Customer3");
    bill.push("Customer4");
    
    cout<<"Queue after adding customers: ";
    display(bill);
    
    if(!bill.empty())
    {
        bill.pop();
        cserevd++;
    }
    
    cout<<"After serving a customer: ";
    display(bill);
    
    if(!bill.empty())
    {
        bill.pop();
        cserevd++;
    }
    
    cout<<"After serving another customer: ";
    display(bill);
    
    cout<<"No. of customer served is "<<cserevd<<endl;
    
    return 0;
}