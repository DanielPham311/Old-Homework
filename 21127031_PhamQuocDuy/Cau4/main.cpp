#include <iostream>
#include <fstream>
#include "function.h"

using namespace std;

int main()
{
    int A[MAX], B[MAX], Asize;
    ReadFromFile(Asize, A);
    AnswerOut(Asize,A,B);
}