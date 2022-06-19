#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main () {
    double M,q,L,T;
    int n;

    cout << "Nhap so tien can gui (don vi la dong): \n";
    cin >> M;

    cout << "Cho biet so thang gui: \n";
    cin >> n;

    cout << "Cho biet lai suat (nhap theo dinh dang so thuc,vd: 0.01): \n";
    cin >> q;

    T = M*pow((1+q),n);
    L = T - M;

    cout << "So tien lai cua ban sau " << n << "thang la: " << fixed << setprecision(3) << L << "dong \n";

          return 0;
}