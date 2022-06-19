#include <iostream>
#include "function.h"

using namespace std;

int main()
{
    node *head = nullptr;
    //Adding some nodes to the list
    AddHead(head,5);
    AddHead(head,6);
    AddHead(head,1);
    AddHead(head,9);
    AddHead(head,4);
    AddHead(head,12);
    AddHead(head,33);
    AddHead(head,0);
    Print(head);

    cout << "\nDeleting the list..." << endl;
    DestroyList(head);
    cout << "List deleted successfully" << endl;
    Print(head);
}