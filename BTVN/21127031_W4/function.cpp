#include "mylib.h"
#include <cmath>
#include<ctime>
#include<cstdlib>
#include<windows.h>
#include <conio.h>

using namespace std;

float TinhTongS1(long n) //Ham de tinh tong S1
{
    float S1;
    for (float a=1;a<=n;a++)
    {
        S1 += 1/a;
    }

    return S1;
}

long TinhFactorial(long n) //Ham de tinh giai thua cua so n
{
    long factorial = 1;
    for (int k=1; k<=n; k++)
    {
        factorial *= k;
    }

    return factorial;
}

float TinhTongS2(long n) //Ham de tinh tong S2
{
    int pos;
    float S2temp1 = 0;
    float S2temp2 = 0;
    double S2 = 0;

    for (float b=0.5; b<=n; b+=0.5)
    {
        long c = 2*b;
        TinhFactorial(c);

        pos += 1;

        if ((pos%2)!=0)
        {
            S2temp1 += ((2*b)+1)/(TinhFactorial(c));
        }

        if ((pos%2)==0)
        {
            S2temp2 -= ((2*b)+1)/(TinhFactorial(c));
        }

    }
    S2 = S2temp1 + S2temp2;
    return S2;
}

float TinhS3(long n,long k) //Ham de tinh tong S3
{
    float S3;
    long nk = n-k; // nk = n-k
    long factn = TinhFactorial(n); //Tinh giai thua cua n
    long factk = TinhFactorial(k); //Tinh giai thua cua k
    long factnk = TinhFactorial(nk); //Tinh giai thua cua (n-k)

    S3 = factn/(factk*factnk);
    return S3;
}
//========================================(Ham duoc dung trong cau 1)============================================ 

double TimSoLonNhat(double n,double max) //Ham de tim so lon nhat trong cac so n duoc nhap lan luot
{
    if (n>max) max = n;
    return max;
}

double TimSoNhoNhat(double n, double min) //Ham de tim so nho nhat trong cac so n duoc nhap lan luot
{
    if (n<min) min = n;
    return min;
}

void KhoangCachGanNhat(double n, double& distance, double& closest, double& closestnum)
{ //Ham de kiem tra so gan nhat voi -123.45
    if(n<0)
    {
        double temp = abs(n); //lay tri tuyet doi cua so n
        distance = abs(temp - abs(-123.45)); //tinh khoang cach tu so n den -123.45
         
        if (distance<closest)
        {
            closestnum = n; //gan n la so gan nhat neu thoa dk
            closest = distance; //cap nhat khoang cach gan nhat
        }    
    }
    
}

// =====================================(Ham duoc dung trong cau 2)==============================================

void RutTien(long n,long a,long b,long c,long d) //Ham de liet ke cac kha nang chi tra cua ATM
{
    for (int a=0; ((a*500000)<=n); a++)
    {
        for (int b=0; ((b*200000)<=n); b++)
        {
            for (int c=0; ((c*100000)<=n); c++)
            {
                for (int d=0; ((d*50000)<=n); d++)
                {
                    if ((((a*500000)+(b*200000)+(c*100000)+(d*50000)) <= n) && ((n-((a*500000)+(b*200000)+(c*100000)+(d*50000))) < 50000 )) 
                    {
                        cout<< a << " to 500k " << b << " to 200k " << c << " to 100k " << d << " to 50k \n";
                    }
                }
            }

        }
    }
}

//=====================================(Ham duoc dung trong cau 3)===============================================

bool KiemTra(long n, long sum, long mul) // Ham kiem tra tong bang tich
{
    while (n)
    {
        sum += n % 10; //Tinh tong cac chu so
        mul *= n % 10; // Tinh tich cac chu so
        n /= 10; //Cap nhat gia tri n
    }

    if (sum==mul) return true; //Tra ve gia tri true neu tong bang tich
    else return false; //Nguoc lai neu tong khong bang tich tra gia tri false
}

//=====================================(Ham duoc dung trong cau 4)===============================================

double ChayKiemTraCanBac3(double& y, double x, double i) //Ham de do can bac 3 cua so x theo hang don vi i
{
    while ((y*y*y)<=x)
    {
        if ((y*y*y)==x) //Neu thoa dieu kien, tra ket qua can bac 3
        {
            cout << "Vay can bac 3 cua x la: " << y;
            return 0;
        }

        y += i; //cap nhat bien y
    }
    y -= i; //neu khong tim duoc y thoa, ta tro ve gia tri y sao cho (y*y*y)<=x va do o hang don vi i ke tiep
    return y;
}

//=====================================(Ham duoc dung trong cau 5)===============================

void DongHo() //Ham the hien dong ho va giao dien cua no (nguon: thao khao tren mang)
{
  char key;
  int sec_prev=0;
  while(1)
  {
    int seconds, minutes, hours;
    string str;
  
    //luu tru tong so giay
    time_t total_seconds=time(0);
  
    //thu thap gia tri cua gio,phut,giay
    struct tm* ct=localtime(&total_seconds);
  
    seconds=ct->tm_sec;
    minutes=ct->tm_min;
    hours=ct->tm_hour;
    
    //chuyen sang dinh dang 12h (AM/PM)
    if(hours>=12)
      str="PM";
    else
      str="AM";
    hours=hours>12?hours-12:hours;	
    
    
    //the hien dong ho tren man hinh
    if(seconds==sec_prev+1 || (sec_prev==59 && seconds==0))
    {
      system("CLS");
      cout<< (hours<10?"0":"") << hours <<":" << (minutes<10?"0":"") << minutes << ":" << (seconds<10?"0":"") << seconds << " " << str <<endl;
      if (sec_prev==59 && seconds==0) //Ham xuat tieng beep neu gia tri giay = 0
      {
          Beep(523,500); // 523 hertz (C5) for 500 milliseconds     
      }
      
      if (kbhit()) //Ham kiem tra xem co phim duoc nhan khong
      {
        key = getch();
        if (key==27) break; //ngat chuong trinh neu nguoi dung an escape
      }
    }
    
    sec_prev=seconds;
    
  }
}

//=====================================(Ham duoc dung trong cau 6)=================================
void KiemTraTangDan(long n,bool& tang) //Ham kiem tra so tang dan tu trai sang phai
{
    int so2 = n%10; //lay chu so hang don vi
    tang = true; // gan flag = true

    while (tang&&(n>10)) // TH tang dan
    {
        n /= 10; //lay phan nguyen con lai cua so da chia
        int so1 = n%10; 

        if (so1>=so2)
        {
            tang = false; //truong hop flag khong thoa nua
        }

        so2 = so1; // doi sang trai theo tung cap so
    }
}

void KiemTraGiamDan(long n,bool& giam) // Ham kiem tra so giam dan tu trai sang phai
{
    giam = true;// gan flag = true
    int so2 = n%10;

    while (giam&&(n>10)) //TH giam dan
    {
        n /= 10; //lay phan nguyen con
        int so1 = n%10;
            

        if (so1<=so2)
        {
            giam = false; //TH flag khong thoa nua
        } 

        so2 = so1;// doi sang trai theo tung cap so
    }
}

bool KiemTraDoiXung(long n) //Ham kiem tra so doi xung
{
    long reverse = 0;
    long temp = n;

    while (temp!=0)
    {
        reverse = reverse*10 + temp%10; //Tinh so dao nguoc cua n
        temp /= 10;
    }

    if (reverse == n) return true; //Tra lai gia tri true neu so dao nguoc cua n bang chinh no
    else return false;////Tra lai gia tri false neu so dao nguoc cua n khong bang chinh no
}

bool KiemTraSoNguyenTo(long n) //Ham kiem tra so nguyen to
{
    for (int i = 2; i <= n/2; i++)
        if (n % i == 0) return false;
    return true;
}

void KiemTraSoHoanHao(long n) //Ham kiem tra so hoan hao
{
    long temp = n;
    long S = 0;

    for (int i=1; i<temp; i++)
    {
        if (temp%i==0) //ta chia lay phan du tung cac so hang trong do va cong chung lai voi nhau
        {
            S += i;
        }
    }

    if (S==n) cout << "\nDay la so hoan thien"; 
    else cout << "\nDay khong la so hoan thien";
}

//=====================================(Ham duoc dung trong cau 7)==================================

void BatPhuongTrinhLonHon0 (float a, float b, float c) //ham tinh BPT > 0
{
    float delta = b*b - 4*a*c;
    float subdelta = sqrt(delta);//subdelta la can bac 2 cua delta
    float d = (-b/(2*a)); 

    if (delta<0)
    {
        if (a<0) cout << "Bat phuong trinh vo nghiem\n";
        if (a>0) cout << "Bat phuong trinh dung voi moi gia tri thuc cua x, x thuoc R\n";
    }

    if (delta == 0)
    {
        if (a<0) cout << "Bat phuong trinh vo nghiem\n";
        if (a>0) cout << "Bat phuong trinh dung voi x thuoc tap nghiem (R hieu " << d << ")\n";
    }

    if (delta > 0)
    {
        float x1 = (-b - subdelta) / (2*a);
        float x2 = (-b + subdelta) / (2*a);

        if (a>0) cout << "Tap nghiem cua bat phuong trinh la: (x<" << x2 << ") hoac (x>" << x1 << ")";
        if (a<0) cout << "Tap nghiem cua bat phuong trinh la: (" << x2 << ";" << x1 << ")";
    }
    
}    

void BatPhuongTrinhNhoHon0 (float a, float b, float c) //ham tinh BPT < 0
{
    float delta = b*b - 4*a*c;
    float subdelta = sqrt(delta); //subdelta la can bac 2 cua delta
    float d = (-b/(2*a));

    if (delta < 0)
    {
        if (a>0) cout << "Bat phuong trinh vo nghiem\n";
        if (a<0) cout << "Bat phuong trinh dung voi moi gia tri thuc cua x, x thuoc R\n";
    }

    if (delta == 0)
    {
        if (a>0) cout << "Bat phuong trinh vo nghiem\n";
        if (a<0) cout << "Bat phuong trinh dung voi x thuoc tap nghiem (R hieu " << d << ")\n";
    }

    if (delta > 0)
    {
        float x1 = (-b - subdelta) / (2*a);
        float x2 = (-b + subdelta) / (2*a);

        if (a<0) cout << "Tap nghiem cua bat phuong trinh la: (x<" << x1 << ") hoac (x>" << x2 << ")";
        if (a>0) cout << "Tap nghiem cua bat phuong trinh la: (" << x1 << ";" << x2 << ")";
    }
}

void GiaiPTBac2(float a, float b, float c) //Ham giai PT bac 2
{
    float delta = b*b - 4*a*c;
    float subdelta = sqrt(delta);
    float d = (-b/(2*a));

    if (delta < 0) cout << "Phuong trinh vo nghiem";

    if (delta == 0) cout << "Phuong trinh co nghiem duy nhat: " << d;

    if (delta > 0)
    {
        float x1 = (-b - subdelta) / (2*a);
        float x2 = (-b + subdelta) / (2*a);

        cout << "Phuong trinh co 2 nghiem phan biet: " << x1 << " va " << x2;
    }
}

//=======================================(Ham duoc dung trong cau 8)================================

int UocChungLonNhat(int M, int N) //Ham tim uoc chung lon nhat
{
    while (M!=N) 
    {
        if (M>N)
        {
            M = M - N;
        }

        else N = N - M;
    }
    return M;
}

//=======================================(Ham duoc dung trong cau 9)==================================

int TimSoFibonacci(int k) //Ham tim so thu k trong day Fibonacci
{
    if (k==0) return 0;
    if (k == 1 ||k == 2)
        return 1;
    return TimSoFibonacci(k - 1) + TimSoFibonacci(k - 2);
}
    

int factorial(int n) {
	if (n > 1) {
		return n * factorial(n - 1);
	}else {
		return 1;
	}
}
