#include <iostream>
using namespace std;

int main() {
    int m = 2;
    int n = 3;
    int p = 2;
    int matrix1[m][n] = {{1, 2, 3}, {4, 5, 6}};
    int matrix2[n][p] = {{7, 8}, {9, 10}, {11, 12}};
    int result_matrix[m][p];

    // MATRIX MULTIPLICATION
    // using row major.
    // order of matrices --> m x n and n x p
    // and the resultant matrix will be of order m x p.

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            int temp_sum = 0;
            for (int k = 0; k < n; k++) {
                temp_sum += matrix1[i][k] * matrix2[k][j];
            }
            result_matrix[i][j] = temp_sum;
        }
    }

    // Print the result matrix
    cout << "Matrix: " << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cout << result_matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}