#include <iostream>

using namespace std;

int main()
{
    int n,temp,sum,mul,so1,so2,reverse,i;
    bool tang,giam;

    sum = 0;
    mul = 1;

    cout << "Nhap so nguyen duong n: ";
    cin >> n;

    if (n<=0)
    {
        cout << "So ban vua nhap khong hop le, vui long thu lai";
        return 0;
    }

    temp = n;

    while (temp)
    {
        sum += temp % 10;
        mul *= temp % 10;
        temp /= 10;
    }

    if (sum==mul) cout << "Tong cac chu so bang tich cac chu so";
    if (sum!=mul) cout << "Tong cac chu so khong bang tich cac chu so";

    temp = n;
    so2 = temp%10; //lay chu so hang don vi
    tang = true; // gan flag = true

    while (tang&&(temp>10)) // TH tang dan
    {
        temp /= 10; //lay phan nguyen con lai cua so da chia
        so1 = temp%10; 

        if (so1>=so2)
        {
            tang = false; //truong hop flag khong thoa nua
        }

        so2 = so1; // doi sang trai theo tung cap so
    }

    temp = n;
    giam = true;// gan flag = true
    so2 = temp%10;

    while (giam&&(temp>10)) //TH giam dan
    {
        temp /= 10; //lay phan nguyen con
        so1 = temp%10;
            

        if (so1<=so2)
        {
            giam = false; //TH flag khong thoa nua
        } 

        so2 = so1;// doi sang trai theo tung cap so
    }  

     if (tang&&(!giam)) 
    {
        cout << "\nCac chu so tang dan tu trai sang phai"; 
    }    

    if (giam&&(!tang)) cout << "\nCac chu so giam dan tu trai sang phai";

    else if ((giam&&tang)||((!giam)&&(!tang))) cout << "\nCac chu so khong tang/giam dan tu trai sang phai"; // truong hop con lai khac 2 
    
    temp = n;
    reverse = 0;

    while (temp!=0)
    {
        reverse = reverse*10 + temp%10;
        temp /= 10;
    }

    if (reverse == n) cout << "\nSo la so doi xung";
    else if (reverse != n) cout << "\nSo khong la so doi xung";

    temp = n;

    if (temp==1) //TH dac biet so 1
    {
        cout << "\nDay khong la so nguyen to";
    }    

    if ((temp==2)||(temp==3)) //Th dac biet cua so 2 va so 3
    {
        cout << "\nDay la so nguyen to ";
    }

    if ((temp%temp==0)&&(temp%2!=0)&&(temp%3!=0)) //cac so thoa dieu kien chia het cho 1 va chinh no
    {
        cout << "\nDay la so nguyen to ";
    }    

    else cout << "\nDay khong la so nguyen to";// con lai khong phai la so nguyen to

    int S = 0;

    for (int i=1; i<temp; i++)
    {
        if (temp%i==0)
        {
            S += i;
        }
    }

    if (S==n) cout << "\nDay la so hoan thien";
    else cout << "\nDay khong la so hoan thien";

}