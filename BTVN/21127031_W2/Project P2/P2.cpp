//Chuong trinh giai phuong trinh bac hai ax^2+bx+c
#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    float a,b,c,d,x1,x2,delta,subdelta;

    cout << "Nhap cac so a,b,c cua phuong trinh bac 2: ";
    cin >> a >> b >> c;

    if ((a==0)&&(b==0)) //Xet TH ca a va b bang 0
    {
        cout << "Phuong trinh vo nghia ";
    } 
    
    else if ((a==0)) //Xet TH chi co a = 0
    {
        d = -c/b;
        cout << "Phuong trinh co nghiem duy nhat la: " << d;
    }

    else 
    {
        delta = b*b - 4*a*c;

        if (delta<0) //TH delta am
        {
            cout << "Phuong trinh vo nghiem ";
        }

        if (delta==0) //TH delta = 0
        {
            d = x1 = x2 = -b/(2*a);
            cout << "Phuong trinh co nghiem kep la: " << d;
        }

        if (delta>0) //TH delta >0
        {
            subdelta = sqrt(delta);
            x1 = (-b + subdelta)/ (2*a);
            x2 = (-b - subdelta)/ (2*a);
            
            cout << "Phuong trinh co hai nghiem phan biet: " << x1 << " " << x2;

        }
    }
    return 0;
}