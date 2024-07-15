#include <iostream>
#include<random>
#include<string>
using namespace std;

void rolldice(int sides,int rolls)          //function to roll dice
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1,sides);
    
    cout<<"Rolling a "<<sides<<" sided dice "<<rolls<<" times \n";
    for(int i=0;i<rolls;++i)
    {
        cout<<dis(gen)<<" ";
    }
    cout<<endl;
    
}

void flipcoin(int flips)                //function to flip coin
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0,1);
    
    cout<<"Flipping a coin "<<flips<<" times \n";
    for(int i=0;i<flips;++i)
    {
        cout<<(dis(gen)?"Heads":"Tails")<<" ";
    }
    cout<<endl;
}

void generatetemp( int count,int mintemp,int maxtemp,const string& distribution)  //function to generate random temperature
{
    random_device rd;
    mt19937 gen(rd());
    
    cout<<"Generating "<<count<<" random temp between "<<mintemp<<" and "<<maxtemp<<"\n";
    
    if(distribution=="uniform")     //for uniform
    {
        uniform_real_distribution<> dis(mintemp,maxtemp);
        for(int i=0;i<count;++i)
        {
            cout<<dis(gen)<<" ";
        }
    }
    else if(distribution=="normal") {       //for normal
        double mean=(mintemp+maxtemp)/2.0;
        double stddev=(maxtemp-mintemp)/6.0;
        
        normal_distribution<> dis(mean,stddev);
        for(int i=0;i<count;++i)
        {
            double temp;
            do{
                temp=dis(gen);
            }while(temp<mintemp || temp>maxtemp);
            cout<<temp;
        }
    }
    else {
        cerr<<"Unknown distribution type : "<<distribution<<endl;   //error for unknown type
    }
    
    cout<<endl;
}

int main()
{
    int ch;
    cout<<"Choose an option: \n";
    cout<<"1. Roll dice \n";
    cout<<"2. Flip a coin \n";
    cout<<"3. Generate random temperature \n";
    cin>>ch;
    
    switch(ch)
    {
        case 1:
        {
            int sides,rolls;
            cout<<"Enter the number of sides on  the dice\n";
            cin>>sides;
            cout<<"Enter the number of rolls\n";
            cin>>rolls;
            rolldice(sides,rolls);
            break;
        }
        case 2:
        {
            int flips;
            cout<<"Enter the no. of coin flips\n";
            cin>>flips;
            flipcoin(flips);
            break;
        }
        case 3:
        {
            int count;
            double mintemp,maxtemp;
            string distribution;
            cout<<"Enter the no. of temp. to generate:\n";
            cin>>count;
            cout<<"Enter the minimum temp:\n";
            cin>>mintemp;
            cout<<"Enter the maximum temp:\n";
            cin>>maxtemp;
            
            cout<<"Enter the distribution type (uniform/normal): ";
            cin>>distribution;
            
            generatetemp(count,mintemp,maxtemp,distribution);
            break;
        }
        default:
        cerr<<"Invalid Choice "<<endl;      //error
        break;
    }
    

    return 0;
}