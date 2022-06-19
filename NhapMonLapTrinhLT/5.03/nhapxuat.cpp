#include <iostream>
#include "nhapxuat.h"

using namespace std;

void NhapChuoi(char array[]) //Hàm nhập vào một chuỗi ký tự
{
    cin.ignore();
    cout << "\nNhap chuoi: ";
    cin.getline(array,MAX,'\n'); //nhập chuỗi ký có độ dài đến MAX, nhấn enter thì dừng nhập
}  

void XuatChuoi(char array[], int size) //Hàm xuất ra chuỗi ký tự được nhập
{
    for (int i=0; i<size; ++i)
    {
        cout << array[i];
    }
}

int DoDaiChuoi(char array[]) //Hàm trả về độ dài của một chuỗi ký tự
{
    int i = 0;
    while (array[i] != '\0') //tăng biến đếm đến khi i đến phần tử kết thúc chuỗi thì xuất i
        i++;
    return i;
}