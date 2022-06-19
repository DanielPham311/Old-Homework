//Chuong trinh kiem tra va phan loai tam giac
#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    float a,b,c;

    cout << "Nhap vao do dai cua 3 canh tam giac: ";
    cin >> a >> b >> c;
          //Tong 2 canh khong lon hon canh con lai thi khong la tam giac
    if (((a+b)<=c) || ((a+c)<=b) || ((b+c)<=a)) 
    {
        cout << "Day khong phai la tam giac";
        return 0;
    }
          //hai canh bang nhau va khong bang canh thu 3
    if (((a==b)&&(b!=c)) || ((a==c)&&(b!=c)) || ((b==c)&&(a!=b)))
    {
        cout << "Day la tam giac can";
        return 0;
    }
         // tong binh phuong canh nay bang binh phuong canh con lai
    if (((a*a)+(b*b)==(c*c)) || ((a*a)+(c*c)==(b*b)) || ((c*c)+(b*b)==(a*a))) 
    {
        cout << "Day la tam giac vuong";
        return 0;
    }
         //ba canh bang nhau
    if ((a==b)&&(b==c)) 
    {
        cout << "Day la tam giac deu";
        return 0;
    }
        // hai canh bang nhau va tong binh phuong canh nay bang binh phuong canh con lai
    if (((a==b)&&((a*a)+(b*b)==(c*c))) || ((b==c)&&((c*c)+(b*b)==(a*a))) || ((a==c)&&((a*a)+(c*c)==(b*b)))) 
    {
        cout << "Day la tam giac vuong can";
        return 0;
    }
    
    else 
    {
        cout << "Day la tam giac thuong";
        return 0;
    }
    
    return 0;
}