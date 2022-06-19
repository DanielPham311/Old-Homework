#include <iostream>

using namespace std;

int main ()
{
    char a;

    cout << "Hay nhap mot ky tu: \n";
    cin >> a;

    cout << "Ki tu da nhap la: " << a << "\n";
    cout << "Ma ASCII cua ky tu la: " << static_cast<int16_t>(a) << "\n"; 
    return 0;

}