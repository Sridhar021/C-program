#include <iostream>
using namespace std;

class Box {
private:
    double length;
    double width;
    double height;

public:
    
    Box(double l, double w, double h){          //parameterized constructor
         length=l;
         width=w;
         height=h;
    }
    
    double volume(){                            //function volume
        return length*width*height;
    }
};

int main() {
    
    Box box(3.0, 4.0, 5.0);

    
    Box &boxref=box;                //reference to box

    
    double vol=boxref.volume();     //call the volume usin reference

    
    cout<<"Volume of the box: "<<vol<<endl; //display volume

    return 0;
}

