#include <iostream>

using namespace std;

int main()
{
    int M,N;

    cout << "Nhap hai so nguyen duong M va N: ";
    cin >> M >> N;

    if ((M<=0)||(N<=0))
    {
        cout << "Cac so da duoc nhap khong hop le, vui long nhap lai";
        return 0;
    }

    while (M!=N)
    {
        if (M>N)
        {
            M = M - N;
        }

        else N = N - M;
    }

    cout << "Uoc chung lon nhat cua M va N la: " << M;
}