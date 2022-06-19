#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double M,q,T,L; // T la tien thu duoc sau n thang co ca von lan lai; L la tien lai
    int n;

    cout << "Hay nhap so tien ban muon gui (don vi:dong): \n";
    cin >> M;

    cout << "Hay cho biet thoi gian gui (tinh theo thang): \n";
    cin >> n;

    cout << "Hay cho biet lai suat ngan hang (nhap kieu so thuc, vd: 1% => 0.01):  \n";
    cin >> q;

    T = M*pow((1+q),n);
    L = T-M;

    cout << "So tien lai cua ban sau " << n << " thang la: " << fixed << setprecision(1) << L << " dong \n";

    return 0;

}