#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <exception>

using namespace std;

class Fileopenerror: public exception
{
    public:
    const char* what() const noexcept override
    {
        return "Error: unable to open file";
    }
};

class Invalidformat: public exception
{
    public:
    const char* what() const noexcept override
    {
        return "Error: Invalid data format";
    }
};

class Calculationerror: public exception
{
    private:
    string message;
    public:
    Calculationerror(const string& msg):message(msg) {}
    
    const char* what() const noexcept override
    {
        return message.c_str();
    }
};

double calculate(double a,double b)
{
    if(b==0)
    {
        throw Calculationerror("Error: Division by zero");
    }
    return a/b;
}

int main()
{
    ifstream file("data.txt");
    if(!file.is_open()){
        throw Fileopenerror();
    }
    
    string line;
    vector<pair<double,double>> data;
    
    while(getline(file,line))
    {
        istringstream iss(line);
        double num1,num2;
        if(!(iss>>num1>>num2))
        {
            throw Invalidformat();
        }
        data.push_back(make_pair(num1,num2));
    }
    file.close();
    
    for(const auto& pair: data){
        try{
            double result=calculate(pair.first,pair.second);
            cout<<"Result of "<<pair.first<<"/"<<pair.second<<"="<<result<<endl;
        }catch(const Calculationerror& e){
            cerr<<e.what()<<endl;
        }
    }
    
    return 0;
}