#include<iostream>
#include <string.h>
using namespace std;
#define MAX 1000

typedef struct {
    int ngay, thang, nam, gio, phut; 
}thoi_diem;

typedef struct {
    thoi_diem TG;
    char ten_su_kien[81];
    char do_quan_trong[81];
}MSK;

void nhapmang(MSK a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        cout << "Nhap vao ten su kien: ";
        cin.getline(a[i].ten_su_kien, 81, '\n');
        cout << "Nhap vao do quan trong cua su kien (ko/cochut/quantrong/rat): "; //Can ham kiem tra input
        cin.getline(a[i].do_quan_trong, 81, '\n');
        cout << "Nhap vao lan luot ngay thang nam gio phut: ";
        cin >> a[i].TG.ngay >> a[i].TG.thang >> a[i].TG.nam >> a[i].TG.gio >> a[i].TG.phut;//Can ham kiem tra
    }
}

void xuatmang(MSK a[], int n, thoi_diem b[])
{
    for (int i = 0; i < n; i++)
    {
        cout << "Ten su kien: " << a[i].ten_su_kien << endl;
        cout << "do quan trong: " << a[i].do_quan_trong << endl;
        cout << "ngay: " << a[i].TG.ngay << a[i].TG.thang << a[i].TG.nam << endl;
        cout << "gio:" << a[i].TG.gio << a[i].TG.phut << endl;
    }
}

bool sosanh(MSK a[],char c[], char b[],int i)
{
    int n = 0;
    int flag(1);
    while (a[i].do_quan_trong[n] != '\0') {
        if (a[i].do_quan_trong[n] != b[n]) {
            flag = 0;
            break;
        }
        n++;
    }
    if (flag == 0)
        return false;
    else
        return true;
}

void quantrong(MSK a[], int n, thoi_diem b[])
{
    char ans1[81] = "rat";
    char ans2[81] = "quantrong";
    for (int i = 0; i < n; i++)
    {
        if (sosanh(a,a[i].do_quan_trong,ans1,i)||sosanh(a,a[i].do_quan_trong,ans2,i))
        {
            cout << "Ten su kien: " << a[i].ten_su_kien << endl;
            cout << "do quan trong: " << a[i].do_quan_trong << endl;
            cout << "ngay: " << a[i].TG.ngay << a[i].TG.thang << a[i].TG.nam << endl;
            cout << "gio:" << a[i].TG.gio << a[i].TG.phut << endl;
        }
    }
}

int main()
{
    MSK a[MAX];
    thoi_diem b[MAX];
    int n;
    cout << "Nhap vao so moc su kien: ";
    cin >> n;
    cout << endl;
    nhapmang(a, n);
    xuatmang(a, n, b);
    cout << endl;

    cout << "Cac su kien thoa yeu cau: "<<endl;
    quantrong(a,n,b);
    

    system("pause");
    return 0;
}