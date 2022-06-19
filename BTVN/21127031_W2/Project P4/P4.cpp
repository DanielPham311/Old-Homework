//Chuong trinh kiem tra ky tu thuong hay hoa va bien doi
#include <iostream>
#include <cctype>
using namespace std;

int main () 
{
    char a,b;
    
    cout << "Hay nhap mot chu cai bat ky: ";
    cin >> a;

    if (islower(a)!=0) 
    { //truong hop a la mot ky tu thuong
        b = toupper (a);
        cout << "Ky tu in hoa la: " << b;
    }

    else 
    { //truong hop a la ky tu in hoa
        b = tolower(a);
        cout << "Ky tu viet thuong la: " << b;
    }

    return 0;
}