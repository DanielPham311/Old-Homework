#include <iostream>

using namespace std;

int main () {
    int n;
    int tam;// bien tam
    int sum = 0;
    cout << "Nhap so nguyen n co 3 chu so: ";
    cin >> n;

    tam = n;
    while (tam !=0) {
        sum += tam % 10;
        tam /= 10;
    }
         cout << "Tong cac chu so cua so " << n << " la: " << sum;
         return 0;

}