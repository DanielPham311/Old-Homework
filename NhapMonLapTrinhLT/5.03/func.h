#include <iostream>
//Thư viện chứa khai báo các hàm xử lý các thao tác chính của chương trình
#define MAX 80

void Xoa(char array[], int &size, int pos); //Hàm xóa ký tự tại một vị trí pos

void XoaKhoangTrang(char array[], int size); //Hàm xóa các khoảng trắng dư thừa

void ChuyenSangTitleCase(char array[], int size); //Hàm chuyển đổi chuỗi sang dạng Title Case

void XoaNKyTu(char array[], int &size, int pos, int amount); //Hàm xóa n ký tự từ vị trí pos

void XoaTu(char array1[], int &size1, char array2[], int size2, int pos); //Hàm xóa các từ giống một từ có sẵn trong một xâu ký tự

void XoaTuGiongNhau(char array[], int &size); //Hàm xóa từ giống nhau, chỉ giữ lại một từ trong chuỗi





