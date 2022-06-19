//VCT tính căn bậc ba của một số thực chính xác đến 0.001 
//– áp dụng thuật toán nhị phân, không dùng đến các hàm tính toán
#include <iostream>
#include "mylib.h"

using namespace std;

int main()
{
    double x,y;
    y = 0;

    cout << "Nhap so x can tim can bac 3: ";
    cin >> x;

    ChayKiemTraCanBac3(y,x,1); //Do o hang don vi
    ChayKiemTraCanBac3(y,x,0.1); //Do o hang thap phan 0.1
    ChayKiemTraCanBac3(y,x,0.01); //Do o hang thap phan 0.01
    ChayKiemTraCanBac3(y,x,0.001); //Do o hang thap phan 0.001

    cout << "Can bac 3 cua so " << x << " la: " << y;
    
}