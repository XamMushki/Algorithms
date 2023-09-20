#include <iostream>
#include <sstream>
using namespace std;
int binarySearch(int *arr, int end, int key) {
    // Binary Search using iterative method, that is, using loops instead of recursion.
    int start = 0;
    // Binary search on array arr[start:end]
    while (start <= end) {
        // integer/float division
        int mid = (start + end) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            // that is, key lies on the left side of mid index in arr[]
            // so we need to modify 'end' index.
            end = mid - 1;
        } else {
            // that is, key lies on the right side of mid index in arr[]
            // so we need to modify 'start' index.
            start = mid + 1;
        }
    }
    // element/key not found, so the above return statement is never executed.
    // return with false (-1)
    return -1;
}

int main() {
    string user_input;
    cout << "Enter elements in non-decreasing order, separated by commas ','\n>>> ";
    cin >> user_input;
    int arr_len = (user_input.length() / 2) + 1;
    int arr[arr_len];
    int c = 0;
    stringstream ss(user_input);
    string temp;
    while (getline(ss, temp, ',')) {
        arr[c] = stoi(temp);
        c++;
    }

    int key;
    cout << "Enter key to find: ";
    cin >> key;

    int index = binarySearch(arr, arr_len - 1, key);
    if (index == -1) {
        cout << key << " not found" << endl;
    } else {
        cout << key << " found at index " << index << endl;
    }

    return 0;
}