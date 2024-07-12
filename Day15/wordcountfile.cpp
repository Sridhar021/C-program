#include <iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    ifstream inputFile("data.txt");
    
    if(!inputFile)
    {
        cerr<<"Error opening file";
        return 1;
    }
    
    string word;
    int wc=0;
    
    while(inputFile>>word)
    {
        wc++;
    }

    inputFile.close();
    
    cout<<"Number of words in the file "<<wc<<endl;
    return 0;
}