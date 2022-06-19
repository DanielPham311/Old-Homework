#include <iostream>

using namespace std;

// int a[100]: 100 int array
// int *q[100]: q array of 100 int ptrs

/*
SOL 1:
typedef int Array1D[100];
Array1D *r;
ptr to look over all of the array

int a[100] = {1,4,5,6,7,8,1,0};
    int *p;
    Array1D *q;
    p = a;
    // q = a (fail) different type
    // p = &a (diff types)
    q = &a; //same type
*/

typedef int Array1D[100];
typedef int Array2D[200][100];
typedef Array1D Array2D_2[200];

void func1(Array2D a, int m, int n)
{
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
}

void func2(Array2D_2 a, int m, int n)
{
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
}

void func3(Array1D a[], int m, int n)
{
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
}

void func4(Array1D *a, int m, int n)
{
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
}

int main()
{
    Array2D_2 b = {{1,2} , {3,4}};
    Array2D c = {{3,4} , {5,6}};
    func3(b,2,2);
    // Array1D *q; != int *q[100]
    Array1D *q;  
    int (*r)[100];
    q = r;
    // q=b;
    // q=c;
    // q=&b[0];
    // q = &b[4];
}    