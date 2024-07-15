#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

class Animal{           //base class
    public:
    virtual void makesound() const =0;      //pure virtual function
    virtual ~Animal()= default;             //virtual destructor
};

class Dog: public Animal{               //derived class
    public:
    void makesound() const override {
        cout<<"Woof"<<endl;
    }
};

class Cat: public Animal{               //derived class
    public:
    void makesound() const override {
        cout<<"Meow"<<endl;
    }
};

class Bird: public Animal{              //derived class
    public:
    void makesound() const override {
        cout<<"Chirp"<<endl;
    }
};

shared_ptr<Animal> createanimal(const string& type)     //function to create animal based on type
{
    if(type=="Dog"){
        return make_shared<Dog>();
    }
    else if(type=="Cat"){
        return make_shared<Cat>();
        
    }else if(type=="Bird"){
        return make_shared<Bird>();
    }
    else{
        throw invalid_argument("Unknown animal type "+ type);
    }
}
int main()
{
    try{
        vector<shared_ptr<Animal>> animals;     //creating vector using smart pointer
        
        animals.push_back(createanimal("Dog"));     //adding animals to vector
        animals.push_back(createanimal("Cat"));
        animals.push_back(createanimal("Bird"));
        //animals.push_back(createanimal("Snake"));   //error case
        
        for(const auto& animal:animals){        //loop to call makesound for each animal
        }
    }catch(const exception& e){
        cerr<<"Error: "<<e.what()<<endl;
    }

    return 0;
}