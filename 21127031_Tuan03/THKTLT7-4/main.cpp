#include <iostream>
#include "function.h"
#include <fstream>

using namespace std;

int main()
{
    Array2D f, A;
    int rows, cols;
    ReadFromFile(A,rows,cols);
    Results(f,A,rows,cols);
}