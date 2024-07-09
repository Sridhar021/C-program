
#include <iostream>
#include<vector>
#include<string>
using namespace std;

class Task{
    private:
    string des;
    int p;
    string date;
    public:
    Task(const string& description,int pri,const string& due):des(description),p(pri),date(due){}
    
    void print() const {
        cout<<"Task: "<<des<<"\nPriority: "<<p<<"\nDue Date: "<<date<<endl;
    }
};
int main()
{
    vector<Task> tasks;
    
    Task task1("Complete assignment",2,"15-07-2024");
    Task task2("Upload to git",3,"15-07-2024");
    
    tasks.push_back(task1);
    tasks.insert(tasks.begin(),task2);
    
    tasks.emplace_back("Join Call",4,"16-07-2024");
    tasks.emplace(tasks.begin() + 1,"submit report",5,"17-07-2024");
    
    cout<<"TASKS"<<endl;
    
    for(const Task& task:tasks){
        task.print();
    }
    return 0;
}