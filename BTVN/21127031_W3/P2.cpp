#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float n,m,temp,max,min,closest,absdemo,distance,closestnum;
    m = 0;

    const float demo = -123.45;
    absdemo = abs(demo);

    max = m;
    min = m;
    closestnum = 1;
    closest = 1000000;

    while (n!=0)
    {
        cout << "Nhap gia tri n moi: ";
        cin >> n;

        if ((n>100000)||(n<-100000)) 
        {
            cout << "So ban nhap qua lon hoac qua nho, vui long thu lai so khac";
            return 0;
        }

        if (n>max) max = n;
    
        if (min>n) min = n;

    
        
        temp = abs(n);
        distance = abs(temp - absdemo);
        
        if (distance<closest)
        {
            closestnum = n;
            closest = distance;
        }    
        
    }

    cout << "So lon nhat la: " << max;
    cout << "\nSo thuc nho nhat la: "<< min;
    cout << "\nSo thuc am gan nhat voi -123.45 la: " << closestnum;

}