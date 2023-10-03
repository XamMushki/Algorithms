/* Given array a[1:n], such that n/2 elements are unique (distinct)
and the other half (n/2) are copies of the single element.
Where 'n' is the number of elements in a[1:n]
To Do: Find the repeated element using multiple apporaches. */
#include <stdlib.h>

#include <iostream>
#include <sstream>

using namespace std;

// Deterministic Approach

int approachOne(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return i;
            }
        }
    }
    // Element not found, which is not possible since in this case,
    // it is certain that there is an element which gets repeated.
    return -1;
}

// Deterministic Approach
int approachTwo(int* arr, int n) {
    // by skipping elements
    // skipping elements while comparing, skip is increased
    // by 1 after every set of comparisons (that is, in the given fashion)
    int skip = 1;
    int i = 0;  // used as index
    while (1) {
        // cout << "i = " << i << "       skip = " << skip << "         i+skip = " << i + skip << endl;
        if (i + skip >= n) {
            i = 0;
            skip++;
        } else {
            if (arr[i] == arr[i + skip]) {
                return i;
            }
        }
        i++;
    }
    return -1;
}

// Randomized Approach

int approachThree(int* arr, int n) {
    // generating indices i and j both between 0 and n-1 randomly.
    while (1) {
        int i = rand() % n;
        int j = rand() % n;
        if (i != j && arr[i] == arr[j]) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n = 9;
    int arr[] = {1, 2, 3, 4, 4, 4};
    cout << "Deterministic Approaches" << endl;
    cout << "Approach 1: Repeated Element is " << arr[approachOne(arr, n)] << endl;
    cout << "Approach 2: Repeated Element is " << arr[approachTwo(arr, n)] << endl;
    cout << "\nRandomized Approach" << endl;
    cout << "Repeated Element is " << arr[approachThree(arr, n)] << endl;
    return 0;
}