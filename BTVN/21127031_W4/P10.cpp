// Xác định phần tử thứ k của dãy Fibonacci:  F(0)=0;  F1=(1);  F(n)=F(n-1)+F(n-2) 
#include <iostream>
#include "mylib.h"

using namespace std;

int main()
{
    int k;

    cout << "Nhap phan tu thu k ban muon tim? ";
    cin >> k;

    if (k<0) //Loai TH k duoc nhap la so am
    {
        cout << "So k ban nhap khong hop le, vui long thu lai";
        return 0;
    }

    cout << "So Fibonacci thu " << k << " la: " << TimSoFibonacci(k);
}