#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int number_of_walsh_codes;
    cout << "Enter Number of Walsh codes to generate: ";
    cin >> number_of_walsh_codes;
    if (log2(number_of_walsh_codes) - int(log2(number_of_walsh_codes)) != 0) {
        // that is, number_of_walsh_codes is not a power of 2
        int i = 0;
        while (1) {
            if (pow(2, i) >= number_of_walsh_codes) {
                number_of_walsh_codes = pow(2, i);
                break;
            }
            i++;
        }
    }

    int hadamard_matrix[number_of_walsh_codes][number_of_walsh_codes];

    cout << "Start with (1/0): ";
    cin >> hadamard_matrix[0][0];
    for (int i = 1; i < number_of_walsh_codes; i += i) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < i; k++) {
                hadamard_matrix[j + i][k] = hadamard_matrix[j][k];
                hadamard_matrix[j][k + i] = hadamard_matrix[j][k];
                hadamard_matrix[j + i][k + i] = 1 - hadamard_matrix[j][k];
            }
        }
    }

    // print the hadamard matrix/ Walsh codes.
    cout << "The " << number_of_walsh_codes << " Walsh Codes are: " << endl;

    for (int i = 0; i < number_of_walsh_codes; i++) {
        for (int j = 0; j < number_of_walsh_codes; j++) {
            cout << hadamard_matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}