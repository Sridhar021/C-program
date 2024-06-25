
#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
                                // Default constructor
    Complex(){ 
        real=0;
        imag=0;
    }
    

                                // Parameterized constructor
    Complex(double r, double i){
        
     real=r;
     imag=i; 
    }
                                    // Method to display the complex number
    void display() {
        cout << "Complex number: " << real << " + "<<imag<<" i "<<endl;
    }
};

int main() {
                                // Create a Complex object using the default constructor
    Complex defaultComplex;
    defaultComplex.display();

                                // Create a Complex object using the parameterized constructor
    Complex parameterizedComplex(3.0, 4.5);
    parameterizedComplex.display();

    return 0;
}
