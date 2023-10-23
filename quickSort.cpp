#include <iostream>
#include <sstream>
using namespace std;

// void quickSort(int* ar)
void interchange(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(int* arr, int m, int p) {
    int v = arr[m];  // pivot element
    int i = m;       // first index
    int j = p;       // last index
    do {
        do {
            i++;
        } while (arr[i] < v);
        do {
            j--;
        } while (arr[j] > v);
        if (i < j) {
            interchange(arr, i, j);
        }
    } while (i < j);
    arr[m] = arr[j];
    arr[j] = v;
    return j;
}
void quickSort(int* arr, int p, int q) {
    // arr[p:q]
    if (p < q) {
        int j = partition(arr, p, q);
        quickSort(arr, p, j - 1);
        quickSort(arr, j + 1, q);
    }
}

void printArray(int* arr, int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i];
        if (i < arr_size - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}
int main() {
    string array_string;
    cout << "Enter array elements separated by commas ','.\n>> ";
    cin >> array_string;
    stringstream ss(array_string);
    string temp;
    int array_size = (array_string.length() / 2) + 1;
    int arr[array_size];
    int count = 0;
    while (getline(ss, temp, ',')) {
        arr[count] = stoi(temp);
        count++;
    }
    cout << "Array Inserted: ";
    printArray(arr, array_size);
    quickSort(arr, 0, array_size - 1);
    cout << "Array Sorted: ";
    printArray(arr, array_size);

    return 0;
}