
#include <iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream sourceFile("source.txt");
    if(!sourceFile)
    {
        cerr<<"Error opening source file"<<endl;
        return 1;
    }
    
    ofstream destinationFile("destination.txt");
    if(!destinationFile)
    {
        cerr<<"Error opening destination file "<<endl;
        sourceFile.close();
        return 1;
    }
    
    string line;
    while(getline(sourceFile,line))
    {
        destinationFile<<line<<endl;
    }
    
    sourceFile.close();
    destinationFile.close();
    

    return 0;
}