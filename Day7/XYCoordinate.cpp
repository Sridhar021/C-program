#include <iostream>
using namespace std;

class Point{
    private:
    int x,y;
    public:
    Point(int xc=0,int yc=0){
        x=xc;
        y=yc;
    }
    
    int getx() const {
        return x;
    }
    int gety()const {
        return y;
    }
    friend ostream& operator<<(ostream& os, const Point& p);
};
class Pointout{
    public:
    friend ostream& operator<<(ostream& os, const Point& p){
        os<<"Point ("<<p.getx()<<","<<p.gety()<<")";
        return os;
    }
};
int main()
{
    Point p1(10,20);
    Point p2(30,40);
    
    cout<< p1 <<endl;
    cout<< p2 <<endl;

    return 0;
}