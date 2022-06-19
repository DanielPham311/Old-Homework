//Chuong trinh xet ngay thang nam duoc nhap
#include <iostream>

using namespace std;

int main () 
{
    int day, month,dbefore,dafter,mbefore,mafter; //dbefore, dafter la ngay truoc ngay sau, tuong tu voi thang

    cout << "Nhap vao ngay, thang hien tai: ";
    cin >> day >> month;
         //loai cac truong hop ngay thang khong hop le, ngay 29,30,31 thang 2, ngay 31 thang 4,6,9,11
    if ((day<0)||(month<0)||(day>31)||(month>12)||((day>=29)&&(month==2))||((day==31)&&(month==4))||((day==31)&&(month==6))||((day==31)&&(month==9))||((day==31)&&(month==11)))
    {
        cout << "Ngay thang ban da nhap khong hop le ";
        return 0;
    }

    switch (month) // phan loai thang
    {
        case(2): cout << "Thang nay co 28 ngay \n"; break;
        case(1):
        case(3):
        case(5):
        case(7):
        case(8):
        case(10):
        case(12): cout << "Thang nay co 31 ngay \n"; break;

        default: cout << "Thang nay co 30 ngay \n";
    }

           //phan ro cac truong hop cuoi thang
    if ((day==31)&&(month==1)||(day==28)&&(month==2)||(day==31)&&(month==3)||(day==30)&&(month==4)||(day==31)&&(month==5)||(day==30)&&(month==6)||(day==31)&&(month==7)||(day==31)&&(month==8)||(day==30)&&(month==9)||(day==31)&&(month==10)||(day==30)&&(month==11))
    {
        dafter = 1;
        mafter = month +1;
        cout << "Ngay hom sau la ngay " << dafter <<" thang "<<mafter<<" nam 2021 \n";
    }

    else if ((day==31)&&(month==12)) //truong hop ngay cuoi cung cua 2021
    {
        dafter = 1;
        mafter = 1;
        cout << "Ngay hom sau la ngay " << dafter <<" thang "<<mafter<<" nam 2022 \n";
    }

    else // cac truong hop con lai
    {
        dafter = day + 1;
        mafter = month;
        cout << "Ngay hom sau la ngay " << dafter <<" thang "<<mafter<<" nam 2021 \n";
    }
         // cac truong hop dau thang tim ngay phia truoc la ngay 31
    if ((day==1)&&(month==2)||(day==1)&&(month==4)||(day==1)&&(month==6)||(day==1)&&(month==8)||(day==1)&&(month==9)||(day==1)&&(month==11)) 
    {
        dbefore = 31;
        mbefore = month - 1;

        cout << "Ngay hom truoc la ngay " << dbefore << " thang " << mbefore << " nam 2021 \n";
    }

    else if ((day==1)&&(month==3)) //truong hop dau thang tim ngay phia truoc la ngay 28 thang 2
    {
        dbefore = 28;
        mbefore = month - 1;

        cout << "Ngay hom truoc la ngay " << dbefore << " thang " << mbefore << " nam 2021 \n";
    }

    else if ((day==1)&&(month==1)) //truong hop ngay dau tien cua 2021
    {
        dbefore = 31;
        mbefore = 12;
        cout << "Ngay hom truoc la ngay " << dbefore << " thang " << mbefore << " nam 2020 \n";
    }

    else // cac truong hop con lai
    {
        dbefore = day - 1;
        mbefore = month;

        cout << "Ngay hom truoc la ngay " << dbefore << " thang " << mbefore << " nam 2021 \n";
    }
    return 0;
}