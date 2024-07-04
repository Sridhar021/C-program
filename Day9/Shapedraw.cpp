

#include <iostream>
#include<vector> 
using namespace std;


class Shape{                //base class
    public:
    virtual void draw()=0;      //pure virtual function
    virtual ~Shape(){}          //virtual destructor
};

class Circle:public Shape{      //derived class
    public:
    void draw() override{
        cout<<"Draw Circle "<<endl;
    }
};

class Square:public Shape{      //derived class
    public:
    void draw() override{
        cout<<"Draw Square "<<endl;
    }
};

class Triangle:public Shape{
    public:
    void draw() override{
        cout<<"Draw Triangle "<<endl;
    }
};
int main()
{
    vector<Shape*> shapes;      //pointer to objects
    
    shapes.push_back(new Circle());
    shapes.push_back(new Square());             //instances of derived class
    shapes.push_back(new Triangle());
    
    for(Shape* shape:shapes){               //calls draw() on every pointer
        shape->draw();
    }
    
    for(Shape* shape:shapes){           
        delete shape;
    }

    return 0;
}