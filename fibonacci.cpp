// Fibonacci - nth term.

/*
Algorithm Fibonacci(n){
// Computer the n-th Fibonacci number
if(n <=1)
    write(n);
else{
    fnm1=0; fnm2=1;
    for i := 2 to n do{
        fn := fnm1 + fnm2;
        fnm1 := fnm2;
        fnm2 := fn;
        }
    write(fnm2);
    }
}
 */

#include <iostream>
using namespace std;

int fibonacci(int n) {
    // finding n-th term of the Fibonacci seq.
    if (n <= 1) {
        return n;
    } else {
        // first two terms of the Fibonacci Sequence
        int fib_num1 = 0;
        int fib_num2 = 1;

        for (int i = 2; i < n; i++) {
            int n_num = fib_num1 + fib_num2;
            fib_num1 = fib_num2;
            fib_num2 = n_num;
        }
        return fib_num2;
    }
}

int main() {
    int term;
    cout << "Enter value of 'n' to find nth term of Fibonacci sequence: ";
    cin >> term;
    cout << term << "th Term: " << fibonacci(term) << endl;
    return 0;
}