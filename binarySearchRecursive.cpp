#include <iostream>
#include <sstream>
using namespace std;

int binarySearch(int *arr, int start, int end, int key) {
    // Recursive Binary search algorithm to find 'key' in arr.
    if (start == end) {
        if (arr[start] == key) {
            return start;
        }
        return -1;
    } else {
        int mid = (start + end) / 2;  // integer/floor division
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            // end := mid-1;
            return binarySearch(arr, start, mid - 1, key);
        } else {
            // lessthan condition is true...
            // start := mid+1;
            return binarySearch(arr, mid + 1, end, key);
        }
    }
}

int main() {
    string user_input;
    cout << "Enter elements of array in non-decreasing order, separated by commas ','.\n>>> ";
    cin >> user_input;
    int arr_len = (user_input.length() / 2) + 1;
    int arr[arr_len];

    stringstream ss(user_input);
    string temp;
    int c = 0;
    while (getline(ss, temp, ',')) {
        arr[c] = stoi(temp);
        c++;
    }

    int key;
    cout << "Enter key to find: ";
    cin >> key;
    int index = binarySearch(arr, 0, arr_len - 1, key);
    if (index == -1) {
        cout << key << " not found." << endl;
    } else {
        cout << key << " found at index " << index << endl;
    }
    return 0;
}