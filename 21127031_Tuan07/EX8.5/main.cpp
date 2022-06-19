#include <iostream>
#include "function.h"

using namespace std;

int main()
{
    node *current = nullptr;
    //Adding some nodes
    Insert(current,5);
    Insert(current,6);
    Insert(current,1);
    Insert(current,12);
    Insert(current,3);
    Insert(current,9);
    Insert(current,0);
    Insert(current,16);
    cout << "Linked list created: ";
    Print(current); // Printing the list

    cout << "The given value is at position " << Search(current,6) << endl;
    cout << "The given value is at position " << Search(current,0) << endl;
    cout << "The given value is at position " << Search(current,5) << endl;
    cout << "The given value is at position " << Search(current,16) << endl;
    cout << Search(current,69) << endl; //Searching for values, if found return the index, else return -1

    Delete(current,0);
    Delete(current,7);
    Delete(current,16);
    Print(current);
}