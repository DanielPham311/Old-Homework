#include <iostream>
#include <cmath>

using namespace std;

int main ()
{
    double c,dt,tt; // canh, dien tich,the tich HINH LAP PHUONG
    cout << "Hay nhap canh hinh lap phuong: \n";
    cin >> c;

    dt = 6*pow(c,2);
    cout << "Dien tich be mat cua hinh lap phuong: " << dt << "\n";

    tt = pow(c,3);
    cout << "The tich cua hinh lap phuong: " << tt << "\n";

    return 0;



}