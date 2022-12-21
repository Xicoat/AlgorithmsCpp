/*You have been given an integer array/list(ARR) and a number 'num'. Find and return the total number of pairs in the array/list which sum to 'num'.
Note:
Given array/list can contain duplicate elements. 
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the first array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Third line contains an integer 'num'.
Output format :
For each test case, print the total number of pairs present in the array/list.

Output for every test case will be printed in a separate line.*/

#include <iostream>
#include <algorithm>
using namespace std;


int compare(const void *_a, const void *_b) {
        int *a, *b;
        a = (int *) _a;
        b = (int *) _b;
        return (*a - *b);
}

int pairSum(int *arr, int n, int num)
{
    int count = 0;
    qsort(arr, n, sizeof(int), &compare);

    for(int i = 0, j = n-1; i < j;){
        int sum = arr[i] + arr[j];
        if(sum == num){
            for(int k = j; arr[i] + arr[k] == num & k > i; k--){
                count++;
            }
            i++;
        }
        else if (sum > num){
            j--;
        }
        else if (sum < num){
            i++;
        }
    }
	return count;
}



int main()
{
	int t = 1;
	while (t--)
	{
		int size = 5;
        int arr[] = {3, 3, 3, 3, 3};
		int x = 6;
		int *input = new int[size];
		for (int i = 0; i < size; i++)
		{
			input[i] = arr[i];
		}
		cout << pairSum(input, size, x) << endl;
		delete[] input;
	}
	return 0;
}


