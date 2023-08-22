// Highest of 'n' numbers
/*
Algorithm Highest(a, n)
// a is an array containing 'n' elements
{
    res := a[1];
    for i := 2 to n do
        if a[i] > res then res := a[i];
    Return res;
}
 */

// CODE
#include <iostream>
#include <sstream>
using namespace std;

int highest(int *arr, int n) {
    int res = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > res) {
            res = arr[i];
        }
    }

    return res;
}
int main() {
    string str_arr;
    cout << "Enter array elements separated by commas ',': ";
    cin >> str_arr;
    int len = str_arr.length();
    int number_of_elements = len - len / 2;
    int arr[number_of_elements];

    stringstream ss(str_arr);
    string temp;
    int i = 0;
    while (getline(ss, temp, ',')) {
        arr[i] = stoi(temp);
        i++;
    }


    int res = highest(arr, number_of_elements);
    cout << "Highest Number: " << res << endl;
}