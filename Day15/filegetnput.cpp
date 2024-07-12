
#include <iostream>
#include<conio.h>
#include<fstream>
using namespace std;
class Student 
{
    public:
    struct stu 
    {
        char name[20];
        int roll;
        
    }s;
    void put_data();
    void get_data();
};

void Student::put_data()
{
    cout<<"Enter Name: ";
    cin>>s.name;
    cout<<"Enter roll: ";
    cin>>s.roll;
    fstream file;
    file.open("hit.txt",ios::out | ios::app);
    file.write((char*)this, sizeof(Student));
    file.close();
    get_data();
    
}

void Student::get_data()
{
    int temp;
    cout<<"Enter roll no: ";
    cin>>temp;;
    
    fstream file;
    file.open("hit.txt",ios::in);
    file.seekg(0,ios::beg);
    while(file.read((char*)this, sizeof(Student)))
    {
        if(temp==s.roll)
        {
            cout<<"Student Name: "<<s.name;
            cout<<"\nStudent roll: "<<s.roll;
        }
    }
}
int main()
{
    
    Student st;
    st.put_data();

    return 0;
}