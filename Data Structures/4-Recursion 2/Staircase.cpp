#include <iostream>
using namespace std;

int stair(int n, int &steps){
    if(n <= 0){
        return 0;
    } else steps++;

    stair(n-3, steps);
    stair(n-2, steps);
    stair(n-1, steps);

}


int staircase(int n){

    // base case
    if(n <= 0){
        return 0;
    }

    int steps = 0;
    stair(n-3, steps);
    stair(n-2, steps);
    stair(n-1, steps);

    return steps;
}


int main() {
    int n, output;
    n = 5;
    output=staircase(n);
    cout<< output <<endl;
}
