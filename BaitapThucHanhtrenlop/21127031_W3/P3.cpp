//Chuong trinh xet tinh giam/tang dan tu trai sang phai
#include <iostream>

using namespace std;

int main ()
{
    int n,so1,so2; //so2 so1 lan luot la chu so thu 2,1 tu phai qua
    bool tang,giam; //2 co cho 2 TH tang giam

    cout << "Nhap so nguyen duong n: ";
    cin >> n;

    if (n<0) //loai cac TH bat hop ly
    {
        cout << "So ban nhap khong hop le, vui long nhap so nguyen duong ";
        return 0;
    }
    
    
    so2 = n%10; //lay chu so hang don vi
    tang = true; // gan flag = true

    while (tang&&(n>10)) // TH tang dan
    {
        n /= 10; //lay phan nguyen con lai cua so da chia
        so1 = n%10; 

        if (so1>=so2)
        {
            tang = false; //truong hop flag khong thoa nua
        }

        so2 = so1; // doi sang trai theo tung cap so
    }

    if (tang) 
    {
        cout << "Cac chu so tang dan tu trai sang phai"; 
        return 0;
    }    
    
    giam = true;// gan flag = true
    so2 = n%10;

    while (giam&&(n>10)) //TH giam dan
    {
        n /= 10; //lay phan nguyen con
        so1 = n%10;
            

        if (so1<=so2)
        {
            giam = false; //TH flag khong thoa nua
        } 

        so2 = so1;// doi sang trai theo tung cap so
    }  
      

    if (giam) cout << "Cac chu so giam dan tu trai sang phai";

    else cout << "Cac chu so khong tang/giam dan tu trai sang phai"; // truong hop con lai khac 2 flag
    

}