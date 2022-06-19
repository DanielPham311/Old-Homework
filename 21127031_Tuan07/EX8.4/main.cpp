#include <iostream>
#include "function.h"

using namespace std;

int main()
{
    node *head = nullptr;
    //Adding some values to the list
    Append(head,2);
    node *oldhead = head;
    Append(head,1);
    Append(head,9);
    Append(head,3);
    Append(head,4);
    Print(head);

    head->next = oldhead; //case 1: linking the last node of the list to the first node
    //head->next = nullptr; //case 2: last node isn't linked to any node before in the list

    if (ContainCycle(head)) cout << "\nList contains cycle" << endl;
    else cout << "\nList does not contain cycle" << endl;
    DestroyList(head);
}