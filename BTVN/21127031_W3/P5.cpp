#include <iostream>

using namespace std;

int main()
{
    float x,y;

    cout << "Nhap so x can tim can bac 3: ";
    cin >> x;

    y = 0;

    while ((y*y*y)<=x)
    {
        if ((y*y*y)==x)
        {
            cout << "Vay can bac 3 cua x la: " << y;
            return 0;
        }

        y += 1;
    }

    y -= 1;

     while ((y*y*y)<=x)
    {
        if ((y*y*y)==x)
        {
            cout << "Vay can bac 3 cua x la: " << y;
            return 0;
        }

        y+=0.1;
    }

    y -= 0.1;

     while ((y*y*y)<=x)
    {
        if ((y*y*y)==x)
        {
            cout << "Vay can bac 3 cua x la: " << y;
            return 0;
        }

        y+=0.01;
    }

    y -= 0.01;

    while ((y*y*y)<=x)
    {
        if ((y*y*y)==x)
        {
            cout << "Vay can bac 3 cua x la: " << y;
            return 0;
        }

        y+=0.001;
    }

    y -= 0.001;

    cout << "Vay can bac 3 cua x la: " << y;
    return 0;
}