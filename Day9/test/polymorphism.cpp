
#include<iostream>
using namespace std;

class Shape{
    public:
    virtual void draw()const =0;
    virtual ~Shape(){}
};

class Circle:public Shape{
    public:
    void draw() const override{
        cout<<"Circle"<<endl;
    }
};

class Rectangle:public Shape{
    public:
    void draw() const override{
        cout<<"Rectangle "<<endl;
    }
};

class Triangle:public Shape{
    public:
    void draw() const override{
        cout<<"Triangle"<<endl;
    }
};

void drawshape(const Shape* shape){
    shape->draw();
}

int main()
{
    Circle c;
    Rectangle r;
    Triangle t;
    
    Shape* shapes[]={ &c, &r, &t};
    
    
    for(const Shape* shape: shapes){
        drawshape(shape);
    }
    
    return 0;
}