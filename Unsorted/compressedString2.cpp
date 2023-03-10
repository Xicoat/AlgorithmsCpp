#include <iostream>
#include <cstring>
#include<string>
using namespace std;



string getCompressedString(string &input) {
    if (input.length() == 0){
        return "";
    }
    
    int startIndex = 0;
    int endIndex = 0;
    
    string compressedString = "";
    
    while (startIndex < input.length()) {
        while ((endIndex < input.length()) && (input[endIndex] == input[startIndex])) {
            endIndex += 1;
        }
        int totalCharCount = endIndex - startIndex;
        
        if (totalCharCount != 1) {
            compressedString += input[startIndex];
            compressedString += (char)(totalCharCount + '0');
        }
        else {
            compressedString += input[startIndex];
        }
        startIndex = endIndex;
    }
    return compressedString;
}


int main() {
    int size = 1e6;
    string str;
    cin >> str;
    str = getCompressedString(str);
    cout << str << endl;
}