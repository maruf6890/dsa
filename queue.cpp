#include <iostream>
using namespace std;

const int capacity = 5;
int que[capacity];
int f = -1, r = -1;

// Check if queue is full
bool isFull() {
    return r == capacity - 1;
}

// Check if queue is empty
bool isEmpty() {
    return f == -1;
}

// Enqueue operation
void push(int x) {
    if (isFull()) {
        cout << "Queue is full" << endl;
    } else {
        if (isEmpty()) {
            f = 0;  // First element being added
        }
        que[++r] = x;
        cout << x << " added to the queue." << endl;
    }
}

// Dequeue operation
void pop() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << que[f] << " removed from the queue." << endl;
        f++;
        if (f > r) {
            f = r = -1;  // Queue is empty after this pop
        }
    }
}

// Print the front element
void top() {
    if (!isEmpty()) {
        cout << "Front element: " << que[f] << endl;
    } else {
        cout << "Queue is empty" << endl;
    }
}

int main() {
    // Testing the queue operations
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);  // This should indicate that the queue is full

    top();    // Front element is 1
    pop();    // Remove 1
    top();    // Front element is 2
    pop();    // Remove 2
    top();    // Front element is 3
    pop();    // Remove 3
    top();    // Front element is 4
    pop();    // Remove 4
    top();    // Front element is 5
    pop();    // Remove 5, queue is empty now
    top();    // Queue is empty

    return 0;
}
