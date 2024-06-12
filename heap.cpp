#include <bits/stdc++.h>
using namespace std;

const int capacity = 10; // maximum capacity of the heap
int heap[capacity + 1]; // heap array (1-based index)
int index = 0; // current number of elements in the heap

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

void deleteElement(){
    if(index>0){

        heap[1]=heap[index];
        int i=1;
        while(i<=capacity)
        {
            int l=i*2;
            int r=i*2+1;
            int largest =(heap[l]<=heap[r]) ? 2*i :  2*i+1;
            if(largest>heap[i]) {swap(heap[largest],heap[i]); i=largest;}
            else return;

        }

    }
}

int main() {
    insert(heap, 3);
    insert(heap, 9);
    insert(heap, 2);
    insert(heap, 1);
    insert(heap, 4);
    insert(heap, 5);

    // Print the heap
    for (int i = 1; i <= index; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;

    return 0;
}
