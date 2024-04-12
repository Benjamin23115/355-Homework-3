#include <iostream>

using namespace std;

const int SIZE = 100;

// Function to create static matrices
void createStaticMatrices()
{
    static int staticMatrix1[SIZE][SIZE];
    static int staticMatrix2[SIZE][SIZE];
    static int staticMatrix3[SIZE][SIZE];

    fillMatrixWithRandomNumbers(staticMatrix1);
    fillMatrixWithRandomNumbers(staticMatrix2);
}

// Function to create stack dynamic matrices
void createStackDynamicMatrices()
{
    int stackDynamicMatrix1[SIZE][SIZE];
    int stackDynamicMatrix2[SIZE][SIZE];
    int stackDynamicMatrix3[SIZE][SIZE];

    fillMatrixWithRandomNumbers(stackDynamicMatrix1);
    fillMatrixWithRandomNumbers(stackDynamicMatrix2);
}

// Function to fill a matrix with random numbers in the range of 1 to 100
void fillMatrixWithRandomNumbers(int matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrix[i][j] = rand() % 100 + 1;
        }
    }
}

int main(int argc, char const *argv[])
{
    // Create static matrices
    createStaticMatrices();
    // Create stack dynamic matrices
    createStackDynamicMatrices();

    return 0;
}
