#include <iostream>
#include <stdlib.h>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
};
//create node
struct node* create(int value){
    struct node *newNode=(struct node *) malloc(sizeof(struct node));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

//insert left 
struct node* insertLeft(struct node *root,int value){
    root->left=create(value);
    return root->left;
}
//insert right
struct node* insertRight(struct node *root,int value)
{
    root->right=create(value);
    return  root->right;
}


//preorder traversal
void pre(struct node* root)
{
    if(root==NULL) return;
    cout<<root->data<<" -> ";
    pre(root->left);
    pre(root->right);
    
}
//inorder
void in(struct node *root)
{
    if(root==NULL) return ;
    in(root->left);
    cout<<root->data<<" -> ";
    in(root->right);
}
//post order traversal
void post(struct node *root)
{
    if(root==NULL) return ;
    post(root->left);
    post(root->right);
    cout<<root->data<<" -> ";
    
}
bool isFullBinary(struct node *root) {
    // Check empty
    if (root == NULL) return true;
    
    // Checking the presence of children
    if (root->left == NULL && root->right == NULL) return true;
    
    // If both left and right are not NULL, and both subtrees are full
    if (root->left != NULL && root->right != NULL) {
        return isFullBinary(root->left) && isFullBinary(root->right);
    }
    // If one child is NULL and the other is not, it's not a full binary tree
    return false;
}

// perfect binary tree
// Function to calculate the depth (or height) of the tree
int depth(struct node *root) {
    int d = 0;
    // Traverse the leftmost path to calculate depth
    while (root != NULL) {
        d++;
        root = root->left;
    }
    return d;
}

// Recursive function to check if the tree is perfect
bool cheakPerfect(struct node *root, int d, int level) {
    // An empty tree is perfect
    if (root == NULL) return true;

    // If this is a leaf node, check if it is at the correct depth
    if (!root->left && !root->right) return (d == level + 1);

    // If the node has one child missing, it is not a perfect tree
    if (!root->left || !root->right) return false;

    // Recursively check the left and right subtrees
    return cheakPerfect(root->left, d, level + 1) && cheakPerfect(root->right, d, level + 1);
}

// Function to check if the tree is perfect
bool isPerfect(struct node *root) {
    // Calculate the depth of the tree
    int d = depth(root);
    // Start the recursive check from the root at level 0
    return cheakPerfect(root, d, 0);
}


//complete binary tree - left shifted 
// Function to calculate the total number of nodes in the tree
int totalNodeNumber(struct node *root) {
    if (!root) return 0;
    // Recursively count the nodes in the left and right subtrees and add 1 for the current node
    return (1 + totalNodeNumber(root->left) + totalNodeNumber(root->right));
}

// Recursive function to check if the tree is complete
bool isComplete(struct node *root, int index, int totalNodeNumber) {
    // An empty tree is complete
    if (root == NULL) return true;

    // If the index of the current node is greater than or equal to the total number of nodes, the tree is not complete
    if (index >= totalNodeNumber) return false;

    // Recursively check the left and right subtrees
    return (isComplete(root->left, 2 * index + 1, totalNodeNumber) && isComplete(root->right, 2 * index + 2, totalNodeNumber));
}

// Function to check if the tree is a complete binary tree
bool isCompleteBinary(struct node *root) {
    // Calculate the total number of nodes in the tree
    int t = totalNodeNumber(root);
    // Start the recursive check from the root node at index 0
    return isComplete(root, 0, t);
}

/ Check for height balance
bool checkHeightBalance(struct node *root, int *height) {
  // Check for emptiness
  int leftHeight = 0, rightHeight = 0;
  int l = 0, r = 0;

  if (root == NULL) {
    *height = 0;
    return 1;
  }

  l = checkHeightBalance(root->left, &leftHeight);
  r = checkHeightBalance(root->right, &rightHeight);

  *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

  if ((leftHeight - rightHeight >= 2) || (rightHeight - leftHeight >= 2))
    return 0;

  else
    return l && r;
}
int main()
{
    struct node *root=create(1);
 insertLeft(root, 12);
  insertRight(root, 9);

insertLeft(root->left, 5);
  insertRight(root->left, 6);
  
insertLeft(root->right, 7);
  insertRight(root->right, 8);

  
cout<<isFullBinary(root)<<endl;
cout<<isPerfect(root)<<endl;
cout<<isCompleteBinary(root)<<endl;

  cout<<"preorder"<<endl;
  pre(root);
  cout<<endl;
  cout<<"inorder"<<endl;
  in(root);
  cout<<endl;
  cout<<"postorder"<<endl;
  post(root);
  cout<<endl;
  
        

}
