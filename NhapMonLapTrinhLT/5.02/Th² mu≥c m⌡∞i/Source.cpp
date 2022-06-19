#include<iostream>
using namespace std;
#define MAX 100
typedef struct {
	int ngay, thang, nam, gio, phut;
}thoi_diem;
typedef struct {
	thoi_diem TG;
	char ten_su_kien[81];
	char do_quan_trong[81];
}MSK;


int length(char a[]) {
	int dem = 0;
	for (int i = 0; a[i] != '\0'; i++) {
		dem++;
	}
	return dem;
}
bool kiemtragiophut(int a, int b) //Hàm kiểm tra tính hợp lệ của giờ và phút nhập vào
{
	if (a > 24 || a < 0 || b > 60 || b < 0)
		return false;
	else
		return true;
}
int songaytrongthang(int thang) //Hàm xuất số ngày trong 1 tháng trong năm không nhuận
{
	int songay(0);
	switch (thang)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		songay = 31;
		break;
	}
	case 4:
	case 6:
	case 9:
	case 11:
	{
		songay = 30;
		break;
	}
	case 2:
		songay = 28;
	}
	return songay;
}
bool kiemtrangaythangnam(int n, int t, int N) //Hàm kiểm tra tính hợp lệ của ngày tháng năm được nhập vào
{
	if (N < 2021 || N > 2022)
		return false;
	else if (t > 12 || t < 1)
		return false;
	else if (n < 1 || n >songaytrongthang(t))
		return false;
	else
		return true;
}
void kiemtrasolieu(int& ngay, int& thang, int& nam, int& gio, int& phut) //Hàm kiểm tra thời điểm được nhập vào
{
	cout << " Nhap vao lan luot ngay thang nam gio phut: ";
	cin >> ngay >> thang >> nam >> gio >> phut;
	while (!kiemtragiophut(gio, phut) || !kiemtrangaythangnam(ngay,thang, nam)) //các trường hợp số liệu không hợp lệ
	{
		cout << "Vui long nhap dung thoi gian!" << endl; 
		cout << "Nhap vao lan luot ngay thang nam gio phut: ";
		cin >>ngay >> thang >> nam >> gio >>phut; //cho nhập lại
	}
}
void kiemtraTG(MSK a[], int i, thoi_diem b[])
{
	while (!kiemtragp(a[i].TG.gio, a[i].TG.phut) || !kiemtrantn(a[i].TG.ngay, a[i].TG.thang, a[i].TG.nam))
	{
		cout << "Vui long nhap dung thoi gian!" << endl;
		cout << "Nhap vao lan luot ngay thang nam gio phut: ";
		cin >> a[i].TG.ngay >> a[i].TG.thang >> a[i].TG.nam >> a[i].TG.gio >> a[i].TG.phut;
	}
}
void nhapmang(MSK a[], int n, thoi_diem b[])
{
	for (int i = 0; i < n; i++)
	{
		cin.ignore();
		cout << "Nhap vao ten su kien: ";
		cin.getline(a[i].ten_su_kien, 81, '\n');
		cout << "Nhap vao do quan trong cua su kien (ko/cochut/quantrong/rat): ";
		cin.getline(a[i].do_quan_trong, 81, '\n');
		kiemtraquantrong(a, i);
		cout << "Nhap vao lan luot ngay thang nam gio phut: ";
		cin >> a[i].TG.ngay >> a[i].TG.thang >> a[i].TG.nam >> a[i].TG.gio >> a[i].TG.phut;
		kiemtraTG(a, i, b);
	}
}
bool sosanh(MSK a[], char b[], int i)
{
	int n = 0;
	int temp(1);
	while (a[i].do_quan_trong[n] != '\0') {
		if (a[i].do_quan_trong[n] != b[n]) {
			temp = 0;
			break;
		}
		n++;
	}
	if (length(a[i].do_quan_trong) != length(b))
		return false;
	if (temp == 0)
		return false;
	else
		return true;
}
void kiemtraquantrong(MSK a[], int i)
{
	char temp1[3] = "ko";
	char temp2[7] = "cochut";
	char temp3[10] = "quantrong";
	char temp4[4] = "rat";
	int count(0);
	while (count == 0)
	{
		if (sosanh(a, temp1, i) || sosanh(a, temp2, i) || sosanh(a, temp3, i) || sosanh(a, temp4, i))
		{
			count = 1;
		}
		else
		{
			cout << "Vui long nhap dung theo yeu cau!" << endl;
			cout << "Nhap vao do quan trong cua su kien (ko/cochut/quantrong/rat): ";
			cin.getline(a[i].do_quan_trong, 81, '\n');
		}
	}
}
void xuatmang(MSK a[], int& n, thoi_diem b[])
{
	for (int i = 0; i < n; i++)
	{
		cout << "Ten su kien: " << a[i].ten_su_kien << endl;
		cout << "do quan trong: " << a[i].do_quan_trong << endl;
		cout << "ngay: " << a[i].TG.ngay <<"thang: " << a[i].TG.thang <<"nam: " << a[i].TG.nam << endl;
		cout << "gio:" << a[i].TG.gio << "phut: " << a[i].TG.phut << endl;
	}
}
void xuatmang1(MSK a[], int n)
{
	cout << "Ten su kien: " << a[n].ten_su_kien << endl;
	cout << "Do quan trong: " << a[n].do_quan_trong << endl;
	cout << a[n].TG.gio << " gio " << a[n].TG.phut << " phut" << " , " << "ngay: " << a[n].TG.ngay << " thang: " << a[n].TG.thang << " nam: " << a[n].TG.nam << endl;
}
/*void lietkebuoisang(MSK a[], int n, thoi_diem b[])
{
	for (int i = 0; i < n; i++)
	{
		if ((a[i].TG.gio > 4 && a[i].TG.gio < 10) || (a[i].TG.gio == 4 && a[i].TG.phut == 0) || (a[i].TG.gio == 10 && a[i].TG.phut == 0))
		{
			xuatmang1(a, i);
		}
	}
}*/
/*void quantrong(MSK a[], int n, thoi_diem b[])
{
	char ans1[81] = "rat";
	char ans2[81]= "quantrong";
	for (int i = 0; i < n; i++)
	{
		if (sosanh(a,ans1,i)|| sosanh(a, ans2, i))
		{
			xuatmang1(a, i);
		}
	}
}*/
/*void xoaphantu(MSK a[], int& n, int vitri)
{
	for (int i = vitri; i < n; i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}*/
/*void xoakoqt(MSK a[], int& n)
{
	char ans[3] = "ko";
	for (int i = 0; i < n; i++)
	{
		if (sosanh(a, ans, i))
		{
			xoaphantu(a, n, i);
			i--;
		}
	}
}*/
/*long tinhsogiokhibietthang(MSK a[], int i)
{
	long temp(0);
	if (a[i].TG.thang == 1)
	{
		return false;
	}
	for (int j = 1; j < a[i].TG.thang; j++)
	{
		temp = temp + (songaytrongthang(j)) * 24 * 60;
	}
	return temp;
}*/
/*long tinhsogio(MSK a[], int i) // moc  0 h 0p n 0 t 0 n 2021
{
	long temp;
	temp = (a[i].TG.nam - 2021) * 365 * 24 * 60 + tinhsogiokhibietthang(a, i) + (a[i].TG.ngay - 1) * 24 * 60 + (a[i].TG.gio) * 60 + a[i].TG.phut;
	return temp;
}*/
/*void sapxepsukien(MSK a[], int n)
{
	MSK c[1];
	cout << n << endl;
	for (int i = 0; i < n - 1; ++i) 
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (tinhsogio(a, i) > tinhsogio(a, j))
			{
				c[0] = a[i];
				a[i] = a[j];
				a[j] = c[0];
				if (i > 0)
					i--;
			}
		}
	}
}*/
/*void KiemTraTonTai(MSK a[], int n, thoi_diem b[], int ngay, int thang, int nam, int gio, int phut)
{
	int count(0);
	for (int i = 0; i < n; ++i)
	{
		if ((a[i].TG.nam == nam) && (a[i].TG.thang == thang) && (a[i].TG.ngay == ngay) && (a[i].TG.gio == gio) && (a[i].TG.phut == phut))
		{
			count = 1;
			cin.ignore();
			cout << "Nhap vao do quan trong cua su kien (ko/cochut/quantrong/rat): ";
			cin.getline(a[i].do_quan_trong, 81, '\n');
			kiemtraquantrong(a, i);
			break;
		}
		else
			count = 0;
	}
	if (count == 0) {
		cout << "Khong co su kien nao dien ra" << endl;
	}
}*/
/*void XDDRatQuanTrong(MSK a[], int n, thoi_diem b[], int ngay, int thang, int nam, int gio, int phut)
{
	char temp[4] = "rat";
	for (int i = 0; i < n; ++i)
	{
		if ((a[i].TG.nam > nam) && (sosanh(a, temp, i)))
			xuatmang1(a, i);
		else
		{
			if ((a[i].TG.nam == nam) && (a[i].TG.thang > thang) && (sosanh(a, temp, i)))
				xuatmang1(a, i);
			else
			{
				if ((a[i].TG.nam == nam) && (a[i].TG.thang == thang) && (a[i].TG.ngay > ngay) && (sosanh(a, temp, i)))
					xuatmang1(a, i);
				else
				{
					if ((a[i].TG.nam == nam) && (a[i].TG.thang == thang) && (a[i].TG.ngay == ngay) && (a[i].TG.gio > gio) && (sosanh(a, temp, i)))
						xuatmang1(a, i);
					else
					{
						if ((a[i].TG.nam == nam) && (a[i].TG.thang == thang) && (a[i].TG.ngay == ngay) && (a[i].TG.gio == gio) && (a[i].TG.phut > phut) && (sosanh(a, temp, i)))
							xuatmang1(a, i);
					}
				}
			}
		}
	}
}*/
int main()
{
	MSK a[MAX];
	thoi_diem b[MAX];
	int n;
	cout << "Nhap vao so moc su kien: ";
	cin >> n;
	nhapmang(a, n, b);
	xuatmang(a, n, b);
	system("pause");
	return 0;
}