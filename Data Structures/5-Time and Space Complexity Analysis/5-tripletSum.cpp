/*You have been given a random integer array/list(ARR) and a number X. Find and return the triplet(s) in the array/list which sum to X.*/

#include <iostream>
#include <algorithm>
using namespace std;



int compare(const void *_a, const void *_b) {
        int *a, *b;
        a = (int *) _a;
        b = (int *) _b;
        return (*a - *b);
}



int tripletSum(int *arr, int n, int num){
	int count = 0;
    qsort(arr, n, sizeof(int), &compare);

    for(int i = 0, j = 1, k = n-1; i < n-2;){        
        int sum = arr[i] + arr[j] + arr[k];
        cout << arr[i] << " + " << arr[j] << " + " << arr[k] << " = " << sum << endl; 

        if(sum == num){
            for(int z = k; arr[i] + arr[j] + arr[z] == num & z > j; z--){
                count++;
            }
            j++;
            continue;
        }
        else if (sum > num){
            k--;
        }
        else if (sum < num){
            j++;
        }
        if(k <= j){
            i++;
            j = i+1;
            k = n-1;
        }
    }
	return count;
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
    int size = 9;
    int arr[] = {2, -5, 8, -6, 0, 5, 10, 11, -3};
	int x = 10;

	while (t--){
		int *input = new int[size];
		for (int i = 0; i < size; i++){
			input[i] = arr[i];
		}
		cout << tripletSum(input, size, x) << endl;
		delete[] input;
	}

	return 0;
}