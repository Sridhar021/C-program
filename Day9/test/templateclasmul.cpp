

#include <iostream>
using namespace std;

template <typename T1,typename T2>
class Pair{
    private:
    T1 first;
    T2 second;
    public:
    Pair(const T1& f,const T2& s):first(f),second(s){}
    
    void setpair(const T1& f,const T2& s){
        first=f;
        second=s;
    }
    T1 getfirst() const{
        return first;
    }
    T2 getsecond() const{
        return second;
    }
};
int main()
{
    Pair<int,double> p1(10,3.14);
    cout<<"Pair1: First value = "<<p1.getfirst()<<" Second value = "<<p1.getsecond()<<endl;
    
    Pair<char,string> p2('A',"hello");
    cout<<"Pair2: First value = "<<p2.getfirst()<<" Second value = "<<p2.getsecond();

    return 0;
}