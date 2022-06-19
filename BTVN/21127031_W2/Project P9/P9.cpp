//Chuong trinh xac dinh thang trong nam
#include <iostream>

using namespace std;

int main () 
{
    int thang;

    cout << "Nhap vao mot thang bat ky trong nam: ";
    cin >> thang;

    if ((thang<1)||(thang>12)) //Loai nhung truong hop input khong hop le
    {
        cout << "Thang nhap khong hop le";
    }

    else 
    {
        switch (thang) //Phan loai cac thang theo mua
        {
            case(12):
            case(1):
            case(2): cout << "Day la mua dong "; break;
            case(3):
            case(4):
            case(5): cout << "Day la mua xuan "; break;
            case(6):
            case(7):
            case(8): cout << "Day la mua he "; break;
            case(9):
            case(10):
            case(11): cout << "Day la mua thu "; break;

        }
    }
    return 0;
}