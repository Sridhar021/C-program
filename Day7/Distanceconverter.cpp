
#include<iostream>
#include<string>
using namespace std;

class Distanceconverter{
    public:
    static double convertmk(double miles){
        return miles*1.60934;
    }
    static double convertkm(double kilo){
        return kilo/1.60934;
    }
};

int main(){
    double distance;
    string unit;
    
    cout<<"Enter the distance "<<endl;
    cin>>distance;
    cout<<"\nEnter the unit (miles or kilometers) "<<endl;
    cin>>unit;
    
    if(unit=="miles"){
        double km=Distanceconverter::convertmk(distance);
        cout<<distance<<" Miles is "<<km<<" kilometers"<<endl;
    }
    else if(unit=="kilometers"){
        double m=Distanceconverter::convertkm(distance);
        cout<<distance<<" Kilometers is "<<m<<" Meters"<<endl;
    }
    else{
        cout<<"Invalid option"<<endl;
    }
    return 0;
}