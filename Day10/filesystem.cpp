
#include<iostream>
#include<string>
#include<fstream>
#include<exception>
using namespace std;

class File{
    public:
    virtual void rdata()=0;
    virtual ~File() {}
};

class Textfile:public File{
    private:
    string fname;
    public:
    Textfile(const string& name):fname(name){}
    
    void rdata() override{
        ifstream file(fname);
        if(!file.is_open()){
            throw ios_base::failure("Failed to open file");
        }
        string line;
        while(getline(file,line)){
            cout<<line<<endl;
        }
        file.close();
    }
};

class Imagefile:public File{
    private:
    string fname;
    public:
    Imagefile(const string& name):fname(name){}
    
    void rdata() override{
        ifstream file(fname,std::ios::binary);
        if(!file.is_open()){
            throw ios_base::failure("Failed to open image file ");
        }
        char buffer[1024];
        while(file.read(buffer,sizeof(buffer))){
            cout<<"Reading image data"<<endl;
        }
        file.close();
    }
};
void process(File* file){
    try{
        file->rdata();
    }catch(const ios_base::failure& e){
        cerr<<"File I/O error "<<e.what()<<endl;
    }catch(const exception& e){
        cerr<<"General error "<<e.what()<<endl;
    }
}
int main()
{
    File* textfile= new Textfile("Exampl.txt");
    File* imagefile=new Imagefile("Example.png");
    
    cout<<"Processing text file "<<endl;
    process(textfile);
    
    cout<<"Processing image file "<<endl;
    process(imagefile);
    
    delete textfile;
    delete imagefile;

    return 0;
}