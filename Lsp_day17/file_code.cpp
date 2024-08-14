/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<stdexcept>

void readProcess(const std::string& fname) {
    std::ifstream file(fname);
    if(!file.is_open()) {
        throw std::runtime_error("File not found: " + fname);
    }
    
    std::string line;
    int sum = 0;
    
    while(std::getline(file, line)) {
        std::istringstream lineStream(line);
        int num;
        
        while(lineStream >> num) {
            sum += num;
        }
        
        if(lineStream.fail() && !lineStream.eof()) {
            throw std::runtime_error("Unexpected data format in line : " + line);
            
        }
    }
    
    if(file.bad()) {
        throw std::runtime_error("Error reading file: " + fname);
    }
    file.close();
    std::cout<<"Sum of numbers in file: "<<sum<<std::endl;
}
int main() {
    std::string fname;
    std::cout<<"Enter file name: ";
    std::cin>>fname;
    try {
        readProcess(fname);
    } catch (const std::runtime_error& e) {
        std::cerr<<"Runtime error "<<e.what()<<std::endl;
    } catch (const std::exception& e) {
        std::cerr<<"An error occured "<<e.what();
    }
    return 0;
}
