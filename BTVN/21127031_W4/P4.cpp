//VCT nhập vào 1 số nguyên dương, kiểm tra xem tổng các chữ số có bằng tích
// và xuất ra thông báo tương ứng, lặp lại việc trên cho đến khi nhập số 0.
#include <iostream>
#include "mylib.h"

using namespace std;

int main()
{
    long n,sum,mul,temp;

    sum = 0; //Gan bien tong ban dau bang 0
    mul = 1; //Gan bien tich ban dau bang 1
    n = 1; // Gan gia tri ban dau cua n khac 0

    while (n!=0)
    {
        cout << "\nNhap so nguyen duong n: ";
        cin >> n;
        if (n==0) break; // Neu n = 0 thoat khoi vong lap

        if (n<0) //Loai TH n duoc nhap khong hop le
        {
            cout << "So ban nhap khong thoa yeu cau, vui long nhap lai";
            return 0;
        }

        bool kiemtra = KiemTra(n,sum,mul); //goi ham de kiem tra tong co bang tich khong
        if (kiemtra==true) cout << "Tong cac chu so bang tich cac chu so";
        if (kiemtra==false) cout << "Tong cac chu so khong bang tich cac chu so";
    }
}