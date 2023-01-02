/*You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
You need to find and return that number which is unique in the array/list.*/

#include <iostream>
using namespace std;


int findUnique(int *arr, int n) {
    int result = 0;
    for (int i = 0; i < n; ++i) {
        result = result ^ arr[i];
    }
    return result;
}


int main() {
    int t = 1;
    int size = 11;
    int arr[] = {6, 3, 7, 5, 1, 3, 5, 1, 7, 9, 6 };

    while (t--) {
        int *input = new int[size];

        for (int i = 0; i < size; ++i) {
            input[i] = arr[i];
        }

        cout << findUnique(input, size) << endl;
    }

    return 0;
}