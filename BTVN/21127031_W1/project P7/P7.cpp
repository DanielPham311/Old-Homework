#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main ()
{
    int n;
    float x,A;

    cout << "Nhap so nguyen duong n: \n";
    cin >> n;

    cout << "Nhap so thuc x: \n";
    cin >> x;

    A = pow((x*x+1),n);

    cout << "Gia tri cua bieu thuc la: " << fixed << setprecision(3) << A << "\n";
    return 0;



}