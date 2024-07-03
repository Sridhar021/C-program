

#include <iostream>
using namespace std;

template <class T>
class Smartpointer{
    T *p;
    public:
    Smartpointer(T *ptr=NULL){
        p=ptr;
    }
    ~Smartpointer(){
        delete(p);
    }
    T & operator *(){
        return *p;
        
    }
    T * operator->(){
        return p;
    }
};
int main()
{
    Smartpointer<int> p(new int());
    *p=26;
    cout<<"Value is "<<*p;

    return 0;
}