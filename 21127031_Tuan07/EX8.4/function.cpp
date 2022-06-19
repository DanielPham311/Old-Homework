#include <iostream>
#include "function.h"

using namespace std;

node *create(int value) // Function: creating a node
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

void AddHead(node *&head, int value) // Function: adding a node to the head of a list
{
    node *oldhead = head;
    head = create(value);
    head->next = oldhead;
}

void Append(node *&head, int value) //Function: appending a node to the end of a list
{
    if (head == nullptr)
    {
        head = create(value);
    }

    else 
    {
        node *newnode = create(value);
        node *temphead = head;

        while (temphead->next != nullptr)
        {
            temphead = temphead->next;
        }
        temphead->next = newnode;
        newnode->next = nullptr;
    }
}

void Print(node *head) // Function: printing the list
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

bool ContainCycle(node *head) //Function: checking for a loop in the list using Floyd's tortoise and hare algorithm
{
    if (head == nullptr) return false;

    node *tor = head;
    node *hare = head;

    while (tor != nullptr && hare != nullptr && hare->next != nullptr)
    {
        tor = head->next;
        hare = (head->next)->next;

        if (tor == hare) return true;
    }
    return false;
}