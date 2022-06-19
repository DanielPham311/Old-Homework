#include <iostream>
#include "function.h"

using namespace std;

int MaxChocolate(int &money, int &price, int &wrap) //Hàm nhập tiền, giá, số vỏ kẹo cần đổi
{
    cout << "Amount of money : ";
    cin >> money;

    while (money < 1) //vòng lặp để ngăn dữ liệu không hợp lệ
    {
        cout << "All values are positive integers and greater than 1, please try again" << endl;
        cout << "Amount of money : ";
        cin >> money;
    }
    cout << "\nPrice of each chocolate: ";
    cin >> price;

    while (price <= 1) //vòng lặp để ngăn dữ liệu không hợp lệ
    {
        cout << "All values are positive integers and greater than 1, please try again" << endl;
        cout << "Price of each chocolate : ";
        cin >> price;
    }
    cout << "\nNumber of wraps to exchange for a chocolate: ";
    cin >> wrap;

    while (wrap <= 1) //vòng lặp để ngăn dữ liệu không hợp lệ
    {
        cout << "All values are positive integers and greater than 1, please try again" << endl;
        cout << "Number of wraps to exchange for a chocolate: ";
        cin >> wrap;
    }

    return HelperFunc(money,price,wrap); 
}

int HelperFunc(int money, int price, int wrap) //Hàm chính và xuất ra kết quả cuối cùng
{
    int BoughtChoco = money / price; //Tổng số chocolate mua được bằng tiền
    return BoughtChoco + ExchangeWraps(BoughtChoco, wrap); // Số chocolate tối đa sẽ là số chocolate ban đầu và số chocolate đổi được từ số vỏ
}    

int ExchangeWraps(int chocolate, int wrap) //Hàm tính số chocolate đổi được từ vỏ 
{
    int Choco = chocolate / wrap; //Số chocolate mới bằng số vỏ đổi được từ tổng số chocolate ban đầu chia cho điều kiện để đổi vỏ kẹo
    if (chocolate < wrap) return 0; //điều kiện dừng (không đổi được thêm nữa)
    else return Choco + ExchangeWraps(Choco + chocolate % wrap,wrap); //Số vỏ mới = số vỏ đã có (tương ứng với mỗi thanh chocolate) + số vỏ còn dư từ những lần trước
}