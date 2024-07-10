#include <iostream>
using namespace std;

template <typename T>
class Vector{
    T* arr;
    int capacity;
    int size;
    
    public:
    Vector()
    {
        arr=new T[1];
        capacity=1;
        size=0;
    }
    ~Vector(){
        delete[] arr;
    }
    
    void push(T data)
    {
        if(size==capacity){
            T* temp=new T[2*capacity];
            for(int i=0;i<capacity;i++){
                temp[i]=arr[i];
            }
            
            delete[] arr;
            capacity=capacity*2;
            arr=temp;
        }
        arr[size]=data;
        size++;
    }
    
    void push(T data,int index)
    {
        if(index==size){
            push(data);
        }else{
        arr[index]=data;
        }
    }
    
    T get(int index)
    {
        if(index<size){
            return arr[index];
        }
        return -1;
    }
    
    void pop(){
        size--;
    }
    
    int sizev(){
        return size;
    }
    
    int getcapacity(){
        return capacity;
    }
    
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Vector<int> v;
    
    v.push(10);
    v.push(20);
    v.push(30);
    v.push(40);
    
    
    cout<<"Vector size "<<v.sizev()<<endl;
    cout<<"Vector capacity "<<v.getcapacity()<<endl;
    cout<<"Vector Elements "<<endl;
    v.print();
    
    v.push(50,4);
    cout<<"Vector Elements "<<endl;
    v.print();
    cout<<"Vector size "<<v.sizev()<<endl;
    
    cout<<"Element at 1 index "<<v.get(1)<<endl;
    
    cout<<"poping elemet"<<endl;
    v.pop();
    cout<<"Vector Elements "<<endl;
    v.print();
    cout<<"Vector size "<<v.sizev()<<endl;
    
    return 0;
    
}

