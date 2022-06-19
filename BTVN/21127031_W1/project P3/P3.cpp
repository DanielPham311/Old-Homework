    #include <iostream>
    #include <cmath>

using namespace std;

int main () 
{
    float R,C,S;
    const float pi=3.14;

    cout << "Nhap ban kinh cua hinh tron: \n";
    cin >> R;

    C= 2*pi*R;
    cout << "Chu vi cua hinh tron la: " << C << "\n";

    S= pi*pow(R,2);
    cout << "Dien tich hinh tron la: " << S << "\n";

    return 0;


}