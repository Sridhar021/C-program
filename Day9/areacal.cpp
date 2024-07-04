
#include <iostream>
#include<vector>
using namespace std;

class Shape{            //base class
    public:
    virtual double area() const =0;     //pure virtual function
    virtual ~Shape()=0;                 //pure virtual destructor
};

Shape::~Shape() {}              //define the destructor

class Circle:public Shape{      //derived class
    private:
    double radius;
    public:
    Circle(double r):radius(r) {}
    double area() const override{
        return 3.14*radius*radius;
    }
};

class Square:public Shape{
    private:
    double side;
    public:
    Square(double s):side(s) {}
    double area() const override{
        return side*side;
    }
};

class Triangle:public Shape{
    private:
    double base,height;
    public:
    Triangle(double b,double h):base(b),height(h) {}
    double area() const override{
        return 0.5*base*height;
    }
};
int main()
{
    vector<Shape*> shapes;      //array pointer to objects
    
    shapes.push_back(new Circle(3.0));          //allocate memory to each objects
    shapes.push_back(new Square(5.0));
    shapes.push_back(new Triangle(4.5,9.0));
    
    for(const Shape* shape:shapes){     //call area() on each pointer
        cout<<"Area = "<<shape->area()<<endl;
    }
    
    for(const Shape* shape:shapes){     //deletes memory
        delete shape;
    }

    return 0;
}