#include <iostream>
#include "function.h"

using namespace std;

int main()
{
    Student a;
    Input(a);
    Print(a);
    delete []a.Address;
    delete []a.Name;
}