#include <iostream>
#include <list>
using namespace std;

int main() 
{
    list<int> mylist;
    
    mylist.push_back(10);
    mylist.push_back(20);
    mylist.push_back(30);
    
    mylist.push_front(5);
    mylist.push_front(1);
    
    cout<<"List after push back and push front: ";
    for(int val: mylist)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    
    auto it=mylist.begin();
    advance(it,2);
    mylist.insert(it,15);
    
    cout<<"List after insert: ";
    for(int val: mylist)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    
    it=mylist.begin();
    advance(it,3);
    mylist.erase(it);
    
    cout<<"List after erase: ";
    for(int val: mylist)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    
    mylist.remove(10);
    
    cout<<"List after remove: ";
    for(int val: mylist)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    
    mylist.remove_if([](int n){ return n < 10;});
    
    cout<<"List after remove_if: ";
    for(int val: mylist)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    
    mylist.sort();
    
    cout<<"List after sort: ";
    for(int val: mylist)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    
    mylist.reverse();
    
    cout<<"List after reverse: ";
    for(int val: mylist)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    
    list<int> otherlist= {40,50,60};
    mylist.merge(otherlist);
    
    cout<<"List after merge: ";
    for(int val: mylist)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    
    mylist.clear();
    cout<<"List after clear: ";
    for(int val: mylist)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    
    if(mylist.empty()){
        cout<<"List is empty."<<endl;
    }
    
    mylist.push_back(100);
    mylist.push_back(200);
    
    cout<<"Front element: "<<mylist.front()<<endl;
    cout<<"Back element: "<<mylist.back()<<endl;
    
    return 0;
}