#include <iostream>
#include <cmath>

using namespace std;

int main () 
{
    double c,r,s,dt,tt; //chieu cao,chieu rong, chieu sau, dien tich, the tich KHOI HOP
    cout << "Hay nhap chieu cao: \n";
    cin >> c;

    cout << "Hay nhap chieu rong: \n";
    cin >> r;

    cout << "Hay nhap chieu sau: \n";
    cin >> s;

    dt = 2*(r*s+c*s+c*r);
    cout << "Dien tich be mat la: " << dt << "\n";

    tt = c*r*s;
    cout << "The tich la: " << tt << "\n";

    return 0;


}