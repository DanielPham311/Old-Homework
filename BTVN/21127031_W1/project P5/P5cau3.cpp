#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const double pi= 3.14;
    double h,r,dt,tt; // chieu cao,bkinh,dientich,the tich

    cout << "Nhap chieu cao cua khoi tru tron: \n";
    cin >> h;

    cout << "Nhap ban kinh day khoi tru: \n";
    cin >> r;

    dt = 2*pi*r*(r+h);
    cout << "Dien tich be mat cua khoi tru: " << dt << "\n";

    tt = pi*pow(r,2)*h;
    cout << "The tich cua khoi tru: " << tt << "\n";

    return 0;
}