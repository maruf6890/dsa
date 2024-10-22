#include <bits/stdc++.h>
using namespace std;

// Heapify function to maintain the max heap property
void heapify(int a[], int n, int i) {
    int largest = i;
    int l = 2 * i;
    int r = 2 * i + 1;

    // Check if left child is larger
    if (l <= n && a[l] > a[largest]) 
        largest = l;

    // Check if right child is larger
    if (r <= n && a[r] > a[largest]) 
        largest = r;

    // If the largest element is not the current node
    if (largest != i) {
        swap(a[largest], a[i]);
        heapify(a, n, largest);  // Recursively heapify the affected sub-tree
    }
}

// Function to build the max heap
void buildHeap(int a[], int n) {
    for (int i = n / 2; i > 0; i--) {
        heapify(a, n, i);
    }
}

// Function to implement heap sort
void heapSort(int a[], int n) {
    buildHeap(a, n);  // First, build the heap

    // One by one extract elements from the heap
    for (int i = n; i > 1; i--) {
        // Move current root to the end (largest element)
        swap(a[1], a[i]);
        // Reduce the size of the heap
        n--;
        // Call heapify on the reduced heap
        heapify(a, n, 1);
    }
}

// Function to print the array
void printArray(int a[], int n) {
    for (int i = 1; i <= n; ++i)
        cout << a[i] << " ";
    cout << "\n";
}

int main() {
    int a[] = {-1, 4, 10, 3, 5, 1};  // Index 0 is unused, 1-based indexing
    int n = sizeof(a) / sizeof(a[0]) - 1;  // Adjust for 1-based indexing

    buildHeap(a, n);
    cout << "Heapified array: \n";
    printArray(a, n);

    // Perform heap sort
    heapSort(a, n);
    
    cout << "Sorted array: \n";
    printArray(a, n);

    return 0;
}
