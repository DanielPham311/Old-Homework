#include <iostream>
#include <cmath>

using namespace std;

#define MAX 1000

typedef struct ToaDo{
    double x;
    double y;
} TD;

double ChuVi(TD array[], int size)
{
    double sum = 0; //khởi tạo giá trị ban đầu của biến tổng
    for (int i=0; i< size-1; ++i)
    {
        // Ta tính độ dài các cạnh nối từ đỉnh 1 ->2, 2->3... n-1->n
        sum += sqrt(pow((array[i+1].x)-(array[i].x),2) + pow((array[i+1].y)-(array[i].y),2));
    }                   //(lay toa do x(i+1)-xi)                //(lay toa do y(i+1)-yi)

    sum = sum + sqrt(pow((array[size-1].x)-(array[0].x),2) + pow((array[size-1].y)-(array[0].y),2));
    //Trường hợp đỉnh thứ n nối với đỉnh thứ 1
    return sum;
}

void XuatMangNguyen(TD array[],int size) //Hàm để xuất các phần tử của mảng
{
    for (int i=0; i<size; ++i)
    {
        cout << "("<<array[i].x << ","<< array[i].y << " )";    
    }
}

void NhapMangPhanSo1(TD array[], int &size) //Hàm nhập phần tử nếu người dùng biết cụ thể số lượng phần tử
{
    cout << "Cho biet so luong phan tu?";
    cin >> size;

    if (size<=0||size>MAX) return;

    for (int i=0; i<size; ++i)
    {
        cout << "\nNhap x cua dinh thu ["<<i<<"] : ";
        cin >> array[i].x;
        cout << "\nNhap y cua dinh thu ["<<i<<"] : ";
        cin >> array[i].y;
    } 
}


int main()
{
    TD array[MAX];
    int size;

    NhapMangPhanSo1(array, size);
    XuatMangNguyen(array, size);
    
    cout << ChuVi(array,size);

    
}











































