#include <iostream>

using namespace std;

const int N = 3;
const int M = 4;

int looped(int number, int maxExcepting) {
    if (number < 0) {
        return (maxExcepting + number % maxExcepting) % maxExcepting;
    }
    
    return number % maxExcepting;
}

void shiftRight(int (&srcMatrix)[N][M] , int n) {
    int destMatrix[N][M];
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            destMatrix[r][c] = srcMatrix[r][looped(c - n, M)];
        }
    }
    
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            srcMatrix[r][c] = destMatrix[r][c];
        }
    }
}

void shiftDown(int (&srcMatrix)[N][M] , int n) {
    int destMatrix[N][M];
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            destMatrix[r][c] = srcMatrix[looped(r - n, N)][c];
        }
    }
    
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            srcMatrix[r][c] = destMatrix[r][c];
        }
    }
}

void printMatrix(int matrix[N][M]) {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            cout << matrix[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int matrix[N][M] = {
        {11, 12, 13, 14},
        {21, 22, 23, 24},
        {25, 26, 27, 28}
    };

    // shiftRight(matrix, 2);
    // shiftRight(matrix, -3);
    shiftDown(matrix, 2);
    // shiftDown(matrix, 11);
    
    printMatrix(matrix);

    return 0;
}
