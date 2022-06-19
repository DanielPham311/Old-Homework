//VCT nhập các số thực cho đến khi gặp số 0.
// Xác định số lớn nhất.
// Xác định số thực dương nhỏ nhất.
// Xác định số thực âm gần với -123.45 nhất.

#include <iostream>
#include "mylib.h"
#include <cmath>

using namespace std;

int main()
{
    double n = 1,max,min,results,closestnum,closest,distance;
    max = n;
    min = n; //Khoi tao gia tri max va min = n ban dau
    closestnum = -1;
    closest = 1000000; //Ta dat truoc mot nguong so de so sanh

    while (n!=0)
    {
        cout << "Nhap so n khac: ";
        cin >> n;
        if (n==0) break;

        max = TimSoLonNhat(n,max); //goi ham tim so lon nhat trong cac so duoc nhap
        min = TimSoNhoNhat(n,min);//goi ham tim so nho nhat trong cac so duoc nhap
        KhoangCachGanNhat(n,distance,closest,closestnum);//goi ham tim so gan nhat
        
    }

    cout << "So lon nhat la: " << max;
    cout << "\nSo nho nhat la: " << min;
    cout << "\nSo gan nhat voi -123.45 la: " << closestnum;
}