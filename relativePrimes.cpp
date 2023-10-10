/* Relatively Prime
When two numbers have no common factors other than 1.
In other words there is no value that you could divide
them both by exactly (without any remainder).
aka: coprime or mutually prime.
*/
#include <iostream>
using namespace std;

// function to find whether two numbers are relatively prime or not.
int areRelativelyPrime(int num1, int num2) {
    // 2-to-smallest (including both) are the possible numbers that could
    // possibly divide any or both of them.
    int smallest = min(num1, num2);
    // we will check if any of numbers from 2-to-smallest (inc. both) divides the
    //  both numbers (num1 and num2).
    for (int i = 2; i <= /* code */
                    smallest;
         i++) {
        if (num1 % i == 0 && num2 % i == 0) {
            return (i);  // NOT Relatively Prime
            // returns the common factor
        }
    }
    return -1;  // Relatively Prime, didn't find any of the common factors.
}

int main() {
    int num1, num2;
    cout << "Relatively Prime" << endl;
    cout << "Enter Number 1: ";
    cin >> num1;
    cout << "Enter Number 2: ";
    cin >> num2;
    int res = areRelativelyPrime(num1, num2);
    if (res == -1) {
        cout << num1 << " and " << num2 << " are Relatively Prime." << endl;
    } else {
        cout << num1 << " and " << num2 << " are NOT Relatively Prime.\nBoth are divisible by " << res << endl;
    }

    return 0;
}