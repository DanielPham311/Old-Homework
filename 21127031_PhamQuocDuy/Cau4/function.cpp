#include <iostream>
#include <fstream>
#include "function.h"

using namespace std;

void ReadFromFile(int &Asize, int A[])
{
    ifstream fin;
    fin.open("INP.txt");
    if (fin.is_open())
    {
        fin >> Asize;
        for (int i=0 ; i<Asize; ++i)
        {
            fin >> A[i];
        }
        fin.close();
    }
    else cout << "Unable to open file";
}

int NonDecrease(int Asize, int A[], int B[])
{
    int max, maxlen = 0;
    B[0] = 1;

    for (int i = 1; i<Asize; ++i)
    {
        max = 0;
        for (int j = 0; j < i; ++j)
        {
            if (A[i] >= A[j])
                if (B[j] > max) max = B[j];
        }
        B[i] = max + 1;
    }

    for (int l = 0; l<Asize; ++l)
    {
        if (B[l] > maxlen)
            maxlen = B[l];
    }
    return maxlen;
}

void AnswerOut(int Asize, int A[], int B[])
{
    ofstream fout;
    fout.open("OUT.txt");
    if (fout.is_open())
    {
        fout << NonDecrease(Asize, A, B);
        fout.close();
    }
    else cout << "Unable to open file";
}
