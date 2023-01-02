#include <iostream>
#include <string>
using namespace std;

string getKeypad(int n){
    string keypad[]= {"",  "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    return keypad[n];
}


int keypad(int num, string output[]){


    if(num < 1){
        output[0] = "";
        return 0;
    }

    int lastDigit  = num%10;
    int smallerNumber = num/10;

    int smallerOutput = keypad(smallerNumber,output);
    string optionsForLastDigit = getKeypad(lastDigit);

    int size = smallerOutput * optionsForLastDigit.size()-1;

    for (int i = smallerOutput-1; i >= 0; i--){
        for (int j = 1; j <= optionsForLastDigit.size(); j++ ){
            output[size--] = output[i];
        }
    }

    int i=0;
    if(smallerOutput != 0){
        i = 1;
    }

    int outputCount = 0;
    for(; i <= smallerOutput; i++){
        for(int j = 0; j < optionsForLastDigit.size(); j++){
            output[outputCount++] += optionsForLastDigit[j];
        }
    }

    return outputCount;
}



int main(){
    int num = 473;

    cout << "dial: " << num << endl;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
