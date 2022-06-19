//Chuong trinh xuat tong cac so trong mot so nguyen n
#include <iostream>

using namespace std;

int main ()
{
    int temp,tong;
    int n;

    cout << "Nhap so nguyen n: ";
    cin >> n;

    if (n<0) n = -n;

    temp = n; //n la bien tam
    tong = 0;

    while (temp != 0) //tach tung so hang tu hang don vi va cong don lai vao bien tong
    {
        tong += temp % 10;
        temp /= 10;
    }

    cout << "Tong cua cac chu so la: " << tong;
    return 0;
}