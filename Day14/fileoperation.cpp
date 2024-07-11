#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {
    string fileName;
    char choice;


    cout<<"Enter the file name: ";
    cin>>fileName;
    
    cout<<"Enter 'r' to read from the file or 'w' to write to the file: ";
    cin>>choice;

    if(choice == 'r') {
        
        ifstream inputFile(fileName);

        if(inputFile.is_open()) {
            string line;

            while(getline(inputFile, line)) {
                cout<<line<<endl;
            }

            inputFile.close();
        }else{
            cout<<"Error opening file for reading."<<endl;
        }
    }else if(choice == 'w'){
        ofstream outputFile(fileName);

        if(outputFile.is_open()){
            string content;

            cout << "Enter the content to write to the file: ";
            getline(cin,content,'\n'); 

            outputFile<<content<<endl;

            outputFile.close();
            cout<<"Content written to the file successfully."<<endl;
        } else{
            cout<<"Error opening file for writing."<<endl;
        }
    } else{
        cout<<"Invalid choice. Please enter 'r' or 'w'."<<endl;
    }

    return 0;
}