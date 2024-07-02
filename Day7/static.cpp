

#include <iostream>
class MyClass{
    private:
    static int counter;
    int count;
    public:
    MyClass(){
        counter++;
        count++;
    }
    static int getcounter(){
        return counter;
    }
    int getcount(){
        return count;
    }
};
int MyClass::counter=0;
int main()
{
    MyClass obj1;
    MyClass obj2;
    MyClass obj3;
    std::cout<<"Number of objects created: "<<MyClass::getcounter()<<std::endl;
    std::cout<<"Object 1 count method: "<<obj1.getcount()<<std::endl;
    std::cout<<"Object 2 count method: "<<obj2.getcount()<<std::endl;
    std::cout<<"Object 3 count method: "<<obj3.getcount()<<std::endl;

    return 0;
}