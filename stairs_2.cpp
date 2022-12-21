/*Staircase
Send Feedback
A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return number of possible ways W.
Input format :
Integer N
Output Format :
Integer W
Constraints :
1 <= N <= 30
Sample Input 1 :
4
Sample Output 1 :
7
Sample Input 2 :
5
Sample Output 2 :
13*/

#include <iostream>
using namespace std;



int stair(int n, int &paths){
    if(n < 0){
        return 0;
    } else if(n == 0){
        paths++;
    }

    stair(n-3, paths);
    stair(n-2, paths);
    stair(n-1, paths);

}


int staircase(int n){

    // base case
    if(n <= 0){
        return 0;
    }

    int paths = 0;
    stair(n-3, paths);
    stair(n-2, paths);
    stair(n-1, paths);

    return paths;
}


int main() {
    int n, output;
    n = 10;
    output=staircase(n);
    cout<< output <<endl;
}
