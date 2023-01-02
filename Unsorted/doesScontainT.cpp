/*Given two string s and t, write a function to check if s contains all characters of t (in the same order as they are in string t).
Return true or false.
Do it recursively.
E.g. : s = “abchjsgsuohhdhyrikkknddg” contains all characters of t=”coding” in the same order. So function will return true.*/

#include<iostream>
using namespace std;

bool checksequenece(char large[] , char*small) {
    if(small[0]=='\0'){
        return true;
    }
    if(large[0]=='\0'){
        return false;
    }

    if(large[0]==small[0]){
        bool a = checksequenece(++large, ++small);
        return a;
    }
    else{
        return checksequenece(++large, small);
    }
}



int main()
{
	char large[10000] = "abchjsgsuohhdhyrikkknddg";
	char small[10000] = "codin";
	bool x=checksequenece(large , small);

	if(x)
		cout<<"true";
	else
		cout<<"false";

}
