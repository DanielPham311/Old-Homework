#include <iostream>
#include "function.h"
#include <fstream>

using namespace std;

int main()
{
    int a[MAX], n,W;
    Array2D f;
    ReadFromFile(a,n,W);
    Solve(a,n,W,f);
    Results(f,n,W,a);
}