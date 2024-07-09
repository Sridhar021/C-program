
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> vec1;
    vector<int> vec2(10,5);
    vector<int> vec3{1,2,3,4,5};
    vector<int> vec4(vec3.begin(),vec3.end());
    vector<int> vec5(vec3);
    vector<int> vec6(move(vec5));
    
    vec1=vec2;
    vec1=move(vec2);
    vec1={10,20,30};
    
    cout<<"Element at index 1: "<<vec1[1]<<endl;
    cout<<"Element at index 2: "<<vec1.at(2)<<endl;
    cout<<"First Element: "<<vec1.front()<<endl;
    cout<<"Last Element: "<<vec1.back()<<endl;
    int* data=vec1.data();
    cout<<"Element via data points: "<<data[0]<<endl;
    
    cout<<"Elements in vec1: ";
    for(auto it=vec1.begin();it!=vec1.end();++it){
        cout<<*it<<" ";
    }
    cout<<endl;
    cout<<"Elements in reverse: ";
    for(auto it=vec1.rbegin();it!=vec1.rend();++it){
        cout<<*it<<" ";
    }
    cout<<endl;
    
    cout<<"Size: "<<vec1.size()<<endl;
    cout<<"Capacity: "<<vec1.capacity()<<endl;
    cout<<"Is empty: "<<vec1.empty()<<endl;
    vec1.resize(5);
    cout<<"Resize vec1 size: "<<vec1.size()<<endl;
    vec1.reserve(20);
    cout<<"Reserved capacity: "<<vec1.capacity()<<endl;
    
    vec1.assign(7,100);
    vec1.push_back(200);
    vec1.pop_back();
    vec1.insert(vec1.begin()+ 1,300);
    vec1.erase(vec1.begin() + 2);                                   
    vec1.emplace(vec1.begin(), 400);                                 
    vec1.emplace_back(500);                                          
    vec1.swap(vec3);                                                 
    vec1.clear();  
    
    cout<<"Is vec1 == vec3? "<<(vec1 == vec3)<<endl; 
    swap(vec1,vec3);                                           
    cout<<"Elements after swap: ";
    for(const auto& elem : vec1){
        cout<<elem<<" ";
    }
    cout<<endl;
   
    sort(vec1.begin(),vec1.end());                             
    cout<<"Sorted elements: ";
    for(const auto& elem : vec1){
        cout<<elem<<" ";
    }
    cout<<endl;
    

    return 0;
}