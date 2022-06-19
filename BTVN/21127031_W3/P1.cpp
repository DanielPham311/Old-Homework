#include <iostream>

using namespace std;

int main ()
{
    float a,b,c,d,e,f,factorialn,factorialk,factorialnk,factorial,n,k,S1,S2,S3,S2temp1,S2temp2;
    int pos;
    
    S1 = 0; S2 = 0; S3 = 0;factorial=1;
    S2temp1 = 0;S2temp2 = 0;pos=0;
    factorial=1; factorialn = 1; factorialk = 1; factorialnk =1;

    cout << "Hay nhap lan luot n va k:";
    cin >> n >> k;

    if (n<=0)
    {
        cout << "n khong thoa dieu kien de tinh S1 ";
        return 0;
    }

    else 
    {
        for (float a=1;a<=n;a++)
        {
            S1 += 1/a;
        }

        cout << "Tong S1 la: " << S1;
    }

    for (float b=0.5; b<=n; b+=0.5)
    {
        factorial *= b * 2;

        pos += 1;

        if ((pos%2)!=0)
        {
            S2temp1 += ((2*b)+1)/(factorial);
        }

        if ((pos%2)==0)
        {
            S2temp2 -= ((2*b)+1)/(factorial);
        }

    }
    S2 = S2temp1 + S2temp2;

    cout << "\nTong S2 la: " << S2;

    if ((n<0)||(k<0)||((n-k)<0)) 
    {
        cout << "\nHai gia tri n va k cua ban khong hop le de tinh S3";
        return 0;
    }

    else if ((n>0)&&(k>0)&&((n-k)>0))
    {
        for (float c=1; c<=n; c++)
        {
            factorialn *= c;
        }

        for (float d=1; d<=k; d++)
        {
            factorialk *= d;
        }

        f = n-k;

        for (float e=1; e<=f; e++)
        {
            factorialnk *= e;
        }

        S3 = factorialn/((factorialk)*(factorialnk));

        cout << "\nTong S3 la: " << S3;

    }

}