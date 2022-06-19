#include <iostream>
#include <fstream>
#include "function.h"

using namespace std;

int main()
{
    Array2D f;
    int A[MAX], B[MAX];
    int M,N;
    ReadFromFile(A,B,M,N);
    Solve(f,A,B,M,N);
    Results(f,A,B,M,N);
}