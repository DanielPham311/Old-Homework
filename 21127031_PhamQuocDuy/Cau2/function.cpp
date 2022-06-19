#include <iostream>
#include "function.h"

using namespace std;

int CalcSum(int n)
{
    if (n==1) return n;
    else return CalcSum(n-1) + n;
}

int Calcxn(int n)
{
    if (n==1) return 1;
    else return (n)*(CalcSum(Calcxn(n-1)));
}
