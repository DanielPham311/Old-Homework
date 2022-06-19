#include <iostream>
#include "function.h"

using namespace std;

node *create(int data) //Function: creating a node
{
    node *newnode = new node;
    if (newnode == nullptr) return NULL;
    else 
    {
        newnode->value = data;
        newnode->next = nullptr;
        newnode->prev = nullptr;
    }
    return newnode;
}

void Insert(node *&current, int value) //Function: Inserting a node into the list
{
    node *newnode = create(value);
    if (current == nullptr) //empty list
    {
        newnode->next = newnode;
        newnode->prev = newnode;
    }

    else if (current->next == nullptr && current->prev == nullptr && current != nullptr)// only one node in list
    {
        current->next = newnode;
        current->prev = newnode;
        newnode->next = current;
        newnode->prev = current;
    } 

    else if (current != nullptr)
    {
        newnode->next = current->next;
        newnode->prev = current;
        current->next->prev = newnode;
        current->next = newnode;
    }
    
    current = newnode;
}

void Print(node *current) // Function: printing the list
{
    current = current->next;
    node *start = current->prev;
    while (current->value != start->value)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << current->value << endl;
}

int Search(node *current, int key) //Function: searching for a key in the list, return -1 if not found
{
    current = current->next;
    node *temp = current->prev;
    int ind = 0;

    if (current->value == key) return ind;

    while (current->value != temp->value)
    {
        if (current->value == key) return ind;
        ind++;
        current = current->next;
    }

    if (current->value == key) return ind;
    return -1;
}

void Delete(node *&current, int pos) //Function: deleting a node at a specific position
{
    current = current->next;
    node *temp = current;
    node *start = current->prev;
    int ind = 0;

    while (ind != pos && temp->value != start->value)
    {
        ind++;
        temp = temp->next;
    }

    if (temp->value == start->value) return;
    else if (pos != ind) return;
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
}