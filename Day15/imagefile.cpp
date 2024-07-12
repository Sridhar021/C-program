#include<iostream>
#include<fstream>
using namespace std;

void copy(const string& sourceFilename,const string& destinationFilename)
{
    ifstream sourceFile(sourceFilename,ios::binary);
    ofstream destinationFile(destinationFilename,ios::binary);
    
    if(!sourceFile){
        cerr<<"Error: unable to open source file"<<sourceFilename<<endl;
        return;
    }
    
    if(!destinationFile){
        cerr<<"Error: unable to open source file"<<destinationFilename<<endl;
        return;
    }
    
    destinationFile << sourceFile.rdbuf();
    
    cout<<"File copied successfully from "<<sourceFilename<<" to "<<destinationFilename<<endl;
    
    sourceFile.close();
    destinationFile.close();
}
int main()
{
    string sourceFilename, destinationFilename;
    cout<<"Enter the source image file name: ";
    cin>>sourceFilename;
    cout<<"Enter the destination image file name: ";
    cin>>destinationFilename;
    
    copy(sourceFilename,destinationFilename);

    return 0;
}