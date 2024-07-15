#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

class LargeObject{
    private:
    size_t size;
    int* data;
    
    public:
    
    LargeObject(size_t size): size(size),data(new int[size])        
    {
        cout<<"Constructing large object of size "<<size<<endl;
    }
    
    LargeObject(const LargeObject& other):                          //copy constructor
    size(other.size), data(new int[other.size]){
        copy(other.data,other.data+other.size,data);
        cout<<"Copy Constructing LargeObject of size "<<size<<endl;
    }
    
    LargeObject(LargeObject&& other) noexcept:                      //move constructor
    size(other.size),data(other.data){
        other.size=0;
        other.data=nullptr;
        cout<<"Moving constructing LargeObject of size "<<size<<endl;
    }
    
    LargeObject& operator=(const LargeObject& other)                //copy assignment operator
    {
        if(this== &other){
        return *this;
        }
        delete[] data;
        size=other.size;
        data=new int[size];
        copy(other.data,other.data+size,data);
        cout<<"Copy assigning LargeObject of size "<<size<<endl;
        return *this;
    }
    
    LargeObject& operator=(LargeObject&& other) noexcept            //move assignment operator
    {
        if(this== &other){
        return *this;
        }
        delete[] data;
        size=other.size;
        data=other.data;
        other.size = 0;
        other.data = nullptr;
        
        cout<<"Move assigning LargeObject of size "<<size<<endl;
        return *this;
    }
    
    ~LargeObject(){                                                 //destructor
        delete[] data;
        cout<<"Destructing LargeObject of size "<<size<<endl;
    }
    
    size_t getSize() const {
        return size;
    }
};

class Container{
    private:
    vector<LargeObject> objects;
    
    public:
    
    void add(LargeObject&& obj){                    //add a LargeObject to container
        objects.push_back(move(obj));
    }
    
    void processObjects(const function<void(LargeObject&)>& func)       // process all objects in the container using a lambda
    {
        for(auto& obj: objects){
            func(obj);
        }
    }
    
    void iterate(const function<void(const LargeObject&)>& func) const{         //custom iterator using lamda
        for_each(objects.begin(),objects.end(),func);
    }
};
int main()
{
    Container c;
    c.add(LargeObject(1000000));            //add a LargeObject to container
    c.add(LargeObject(2000000));
    
    c.processObjects([](LargeObject& obj)       // process objects using a lambda
    {
        cout<<"Processing Object of size "<<obj.getSize()<<endl;
    });
    
    c.iterate([](const LargeObject& obj){           //custom iterator using lamda
        cout<<"iterating over object of size "<<obj.getSize()<<endl;
    });

    return 0;
}