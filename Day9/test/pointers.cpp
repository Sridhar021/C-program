
#include <iostream>
#include<string>
using namespace std;

class Student{
    private:
    string name;
    int age;
    
    public:
    Student():name(""),age(0) {}
    
    void getdetails(const string& sname,int sage){
        name=sname;
        age=sage;
    }
    void display() const{
        cout<<"Name: "<<name<<"\nAge: "<<age<<endl;
    }
    
    void deallocate(Student* students){
        delete[] students;
        cout<<"Memory deleted "<<endl;
    }
};
int main()
{
    int n;
    cout<<"Enter no. of students "<<endl;
    cin>>n;
    
    Student* students=new Student[n];
    
    for(int i=0;i<n;++i){
        string name;
        int age;
        
        cout<<"Enter the name of student "<<i+1<<"="<<endl;
        cin>>name;
        cout<<"Enter the age of student "<<i+1<<"="<<endl;
        cin>>age;
        
        students[i].getdetails(name,age);
    }
    
    cout<<"Students details"<<endl;
    for(int i=0;i<n;++i){
        students[i].display();
    }
    
    students[0].deallocate(students);

    return 0;
}