#include <iostream>

using namespace std;

int main () {
    int n,sh;
    int sh1,sh2,sh3;
    int temp;

    cout << "Nhap so nguyen duong n co 3 chu so: ";
    cin >> n;

    temp = n;
// xac dinh tung so hang cua so o hang tram, chuc, don vi
    if (temp != 0) {
        sh = temp % 10;
        sh3 = sh;
        temp /= 10;
    }

    if (temp != 0) {
        sh = temp % 10;
        sh2 = sh;
        temp /= 10;
    }

    if (temp != 0) {
        sh = temp %10;
        sh1 = sh;
        temp /=10;
    }

    sh1 = sh1 + sh3;
    sh3 = sh1 - sh3;
    sh1 = sh1 - sh3; //hoan vi so thu 1,3

    cout << "Ngich dao cua so " << n << " la : " << sh1 << sh2 << sh3;
 return 0;

}