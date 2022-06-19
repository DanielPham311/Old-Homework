//Chuong trinh xuat tung chu so theo dang chu
#include <iostream>

using namespace std;

int main ()
{
    int n,temp,sh,i,k; //temp la bien tam, sh la so n bi lat nguoc thu tu
                       // i la bien de dem so so khong o phia sau (VD: n= 1200 se co i=2)
    cout << "Nhap so nguyen n: ";
    cin>> n;

    if (n<0)
    {
        cout << "So ban da nhap khong hop le, vui long nhap lai so khac";
        return 0;
    }

    temp = n;
    sh = 0;
    i = 0;
    
    while (temp != 0)
    {
        sh = sh*10 + temp % 10; //lat nguoc thu tu cua so n
        if (sh==0) i += 1; // cong bien dem i them 1 khi gap gia tri 0
        temp /= 10;
    }
    
    while (sh!=0)
    {
         switch (sh%10) 
        {
            case 1: cout << "Mot "; break;
            case 2: cout << "Hai "; break;
            case 3: cout << "Ba "; break;
            case 4: cout << "Bon "; break;
            case 5: cout << "Nam "; break;
            case 6: cout << "Sau "; break;
            case 7: cout << "Bay "; break;
            case 8: cout << "Tam "; break;
            case 9: cout << "Chin "; break;
            case 0: cout << "Khong "; break;
        }
        sh /= 10;
    }

    for(int k=0; k<i; k++)
    {
        cout << "Khong "; //voi so gia tri cua i ta xuat bay nhieu tu "Khong o phia sau"
    }
    
}