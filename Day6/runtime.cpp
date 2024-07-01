

#include <iostream>
using namespace std;

class Animal{
    public:
    virtual void speak() const =0;
};


class Lion:public Animal{
    public:
    void speak() const override {
        cout<<"Lion: Roar"<<endl;
    }
};
class Elephant:public Animal{
    public:
    void speak()const override {
        cout<<"Elephant: Trumpet"<<endl;
    }
};

class Dog:public Animal{
    public:
    void speak()const override {
        cout<<"Dog: Woof"<<endl;
    }
};
class Cat:public Animal{
    public:
    void speak()const override {
        cout<<"Cat: Meow"<<endl;
    }
};

int main()
{
    Animal* zoo[4];
    
    zoo[0]=new Lion();
    zoo[1]=new Elephant();
    zoo[2]=new Dog();
    zoo[3]=new Cat();
    
    for(int i=0;i<4;++i){
        zoo[i]->speak();
    }
    
    for(int i=0;i<4;++i){
        delete zoo[i];
        }
    return 0;
}