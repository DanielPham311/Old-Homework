//Chuong trinh giai bieu thuc (x^2+1)^n voi input x,n
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main () 
{
    int n;
    float x,a;

    cout << "Nhap so nguyen duong n: ";
    cin >> n;

    cout << "Nhap so thuc x: ";
    cin >> x;


    a = pow((x*x+1),n); //bieu thuc a= (x^2+1)^n

    cout << "Gia tri cua bieu thuc la: " << fixed << setprecision(3) << a;
    return 0;

}