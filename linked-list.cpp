#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// insert at the beginning
void insert(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// inserting in a position
void insertP(int p, int x)
{

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;

    struct node *temp = head;
    for (int i = 2; i < p; i++)
    {
        if (temp->next != NULL)
            temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
// delet first element
void deleteFirst()
{
    if (head != NULL)
    {
        head = head->next;
    }
}
// delete by position
void deleteP(int position)
{
    struct node *temp = head;
    for (int i = 1; i < position - 1; i++)
    {
        if (temp->next != NULL)
            temp = temp->next;
    }
    temp->next = temp->next->next;
}
int Lsearch(int value)
{
    int i = 1;
    struct node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == value)
            return i;
        i++;
        temp = temp->next;
    }
    return -1;
}
// bubble sort
void Lsort()
{
    struct node *current = head;
    if (current == NULL)
    {
    }
    else
    {
        while (current != NULL)
        {
            struct node *index = current->next;
            while (index != NULL)
            {
                if (index->data < current->data)
                {
                    int temporary = current->data;
                    current->data = index->data;
                    index->data = temporary;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}


//linked-list reverse
void reverse() {
    node* prev = nullptr;
    node* current = head;
    node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}


// traverse
void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{

    insert(1);
    insert(2);
    insert(3);
    insert(5);
    insert(3);
    Lsort();
    insertP(4, 4);

    //  deleteFirst();
    // deleteP(2);
    //  lsearch(5);
    display();
    //  cout<<Lsearch(6)<<endl;

    return 0;
}