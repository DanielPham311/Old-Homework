#include <iostream>

using namespace std;

// void ArrayIn(double **a, int &n)
// {
//     cout << "Number of members :";
//     cin >> n;

//     *a = new (nothrow) double[n];
//     if (*a == nullptr) 
//     {
//         cout << "Memory allocation error";
//         return;
//     }
//     else 
//     {
//         for (int i=0; i<n; ++i)
//         {
//             cin >> *(*(a+i));
//         }
//     }
// }

// void ArrayOut(double *a, int n)
// {
//     for (int i=0; i<n; ++i)
//     {
//         cout << a[i] << " ";
//     }
// }

int fibo(int n)
{
    int *a = new (nothrow) int[n+2];
    int r;
    if (a == nullptr)
    {
        cout << "Memory allocation failed";
        return 0;
    } 
    else 
    {
        *a = *(a+1) = 1;
        for (int i=2; i<=n ;++i)
            *(a+i) = *(a+i-1) + *(a+i-2);    
    }
    r = *(a+n);
    delete[] a;
    return r;
}

int fibo2(int n) //space complex la O(1), time la O(n)
{
    int fi,fi1,fi2;
    if (n<2) return 1;
    fi1 = 1;
    fi2 = 2;
    for (int i=2; i<=n; ++i)
    {
        fi = fi1 + fi2;
        fi2 = fi1;
        fi1 = fi;
    }
    return fi;
}

double fibo3(int n)
{
    double *dp = new double [n+1];
    if (dp == nullptr) exit (1);
    if (n<2) return 1;
    double *fi1 = dp+1;
    double *fi2 = dp;
    *fi1 = 1, *fi2 = 1;
    for (double *fi = dp+2; fi <=dp+n; fi++)
    {
        *fi = *fi1 + *fi2;
        fi2 = fi1;
        fi1 = fi;
    }
    double ans = *(dp + n);
    delete[] dp;
    return ans;
}

int bin(int n, int k)
{
    int B[100][100];
    for (int i=0; i<=n; ++i)
        for (int j=0; j<=i; ++j)
        {
            if (j==0 || j==i) B[i][j] = 1;
            else B[i][j] = B[i-1][j-1] + B[i-1][j];
        }
    return B[n][k];
}

int bin2(int n, int k)
{
    int (*p)[100];
    p = (int (*)[100]) new int[(n+1) * (n+1)];
    
}

int main()
{
    int n;
    cin >> n;
    cout << fibo(n);
}