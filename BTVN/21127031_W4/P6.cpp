//VCT hiển thị đồng hồ theo đúng dạng <hh:mm:ss AM/PM> (giờ của đồng hồ được lấy theo giờ của máy), 
//khi chỉ số giây ss=0 thì phát ra 1 tiếng bíp. 
//Chương trình kết thúc khi người dùng nhấn phím Esc hoặc khi đã chạy đủ số giây được nhập vào trước đó.
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<windows.h>
#include <conio.h>
#include "mylib.h"

using namespace std;

int main()
{
    DongHo();
}