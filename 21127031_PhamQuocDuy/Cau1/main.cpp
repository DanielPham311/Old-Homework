#include <iostream>
#include "function.h"
#include <cmath>

using namespace std;

int main()
{
    int array[MAX];
    int n;
    ArrIn(array,n);
    ArrayAscend(array,n);
    Results(array,n);
}