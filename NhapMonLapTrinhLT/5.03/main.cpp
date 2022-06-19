/*VCT nhập 1 chuỗi tối đa 80 ký tự và xuất menu cho phép lữa chọn để thực hiện các xử lý sau:
- Cắt bỏ các khoảng trắng nằm cạnh nhau nếu có - chỉ chừa lại 1. (vd: "      Hello,      world    " =>" Hello, world " )
- Chuyển chữ cái đầu mỗi từ thành hoa và các chữ cái còn lại thành thường. (vd: "CONg nGHE thONG TIN" =>"Cong Nghe Thong Tin")
- Xóa các từ giống nhau, chỉ giữ lại từ đầu.  (vd: "Messi la Pulga, Messi la Goat, gio thi Messi dang la Hetxiquach" => Messi la Pulga, Goat, gio thi dang Hetxiquach" */
#include "menu.h"
#include "func.h"
#include "nhapxuat.h" //include các thư viện
#include <iostream>

using namespace std;

int main()
{
    Menu(); 
    int choice = Input(); //xuất menu và lưu lựa chọn của người dùng
    char chuoi[MAX];
    
    while (choice!=4) //vòng lặp này sẽ đảm bảo người dùng sẽ dùng lại được chương trình mà không cần chạy lại
    {
        NhapChuoi(chuoi);
        int size = DoDaiChuoi(chuoi);
        cout << "\nChuoi ban da nhap la: ";
        XuatChuoi(chuoi,size); //Nhập chuỗi

        Execute(choice,chuoi,size); //gọi hàm execute để xử lý các thao tác ứng với input người dùng
        cout << "\nChuoi sau khi xu ly la: ";
        XuatChuoi(chuoi,size); //Xuất chuỗi sau khi xử lý
        cout << endl;
        cout << "\nBan co muon tiep tuc su dung khong? (y/n)";
        char ans = getchar();

        if (ans=='y'||ans=='Y')
        {
            Menu();
            choice = Input();
        } //nếu người dùng muốn tiếp tục sử dụng thì xuất menu và thực hiện lại
        else
        {
            cout << "\nCam on ban da su dung chuong trinh cua chung toi";
            break;
        } //nếu không thì dừng chương trình
    }

    
    






}
