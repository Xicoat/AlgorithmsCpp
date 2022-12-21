#include <iostream>
using namespace std;

void printRow(){
    cout << "printRow";
}

void spiralPrint(int **input, int nRows, int nCols)
{
    
    if(nRows < 0 || nRows > 10000){
        return ;
    } 
    if(nCols < 0 || nCols > 10000){
        return ;
    }
    
    if(nRows == 0 || nCols == 0){
        return;
    }
    
    int rowStart = 0 , rowEnd = nRows-1;
    int columnStart = 0, columnEnd = nCols-1;
    
    int size = (nRows * nCols);
    int s = 0;
    
    while(s < size){

        //Column Up
        for (int i = columnStart; i <= columnEnd && s <= size; i++){
            cout << input[rowStart][i] << " ";
            s++;
        }
        
        rowStart++;

        //Row Up
        for (int i = rowStart; i <= rowEnd && s <= size; i++){
            cout << input[i][columnEnd] << " ";
            s++;
        }
        
        columnEnd--;
        
        //Column Back
        for (int i = columnEnd; i >= columnStart && s <= size; i--){
            cout << input[rowEnd][i] << " ";
            s++;
        }

        rowEnd--;

        //Row Back
        for (int i = rowEnd; i >= rowStart && s < size; i--){
            cout << input[i][columnStart] << " ";
            s++;
        }
        columnStart++;
    }    
}

int main()
{
    int t = 1;
    int row = 4, col = 4;
    int mtrx[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    while (t--)
    {
        int **matrix = new int *[row];

        for (int i = 0; i < row; i++)
        {
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                matrix[i][j] = mtrx[i][j];
            }
        }
        spiralPrint(matrix, row, col);

        for (int i = 0; i < row; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;

        cout << endl;
    }
}