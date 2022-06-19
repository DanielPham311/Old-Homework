#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    float a,b,c,d,x1,x2,delta,subdelta;

    cout << "Nhap 3 so nguyen a,b,c: ";
    cin >> a >> b >> c;

    if (a==0) 
    {
        cout << "Ban da nhap so khong hop le, vui long thu lai voi so a khac khong";
        return 0;
    }

    delta = b*b - 4*a*c;
    subdelta = sqrt(delta);
    d = (-b/(2*a));

    if ((a<b)&&(b<c))
    {
        cout << "Cac so a,b,c duoc xep theo thu tu tang dan \n";

        if (delta<0)
        {
            if (a<0) cout << "Bat phuong trinh vo nghiem\n";
            if (a>0) cout << "Bat phuong trinh dung voi moi gia tri thuc cua x, x thuoc R\n";
        }

        if (delta == 0)
        {
            if (a<0) cout << "Bat phuong trinh vo nghiem\n";
            if (a>0) cout << "Bat phuong trinh dung voi x thuoc tap nghiem (R hieu " << d << ")\n";
        }

        if (delta > 0)
        {
            x1 = (-b - subdelta) / (2*a);
            x2 = (-b + subdelta) / (2*a);

            if (a>0) cout << "Tap nghiem cua bat phuong trinh la: (x<" << x2 << ") hoac (x>" << x1 << ")";
            if (a<0) cout << "Tap nghiem cua bat phuong trinh la: (" << x2 << ";" << x1 << ")";
        }
        
    }

    else if ((a>b)&&(b>c))
    {
        cout << "Cac a,b,c duoc sap xep theo thu tu giam dan\n";

        if (delta < 0)
        {
            if (a>0) cout << "Bat phuong trinh vo nghiem\n";
            if (a<0) cout << "Bat phuong trinh dung voi moi gia tri thuc cua x, x thuoc R\n";
        }

        if (delta == 0)
        {
            if (a>0) cout << "Bat phuong trinh vo nghiem\n";
            if (a<0) cout << "Bat phuong trinh dung voi x thuoc tap nghiem (R hieu " << d << ")\n";
        }

        if (delta > 0)
        {
            x1 = (-b - subdelta) / (2*a);
            x2 = (-b + subdelta) / (2*a);

            if (a<0) cout << "Tap nghiem cua bat phuong trinh la: (x<" << x1 << ") hoac (x>" << x2 << ")";
            if (a>0) cout << "Tap nghiem cua bat phuong trinh la: (" << x1 << ";" << x2 << ")";
        }
    }

    else 
    {
        cout << "Cac so duoc sap xem theo thu tu khong tang/khong giam \n";

        if (delta < 0) cout << "Phuong trinh vo nghiem";

        if (delta == 0) cout << "Phuong trinh co nghiem duy nhat: " << d;

        if (delta > 0)
        {
            x1 = (-b - subdelta) / (2*a);
            x2 = (-b + subdelta) / (2*a);

            cout << "Phuong trinh co 2 nghiem phan biet: " << x1 << " va " << x2;
        }
    }

    return 0;
}