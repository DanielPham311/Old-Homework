//VCT tính tổng 1 dãy phân số, sắp xếp lại dãy theo thứ tự tăng & xuất kết quả.
//MSSV_Họ tên: 21127456_Võ Cao Trí , 21127031_Phạm Quốc Duy
#include <iostream>

using namespace std;

#define MAX 1000 //Định giá trị tối đa của mảng

typedef struct PhanSo //struct gồm 2 biến Tu và Mau đại diện cho tử và mẫu của một phân số
{
    double Tu;
    double Mau;
} PS;//tên gọi khác của struct

bool KiemTraSoPhanTu() //Hàm để kiểm tra người nhập có biết cụ thể số phần tử của mảng không để cho hàm nhập thuận lợi
{
    char ans;
    cout << "Ban co biet cu the so luong phan tu cua mang khong? (y/n)";
    ans = getchar();//nhận input từ bàn phím

    if (ans=='y'||ans=='Y') return true; //nếu người dùng gõ "y" hoặc "Y" sẽ trả về true
    else return false; //Các phím còn lại trả giá trị false
}

void NhapMangPhanSo1(PS array[], int &size) //Hàm nhập phần tử nếu người dùng biết cụ thể số lượng phần tử
{
    cout << "Cho biet so luong phan tu?";
    cin >> size;// nhập số lượng phần tử của mảng

    if (size<=0||size>MAX) return;

    for (int i=0; i<size; ++i)
    {
        cout << "\nNhap tu cua phan so thu ["<<i<<"] : ";
        cin >> array[i].Tu; //Nhập tử
        cout << "\nNhap mau cua phan so thu ["<<i<<"] : ";
        cin >> array[i].Mau; //Nhập mẫu

        if (array[i].Mau==0) 
        {
            cout << "Mau so phai khac 0";
            return; //dừng nếu mẫu được nhập là 0
        }
    } 
}

void NhapMangPhanSo2(PS array[], int &size) //Hàm nhập mảng nếu người dùng không biết cụ thể số phần tử
{
    size = 0;
    char ans;
    do
    {
        cout << "\nNhap tu cua phan so thu ["<<size<<"] : ";
        cin >> array[size].Tu;//Nhập tử
        cout << "\nNhap mau cua phan so thu ["<<size<<"] : ";
        cin >> array[size].Mau;//Nhập mẫu

        if (array[size].Mau==0) 
        {
            cout << "Mau so phai khac 0";
            return;//Dừng nếu mẫu được nhập là 0
        }
        size ++; // Sau khi nhập, ta tăng kích thước mảng lên 1

        if (size==MAX) return;
        cout << "Ban co muon nhap nua khong? (y/n)"; //Sau khi tăng, ta hỏi người dùng có muốn nhập nữa không và cứ thế tiếp tục cho đến khi không nhập nữa
        getchar();
        ans = getchar();
    }while (ans=='y'||ans=='Y');
}

void XuatMangNguyen(PS array[],int size) //Hàm để xuất các phần tử của mảng
{
    for (int i=0; i<size; ++i)
    {
        if ((array[i].Tu<0)&&(array[i].Mau<0))
        {
            array[i].Mau = -array[i].Mau;
            array[i].Tu = -array[i].Tu; 
        }
        cout << array[i].Tu << "/" << array[i].Mau << " ";    
    }
}

int UCLN(int a,int b)
{
    if (a<0) a = -a;
    if (b<0) b = -b;

    while (a!=b)
    {
        if (a>b)
        {
            a -= b;
        }

        else b -= a;
    }
    return a;
}

void DonGianPhanSoTrongMang(PS array[], int size)
{
    for (int i=0; i<size; ++i)
    {
        int gcd = UCLN(array[i].Tu,array[i].Mau);
        array[i].Tu /= gcd;
        array[i].Mau /= gcd;
    }
}

void DonGianPhanSo(double &a, double &b)
{
    int gcd = UCLN(a,b);
    a /= gcd;
    b /= gcd;
}

void TongPhanSo(PS array[], int size)
{
    PS temp = array[0];
    
    for (int i=1; i<size;++i)
    {
        temp.Tu = (temp.Tu*array[i].Mau) + (array[i].Tu*temp.Mau);
        temp.Mau = temp.Mau * array[i].Mau;
    }
    DonGianPhanSo(temp.Tu,temp.Mau);
    cout << "\nTong cac phan so la: " << temp.Tu << "/" << temp.Mau;
}

void SapXepTangDan(PS array[], int size)
{
    int temp1;
    int temp2;
    for (int i=0; i<size; ++i)
    {
        for (int k=i+1; k<size; ++k)
        {
            if ((array[i].Tu/array[i].Mau) > (array[k].Tu/array[k].Mau))
            {
                temp1 = array[i].Tu;
                temp2 = array[i].Mau;
                array[i].Tu = array[k].Tu;
                array[i].Mau = array[k].Mau;
                array[k].Tu = temp1;
                array[k].Mau = temp2;   
            }
        }
    }
}

int main()
{
    PS array[MAX];
    int size;

    if (KiemTraSoPhanTu())
        NhapMangPhanSo1(array,size);
    else NhapMangPhanSo2(array,size);    
    
    DonGianPhanSoTrongMang(array,size);

    cout << "\nCac phan so da nhap: ";
    XuatMangNguyen(array,size);

    TongPhanSo(array,size);

    cout << "\nMang sau khi sap xep tang dan: ";
    SapXepTangDan(array,size);
    XuatMangNguyen(array,size);
}