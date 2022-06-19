#include <iostream>

using namespace std;

int main()
{
    int n,sum,mul,temp;

    sum = 0;
    mul = 1;
    n = 1;

    while (n!=0)
    {
        cout << "\nNhap so nguyen duong n: ";
        cin >> n;

        temp = n;

        if (n<0)
        {
            cout << "Ban da nhap so khong hop le, vui long thu lai";
            return 0;
        }

        while (temp)
        {
            sum += temp % 10;
            mul *= temp % 10;
            temp /= 10;
        }

        if (sum==mul) cout << "Tong cac chu so bang tich cac chu so";
        if (sum!=mul) cout << "Tong cac chu so khong bang tich cac chu so";

        sum = 0;
        mul = 1;
    }
    return 0;
}