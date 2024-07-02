#include<iostream>
#include<string>
using namespace std;

class User{
    private:
    string username;
    string profilepic;
    public:
    User(string uname,string ppic){
        username=uname;
        profilepic=ppic;
    }
    
    string getname() const{
        return username;
    }
    string getpic() const{
        return profilepic;
    }
};

class Post:public User{
    private:
    string content;
    string timestmp;
    public:
    Post(string uname,string ppic,string cont,string time):User(uname,ppic),content(cont),timestmp(time) {}
    
    string getinfo() const{
        return "Username: "+getname()+"\nProfile Pic: "+getpic()+"\nContent: "+content+"\nTimestamp: "+timestmp;
    }
};

void interact(const User& u1,const User& u2){
    cout<<u1.getname()<<" interacts with "<<u2.getname()<<endl;;
}

void follow(const User& u1,const User& u2){
    cout<<u1.getname()<<" follows "<<u2.getname()<<endl;
}

void like(const User& u1,const Post& p1){
    cout<<u1.getname()<<" liked the post by "<<p1.getname()<<endl;
}

int main()
{
    User u1("Sridhar","Sridharpic");
    User u2("Guru","Gurupic");
    
    Post p1("Guru","Gurupic","Hello","12-12-2023");
    cout<<p1.getinfo()<<endl;
    follow(u1,u2);
    interact(u1,u2);
    like(u1,p1);
    
    return 0;
}