#include <bits/stdc++.h>
using namespace std;

const int capacity = 10; // maximum capacity of the heap
int heap[capacity + 1]; // heap array (1-based index)
int index = 0; // current number of elements in the heap

// Function to insert a value into the heap
void insert(int a[], int value) {
    if (index >= capacity) {
        cout << "Heap is full!" << endl;
        return;
    }

    // Insert the new value at the end of the heap
    a[++index] = value;
    int i = index;

    // Fix the max heap property if it is violated
    while (i > 1) {
        int parent = i / 2;
        if (a[parent] < a[i]) {
            swap(a[parent], a[i]);
            i = parent;
        } else {
            break;
        }
    }
}

// Function to maintain the max heap property
void heapify(int a[], int n, int i) {
    int largest = i;
    int l = 2 * i;
    int r = 2 * i + 1;

    if (l <= n && a[l] > a[largest]) 
        largest = l;
    if (r <= n && a[r] > a[largest]) 
        largest = r;

    if (largest != i) {
        swap(a[largest], a[i]);
        heapify(a, n, largest);
    }
}

// Function to build a heap from an unsorted array
void buildHeap(int a[], int n) {
    for (int i = n / 2; i > 0; i--) {
        heapify(a, n, i);
    }
}

// Function to delete a specific element from the heap
void deleteElement(int value) {
    int i = 1;
    while (i <= index) {
        if (heap[i] == value) {
            heap[i] = heap[index];
            index--;
            heapify(heap, index, i); // Ensure heap property is maintained after deletion
            break;
        }
        i++;
    }
}

int main() {
    insert(heap, 3);
    insert(heap, 9);
    insert(heap, 2);
    insert(heap, 1);
    insert(heap, 4);
    insert(heap, 5);

    // Print the heap before deletion
    cout << "Heap before deletion: ";
    for (int i = 1; i <= index; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;

    // Delete an element from the heap
    deleteElement(4);

    // Print the heap after deletion
    cout << "Heap after deletion: ";
    for (int i = 1; i <= index; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;

    return 0;
}
