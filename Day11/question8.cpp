
#include <iostream>
using namespace std;

int calcuate(int w,int h){
    return w*h;
}

double calcuate(double w,double h){
    return w*h;
}
int main()
{
    int iw=5;
    int ih=10;
    double dw=5.4;
    double dh=10.5;
    
    double area1=calcuate(static_cast<double>(iw),dh);
    cout<<"Area = "<<area1<<endl;
    
    double area2=calcuate(static_cast<int>(dw),static_cast<int>(dh));
    cout<<"Area = "<<area2<<endl;

    return 0;
}