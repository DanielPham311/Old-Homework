#include <iostream>
#include <string>

using namespace std;

typedef void (*TPF)(float[], int);

void PrintArray(float a[], int n)
{
    float *ptr = a;
    for (int i=0; i<n; ++i, ++ptr)
    {
        cout << *ptr << " ";
    }
}

void Sort(float a[], int n)
{
    float *pi, *pj;
    float *piend = a+n - 1;
    float *pjend = a + n;
    for (pi = a; pi < piend; ++pi)
        for (pj = pi+1; pj < pjend; ++pj)
        {
            if (*pi > *pj) swap(*pi,*pj);
        }
}

void DoTask(float a[], int n, TPF pf)
{
    pf(a,n);
}

void DoTaskList(float a[], int n, TPF tasks[], int m)
{
    TPF *p = tasks;
    for (int i=0; i<m; ++i,++p)
    {
        (*p)(a,n);
    }
}

int main()
{
    float a[] = {0,2,4,5,23,6,9};
    int n = 7;
    // DoTask(a,n,PrintArray);
    // DoTask(a,n,Sort);
    // cout << endl;
    // DoTask(a,n,PrintArray);
    TPF tasks[] = {PrintArray, Sort, PrintArray};
    int m = 3;
    DoTaskList(a,n,tasks,m);
}