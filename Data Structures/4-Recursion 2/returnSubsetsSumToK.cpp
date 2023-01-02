/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 3, 4, 2} and K = 5, then output array should contain
	{{2, 1, 4},	// Length of this subset is 2
	{2, 3, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

#include <iostream>
using namespace std;


int subsetSumToK(int input[], int n, int output[][50], int k) {
   // Write your code here

}

int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here

}


int main() {
  int input[20],length, output[10000][50], k;
  
  length = 3;
  int arr[] = {1, 2, 3, 4, 5, 6};
  k = 10;

  for(int i=0; i < length; i++)
    input[i] = arr[i];
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
