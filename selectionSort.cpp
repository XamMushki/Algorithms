// Selection Sort
/*
Algorithm SelectionSort(arr, n)
// Sorting the elements of array 'arr' containing 'n' elements
// in non-decreasing order.
{
    for i := 1 to n do
    {
        j := i;
        for k := i+1 to n do
            if arr[k] < arr[j] then j := k;
        temp := arr[i];
        arr[i] := arr[j];
        arr[j] := temp;
    }
}
 */

// CODE
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void printArray(int *arr, int n) {
    cout << "Array : [";
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    ;
}

void selectionSort(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        int j = i;
        for (int k = i + 1; k < n; k++) {
            if (arr[k] < arr[j]) {
                j = k;
            }
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
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

    selectionSort(arr, number_of_elements);
    printArray(arr, number_of_elements);
}