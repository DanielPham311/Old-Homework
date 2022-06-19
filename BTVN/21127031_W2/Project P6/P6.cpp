//Chuong trinh phan loai thanh tich hoc tap
#include <iostream>
#include <string>

using namespace std;

int main ()
{
    string Hoten;
    float T,L,H,dtb;
    int sohs,n;

    cout << "Hay cho biet so hoc sinh trong lop: "; // cho nguoi dung nhap so hs
    cin >> sohs;

    for (n=0;n<sohs;n++) 
    {
        cout << "\nHay nhap Ho Va Ten hoc sinh thu " << (n+1) <<" : (Hay an dau '.' va Enter sau khi nhap xong) \n";

        getline(cin,Hoten,'.'); //input tên hs

        cout << "Ho ten hoc sinh:" << Hoten;

        cout << "\nHay nhap diem toan: ";
        cin >> T;

        cout << "\nHay nhap diem Ly: ";
        cin >> L;

        cout << "\nHay nhap diem Hoa: ";
        cin >> H;

        dtb = (T+L+H)/3; // nhập điểm và tính điểm trung bình

        if (dtb >= 9) 
        {
            cout << "Hoc sinh xuat sac ";
        }

        if ((dtb<9)&&(dtb>=8)) 
        {
            cout << "Hoc sinh gioi";
        }

        if ((dtb<8)&&(dtb>=6.5)) 
        {
            cout << "Hoc sinh kha ";
        }

        if ((dtb<6.5)&&(dtb>=5)) 
        {
            cout << "Hoc sinh trung binh ";
        }

        if ((dtb<5)&&(dtb>=3.5)) 
        {
            cout << "Hoc sinh yeu ";
        }

        if (dtb<3.5) 
        {
            cout << "Hoc sinh kem"; // xếp loại các học sinh dựa trên điểm
        }

        string Hoten; // reset string Hoten
    }

    return 0;
}