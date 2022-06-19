#include <iostream>
#include <cmath>
#include "function.h"

using namespace std;

void ArrIn(int arr[], int &n)
{
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;

    int *p = arr;
    for (int i=0; i<n; ++i)
    {
        cin >> *(p+i);
    }
}

void ArrayAscend(int arr[], int n)
{
    int *ptr = arr;
    for (int i=0; i<n; ++i)
    {
        for (int j=i+1; j<n; ++j)
        {
            if (abs(*(ptr+i)) < abs(*(ptr+j))) swap(*(ptr+i),*(ptr+j));
        }
    }
}

void Results(int arr[], int n)
{
    int *res = arr;
    cout << "Ba so co tich lon nhat trong mang la: ";
    for (int i=0; i<3; ++i)
    {
        cout << *(res+i) << " ";
    }
}