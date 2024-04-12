#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int SIZE = 100;
int staticMatrix1[SIZE][SIZE];
int staticMatrix2[SIZE][SIZE];
int staticMatrix3[SIZE][SIZE];

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

void multiplyMatrixNumbers(int matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrix[i][j] = matrix[i][j] * rand() % 100 + 1;
        }
    }
}

void matrixCreation()
{
    // stack dynamic matrices
    int stackDynamicMatrix1[SIZE][SIZE];
    int stackDynamicMatrix2[SIZE][SIZE];
    int stackDynamicMatrix3[SIZE][SIZE];

    fillMatrixWithRandomNumbers(staticMatrix1);
    fillMatrixWithRandomNumbers(staticMatrix2);
    // after we fill we multiply the matrices
    auto startStatic = high_resolution_clock::now();
    multiplyMatrixNumbers(staticMatrix1);
    multiplyMatrixNumbers(staticMatrix2);
    auto stopStatic = high_resolution_clock::now();
    auto durationStatic = duration_cast<microseconds>(stopStatic - startStatic);
    cout << "Time taken by static matrices: " << endl;
    cout << durationStatic.count() << endl;

    fillMatrixWithRandomNumbers(stackDynamicMatrix1);
    fillMatrixWithRandomNumbers(stackDynamicMatrix2);
    // after we fill we multiply the matrices

    auto startDynamic = high_resolution_clock::now();
    multiplyMatrixNumbers(stackDynamicMatrix1);
    multiplyMatrixNumbers(stackDynamicMatrix2);
    auto stopDynamic = high_resolution_clock::now();
    auto durationDynamic = duration_cast<microseconds>(stopDynamic - startDynamic);
    cout << "Time taken by stack dynamic matrices: " << endl;
    cout << durationDynamic.count() << endl;
}

int main(int argc, char const *argv[])
{
    matrixCreation();
    return 0;
}
