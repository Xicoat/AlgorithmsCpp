/*You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. 
You need to print their intersection; An intersection for this problem can be defined when 
both the arrays/lists contain a particular value or to put it in other words, when there is 
a common value that exists in both the arrays/lists.You have been given two integer 
arrays/list(ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; 
An intersection for this problem can be defined when both the arrays/lists contain a particular 
value or to put it in other words, when there is a common value that exists in both the arrays/lists.*/


#include <iostream>
#include <algorithm>
using namespace std;

int compare(const void *_a, const void *_b) {
        int *a, *b;
        a = (int *) _a;
        b = (int *) _b;
        return (*a - *b);
}

void intersection(int *arr1, int *arr2, int n, int m) 
{
	qsort(arr1, n, sizeof(int), &compare);
	qsort(arr2, m, sizeof(int), &compare);

	for(int i = 0, j = 0; i < n; ){
		if(arr2[j] < arr1[i]){
			j++;
		}
		if(arr1[i] < arr2[j]){
			i++;
		}
		else if (arr1[i] == arr2[j]){
			cout << arr1[i] << " ";
			i++;
			j++;
		}
	}

}

int main()
{
	int t = 1;
    int size1 = 4, size2 = 5;
    int arr1[] = {5, 5, 5, 5};
    int arr2[] = {5, 5, 5, 5, 5};

	while (t--)	{
		int *input1 = new int[size1];
		for (int i = 0; i < size1; i++)
		{
			input1[i] = arr1[i];
		}
		int *input2 = new int[size2];
		for (int i = 0; i < size2; i++)
		{
			input2[i] = arr2[i];
		}
		intersection(input1, input2, size1, size2);
		delete[] input1;
		delete[] input2;
		cout << endl;
	}

	return 0;
}