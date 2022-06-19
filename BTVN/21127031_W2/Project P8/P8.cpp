//Chuong trinh tinh tien thue nha
#include <iostream>
#include <string>

using namespace std;

int main () 
{
    int nt,tien;
    string lp;

    cout << "Cho biet so ngay thue: ";
    cin >> nt;

    cout << "Cho biet loai phong: (chi nhap A,B hoac C) ";
    cin >> lp;

    if ((nt<=0)) //Loai nhung TH ngay thue khong hop le
    {
        cout << "Ngay thue khong hop le \n";
        return 0;
    }

    else 
    {

        if (lp=="A") //TH thue phong A
        {
            if (nt>12) //Thue hon 12 ngay
            {
                tien = nt * 400000;
                tien = tien*0.9;
            }

            else 
            {
                tien = nt * 400000;
            }
        }

        if (lp=="B") //TH thue phong B
        {
            if (nt>12) //Thue hon 12 ngay
            {
                tien = nt * 300000;
                tien = tien*0.92;
            }

            else 
            {
                tien = nt * 300000;
            }
        }

        if (lp=="C") //TH thue phong C
        {
            if (nt>12) //Thue hon 12 ngay
            {
                tien = nt * 250000;
                tien = tien*0.92;
            }

            else 
            {
                tien = nt * 250000;
            }
        }
    }

    cout << "Tien thue cua ban la: " << tien << " dong ";
    return 0;
}
