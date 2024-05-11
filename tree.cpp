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

int main()
{
    struct node *root=create(1);
 insertLeft(root, 12);
  insertRight(root, 9);

  insertLeft(root->left, 5);
  insertRight(root->left, 6);
  

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