#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    float cd,cr,C,S;

    cout << "Nhap chu vi cua hinh chu nhat: \n";
    cin >> C;

    cr = C/5;
    cd = 1.5*cr;

    S = cd*cr;

    cout << "Dien tich hinh chu nhat la: " << S;

    return 0;
}