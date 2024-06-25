
#include<iostream>	//header files
#include<string>
using namespace std;
class Student		//class Student
{
	private: string name;	//define name and age datatype
	int age;	
	public:
	Student():name("Unknown"),age(0){}	//Default constructor and initializing the students name and age
	
	void display(){					//Display method to print Name and Age
	cout<<"Name: "<<name<<"\nAge: "<<age<<endl;	
	}
};
int main()
{
	Student s;		//Create an object for Student
	s.display();		//Calls display function
	return 0;
}