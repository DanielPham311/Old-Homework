//VCT tìm ước số chung lớn nhất của 2 số nguyên dương M và N.
#include <iostream>
#include "mylib.h"

using namespace std;

int main()
{
    int M,N;

    cout << "Nhap hai so nguyen duong M va N: ";
    cin >> M >> N;

    if ((M<=0)||(N<=0)) //Loat TH M va N khong thoa dieu kien
    {
        cout << "Cac so da duoc nhap khong hop le, vui long nhap lai";
        return 0;
    }

    int result = UocChungLonNhat(M,N);
    cout << "Uoc chung lon nhat cua M va N la: " << result;
}