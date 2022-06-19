#include <iostream>

using namespace std;

int main()
{
    int n,a,b,c,d;

    cout << "Nhap so tien muon rut: (don vi: dong) ";
    cin >> n;

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
    return 0;
}