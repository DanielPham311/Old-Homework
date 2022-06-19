#include <iostream>
#include "function.h"

using namespace std;

node *create(int value) //Function for creating a new node 
{
    node *newnode = new node;

    if (newnode == nullptr)
    {
        cout << "Memory allocation error";
        return NULL;
    }
    else
    {
        newnode->value = value;
        newnode->next = nullptr;
        return newnode;
    }     
}

void AddHead(node *&head, int value) //Fucntion: adding a node to the head of a list
{
    node *oldhead = head;
    head = create(value);
    head->next = oldhead;
}

void Print(node *head) //Function: printing the list
{
    while (head != nullptr)
    {
        cout << head->value << " ";
        head = head->next;
    }
}

void DestroyList(node *&head) //Function: destroying the list
{
    node *cur = head;
    node *next = nullptr;

    while (cur!=nullptr)
    {
        next = cur->next;
        delete cur;
        cur = next;
    }
    head = nullptr;
}