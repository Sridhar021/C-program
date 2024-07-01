

#include<iostream>
#include<cstring>
using namespace std;

class String{
    private:
    char* s;
    int size;
    public:
    String(char*);
    ~String();
    void print();
};
String::String (char* c)
{
    size= strlen(c);
    s=new char[size+1];
    strcpy(s,c);
}
String::~String()
{
    delete[] s;
}
void String::print()
{
    cout<<s<<endl;
    cout<<size;
}
int main(){
    char word[]="destructor";
    String str(word);
    str.print();
    
    return 0;
}