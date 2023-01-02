#include <iostream>
using namespace std;

int output[35000][20];

int subset(int input[], int n, int startIndex, int output[][20]) {
  if (startIndex == n) {
    output[0][0] = 0;
    cout << "\0"<< endl;
    return 1;
  }


  int smallSize = subset(input, n, startIndex + 1, output);

  for (int i = 0; i < smallSize; i++) {
    output[i + smallSize][0] = output[i][0] + 1;
    output[i + smallSize][1] = input[startIndex];
    for (int j = 1; j <= output[i][0]; j++) {
      output[i + smallSize][j + 1] = output[i][j];
    }
    for (int j = 1; j <= output[i + smallSize][0]; j++) {
      cout << output[i + smallSize][j] << " ";
    }
    cout << endl;
  }
  return 2 * smallSize;
}

int printSubsetsOfArray(int input[], int n) {
  return subset(input, n, 0, output);
}


int main() {
  int input[1000],length;
  length = 3;
  int arr[] = {1, 2, 3, 4, 5, 6};
  for(int i=0; i < length; i++){
    input[i] = arr[i];
  }
  printSubsetsOfArray(input, length);
}
