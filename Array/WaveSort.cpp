#include <bits/stdc++.h>
using namespace std;

void waveSort(int* arr, int n) {
    for (int i = 0; i < n; i += 2) {
        // If the current element is smaller than the previous one, swap them
        if (i > 0 && arr[i] < arr[i - 1]) {
            swap(arr[i], arr[i - 1]);
        }
        
        // If the current element is smaller than the next one, swap them
        if (i < n - 1 && arr[i] < arr[i + 1]) {
            swap(arr[i], arr[i + 1]);
        }
    }
}

void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Input array
    int arr[] = {3, 6, 5, 10, 7, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Print original array
    cout << "Original array: ";
    printArray(arr, n);
    
    // Apply wave sort
    waveSort(arr, n);
    
    // Print wave sorted array
    cout << "Wave sorted array: ";
    printArray(arr, n);

    return 0;
}
