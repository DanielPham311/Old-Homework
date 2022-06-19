#include <iostream>
#include <fstream>
#include "function.h"

using namespace std;

int main()
{
    Array2D a,f;
    int h;
    ReadFromFile(a,h);
    Results(a,f,h);
}