#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Student{
public:
    string name;
    int id;
    int marks;
    
    void input(){
        cout<<"Enter Name: ";
        cin.ignore();
        getline(cin,name);
        cout<<"Enter ID: ";
        cin>>id;
        cout<<"Enter Marks: ";
        cin>>marks;
    }
    
    void display() const {
        cout<<"Name: "<<name<<" ID: "<<id<<" Marks: "<<marks<<endl;
    }
};

void add(){
    Student s;
    s.input();
    
    ofstream file("students.txt",ios::app);
    if(file.is_open())
    {
        file<<s.name<<" "<<s.id<<" "<<s.marks<<endl;
        file.close();
        cout<<"Record added successfully "<<endl;
    }
    else{
        cout<<"Unable to open file for writting "<<endl;
    }
}

void display()
{
    ifstream file("students.txt");
    if(file.is_open())
    {
        string name;
        int id;
        int marks;
        cout<<"All Students Records "<<endl;
        while(file>>name>>id>>marks)
        {
            cout<<"Name: "<<name<<" ID: "<<id<<" Marks: "<<marks<<endl;
        }
        file.close();
    }
    else{
        cout<<"Unable to open file "<<endl;
    }
}

void search()
{
    int sid;
    cout<<"Enter the ID to search: ";
    cin>>sid;
    ifstream file("students.txt");
    if(file.is_open())
    {
        string name;
        int id;
        int marks;
        bool found=false;
        while(file>>name>>id>>marks)
        {
            if(id==sid)
            {
                cout<<"Student found: "<<endl;
                cout<<"Name: "<<name<<" ID: "<<id<<" Marks: "<<endl;
                found=true;
                break;
            }
        }
        file.close();
        if(!found){
            cout<<"No student found with ID "<<sid<<endl;
        }
        else{
            cout<<"Unable to open file for reading "<<endl;
        }
    }
}

int main()
{
    int choice;
    do{
        cout<<"Menu"<<endl;
        cout<<"1. Add Student"<<endl;
        cout<<"2. Display Records"<<endl;
        cout<<"3. Search Student"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>choice;
        
        switch(choice){
            case 1:
            add();
            break;
            case 2:
            display();
            break;
            case 3:
            search();
            break;
            case 4:
            cout<<"Exiting"<<endl;
            break;
            default: cout<<"Invalid choice"<<endl;
        }
    }while(choice!=4);
    
    return 0;
}