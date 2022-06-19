#include <iostream>

using namespace std;

int main ()
{
    float x,y,z,max,min,closest;
   
    max = 0;
    min = 0;
    closest = 0;

    while (x!=0)
    {
        cout << "Nhap x: ";
        cin >> x;

        while (x)
        {
            if (max<x)
            {
                max = x;
                cout << "So lon nhat la: " << max;
            }    

            if (min>x) 
            {
                min = x;
                cout << "So nho nhat la: " << min;
            }

        }    
        

       
        

    }
}