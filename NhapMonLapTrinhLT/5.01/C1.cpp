//21127456_Võ Cao Trí 21127031 Phạm Quốc Duy
//Câu 1:  VCT tính tổng 1 dãy phân số, sắp xếp lại dãy theo thứ tự tăng& xuất kết quả.
#include<iostream>
using namespace std;
#define MAX 1000
typedef struct phanso { //struct chứa tử và mẫu 
	double tu;
	double mau;
}ps; // tên gọi struct 
void nhapmang0(ps a[], int& n)// hàm nhập mảng biết trước số phần tử 
{
	if (n <= 0 || n > MAX) //điều kiện số phần tử 
		return;
	for (int i = 0; i < n; i++)
	{
		cout << "tu so phan so thu " << (i + 1) << ": ";//nhập tử 
		cin >> a[i].tu;
		cout << "mau so phan so thu " << (i + 1) << ": ";//nhập mẫu
		cin >> a[i].mau;
		if (a[i].mau == 0) { // kiểm tra mẫu khác không nếu không thì nhập lại
			cout << "Mau khac khong! Vui long nhap lai" << endl;
			i--;
		}
	}
}
void nhapmang1(ps a[], int& n)// hàm nhập mảng không  biết trước số phần tử 
{
	n = 0;
	char ans;
	do
	{
		cout << "tu so phan so " << ": "; //nhập tử 
		cin >> a[n].tu;
		cout << "mau so phan so " << ": ";//nhập mẫu
		cin >> a[n].mau;
		if (a[n].mau == 0) // kiểm tra mẫu khác không nếu không thì nhập lại
			cout << "Mau khac khong! Vui long nhap lai" << endl;
		else
			n++;
		if (n <= 0 || n > MAX) //điều kiện số phần tử 
			return;
		cout << "Co nhap them phan so khong (Y/N)";  //người dùng có nhập tiếp không
		getchar();
		ans = getchar();
	} while (ans == 'y' || ans == 'Y'); // điều kiện kiểm tra người dùng có nhập tiếp không
}
void nhapmang(ps a[], int& n) // hàm nhập mảng 
{
	cout << "Ban co biet so phan so khong (y/n): "; //hỏi người dùng có biết số phần tử không 
	char ans = getchar();
	if (ans == 'Y' || ans == 'y') // điều kiện kiểm tra người dùng có biết không 
	{
		cout << "Nhap vao so phan so: "; cin >> n;
		nhapmang0(a, n);
	}
	else
		nhapmang1(a, n);
}
void kiemtramang(ps a[], int& n) // hàm kiểm tra mảng có phần tử có cả tử và mẫu đều âm không 
{									
	for (int i = 0; i < n; i++) {   // nếu có thì đổi dấu cả tử và mẫu
		if (a[i].tu < 0 && a[i].mau < 0)
		{
			a[i].tu = -a[i].tu;
			a[i].mau = -a[i].mau;
		}
	}
}
void xuatmang(ps a[], int& n) //hàm xuất mảng
{
	for (int i = 0; i < n; i++)
	{
		cout <<a[i].tu << "/" << a[i].mau << " ";
	}
}
int UCLN(double a, double b) // hàm tìm ước chung lớn nhất
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	while (a != b)
	{
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}
void rutgonphanso(double& a, double& b) // đơn giản tổng các phân số
{
	int temp = UCLN(a, b);// chia cả tử và mẫu cho ước chung lớn nhất của chúng để tối giản
	a = a / temp;
	b = b / temp;
}
void dongian(ps a[], int& n) //hàm đơn giản kiểm tra phân số trong mảng có tối giản không
{
	int temp;
	for (int i = 0; i < n; i++)
	{
		temp = UCLN(a[i].tu, a[i].mau); // chia cả tử và mẫu cho ước chung lớn nhất của chúng để tối giản
		a[i].tu = a[i].tu / temp;
		a[i].mau = a[i].mau / temp;
	}
}
void tinhtongphanso(ps a[], int n) //hàm xuất ra tổng các phân số
{
	ps temp = a[0]; // biến lưu phân số đầu tiên
	for (int i = 1; i < n; i++)
	{
		temp.tu = temp.tu * a[i].mau + temp.mau * a[i].tu; // tính tổng phân số bằng cách quy đồng
		temp.mau = temp.mau * a[i].mau;
		rutgonphanso(temp.tu, temp.mau);
	}
	cout << temp.tu << "/" << temp.mau << endl;
}
void sapxeptangdan(ps a[], int n) //hàm sắp xếp các phân số theo thứ tự tăng dần
{
	int temp1; 
	int temp2;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if ((a[i].tu/a[i].mau) > (a[j].tu/a[j].mau)) { //kiểm tra phần tử nào nhỏ hơn thì đưa lên vị trí trên
				temp1 = a[i].tu;			//hoán vị các phần tử nếu thỏa điều kiện
				temp2 = a[i].mau;
				a[i].tu = a[j].tu;
				a[i].mau = a[j].mau;
				a[j].tu = temp1;
				a[j].mau = temp2;
			}
		}
	}
}
int main()
{
	ps a[MAX];
	int n;

	nhapmang(a, n);
	kiemtramang(a, n);
	dongian(a, n);
	xuatmang(a, n);

	cout << "\nTong cac phan so la: ";
	tinhtongphanso(a, n);
	cout << "\n";
	
	sapxeptangdan(a, n);
	xuatmang(a, n);
	system("pause");
	return 0;
}