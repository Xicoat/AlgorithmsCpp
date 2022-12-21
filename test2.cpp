#include <iostream>
#include <string>
using namespace std;

string getKeypad(int n){
    string keypad[]= {"",  "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    return keypad[n];
}


int main(){
    int num = 43;

    cout << "dial: " << num << endl;

    string optionsForLastDigit = getKeypad(3); 
    cout<< optionsForLastDigit<< endl;
    cout<< optionsForLastDigit[0] << endl;

    return 0;
}
