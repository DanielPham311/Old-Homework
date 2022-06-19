//21127031_Phạm Quốc Duy
#include <fstream>
#include <iostream>
#include "function.h"
#include <string.h>

using namespace std;

void DocThongTin(HS &a)
{
    ifstream myfile;
    myfile.open("Danh sach hoc sinh.txt");
    if (myfile.is_open())
    {
        char temp;
        string FirstLine;
        getline(myfile, FirstLine);
        cout << FirstLine << "\n";
        myfile >> temp;
        if (temp == '2' || temp == '3' || temp== '1' || temp == '4' || temp == '8')
        {
            a.MaHS = temp;
            myfile >> a.HoDem;
            myfile >> a.Ten;
            myfile >> a.NgaySinh;
            myfile >> a.GioiTinh;
            myfile >> a.DiaChi;
        }
        
    }
    else cout << "Khong tim duoc file";
}

