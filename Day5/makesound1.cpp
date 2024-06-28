

#include <iostream>
#include<string>
using namespace std;

class Animal{
    public:
    virtual string makesound()=0;
};

class Dog:public Animal{
    public:
    string makesound(){
        return "Woof";
    }
};
class Cat:public Animal{
    public:
    string makesound(){
        return "Meow";
    }
};
class Bird:public Animal{
    public:
    string makesound(){
        return "Chirp";
    }
};

void playsound(Animal* animal){
    cout<<animal->makesound()<<endl;
}

int main()
{
    Dog d;
    Cat c;
    Bird b;
    
    Animal* animals[]={&d,&c,&b};
    
    for(Animal* animal:animals){
        playsound(animal);
    }

    return 0;
}