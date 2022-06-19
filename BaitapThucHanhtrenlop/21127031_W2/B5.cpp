#include <iostream>
#include <string>

using namespace std;

int main () {
    int n,sh;
    int sh1,sh2,sh3; //so hang thu 1,2,3 cua so nguyen do
    int temp;// bien tam

    cout << "Nhap so nguyen n co 3 chu so: ";
    cin >>n;

    temp = n;
// xac dinh tung so hang o tung hang tram, chuc, don vi
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
    
    switch (sh1) {
        case 1: cout << "Mot - "; break;
        case 2: cout << "Hai - "; break;
        case 3: cout << "Ba - "; break;
        case 4: cout << "Bon - "; break;
        case 5: cout << "Nam - "; break;
        case 6: cout << "Sau - "; break;
        case 7: cout << "Bay - "; break;
        case 8: cout << "Tam - "; break;
        case 9: cout << "Chin - "; break;
        case 0: cout << "Khong - ";break;
    }
    switch (sh2) {
        case 1: cout << "Mot - "; break;
        case 2: cout << "Hai - "; break;
        case 3: cout << "Ba - "; break;
        case 4: cout << "Bon - "; break;
        case 5: cout << "Nam - "; break;
        case 6: cout << "Sau - "; break;
        case 7: cout << "Bay - "; break;
        case 8: cout << "Tam - "; break;
        case 9: cout << "Chin - "; break;
        case 0: cout << "Khong - ";break;
    }
    switch (sh3) {
        case 1: cout << "Mot"; break;
        case 2: cout << "Hai"; break;
        case 3: cout << "Ba"; break;
        case 4: cout << "Bon"; break;
        case 5: cout << "Nam"; break;
        case 6: cout << "Sau"; break;
        case 7: cout << "Bay"; break;
        case 8: cout << "Tam"; break;
        case 9: cout << "Chin"; break;
        case 0: cout << "Khong";break;
    }
    return 0;
}