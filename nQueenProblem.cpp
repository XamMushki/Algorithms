// Backtracking
// Algorithm for the N-Queen Problem
// Note: N-Queens problem for n = 2 and n = 3 doesn't have any solutions where the queens
// can be placed without attacking each other. The problem only has solutions for n >= 4.
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

// Global
int sol_vector[10];

void show(int n) {
    cout << "Solution Vector: [ ";
    for (int i = 1; i <= n; i++) {
        cout << sol_vector[i] << " ";
    }
    cout << "]" << endl;
}
bool place(int k, int i) {
    /* Returns true if a queen can be placed in kth row and ith column.
    Otherwise it returns false.
    sol_vector[] is a global array whose first k-1 values have been set.
    abs(r) returns the absolute value of r. */
    for (int j = 1; j < k; j++) {
        // for checking whether any of the prev queens is in the same column.
        if (sol_vector[j] == i || abs(sol_vector[j] - i) == abs(j - k)) {
            return false;
        }
    }
    return true;
}
void nQueen(int k, int n) {
    /* Using backtracking this procedure prints
     all possible placements of n-Wueens on an nxn
    chess board so that they are non-attacking. */
    for (int i = 1; i <= n; i++) {
        if (place(k, i)) {
            sol_vector[k] = i;
            if (k == n) {
                show(n);
            } else {
                nQueen(k + 1, n);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of Queens: ";
    cin >> n;

    if (n < 1 || n > 10) {
        cout << "The input value should be between 1 and 10." << endl;
        return 1;
    }
    nQueen(1, n);

    return 0;
}