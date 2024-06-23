#include <bits/stdc++.h>
using namespace std;

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function to place the pivot element in the correct position
int partition(int a[], int l, int h) {
    int pivot = a[l]; // Pivot is the value at the leftmost index
    int i = l + 1;    // Index of smaller element
    int j = h;        // Index of larger element

    // Loop to partition the array
    while (i <= j) {
        // Find an element larger than pivot from the left side
        while (i <= j && a[i] <= pivot) i++;
        // Find an element smaller than or equal to pivot from the right side
        while (i <= j && a[j] > pivot) j--;
        // Swap the found elements
        if (i < j) {
            swap(&a[i], &a[j]);
        }
    }
    // Swap pivot with element at j
    swap(&a[l], &a[j]);
    return j; // Return the partition index
}

// Quick Sort function to sort the array
void quicksort(int a[], int l, int h) {
    if (l < h) {
        int j = partition(a, l, h); // Partition the array
        quicksort(a, l, j - 1);     // Sort the left partition
        quicksort(a, j + 1, h);     // Sort the right partition
    }
}

// Function to print the array
void printArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " "; // Print each element
    }
    cout << endl;
}

// Main function to test the Quick Sort algorithm
int main() {
    int a[] = {10, 7, 8, 9, 1, 5}; // Sample array
    int n = sizeof(a) / sizeof(a[0]); // Calculate the number of elements in the array

    cout << "Unsorted array: ";
    printArray(a, n); // Print the unsorted array

    quicksort(a, 0, n - 1); // Perform Quick Sort

    cout << "Sorted array: ";
    printArray(a, n); // Print the sorted array

    return 0; // End of the program
}
