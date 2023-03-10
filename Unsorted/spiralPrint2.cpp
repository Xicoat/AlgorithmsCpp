#include <iostream>
using namespace std;


void spiralPrint(int **input, int nRows, int mCols){
    if (nRows == 0 || mCols == 0){
        return;
    }
    
    int i, rowStart = 0, colStart = 0;
    int numElements = nRows * mCols, count = 0;
    
    while (count < numElements){
        for (i = colStart; count < numElements && i < mCols; ++i){
            cout << input[rowStart][i] << " ";
            count++;
        }
        rowStart++;
        
        for (i = rowStart; count < numElements && i < nRows; ++i){
            cout << input[i][mCols - 1] << " ";
            count++;
        }
        mCols--;
        
        for (i = mCols - 1; count < numElements &&  i >= colStart; --i){
            cout << input[nRows-1][i] << " ";
            count++;
        }
        nRows--;
        
        for (i = nRows - 1; count < numElements && i >= rowStart; --i ){
            cout << input[i][colStart] << " ";
            count++;
        }
        
        colStart++;
        
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