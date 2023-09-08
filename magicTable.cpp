#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int n;  // used to create nxn magic table (matrix).
    cout << "To create the 'n x n' Magic Table, enter the (ODD) value of n: ";
    cin >> n;
    if (n % 2 == 0) {
        n = n + 1;
        cout << "Changing value of 'n' to " << n << ". (An odd number)" << endl;
    }
    int magicTable[n][n];

    // Initialize with 0's
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            magicTable[i][j] = 0;
        }
    }

    // Magic Table Logic (Algorithm).
    int c = 1;
    int i = 0;
    int j = n / 2;
    while (c <= (n * n)) {
        if (magicTable[i][j] == 0) {
            // that is, value not assigned yet.
            magicTable[i][j] = c;
        } else {
            // value is assigned to the current cell.
            // performing the 'bottom move'
            // for which we first need to revert the changes and add 1 to i.
            // (n-2)th row/col is not affected in any way.
            // so we only need to consider the (n-1)th row/col.
            if (i == (n - 1) || j == (n - 1)) {
                if (i == (n - 1)) {
                    i = 0;
                }
                if (j == (n - 1)) {
                    j = 0;
                }
            } else {
                i++;
                j++;
            }
            i++;
            magicTable[i][j] = c;
        }
        // top left move;
        i--;
        j--;
        if (i < 0) {
            i = n - 1;
        }
        if (j < 0) {
            j = n - 1;
        }

        c++;
    }

    // Print matrix
    cout << "\n"
         << n << "x" << n << " Magic Table\n"
         << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << right << setw(5) << magicTable[i][j] << " ";
        }
        cout << endl;
    }
    // Calculate diagonal/row/column Sum
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += magicTable[0][i];
    }
    cout << "\nRow/Column/Diagonal Sum is " << sum << endl;
    // XM
    return 0;
}