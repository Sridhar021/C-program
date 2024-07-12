#include<fstream>
#include<iostream>
#include<string>
using namespace std;

void createTextFile(const string& filename)
{
  ofstream outfile(filename);
  if(outfile.is_open()) {
    outfile<<"This is a sample text file.\n";
    outfile<<"You can add more content here.\n";
    cout<<"Text file "<<filename<<" created successfully!"<<endl;
  }
  else
  {
    cerr<<"Error creating file: "<<filename<<endl;
  }
  outfile.close(); 
}

void readTextFile(const string& filename)
{
  ifstream infile(filename);

  if(infile.is_open()) {
    string line;
    while(getline(infile, line)) {
      cout<<line<<endl;
    }
  } 
  else 
  {
    cerr<<"Error opening file: "<<filename<<endl;
  }

  infile.close(); 
}


void writeBinaryFile(const string& filename, const char* data, int size) {
  ofstream outfile(filename, ios::binary);

  if(outfile.is_open())
  {
    outfile.write(data, size);
    cout<<"Binary data written to file "<<filename<<endl;
  } 
  else
  {
    cerr<<"Error creating binary file: "<<filename<<endl;
  }

  outfile.close(); 
}


void readBinaryFile(const string& filename, int size)
{
  char buffer[size];

  ifstream infile(filename, ios::binary);

  if(infile.is_open())
  {
    infile.read(buffer, size);
    cout<<"Binary data from file "<<filename<<":"<< endl;
    for(int i=0;i<size;++i) 
    {
      cout<<hex<<static_cast<int>(buffer[i])<<" ";
    }
    cout<<endl;
  } 
  else 
  {
    cerr<<"Error opening binary file: "<<filename<<endl;
  }

  infile.close(); 
}

int main() 
{
  string textFilename="example.txt";
  string binaryFilename="data.bin";

  
  createTextFile(textFilename);

  readTextFile(textFilename);

  char binaryData[]="This is binary data";

  
  writeBinaryFile(binaryFilename, binaryData, sizeof(binaryData));

  
  readBinaryFile(binaryFilename, sizeof(binaryData));

  return 0;
}