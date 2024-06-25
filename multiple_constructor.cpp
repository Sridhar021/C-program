
#include <iostream> //header file
#include<string>
using namespace std;

class Book          //Class Book
{
    private:string title;   //declare title and pages
    int pages;
    public:
    Book(){                 //default constructor
        title="Unknown";
        pages=0;
    }
    Book(string t,int p){       //parameterized constructor
        title=t;
        pages=p;
    }
    void display(){             //display function
        cout<<"Title: "<<title<<"\nPages: "<<pages<<endl;
    }
};

int main()
{
    Book defaultbook;           //object for class
    defaultbook.display();      //call display for default constructor
    
    Book parameterizedbook("One piece ",200);   //passing arguments for parameterized constructor
    parameterizedbook.display();
    return 0;
}