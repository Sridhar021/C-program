

#include <iostream>
using namespace std;

class TemperatureSensor{
    private:
    float celsius;
    public:
    TemperatureSensor(double temp){
        celsius=temp;
    }
    friend void Displaytemp(const TemperatureSensor& sensor);
};

void Displaytemp(const TemperatureSensor& sensor){
    float farenheit=(sensor.celsius*9.0/5.0)+32;
    cout<<"Temperature in Farenheit is "<<farenheit<<endl;
}

int main()
{
    TemperatureSensor s(32);
    Displaytemp(s);

    return 0;
}