
#include <iostream>
using namespace std;

class Animal{
    public:
    virtual void sound() const=0;
};

class Dog:public Animal{
    public:
    void sound() const override{
        cout<<"Dog Woof"<<endl;
    }
};

class Cat:public Animal{
    public:
    void sound() const override{
        cout<<"Cat Meow"<<endl;
    }
};
class Cow:public Animal{
    public:
    void sound() const override{
        cout<<"Cow Moo"<<endl;
    }
};

void asound(const Animal& a){
    a.sound();
}

int main()
{
    Dog d;
    Cat c;
    Cow co;
    
    asound(d);
    asound(c);
    asound(co);

    return 0;
}