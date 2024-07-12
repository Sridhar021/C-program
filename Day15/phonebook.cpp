#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Contact{
    public:
    string name;
    string phno;
    
    void input(){
        cout<<"Enter Name: ";
        cin.ignore();
        getline(cin,name);
        cout<<"Enter Phone number: ";
        getline(cin,phno);
    }
    void display() const {
        cout<<"Name: "<<name<<" Phone Number: "<<phno<<endl;
    }
};

void add()
{
    Contact c;
    c.input();
    
    ofstream file("phonebook.txt",ios::app);
    if(file.is_open())
    {
        file<<c.name<<" "<<c.phno<<endl;
        file.close();
        cout<<"Conatct added successfully."<<endl;
    }else{
        cout<<"Unable to open file for writing"<<endl;
    }
}

void search()
{
    string sname;
    cout<<"Enter the name to search: ";
    cin.ignore();
    getline(cin,sname);
    
    ifstream file("phonebook.txt");
    if(file.is_open())
    {
        string name;
        string phno;
        bool found=false;
        while(file>>name>>phno){
            if(name==sname){
                cout<<"Conatct found:"<<endl;
                cout<<"Name: "<<name<<" Phone Number: "<<phno<<endl;
                found=true;
                break;
            }
        }
        file.close();
        if(!found){
            cout<<"No contact found with name"<<sname<<endl;
        }
    }else{
        cout<<"Unable to open file for reading"<<endl;
    }
}

int main()
{
    int ch;
    do{
        cout<<"Phonebook Menu"<<endl;
        cout<<"1.Add Contact"<<endl;
        cout<<"2.Search Contact by name"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        
        switch(ch)
        {
            case 1: add();break;
            case 2: search();break;
            case 3: cout<<"Exit"<<endl;break;
            default: cout<<"Invalid choice"<<endl;
        }
    }while(ch!=3);

    return 0;
}