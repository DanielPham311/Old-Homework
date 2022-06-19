//Một máy ATM đang có 4 loại tiền là 500K, 200K, 100K, 50K. Nhập số tiền muốn rút và 
//liệt kê tất cả các phương án mà máy có thể chi trả. (Ví dụ, nếu rút 200K thì các phương án có thể là:
//#1: 1 tờ 200K; #2: 2 tờ 100K; #3: 1 tờ 100K + 2 tờ 50K; #4: 4 tờ 50K)
#include <iostream>
#include "mylib.h"

using namespace std;

int main()
{
    long n,a,b,c,d;
    
    cout << "Nhap so tien n can rut: ";
    cin >> n;

    if (((n%50000)!=0)||(n<0)) // Loai TH cac so tien duoc nhap khong hop le
    {
        cout << "So tien ban nhap khong nam trong kha nang chi tra cua chung toi, vui long thu lai ";
        return 0;
    }

    RutTien(n,a,b,c,d);
}