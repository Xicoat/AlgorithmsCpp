#include <iostream>
#include <cstring>
#include<string>
using namespace std;

string getCompressedString(string &input) {
    
    int j = 0, n = 0;
    
    for (int i = 0; input[i] != '\0';){
        if(input[i] == input[j]){
            n++;
            i++;
        } else if(input[i] != input[j]){
            if(n > 1){
                input[++j] = (char)(n+'0');
                j++;
            } else if (n == 1){
                j++;
            }
            input[j] = input[i];
            n = 0;
        }
    }
    

   if(n <= 1){
       j++;
    } else if (n > 1){
        input[++j] = (char)(n+'0');
   }   
    
    j++;
    for(j; input[j] != '\0'; j++){
        input[j] = char(0);
    }
    
    return input;
}

int main() {
    int size = 1e6;
    string str;
    cin >> str;
    str = getCompressedString(str);
    cout << str << endl;
}