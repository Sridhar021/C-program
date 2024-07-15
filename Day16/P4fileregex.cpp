#include<iostream>
#include<fstream>
#include<regex>
#include<string>
#include<stdexcept>
using namespace std;

class FileIOException:public runtime_error {        // Custom exception for file I/O errors
    public:
    explicit FileIOException(const string& message): runtime_error(message) {}
};

void extractErrors(const string& inputFile,const string& outputFile,const regex& pattern) // Function to read a log file and extract lines matching the regex pattern
{
    ifstream inFile(inputFile);
    if(!inFile.is_open()) {
        throw FileIOException("Error opening input file "+inputFile);
    }
    
    ofstream outFile(outputFile);
    if(!outFile.is_open()) {
        throw FileIOException("Error opening output file "+outputFile);
    }
    
    string line;
    
    while(getline(inFile,line))
    {
        if(regex_search(line,pattern)){
            outFile<<line<<endl;
        }
    }
    
    if(inFile.bad()){
        throw FileIOException("Error reading from input file "+inputFile);
    }
    
    if(outFile.bad()){
        throw FileIOException("Error reading from output file "+outputFile);
    }
    
    inFile.close();
    outFile.close();
}
int main()
{
    string inputFile;
    string outputFile;
    string errorPattern;
    
    cout<<"Enter the input log file: ";
    cin>>inputFile;
    cout<<"\nEnter the output file: ";
    cin>>outputFile;
    cout<<"\nEnter the regex pattern to search: ";
    cin.ignore();
    getline(cin,errorPattern);
    
    try{
        regex pattern(errorPattern);
        extractErrors(inputFile,outputFile,pattern);
        cout<<"Error extraction complete. "<<outputFile<<endl;
    }catch(const regex_error& e)
    {
        cerr<<"Invalid regex pattern: "<<e.what()<<endl;
    }catch(const FileIOException& e)
    {
        cerr<<"FileIO error: "<<e.what()<<endl;
    }catch(const exception& e)
    {
        cerr<<"An unexpected error occured"<<e.what()<<endl;
    }

    return 0;
}