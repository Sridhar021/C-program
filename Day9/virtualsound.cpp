
#include <iostream>
using namespace std;

class Animal{               //base class
    public:
    virtual void makesound()=0; //pure virtual function
    virtual ~Animal() {}            //virtual destructor
};

class Cat:public Animal{        //derived class
    public:
    void makesound() override{
        cout<<"Meow!"<<endl;
    }
};

class Dog:public Animal{
    public:
    void makesound() override{
        cout<<"Woof!"<<endl;
    }
};

class Pig:public Animal{
    public:
    void makesound() override{
        cout<<"Oink!"<<endl;
    }
};

void playsound(Animal& animal){             //function playsound
    animal.makesound();
}
int main()
{
    Cat c;
    Dog d;
    Pig p;
    
    playsound(c);           //pass different objects to playsound
    playsound(d);
    playsound(p);

    return 0;
}