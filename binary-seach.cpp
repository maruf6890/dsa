#include <bits/stdc++.h>
using namespace std;

int binary_search(int a[], int n, int key) {
    int s = 0, e = n - 1;
    
    while (s <= e) {
        int mid = (s + e) / 2;
        if (a[mid] == key) return mid;  // return index of the key
        else if (key < a[mid]) e = mid - 1;
        else s = mid + 1;
    }

    return -1;  // if key is not found
}

int main() {
    int a[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(a) / sizeof(a[0]);
    int key;
    
    cout << "Enter the key to search: ";
    cin >> key;

    int result = binary_search(a, n, key);
    if (result != -1) 
        cout << "Key found at index: " << result << endl;
    else 
        cout << "Key not found" << endl;

    return 0;
}
