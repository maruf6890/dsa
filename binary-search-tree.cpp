#include <iostream>
#include <stdlib.h>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node
struct node* create(int data) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to insert a new node in the BST
struct node* insert(struct node *root, int data) {
    if (root == NULL) {
        return create(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data >= root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function for in-order traversal of the BST
void in(struct node *root) {
    if (root != NULL) {
        in(root->left);
        cout << root->data << " ";
        in(root->right);
    }
}

// Function to find the node with the minimum value
struct node* nodeMinValue(struct node *root) {
    struct node* temp = root;
    while (temp && temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

// Function to delete a node from the BST
struct node* deleteNode(struct node *root, int data) {
    // If tree is empty
    if (root == NULL) return root;

    // Find the node to be deleted
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the in-order successor (smallest in the right subtree)
        struct node *temp = nodeMinValue(root->right);

        // Copy the in-order successor's data to this node
        root->data = temp->data;

        // Delete the in-order successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to find a node in the BST
struct node* find(struct node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return find(root->left, data);
    } else {
        return find(root->right, data);
    }
}

int main() {
    struct node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);

    cout << "In-order traversal of the original tree: ";
    in(root);
    cout << endl;

    // Deleting a node
    root = deleteNode(root, 10);
    cout << "In-order traversal after deleting 10: ";
    in(root);
    cout << endl;

    // Finding a node
    int valueToFind = 6;
    struct node* foundNode = find(root, valueToFind);
    if (foundNode != NULL) {
        cout << "Node with value " << valueToFind << " found in the tree." << endl;
    } else {
        cout << "Node with value " << valueToFind << " not found in the tree." << endl;
    }

    return 0;
}
