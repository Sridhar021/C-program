

#include <iostream>
using namespace std;

class Box{
    private:
    int length,breadth,height;
    
    public:
    Box(int l,int b,int h){
        length=l;
        breadth=b;
        height=h;
    }
    
    friend int volume(const Box& box);
};

int volume(const Box& box){
    return box.length*box.breadth*box.height;
}
int main()
{
    Box b1(5,6,7);
    Box b2(8,9,10);
    
    cout<<"Volume of box 1 is "<<volume(b1)<<endl;
    cout<<"Volume of box 2 is "<<volume(b2)<<endl;

    return 0;
}