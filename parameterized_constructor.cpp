
#include <iostream> //header file
#include<string>
using namespace std;

class Rectangle {       //class rectangle
    private:
    double length;
    double width;
    public:
    Rectangle(double l,double w){       //parameterized constructor
        length=l;
        width=w;
    }
    double area(){                      //area function
        return length*width;
    }
    
    void display(){                     //display length and width
        cout<<"Length: "<<length<<"width: "<<width<<endl;
        
    }
};
int main()
{
    Rectangle r(40.0,20.0);             //passing arguments
    r.display();                        //call display 
    cout<<"Area = "<<r.area();          //print area
    return 0;
}