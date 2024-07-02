

#include <iostream>
using namespace std;

class Currencyconverter{
    public:
    static double rate;
    
    static double convertEur(double amt){
        return amt*rate;
    }
    
    static double convertUsd(double amt){
        return amt/rate;
    }
};

double Currencyconverter::rate=0.85;

int main()
{
    double amount;
    string type;
    cout<<"Enter the amount: "<<endl;
    cin>>amount;
    cout<<"Enter conversion choice (EUR or USD) "<<endl;
    cin>>type;
    if(type=="eur"){
        double eur=Currencyconverter::convertEur(amount);
        cout<<amount<<" USD is "<<eur<<" EUR"<<endl;
    }
    else if(type=="usd"){
        double usd=Currencyconverter::convertUsd(amount);
        cout<<amount<<" EUR is "<<usd<<" USD "<<endl;
    }
    else{
        cout<<"Invalid Choice";
    }
    return 0;
}