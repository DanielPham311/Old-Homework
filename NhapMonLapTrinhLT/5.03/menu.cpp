#include "menu.h"
#include "func.h"
#include <iostream>

using namespace std;

void Menu() //Hàm xuất ra menu cho người dùng thao tác
{
    cout << "      ==========================MENU CAC THAO TAC XU LY MANG================ \n";
    cout << "           1. CAT BO KHOANG TRONG NAM CANH NHAU \n";
    cout << "           2. CHUYEN CHU CAI DAU MOI TU THANH HOA VA CAC CHU CON LAI THANH THUONG \n";
    cout << "           3. XOA CAC TU GIONG NHAU, CHI GIU LAI TU DAU \n";
    cout << "      =========================================================================== \n";
    cout << endl;
    cout << "           An 4 de thoat chuong trinh";
}

int Input() //Hàm thu nhận input từ người dùng để xử lý các thao tác tương ứng
{
    int choice;
    cout << "\n         Ban muon thuc hien thao tac nao (vui long nhap 1,2,3 tuong ung voi cac chuc nang : ";
    cin >> choice; //nhập số tương ứng để chọn tác vụ

    while ((choice<1)||(choice>4)) //loại các trường hợp nhập các só không hợp lệ
    {
        cout << "\n     Ban da nhap mot phim khong hop le, vui long thu lai";
        cout << "\n     Ban muon thuc hien thao tac nao (vui long nhap 1,2,3 tuong ung voi cac chuc nang : ";    
        cin >> choice; //cho người dùng nhập lại cho đến khi hợp lệ
    }

    if (choice==4) //người dùng ấn 4 thì thoát chương trình
    {
        cout << "\nCam on ban da su dung chuong trinh cua chung toi";
        exit;
    }
    return choice; //hàm trả lại giá trị biến choice 
}

void Execute(int choice, char array[], int size) //Hàm execute sẽ thực hiện các hàm tương ứng trên mảng phụ thuộc vào input của người dùng
{
    if (choice==1) //người dùng chọn 1 thì thực hiện hàm xóa khoảng trắng
    {
        XoaKhoangTrang(array,size);
    }

    if (choice==2) //người dùng chọn 2 thì thực hiện hàm chuyển chữ cái đầu mỗi từ thành hoa và các chữ cái còn lại thành thường (Title Case)
    {
        ChuyenSangTitleCase(array,size);
    }

    if (choice==3) //người dùng chọn 3 thì thực hiện hàm xóa các từ giống nhau 
    {
        XoaTuGiongNhau(array,size);
    }
}