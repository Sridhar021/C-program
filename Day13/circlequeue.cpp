
#include <iostream>
using namespace std;

class Cqueue{
    private:
    int* data;
    size_t capacity;
    int front;
    int rear;
    size_t size;
    
    public:
    Cqueue(size_t capacity):capacity(capacity),front(-1),rear(-1),size(0)
    {
        data=new int[capacity];
    }
    ~Cqueue(){
        delete[] data;
    }
    
    void enqueue(int value)
    {
        if(isfull())
        {
            cerr<<"Queue is full";
        }
        if(isempty())
        {
            front=rear=0;
        }
        else{
            rear=(rear + 1)% capacity;
        }
        data[rear]=value;
        ++size;
    }
    
    void dequeue(){
        if(isempty())
        {
            cerr<<"Queue is empty";
        }
        if(front==rear)
        {
            front=rear=-1;
        }
        else{
            front=(front + 1) % capacity;
        }
        --size;
    }
    
    int getfront() const {
        if(isempty())
        {
            cerr<<"Queue is empty ";
        }
        return data[front];
    }
    
    bool isempty() const{
        return size==0;
    }
    
    bool isfull() const{
        return size==capacity;
    }
    size_t getsize() const{
        return size;
    }
};
int main()
{
    Cqueue q(5);
    
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    
    cout<<"Front element: "<<q.getfront()<<endl;
    
    q.dequeue();
    cout<<"Front element: "<<q.getfront()<<endl;
    
    q.enqueue(6);
    cout<<"Front element: "<<q.getfront()<<endl;
    
    while(!q.isempty())
    {
        cout<<q.getfront()<<" ";
        q.dequeue();
    }
    cout<<endl;
    return 0;
}