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

void Append(node *&head, int value) //Function: appending a node to the end of a linked list
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

void Delete(node *&head, int key) //Function: deleting a key in a linked list
{
    if (head == nullptr) return;

    if (head->value == key)
    {
        node *temp = head;
        head = head->next;
        delete temp;
    }

    else 
    {
        node *prevNode = nullptr;
        node *curNode = head;

        while (curNode != nullptr && curNode->value != key)
        {
            prevNode = curNode;
            curNode = curNode->next;
        }

        if (curNode != nullptr)
        {
            prevNode->next = curNode->next;
            delete curNode;
        }
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

void Print(node *head) //Function: printing the list
{
    while (head != nullptr)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

node *Reverse(node *head) //Function: Deleting the list
{
    node *cur = head;
    node *prev = nullptr;
    node *next = nullptr;

    while (cur != nullptr)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    return head;
}

int Search(node *head, int key) //Function: Searching for a key in the list, return -1 if not found
{
    int ind = 0;
    node *nodeptr = head;

    while (nodeptr != nullptr && nodeptr->value != key)
    {
        nodeptr = nodeptr->next;
        ind++;
    }

    if (nodeptr != nullptr) return ind;
    else return -1;
}

void Insert(node *&head, int value, int pos) //Function: Inserting a node into a specific position
{
    node *newnode = create(value);
    if (head == nullptr)
    {
        head = newnode;
        return;
    }

    else if (pos == 0)
    {
        node *oldhead = head;
        head = newnode;
        head->next = oldhead;
    }

    else
    {
        pos -= 1;
        int ind = 0;

        node *temp = head;
        while (temp != nullptr && ind != pos)
        {
            temp = temp->next;
            ++ind;
        }

        if (ind != pos)
        {
            Append(head,value);
        }

        else 
        {
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}

void DeletePos(node *&head, int pos) //Function: deleting a node in a specific position
{
    node *temp = head;
    if (head == nullptr)
        return;
    else if (pos == 0)
    {
        head = head->next;
        delete temp;
    }

    else 
    {
        int ind = 0;
        node *prev = nullptr;
        while (temp != nullptr && ind != pos)
        {
            prev = temp;
            temp = temp->next;
            ind++;
        }

        if (ind != pos && temp == nullptr) return;
        else if (temp!=nullptr)
        {
            prev->next = temp->next;
            delete temp;
        }
    }
}