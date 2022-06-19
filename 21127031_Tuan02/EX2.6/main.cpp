#include <iostream>
#include "function.h"

using namespace std;

int main()
{
    int array[MAX], target;
    ArrayInput(array, size);
    cout << "Target number: ";
    cin >> target; 

    if (GroupSum(0, array, target))
        cout << "true";
    else cout << "false";
}