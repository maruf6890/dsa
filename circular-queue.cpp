#include <iostream>
using namespace std;

const int capacity = 5;
int que[capacity];
int f = -1, r = -1;

bool isFull() {
    return (f == (r + 1) % capacity);
}

bool isEmpty() {
    return (f == -1);
}

void push(int x) {
    if (isFull()) {
        cout << "Queue is full" << endl;
        return;
    } else {
        if (isEmpty()) {
            f = r = 0;
        } else {
            r = (r + 1) % capacity;
        }
        que[r] = x;
    }
}

void pop() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return;
    } else if (f == r) {
        // Only one element was present
        f = r = -1;
    } else {
        f = (f + 1) % capacity;
    }
}

void top() {
    if (!isEmpty()) {
        cout << "Front element: " << que[f] << endl;
    } else {
        cout << "Queue is empty" << endl;
    }
}

int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);  // This should fill the queue.
    push(6);  // This should say the queue is full.
    
    top();    // Front element is 1
    pop();    // Remove 1
    top();    // Front element is 2
    pop();    // Remove 2
    top();    // Front element is 3
    pop();    // Remove 3
    top();    // Front element is 4
    pop();    // Remove 4
    top();    // Front element is 5
    pop();    // Remove 5
    top();    // Queue is empty now

    return 0;
}
