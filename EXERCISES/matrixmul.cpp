#include <iostream>

using namespace std;

#define MAX 100
typedef int Array2D[MAX][MAX];
typedef int Array1D[MAX];

void Print(Array2D a, int m, int n)
{
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
}

void mulmatrix(Array2D a, Array2D b, Array2D c, int m, int n, int p)
{
    for (int i=0; i<m; ++i)
        for (int j=0; j<p; ++j)
        {
            int s = 0;
            for (int k=0; k<n; ++k)
            {
                s+= a[i][k] * b[k][j];
            }
            c[i][j] = s;
        }
}

void mulmatrix2(Array2D a, Array2D b, Array2D c, int m, int n, int p)
{
    for (int i=0; i<m; ++i)
        for (int j=0; j<p; ++j)
        {
            int s = 0;
            for (int k=0; k<n; ++k)
            {
                //a[i][j] = *(*(a+i) + j)
                s += *(*(a+i) + j) * *(*(b+k) + j);
            }
            *(*(c+i) + j) = s;
        }
}

void mulmatrix3(Array2D a, Array2D b, Array2D c, int m, int n, int p)
{
    Array1D *ai, *bk, *ci;
    ai = a;
    ci = c;
    for (int i=0; i<m; ++i, ai++, ci++)
        for (int j=0; j<p; ++j)
        {
            int s = 0;
            bk = b;
            for (int k=0; k<n; ++k, bk++)
            {
                //a[i][j] = *(*(a+i) + j)
                s += (*(*ai + j)) * (*(*bk + j));
            }
            *(*ci + j) = s;
        }
}

int main()
{
    Array2D a = {{1,2,3} , {4,5,6}};
    Array2D b = {{7,8,9,1} , {2,3,4,5}, {6,7,8,9}};
    Array2D c;
    int m = 2, n=3, p=4;
    mulmatrix(a,b,c,m,n,p);
    Print(c,m,n);
}