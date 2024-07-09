#include <iostream>
#include<vector>
#include<string>
using namespace std;

class Student{
    private:
    string name;
    int id;
    vector<int> scores;
    
    public:
    Student(const string& n,int i):name(n),id(i) {}
    
    const string& getname() const{
        return name;
    } 
    int getid() const{
        return id;
    }
    
    const vector<int>& getscores() const {
        return scores;
    }
    
    void addscore(int score){
        scores.push_back(score);
    }
    
    double calavg() const{
        if(scores.empty()){
            return 0.0;
        }
        double sum=0;
        for(int score: scores){
            sum=sum+score;
        }
        return sum/scores.size();
    }
    void print() const{
        cout<<"Name: "<<name<<"\nID: "<<id<<endl;
        cout<<"Scores: ";
        for(int score: scores){
            cout<<score<<" ";
        }
        cout<<endl;
    }
};

class ClassManager{
    private:
    vector<Student> students;
    
    public:
    void addstudent(const string& name,int id){
        students.emplace_back(name,id);
    }
    
    void addscore(int id,int score){
        for(auto& student: students){
            if(student.getid()==id){
                student.addscore(score);
                return;
            }
        }
        cout<<"Student with id "<<id<<" not found"<<endl;
    }
    
    Student* findname(const string& name){
        for(auto& student: students){
            if(student.getname()==name){
                return &student;
            }
        }
        return nullptr;
    }
    
    Student* findid(int id){
        for(auto& student: students){
            if(student.getid()==id){
                return &student;
            }
        }
        return nullptr;
    }
    
    void avgscorestudent(int id){
        Student* student=findid(id);
        if(student!=nullptr){
            double avgscore=student->calavg();
            cout<<"Average score for student with ID "<<id<<":"<<avgscore<<endl;
        }else{
            cout<<"Student with ID "<<id<<" not found"<<endl;
        }
    }
    
    void avgscoreclass(){
        double tsum=0.0;
        int tscores=0;
        for(const auto& student :students){
            for(int score:student.getscores()){
                tsum=tsum+score;
                tscores++;
            }
        }
        double tavgscore=(tscores==0)?0.0:tsum/tscores;
        cout<<"Average score for the class: "<<tavgscore<<endl;
    }
    
    void printall() const{
        for(const auto& student: students){
            student.print();
        }
    }
};

int main()
{
    ClassManager m;
    
    m.addstudent("Sridhar",1);
    m.addscore(1,85);
    m.addscore(1,90);
    
    m.addstudent("Manoj",2);
    m.addscore(2,88);
    m.addscore(2,89);
    
    string sname="Sridhar";
    Student* studentname=m.findname(sname);
    if(studentname!=nullptr){
        cout<<"Found student by name "<<sname<<": "<<endl;
        studentname->print();
    }else{
        cout<<"student with name "<<sname<<" not found"<<endl;
    }
    
    int sid=2;
    Student* studentid=m.findid(sid);
    if(studentid!=nullptr){
        cout<<"Found student by ID "<<sid<<": "<<endl;
        studentid->print();
    }else{
        cout<<"student with ID "<<sname<<" not found"<<endl;
    }
    
    sid=1;
    m.avgscorestudent(sid);
    
    m.avgscoreclass();
    
    cout<<"All students : "<<endl;
    m.printall();
    
    return 0;
}
    
    
    
    
    
    
    
    
    
    























