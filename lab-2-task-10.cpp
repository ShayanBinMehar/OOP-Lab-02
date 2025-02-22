#include <iostream>

using namespace std;

int** createMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void inputMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element at [" << i << "][" << j << "]: ";
            cin >> *(*(matrix + i) + j);
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << *(*(matrix + i) + j) << " ";
        }
        cout << endl;
    }
}

void transposeMatrix(int** matrix, int** transpose, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            *(*(transpose + j) + i) = *(*(matrix + i) + j);
        }
    }
}

int main() {
    int rows, cols;

    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    int** matrix = createMatrix(rows, cols);
    int** transposeM = createMatrix(cols, rows); 

    cout << "Enter elements of the matrix:" << endl;
    inputMatrix(matrix, rows, cols);

    transposeMatrix(matrix, transposeM, rows, cols);

    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matrix, rows, cols);

    cout << "\nTranspose Matrix:" << endl;
    printMatrix(transposeM, cols, rows); 

    deleteMatrix(matrix, rows);
    deleteMatrix(transposeM, cols);

    return 0;
}