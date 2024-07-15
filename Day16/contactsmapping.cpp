#include <iostream>
#include <map>
#include <string>
using namespace std;

struct Contact{
    string phone;
    string email;
};

void add(map<string, Contact>& contacts)
{
    string name,phone,email;
    cout<<"Enter Contact name: ";
    cin.ignore();
    getline(cin,name);
    cout<<"Enter phone number: ";
    getline(cin,phone);
    cout<<"Enter email: ";
    getline(cin,email);
    
    contacts[name]={phone, email};
    cout<<"Contact added successfully \n";
}
void search(map<string, Contact>& contacts)
{
    string name;
    cout<<"Enter the name of the contact to search for: ";
    cin.ignore();
    getline(cin,name);
    
    auto it= contacts.find(name);
    if(it!=contacts.end())
    {
        cout<<"Name: "<<it->first<<"\n"<<"Phone: "<<it->second.phone<<"\n"<<"Email: "<<it->second.email<<"\n";
    }
    else{
        cout<<"Contact not found\n";
    }
}

void display(const map<string, Contact>& contacts)
{
    if(contacts.empty())
    {
        cout<<"No contacts stored \n";
        return ;
    }
    
    cout<<"Stored Contacts: \n";
    for(const auto& [name,contact]: contacts)
    {
        cout<<"\nName: "<<name<<"\n"<<"Phone: "<<contact.phone<<"\n"<<"Email: "<<contact.email<<"\n";
    }
}

int main()
{
    map<string, Contact> contacts;
    int ch;
    
    while(true)
    {
        cout<<"\nContact Details\n"<<"1.Add new contact\n"<<"2.Search for a contact\n"<<"3.Display contacts\n"<<"4.Exit\n";
        cout<<"Enter your choice: ";
        cin>>ch;
        
        switch(ch){
            case 1:
            add(contacts);
            break;
            case 2:
            search(contacts);
            break;
            case 3:
            display(contacts);
            break;
            case 4:
            cout<<"Exit\n";
            return 0;
            default:
            cout<<"Invalid choice";
        }
    }
    
    return 0;
}