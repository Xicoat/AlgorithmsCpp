#include <iostream>
using namespace std;

class ComplexNumbers {
    // Complete this class
    public:
    int real;
    int imaginary;

    ComplexNumbers(int real, int imaginary){
        this->real = real;
        this->imaginary = imaginary;
    }

    void plus(ComplexNumbers b){
        this->real += b.real;
        this->imaginary += b.imaginary; 
    }

    void multiply(ComplexNumbers b){
        ComplexNumbers tmp(0,0);
        tmp.real += b.real * this->real;
        tmp.imaginary += b.real * this->imaginary;
        tmp.imaginary += b.imaginary * this->real;
        tmp.real += b.imaginary * this->imaginary * (-1);
        this->real = tmp.real;
        this->imaginary = tmp.imaginary;
    }

    void print(){
        cout << this->real << " + i" << this->imaginary << endl;
    }

};



int main() {
    int real1, imaginary1, real2, imaginary2;
    
    real1 = 4; 
    imaginary1 = 5;
    real2 = 6; 
    imaginary2 = 7;
    
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }   
}