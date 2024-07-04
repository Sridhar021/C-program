

#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;

template<typename T>
class Array{
    private:
    vector<T> data;
    
    public:
    void add(const T& ele){
        data.push_back(ele);
    }
    
    bool remove(const T& ele){
        auto it=std::find(data.begin(),data.end(),ele);
        if(it!=data.end()){
            data.erase(it);
            return true;
        }
        return false;
    }
    
    void display(){
        for(const auto& ele:data){
            cout<<ele<<" ";
        }
        cout <<endl; 
    }
};
        
    

int main()
{
    Array<int> arri;
    arri.add(1);
    arri.add(2);
    arri.add(3);
    
    arri.display();
    
    arri.remove(3);
    
    arri.display();

    return 0;
}