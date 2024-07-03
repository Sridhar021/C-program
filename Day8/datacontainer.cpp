#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;

template <typename T>
class Datacontainer
{
    private:
    vector<T> data;
    
    public:
    Datacontainer(size_t size=0):
    data(size) {}
    
    T& operator[](size_t index)
    {
        if(index>data.size()){
            throw out_of_range("Index out of range ");
        }
        return data[index];
    }
    
    void printall() const{
        for(const auto& element:data){
            cout<<element<<" ";
        }
        cout<<endl;
    }
    
    size_t size() const{
        return data.size();
    }
    
    void push_back(const T& value){
        data.push_back(value);
    }
};

template <typename T>
void swap(Datacontainer<T>& a,Datacontainer<T>& b)
{
    if(a.size()!=b.size()){
        throw invalid_argument("Containers must be same size to swap ");
    }
    for(size_t i=0;i<a.size();++i){
        T temp=a[i];
        a[i]=b[i];
        b[i]=temp;
        
    }
}
int main()
{
    Datacontainer<int> intcont(5);
    Datacontainer<float> floatcont(5);
    Datacontainer<string> stringcont(5);
    
    for(size_t i=0;i<5;++i){
        intcont[i]=i*10;
        floatcont[i]=i*1.5f;
        stringcont[i]="test"+to_string(i);
    }
    
    cout<<"Initial values of int container: "<<endl;
    intcont.printall();
    cout<<"Initial values of float container: "<<endl;
    floatcont.printall();
    cout<<"Initial values of string container: "<<endl;
    stringcont.printall();
    
    Datacontainer<int> anothercont(5);
    for(size_t i=0;i<5;++i){
        anothercont[i]=i*20;
    }
    
    cout<<"Initial values of another container: "<<endl;
    anothercont.printall();
    
    swap(intcont,anothercont);
    
    cout<<"Values after swapping, int container: "<<endl;
    intcont.printall();
    cout<<"Values after swapping, another container: "<<endl;
    anothercont.printall();
    
    return 0;
}