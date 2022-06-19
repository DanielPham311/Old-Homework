#include <iostream>
#include "function.h"

using namespace std;

int main()
{
    int a[MAX];
    ArrayInput(a,size);

    if (ArraySplit(a)) 
        cout << "true";
    else cout << "false";
}