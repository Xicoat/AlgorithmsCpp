/*You have been given a random integer array/list(ARR) of size N. Write a function that rotates 
the given array/list by D elements(towards the left).*/

#include <iostream>
using namespace std;

void invert(int *input, int start, int end){
    for(int i = start, j = end; i < j; i++, j--){
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }
}

void rotate(int *input, int d, int n){
    invert(input, 0, n-1);
    invert(input, 0, n-1-d);
    invert(input, n-d, n-1);
}


int main()
{
	int t = 1;
    int size = 7;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int d = 2;
	
	while (t--){
		int *input = new int[size];

		for (int i = 0; i < size; ++i){
			input[i] = arr[i];
		}
		rotate(input, d, size);
		for (int i = 0; i < size; ++i){
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}
	return 0;
}