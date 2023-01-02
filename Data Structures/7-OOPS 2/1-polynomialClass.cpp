/* C++ implementation to convert infix expression to postfix*/
// Note that here we use std::stack  for Stack operations
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

class Polynomial {
    public:
        int *degCoeff;
        int capacity;

public :
    // Default Constructor
    Polynomial(){
        degCoeff = new int[1];
        degCoeff[0] = 0;
        capacity = 1;
    }

    Polynomial(int capacity, int *degCoeff){
        this->capacity = capacity;
        this->degCoeff = degCoeff;
    }

    // Copy Constructor
    Polynomial(Polynomial const &p){
        // Deep copy
        this->degCoeff = new int[p.capacity];
        for(int i = 0; i < p.capacity; i++) {
            this->degCoeff[i] = p.degCoeff[i];
        }
        this->capacity = p.capacity; 
    }

    // Copy assignment operator
    void operator=(Polynomial const &p) {
        this->degCoeff = new int[p.capacity];
        for(int i = 0; i < p.capacity; i++) {
            this->degCoeff[i] = p.degCoeff[i];
        }
        this->capacity = p.capacity;
    }

    // print
    void print(){
        for(int i=0; i < capacity; i++){
            if(this->degCoeff[i] == 0){
                continue;
            }
            cout << this->degCoeff[i]<< "x"<< i << " ";
        }
        cout << endl;
    }

    // setCoefficient
    void setCoefficient(int degree, int coeff){
        if(capacity-1 < degree){
            int *newDegCoeff = new int[degree+1] ();
            for(int i = 0; i < capacity; i++) {
                newDegCoeff[i] = degCoeff[i];
            }
            delete [] degCoeff;
            degCoeff = newDegCoeff;
            capacity = degree+1;
        }
        degCoeff[degree] = coeff;
    }

    // +
    Polynomial operator+(Polynomial const &p2){
        int n_max = 0;
        if(p2.capacity >= capacity){
            n_max = p2.capacity;
        } else n_max = capacity;
        int *newDegCoeff = new int[n_max] ();
        
        for(int i = 0; i < n_max; i++){
            if (i < capacity){
                newDegCoeff[i] += degCoeff[i];
            }
            if (i < p2.capacity){
                newDegCoeff[i] += p2.degCoeff[i];
            }
        }

        Polynomial newPolynomial(n_max, newDegCoeff);
        return newPolynomial;
    }

    // -
    Polynomial operator-(Polynomial const &p2){
        int n_max = 0;
        if(p2.capacity >= capacity){
            n_max = p2.capacity;
        } else n_max = capacity;
        int *newDegCoeff = new int[n_max] ();
        
        for(int i = 0; i < n_max; i++){
            if (i < capacity){
                newDegCoeff[i] += degCoeff[i];
            }
            if (i < p2.capacity){
                newDegCoeff[i] -= p2.degCoeff[i];
            }
        }
        Polynomial newPolynomial(n_max, newDegCoeff);
        return newPolynomial;
    }

    // *
    Polynomial operator*(Polynomial const &p2){
        int maxDegree = 0;
        maxDegree = (capacity-1) + (p2.capacity);
        int *newDegCoeff = new int[maxDegree] ();
        
        for(int i = 0; i < capacity; i++){
            for( int j = 0; j < p2.capacity; j++){
                newDegCoeff[i+j] += degCoeff[i] * p2.degCoeff[j];
            }
        }
        Polynomial newPolynomial(maxDegree, newDegCoeff);
        return newPolynomial;
    }

};


//Driver program to test above functions
int main()
{
    int count1,count2,choice;
    
    count1 = 3;
    int degreeA[] = {1, 3, 5};
    int coeffA[] = {1, 2, -4};
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        degree1[i] = degreeA[i];
    }
    
    for(int i=0;i < count1; i++) {
        coeff1[i] = coeffA[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    cout << "First: ";
    first.print();

    count2 = 4;
    int degreeB[] = {0, 1, 2, 3};
    int coeffB[] = {4, 2, -3, 1};
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        degree2[i] = degreeB[i];
    }
    
    for(int i=0;i < count2; i++) {
        coeff2[i] = coeffB[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    cout << "Second: ";
    second.print();



    
cin >> choice;
    
    switch(choice){
            // Add
        case 1:
        {
            Polynomial result1 = first + second;
            result1.print();
            break;
        }
            // Subtract
        case 2 :
        {
            Polynomial result2 = first - second;
            result2.print();
            break;
        }
            // Multiply
        case 3 :
        {
            Polynomial result3 = first * second;
            result3.print();
            break;
        }
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}