/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
class Point{
    public:
    double x,y;
    
    Point(double nx, double ny){
        x=nx;y=ny;
        cout<<"Parameter constructor"<<endl;
    }
    Point(Point &o){
        x=o.x;
        y=o.y;
        cout<<"copy constructor constructor"<<endl;
    }
};
int main()
{
    Point q(1.0,2.0);
    Point r=q; //r.x=1.0,r.y=2.0
    

    return 0;
}