#include <iostream>

using namespace std;

int main()
{
    int k,i,result,f0,f1,f2;

    f0 = 0; f1 = 1; f2 = 1;result = 0;

    cout << "Nhap phan tu thu k ban muon tim?: ";
    cin >> k;

    if (k<0)
    {
        cout << "So k ban nhap khong hop le, vui long thu lai";
        return 0;
    }

    if ((k==1)||(k==2))
    {
        result = 1;
        cout << "So Fibonacci thu " << k << " la: " << result;
        return 0;
    }

    for (int i=3; i<=k; i++)
    {
        result = f1 + f2;
        f1 = f2;
        f2 = result;
    }

    cout << "So Fibonacci thu " << k << " la: " << result;
    return 0;
}