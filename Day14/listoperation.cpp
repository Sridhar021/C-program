#include <iostream>
#include <list>
#include<algorithm>
using namespace std;

void display(const list<int>& ele)
{
    for(int num: ele){
        cout<<num<<" ";
    }
    cout<<endl;
}

int main()
{
    list<int> ml;
    
    ml.push_front(10);
    ml.push_front(20);
    ml.push_back(30);
    ml.push_back(40);
    
    cout<<"List after inserting: ";
    display(ml);
    
    ml.pop_front();
    ml.pop_back();
    
    cout<<"List after removing: ";
    display(ml);
    
    ml.sort();
    cout<<"List in ascending order: ";
    display(ml);
    
    ml.sort(greater<int>());
    cout<<"List in descending order: ";
    display(ml);
    
    ml.reverse();
    cout<<"List in reverse: ";
    display(ml);
    
    return 0;
}