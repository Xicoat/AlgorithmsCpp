#include <iostream>
using namespace std;

int subset(int input[], int n, int startIndex, int output[][20]) {
  if (startIndex == n) {
    output[0][0] = 0;
    return 1;
  }

  cout << "subset( input, n = " << n << ", startIndex+1 = " << startIndex+1 <<", output);" << endl;
  int smallSize = subset(input, n, startIndex + 1, output);

  for (int i = 0; i < smallSize; i++) {
    output[i + smallSize][0] = output[i][0] + 1;
    output[i + smallSize][1] = input[startIndex];
    for (int j = 1; j <= output[i][0]; j++) {
      output[i + smallSize][j + 1] = output[i][j];
    }
  }
  return 2 * smallSize;
}

int subset(int input[], int n, int output[][20]) {
  return subset(input, n, 0, output);
}

int main() {
  int input[20],length, output[35000][20];
  
  length = 3;
  int arr[] = {1, 2, 3, 4, 5, 6};

  for(int i=0; i < length; i++)
    input[i] = arr[i];
  
  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) {
    cout << output[i][0] << "||";
    for( int j = 1; j <= output[i][0]; j++) {
      cout << output[i][j] << " ";
    }
  cout << endl;
  }
}