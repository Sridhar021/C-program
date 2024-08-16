#include<iostream>
#include<stdexcept>
#include<string>

template<typename T>
class Stack {
    private:
    T* data;
    size_t size;
    size_t capacity;
    
    void resize(size_t newCapacity) {
        T* newData = new T[newCapacity];
        for(size_t i =0; i<size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
    
    public:
    Stack(size_t initialCapacity = 4):size(0), capacity(initialCapacity) {
        data = new T[capacity];
    }
    
    ~Stack() {
        delete[] data;
    }
    
    void push(const T& value) {
        if(size==capacity) {
            resize(capacity*2);
        }
        data[size++] = value;
    }
    
    void pop() {
        if(size==0) {
            throw std::out_of_range("Stack Underflow");
        }
        --size;
    }
    
    T& peek() {
        if(size==0) {
            throw std::out_of_range("Stack is empty");
        }
        return data[size - 1];
        
    }
    
    bool isEmpty() const {
        return size==0;
    }
    
    size_t getSize() const {
        return size;
    }
};

int main() {
    Stack<int> iStack;
    iStack.push(10);
    iStack.push(20);
    std::cout<<"Int stack top : "<<iStack.peek()<<std::endl;
    iStack.pop();
    std::cout<<"Int stack top : "<<iStack.peek()<<std::endl;
    
    Stack<float> fStack;
    fStack.push(10.5);
    fStack.push(20.5);
    std::cout<<"Float stack top : "<<fStack.peek()<<std::endl;
    fStack.pop();
    std::cout<<"Float stack top : "<<fStack.peek()<<std::endl;
    
    Stack<std::string> sStack;
    sStack.push("Hello");
    sStack.push("World");
    std::cout<<"String stack top : "<<sStack.peek()<<std::endl;
    sStack.pop();
    std::cout<<"String stack top : "<<sStack.peek()<<std::endl;
}
