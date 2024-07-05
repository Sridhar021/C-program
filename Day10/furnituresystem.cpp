

#include <iostream>
#include<memory>
using namespace std;

class Chair{
    public:
    virtual void sit()=0;
    virtual ~Chair(){}
};

class mchair:public Chair{
    public:
    void sit()override{
        cout<<"Modern chair"<<endl;
    }
};

class clchair:public Chair{
    public:
    void sit()override{
        cout<<"Classic chair"<<endl;
    }
};

class Furniturefact{
    public:
    virtual unique_ptr<Chair>cchair()=0;
    virtual ~Furniturefact(){}
};

class Mfurniturefact:public Furniturefact{
    public:
    unique_ptr<Chair>cchair() override{
        return make_unique<mchair>();
    }
};

class Cfurniturefact:public Furniturefact{
    public:
    unique_ptr<Chair>cchair() override{
        return make_unique<clchair>();
    }
};

void cfurniture(Furniturefact* factory){
    unique_ptr<Chair>chair=factory->cchair();
    chair->sit();
}
int main()
{
    unique_ptr<Furniturefact>mfactory=make_unique<Mfurniturefact>();
    unique_ptr<Furniturefact>cfactory=make_unique<Cfurniturefact>();
    
    cout<<"Creating modern furniture"<<endl;
    cfurniture(mfactory.get());
    
    cout<<"Creating classic furniture"<<endl;
    cfurniture(cfactory.get());

    return 0;
}