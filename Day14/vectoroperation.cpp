
#include <iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

void display(const vector<double>& vec)
{
    for(double num: vec)
    {
        cout<<num<<" ";
    }
    cout<<endl;
}

double fmax(const vector<double>& vec)
{
    return *max_element(vec.begin(),vec.end());
}

double fmin(const vector<double>& vec)
{
    return *min_element(vec.begin(),vec.end());
}

double average(const vector<double>& vec)
{
    if(vec.empty()){
        return 0.0;
    }
    double sum=accumulate(vec.begin(),vec.end(),0.0);
    return sum/vec.size();
}

int main()
{
    vector<double> mv;
    
    mv.push_back(10.2);
    mv.push_back(20.3);
    mv.push_back(30.4);
    mv.push_back(40.5);
    
    cout<<"Vector elements: ";
    display(mv);
    
    int premove=2;
    if(premove>=0 && premove<mv.size())
    {
        mv.erase(mv.begin() + premove);
    }
    
    cout<<"Vector after removing element: ";
    display(mv);
    
    double maxele=fmax(mv);
    cout<<"Max element = "<<maxele<<endl;
    
    double minele=fmin(mv);
    cout<<"Min element = "<<minele<<endl;
    
    double avg=average(mv);
    cout<<"Average = "<<avg<<endl;
    
    
    return 0;
}