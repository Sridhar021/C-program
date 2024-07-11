#include <iostream>
#include <cmath>
using namespace std;

class Shape{
    public:
    virtual ~Shape() {}
    virtual double area() const=0;
    
    bool operator==(const Shape& other) const 
    {
        return this->area() == other.area();
    }
    
    friend double  totalarea(Shape* shapes[], int count);
};

class Rectangle:public Shape {
    private:
    double length;
    double width;
    public:
    Rectangle():length(0), width(0) {}
    
    Rectangle(double l,double w):length(l),width(w) {}
    
    ~Rectangle(){}
    
    double area() const override{
        return length*width;
    }
};

class Circle:public Shape{
    private:
    double radius;
    public:
    Circle():radius(0){}
    
    Circle(double r):radius(r){}
    
    ~Circle() {}
    
    double area() const override{
        return M_PI*radius*radius;
    }
    
};

double totalarea(Shape* shapes[], int count)
{
    double total=0;
    for(int i=0;i<count;++i)
    {
        total=total + shapes[i]->area();
    }
    return total;
}

int main()
{
    Rectangle r1(7,4);
    Rectangle r2(9,5);
    
    Circle c1(6);
    Circle c2(8);
    
    Shape* shapes[]={ &r1, &r2, &c1, &c2 };
    
    cout<<"Area of Rectangle 1: "<<r1.area()<<endl;
    cout<<"Area of Rectangle 2: "<<r2.area()<<endl;
    
    cout<<"Area of Circle 1: "<<c1.area()<<endl;
    cout<<"Area of Circle 2: "<<c2.area()<<endl;
    
    cout<<"Rectangle 1 equal to Rectangle 2 is "<<(r1==r2?"True":"False")<<endl;
    cout<<"Circle 1 equal to Circle 2 is "<<(c1==c2?"True":"False")<<endl;
    
    
    double total=totalarea(shapes,4);
    cout<<"Total area of shapes is "<<total;
    
    return 0;
}