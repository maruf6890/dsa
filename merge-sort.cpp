#include <stdio.h>

void merge(int a[], int l, int r, int mid) {
    // Creating two sub-arrays
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int b[n1];
    int c[n2];
    for (int i = 0; i < n1; i++)
        b[i] = a[l + i];
    for (int i = 0; i < n2; i++)
        c[i] = a[mid + 1 + i];

    // Merging and sorting the array

    int i, j, k;
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (b[i] < c[j]) {
            a[k] = b[i];
            i++;
            k++;
        } else {
            a[k] = c[j];
            j++;
            k++;
        }
    }
    // When common number of elements will be over then
    // pick up the remaining elements
    while (i < n1) {
        a[k] = b[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = c[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int l, int r) {
    if (l >= r)
        return;
    int mid = (l + r) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    merge(a, l, r, mid);
}

int main() {
    int a[] = {6, 5, 12, 10, 9, 1};
    int size = sizeof(a) / sizeof(a[0]);

    mergeSort(a, 0, size - 1);

    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}