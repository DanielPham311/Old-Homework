//Chuong trinh tinh tien di xe taxi theo tung moc km
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main ()
{
    float tien1=0,tien2=0,tien3=0,temp1,temp2,temp3,tong,km; //temp la cac bien dem
                                                             //tien1,2,3 la cac gia tien o tung moc km
    cout << "Hay cho biet so km da di? ";
    cin >> km;

    tong = 0;

    for (temp1=0;((temp1<1)&&(temp1<km));temp1+=0.1) { // lap cho bien dem tang tung 0.1km trong 1km dau
    }    
        tien1 = (temp1 * 15000);// so tien sau km thu nhat

    km -= temp1; //cap nhat so km con lai

    for (temp2=0;((temp2<3.9)&&(temp2<km));temp2+=0.1) { //lap cho bien dem tang tung 0.1km tu km thu 2 den 5
    }
        tien2 = (temp2 * 13500);// so tien sau khi di km thu 2 den thu 5

    km -= temp2; //cap nhat so km con lai

    for (temp3=0;(temp3<km);temp3+=0.1) { //lap cho bien dem tang tung 0.1km tu km thu 6 tro di
    }
        tien3 = (temp3 * 11000); //so tien di so km con lai

    if (km>120) //giam gia neu di tren 120km
    {
        tong = tien1 + tien2 + tien3;
        tong = tong - (tong*0.1);
    }

    else 
    {
        tong = tien1 + tien2 + tien3;
    }

    cout << "Tong so tien la: " << fixed << setprecision(1) << tong;
}