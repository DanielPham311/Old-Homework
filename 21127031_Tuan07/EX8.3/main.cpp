#include <iostream>
#include "function.h"

using namespace std;

int main()
{
    node *head = nullptr;
    //Adding some values
    Append(head,5);
    Append(head,3);
    Append(head,9);
    Append(head,1);
    Append(head,2);
    Append(head,7);
    Append(head,17);
    Append(head,6);
    Append(head,23);
    Delete(head,9); //deleting a node
    Print(head);

    //head = Reverse(head); //reversing the original list
    //Print(head);

    cout << Search(head,7) << endl;
    cout << Search(head,11) << endl; //Searching for some nodes, return the index if found, else return -1

    Insert(head,16,0);
    Insert(head,12,16);
    Insert(head,77,3); //Inserting some nodes 16,12,77 to position 0,16,3 respectively
    Print(head);

    DeletePos(head,0);
    DeletePos(head,3);
    DeletePos(head,15);
    DeletePos(head,8);//Deleting nodes at position 0,3,8 respectively
    Print(head);

    DestroyList(head);//Destroy the list
}