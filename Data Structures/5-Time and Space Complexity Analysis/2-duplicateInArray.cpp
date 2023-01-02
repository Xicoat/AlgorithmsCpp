/*You have been given an integer array/list(ARR) of size N which contains numbers from 0 to (N - 2). 
Each number is present at least once. That is, if N = 5, the array/list constitutes values ranging 
from 0 to 3, and among these, there is a single integer value that is present twice. You need to 
find and return that duplicate number present in the array.*/


#include <iostream>
using namespace std;


int findDuplicate(int *arr, int n)
{
    int calculated_sum = ((n-1)*(n-2))/2;
    
    int sum = 0;
    for(int i=0; i< n; i++){
        sum += arr[i];
    }

    return (sum - calculated_sum);
}


int main()
{
	int t = 1;
	int arr[] = {5, 5, 1, 6, 8, 3, 0, 2, 7, 4};
    int size = 10;



	while (t--)
	{
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			input[i] = arr[i];
		}

		cout << findDuplicate(input, size) << endl;
	}

	return 0;
}