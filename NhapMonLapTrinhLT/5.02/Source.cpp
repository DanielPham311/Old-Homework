#include<iostream>
using namespace std;
#define MAX 100 //Số lượng phần tử tối đa của một mảng

typedef struct { //Ta tạo kiểu dữ liệu thoi_diem gồm các biến bên dưới để thể hiện các dữ liệu ngày, tháng, năm, giờ, phút
	int ngay, thang, nam, gio, phut;
}thoi_diem;

typedef struct { //tạo kiểu dữ liệu MSK(mốc sự kiện) gồm hai mảng chứa các xâu thể hiện tên và độ quan trọng của sự kiện và biến TG để truy cập vào cấu trúc thoi_diem
	thoi_diem TG;
	char ten_su_kien[81];//tối đa mỗi xâu chỉ có 81 ký tự
	char do_quan_trong[81];
}MSK;

int length(char a[]) {
	int dem = 0;
	for (int i = 0; a[i] != '\0'; i++) {
		dem++;
	}
	return dem;
}

void kiemtraquantrong(MSK a[], int i)
{
	char temp1[3] = "ko";
	char temp2[7] = "cochut";
	char temp3[10] = "quantrong";
	char temp4[4] = "rat";
	do
	{
		cout << "Vui long nhap dung theo yeu cau!" << endl;
		cout << "Nhap vao do quan trong cua su kien (ko/cochut/quantrong/rat): ";
		cin.getline(a[i].do_quan_trong, 81, '\n');
	} while ((!sosanh(a, temp2, i)));
}
bool kiemtragiophut(int a, int b)
{
	if (a > 24 || a < 0 || b > 60 || b < 0)
		return false;
	else
		return true;
}
int songaytrongthang(int thang)
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
bool kiemtrangaythangnam(int n, int t, int N)
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
void lietke(MSK a[], int n, thoi_diem b[])
{
	for (int i = 0; i < n; i++)
	{
		if ((a[i].TG.gio > 4 && a[i].TG.gio < 10) || (a[i].TG.gio == 4 && a[i].TG.phut == 0) || (a[i].TG.gio == 10 && a[i].TG.phut == 0))
		{
			xuatmang1(a, i);
		}
	}
}
void quantrong(MSK a[], int n, thoi_diem b[])
{
	char ans[81] = "rat";
	for (int i = 0; i < n; i++)
	{
		if (sosanh(a,ans,i))
		{
			xuatmang1(a, i);
		}
	}
}

void thaydoi(MSK a[], int n, thoi_diem b[])
{
	for (int i = 0; i < n; i++)
	{
		
	}
}

bool KiemTraTonTai(MSK a[],int n,int ngay, int thang, int nam, int gio, int phut)
{
	for (int i=0; i<n; ++i)
	{
		if ((a[i].TG.nam==nam)&&(a[i].TG.thang==thang)&&(a[i].TG.ngay==ngay)&&(a[i].TG.gio==gio)&&(a[i].TG.phut==phut))
		{
			cin.ignore();
			cout << "Nhap do quan trong ban muon sua: ";
			cin.getline(a[i].do_quan_trong, 81, '\n');
			xuatmang1(a,n);
			return true;
		}    
	}
	return false;
}

void Swap (int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}



void XDDRatQuanTrong(MSK a[],int n,int ngay, int thang, int nam, int gio, int phut)
{
	char temp [4] = "rat";
	for (int i=0; i<n; ++i)
	{
        if ((a[i].TG.nam>nam)&&(sosanh(a,temp,i)))
		    xuatmang1(a,i);

		else
		{
			if ((a[i].TG.nam==nam)&&(a[i].TG.thang>thang)&&(sosanh(a,temp,i)))
		        xuatmang1(a,i);
		
		
            else 
		    {
			    if ((a[i].TG.nam==nam)&&(a[i].TG.thang==thang)&&(a[i].TG.ngay>ngay)&&(sosanh(a,temp,i)))
		            xuatmang1(a,i);
		    

		        else
		        {
		            if ((a[i].TG.nam==nam)&&(a[i].TG.thang==thang)&&(a[i].TG.ngay==ngay)&&(a[i].TG.gio>gio)&&(sosanh(a,temp,i)))
		                xuatmang1(a,i);
		          

		            else
		            {
		                if ((a[i].TG.nam==nam)&&(a[i].TG.thang==thang)&&(a[i].TG.ngay==ngay)&&(a[i].TG.gio==gio)&&(a[i].TG.phut>phut)&&(sosanh(a,temp,i)))
		                    xuatmang1(a,i);
		            }
				}
			}
		}	
	}
}


int main()
{
	MSK a[MAX];
	thoi_diem b[MAX];
	char ans[81] = "rat";
	int n,ngay,thang,nam,gio,phut;
	cout << "Nhap vao so moc su kien: ";
	cin >> n;
	nhapmang(a, n, b);
	quantrong(a, n, b);
	cout << "Nhap vao thoi diem cua mot su kien: ";
    cin >> ngay >> thang >> nam >> gio >> phut;
	system("pause");
	return 0;
}