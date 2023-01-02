#include <iostream>
using namespace std;

int printInput(int input[], int size){
	for(int i = 0; i < size; i++){
		cout << input[i] << ", ";
	}
	cout << endl;
	return(1);
}

int subset(int input[], int n, int startIndex, int output[][20]){
	if(startIndex == n) {
		output[0][0] = 0;
		return 1;
	} 
	int smallSize = subset(input, n, startIndex+1, output);

	for(int i = 0; i < smallSize; i++) {
		output[i+smallSize][0] = output[i][0] + 1;
		output[i+smallSize][1] = input[startIndex];
		for(int j = 1; j <= output[i][0];  j++) {
			output[i+smallSize][j+1] = output[i][j];
		} 
	}
	return 2 * smallSize;
}

int subset(int input[], int n, int output[][20]){
	return subset(input, n, 0, output);
}





int main() {
  int input[20],length, output[3500][20];
  
	length = 3;
	int arr[] = {1, 2 , 3};


  for(int i=0; i < length; i++)
    input[i] = arr[i];
  
  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
