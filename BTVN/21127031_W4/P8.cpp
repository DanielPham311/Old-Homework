//Viết chương trình (VCT) nhập ba số nguyên a,b,c. Kiểm tra xem chúng có thứ tự như thế nào (tăng, giảm, hay không tăng cũng không giảm). Sau đó thực hiện các việc:

//Nếu tăng: Giải bất phương trình bậc hai aX^2+bX+c>0
//Nếu giảm: Giải phương trình bậc hai aX^2+bX+c<0
//Không tăng không giảm: Giải phương trình bậc hai aX^2+bX+c=0
#include <iostream>
#include "mylib.h"
#include <cmath>

using namespace std;

int main()
{
    float a,b,c,d;

    cout << "Nhap 3 so nguyen a,b,c: ";
    cin >> a >> b >> c;

    if (a==0) //loai TH a = 0 do khong tinh duoc bat phuong trinh
    {
        cout << "Ban da nhap so khong hop le, vui long thu lai voi so a khac khong";
        return 0;
    }

    if ((a<b)&&(b<c)) //TH cac so tang dan
    {
        cout << "Cac so a,b,c duoc xep theo thu tu tang dan \n";
        BatPhuongTrinhLonHon0(a,b,c);
    }

    else if ((a>b)&&(b>c)) //TH cac so giam dan
    {
        cout << "Cac a,b,c duoc sap xep theo thu tu giam dan\n";
        BatPhuongTrinhNhoHon0(a,b,c);
    }

    else //TH khong tang khong giam
    {
        cout << "Cac so duoc sap xem theo thu tu khong tang/khong giam \n";
        GiaiPTBac2(a,b,c);
    }

}