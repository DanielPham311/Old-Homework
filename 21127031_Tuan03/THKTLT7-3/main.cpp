#include <iostream>
#include "function.h"
#include <fstream>

using namespace std;

int main()
{
    int a[MAX], c[MAX], n,W;
    Array2D f;
    ReadFromFile(a,c,n,W);
    Solve(a,c,n,W,f);
    Results(f,n,W,a);
}