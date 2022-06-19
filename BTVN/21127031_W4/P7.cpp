// VCT nhập một số nguyên dương n. Xác định:

//Tổng các chữ số của số vừa nhập có bằng tích.
//Các chữ số này có tăng dần hay giảm dần không?
//Số này có phải là số đối xứng? (các chữ số đối xứng, vd: 77, 191, 2002,..)
//Số này có phải là số nguyên tố?
//Số này có phải là số hoàn chỉnh (bằng tổng các ước nhỏ hơn nó, vd 6 = 1+2+3)
#include <iostream>
#include "mylib.h"

using namespace std;

int main()
{
    long n, sum, mul;
    bool tang,giam;
    sum = 0;
    mul = 1;

    cout << "Nhap so nguyen duong n: ";
    cin >> n;

    if (n<=0) //Loat TH n khong hop le
    {
        cout << "So ban vua nhap khong hop le, vui long thu lai";
        return 0;
    }

    bool checkTBT = KiemTra(n,sum,mul); //Goi ham kiem tra tong co bang tich khong
    if (checkTBT==true) cout << "Tong bang tich";
    else cout << "Tong khong bang tich";

    KiemTraTangDan(n,tang);//goi ham kiem tra so tang dan, tra ve flag tang la true neu dung
    KiemTraGiamDan(n,giam);//goi ham kiem tra so giam dan, tra ve flag giam la true neu dung

    if (tang&&(!giam)) 
    {
        cout << "\nCac chu so tang dan tu trai sang phai"; //TH 1 flag dung la flag tang
    }    

    if (giam&&(!tang)) cout << "\nCac chu so giam dan tu trai sang phai"; //TH 1 flag dung la giam

    else if ((giam&&tang)||((!giam)&&(!tang))) cout << "\nCac chu so khong tang/giam dan tu trai sang phai"; // truong hop con lai khac 2
    //TH con lai khi ca hai khong cung dung hay sai
    bool KTDX = KiemTraDoiXung(n); //goi ham kiem tra so doi xung
    if (KTDX==true) cout << "\nDay la so doi xung";
    else cout << "\nDay khong la so doi xung";

    if (!KiemTraSoNguyenTo(n)) cout << "\n" << n << " khong la so nguyen to";
    else cout << "\n" << n << " la so nguyen to"; //Ham kiem tra so nguyen to
    KiemTraSoHoanHao(n); //Ham kiem tra so hoan hao

}
