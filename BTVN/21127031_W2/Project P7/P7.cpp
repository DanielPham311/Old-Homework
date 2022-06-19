#include <iostream>

using namespace std;

int main ()
{
    int starth,startm,endh,endm,temptimer1,temptimer2,timer,tien;

    cout << "Nhap gio va phut bat dau truy cap: ";
    cin >> starth >> startm;

    cout << "Nhap gio va phut ngung truy cap: ";
    cin >> endh >> endm;

    if ((starth<0)||(startm<0)||(startm>59)||(endh<0)||(endm<0)||(endh<0))
    {
        cout << "Thong tin nhap vao khong hop le";
        return 0;
    }

    temptimer1 = (starth * 60) + startm;
    temptimer2 = (endh * 60) + endm;
    timer = temptimer2 - temptimer1; // don vi la phut

    if ((starth>=0)&&(endh<7))
    {
        if (timer>120)
        {
            tien = timer * 50;
            tien *= 0.85;
            cout << "So tien phai tra: " << tien << " dong ";
        }

        else 
        {
            tien = timer * 50;
            cout << "So tien phai tra: " << tien << " dong ";
        }
    }

    if ((starth>=7)&&(endh<17))
    {
        if (timer>360)
        {
            tien = timer * 100;
            tien *= 0.9;
            cout << "So tien phai tra: " << tien << " dong ";
        }

        else
        {
            tien = timer * 100;
            cout << "So tien phai tra: " << tien << " dong ";
        }
    }

    if ((starth>=17)&&(endh<24))
    {
        if (timer>240)
        {
            tien = timer * 75;
            tien *= 0.88;
            cout << "So tien phai tra: " << tien << " dong ";
        }

        else 
        {
            tien = timer * 75;
            cout << "So tien phai tra: " << tien << " dong ";
        }
    }

}