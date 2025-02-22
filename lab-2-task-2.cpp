#include <iostream>

using namespace std;

int** createMatrix(int row, int colomn) {
    
    int** matrix = new int*[row];
    for (int i = 0; i < row; ++i) {
        
        matrix[i] = new int[colomn];
    }
    
    return matrix;
}

void deleteMatrix(int** ptr, int row, int colomn) {

    for(int x = 0; x < row; x++) {

        delete[] ptr[x];
    }
    delete[] ptr;
}

void inputMatrix(int** ptr, int row, int colomn) {

    for(int x = 0; x < row; x++) {

        for(int y = 0; y < colomn; y++) {

            cout << "Enter the number in the matrix cordinate (" << x+1 << ", " << y+1 << ") ";
            cin >> ptr[x][y];
        }
    }
}

void printMatrix(int** ptr, int row, int colomn) {

    for(int x = 0; x < row; x++) {
        cout << " | ";
        
        for(int y = 0; y < colomn; y++) {

            cout << ptr[x][y];
            cout << " | ";
        }
        cout << endl;
    }
}

void additionMatrix(int** ptr1, int** ptr2, int** ptr3, int row, int colomn) {

    for(int x = 0; x < row; x++) {

        for(int y = 0; y < colomn; y++) {

            ptr3[x][y] = ptr1[x][y] + ptr2[x][y];
        }
    }
}

void SubtractMatrix(int** ptr1, int** ptr2, int** ptr3, int row, int colomn) {

    for(int x = 0; x < row; x++) {

        for(int y = 0; y < colomn; y++) {

            ptr3[x][y] = ptr1[x][y] - ptr2[x][y];
        }
    }
}
void multiplyMatrices(int** ptr1, int** ptr2, int** ptr3, int row, int colomn) {
    
    for (int i = 0; i < row; ++i) {

        for (int j = 0; j < colomn; ++j) {
            
            ptr3[i][j] = 0;
            for (int k = 0; k < colomn; ++k) {

                ptr3[i][j] += ptr1[i][k] * ptr2[k][j];
            }
        }
    }
}


int main() {

    int row, colomn;
    int** matrix1;
    int** matrix2;
    int** addMatrix;
    int** subMatrix;
    int** multiplyMatrix;

    cout << "Enter the row for the matrix" << endl;
    cin >> row;

    cout << "Enter the colomn for the matrix" << endl;
    cin >> colomn;

    matrix1 = createMatrix(row, colomn);
    cout << "MATRIX 1" << endl;
    inputMatrix(matrix1, row, colomn);
    
    matrix2 = createMatrix(row, colomn);
    cout << "MATRIX 2" << endl;
    inputMatrix(matrix2, row, colomn);

    addMatrix = createMatrix(row, colomn);
    subMatrix = createMatrix(row, colomn);
    multiplyMatrix = createMatrix(row, colomn);

    cout << "ADDTION" << endl;
    cout << "Matrix 1 :" << endl;
    printMatrix(matrix1, row, colomn);
    cout << "Matrix 2 :" << endl;
    printMatrix(matrix2, row, colomn);
    additionMatrix(matrix1, matrix2, addMatrix, row, colomn);
    cout << "Final Matrix :" << endl;
    printMatrix(addMatrix, row, colomn);

    cout << "SUBTRACT" << endl;
    cout << "Matrix 1 :" << endl;
    printMatrix(matrix1, row, colomn);
    cout << "Matrix 2 :" << endl;
    printMatrix(matrix2, row, colomn);
    SubtractMatrix(matrix1, matrix2, subMatrix, row, colomn);
    cout << "Final Matrix :" << endl;
    printMatrix(subMatrix, row, colomn);

    cout << "Multiplication" << endl;
    cout << "Matrix 1 :" << endl;
    printMatrix(matrix1, row, colomn);
    cout << "Matrix 2 :" << endl;
    printMatrix(matrix2, row, colomn);
    multiplyMatrices(matrix1, matrix2, multiplyMatrix, row, colomn);
    cout << "Final Matrix :" << endl;
    printMatrix(multiplyMatrix, row, colomn);

    deleteMatrix(matrix1, row, colomn);
    deleteMatrix(matrix2, row, colomn);
    deleteMatrix(addMatrix, row, colomn);
    deleteMatrix(subMatrix, row, colomn);
    deleteMatrix(multiplyMatrix, row, colomn);
}