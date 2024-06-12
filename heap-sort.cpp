#include <bits/stdc++.h>
using namespace std;

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

void buildHeap(int a[], int n) {
    for (int i = n / 2; i > 0; i--) {
        heapify(a, n, i);
    }
}




void heapSort(int a[],int b[],int n){
    buildHeap(a,n);
    int j=1;
    while(j<=n){
        
    }
    
}
void printArray(int a[], int n) {
    for (int i = 1; i <= n; ++i)
        cout << a[i] << " ";
    cout << "\n";
}

int main() {
    int a[] = {-1, 4, 10, 3, 5, 1}; // Index 0 is unused
    int n = sizeof(a) / sizeof(a[0]) - 1; // Adjust for 1-based indexing

    buildHeap(a, n);

    cout << "Heapified array: \n";
    printArray(a, n);


    // heap sort
    int sortedHeap()
    return 0;
}
