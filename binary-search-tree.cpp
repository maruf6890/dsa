#include <iostream>
#include <stdlib.h>
using namespace std;


struct node{
 int data;
 struct node *left;
 struct node *right;
};
struct node *create(int data)
{
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;

}
struct node *insert(struct node *root,int data)
{
    if(root==NULL) return create(data);
    if(data< root->data)
    root->left=insert(root->left,data);
    if(data> root->data)
    root->right=insert(root->left,data);

}
int main()
{
   





}