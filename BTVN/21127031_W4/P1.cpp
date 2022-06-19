//VCT nhập n, k. Tính:

//S1 = 1 + 1/2 + … + 1/n
//S2 = 2/1! - 3/2! + 4/3! - 5/4! + … - (2n+1)/2n!
//S3 = n! / k!(n-k)!   

#include <iostream>
#include "mylib.h"

using namespace std;

int main()
{
    long n,k;

    cout << "Hay nhap lan luot n va k: ";
    cin >> n >> k;

    if (n<=0) //Loai TH khong thoa dieu kien de tinh S1
    {
        cout << "n khong thoa dieu kien de tinh S1 ";
        return 0;
    }
    
    float S1 = TinhTongS1(n);
    cout << "Tong S1 la: " << S1;

    float S2 = TinhTongS2(n);
    cout << "\nTong S2 la: " << S2;

    if ((n<0)||(k<0)||((n-k)<0)) // Loai TH khong thoa de tinh S3
    {
        cout << "\nHai gia tri n va k cua ban khong hop le de tinh S3";
        return 0;
    }

    float S3 = TinhS3(n,k);
    cout << "\nS3 la: " << S3;

}