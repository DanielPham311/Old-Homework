#include <iostream>

using namespace std;

int main ()
{
    int a,b,c;
    cout << "Nhap 3 so nguyen duong a,b,c: ";
    cin >> a >> b >> c;

    a = a+b;
    b = a-b;
    a = a-b; //hoan vi a va b
    b = b+c;
    c = b-c;
    b = b-c; //hoan vi b va c


    cout << "3 so sau hoan vi la: \n";
    cout << "a: " << a << "\n";
    cout << "b: " << b << "\n";
    cout << "c: " << c << "\n";

    return 0;
}