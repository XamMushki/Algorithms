#include <iostream>
using namespace std;

int factorialIterative(int num) {
    int fact = 1;
    for (int i = num; i > 1; i--) {
        fact *= i;
    }
    return fact;
}
int factorialRecursive(int num){
    if(num<=1){
        return 1;
    }
    return num * factorialRecursive(num-1);
}
int main() {
    int num;
    cout << "Enter number: ";
    cin >> num;
    cout << "Iterative: Factorial of " << num << " is " << factorialIterative(num) << endl;
    cout << "Recursive: Factorial of " << num << " is " << factorialRecursive(num) << endl;
    return 0;
}