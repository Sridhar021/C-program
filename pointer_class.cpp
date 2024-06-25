
#include <iostream> //header file

using namespace std;

class Circle{           //class circle
    private:            
    float radius;       //declare radius
    public:
    Circle(float r){    //parameterized constructor
        radius=r;
    }
    float area(){       //area function
        return 3.14*radius*radius;
    }
};
int main()
{
    Circle *circleptr= new Circle(5);       //create pointer object and pass argument
    cout<<"Area of the circle is "<<circleptr->area();      //display area
    return 0;
    
}