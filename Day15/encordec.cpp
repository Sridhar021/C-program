#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void caesarCipher(const string& inputFile, const string& outputFile, int shift, bool encrypt) {
    ifstream inFile(inputFile);
    if(!inFile) {
        cerr<<"Error: Unable to open input file."<<endl;
        return;
    }

    ofstream outFile(outputFile);
    if(!outFile) {
        cerr<<"Error: Unable to open output file."<<endl;
        inFile.close();
        return;
    }

    char ch;
    while(inFile.get(ch)) {
        if(isalpha(ch)) {  // Check if the character is alphabetic
            if(isupper(ch)) {
                ch = encrypt ? 'A' + (ch - 'A' + shift) % 26 : 'A' + (ch - 'A' - shift + 26)%26;
            }else {
                ch = encrypt ? 'a' + (ch - 'a' + shift) % 26 : 'a' + (ch - 'a' - shift + 26)%26;
            }
        }
        outFile << ch;
    }

    cout<<(encrypt ? "Encryption" : "Decryption") << " complete." << endl;

    inFile.close();
    outFile.close();
}

int main() 
{
    string inputFile, outputFile;
    int shift;
    char choice;

    cout<<"Enter the input file name: ";
    cin>>inputFile;
    cout<<"Enter the output file name: ";
    cin>>outputFile;
    cout<<"Enter the shift (a positive integer): ";
    cin>>shift;
    cout<<"Encrypt (e) or Decrypt (d): ";
    cin>>choice;

    bool encrypt =(choice == 'e' || choice == 'E');

    caesarCipher(inputFile, outputFile, shift, encrypt);

    return 0;
}
