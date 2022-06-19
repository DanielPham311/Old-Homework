#include <fstream>
#include <iostream>
#include "function.h"
#include <string.h>

using namespace std;

typedef struct SoTrau
{
    int SoTD, SoTN, SoTG;
}ST;

typedef struct LuuNghiem
{
    ST array[100];
    int SoCapNghiem;
}LN;

bool TimSoTrau(int &SoTD, int &SoTN, int &SoTG, int TongSoTrau = 100, int TongSoCo = 100, int min=0)
{
    for (SoTD = min; SoTD <= TongSoCo/5; SoTD++)
    {
        int SoTN_TG = TongSoTrau - SoTD;
        for (SoTG = 0; SoTG <= SoTN_TG; SoTG+=3)
        {
            SoTN = SoTN_TG - SoTG;
            if (SoTD * 5 + SoTN * 3 + SoTG / 3 ==TongSoCo)
                return true;
        }        
    }    
    return false; 
}

void TimNghiem(LN &n, LN array[100])
{
    int sotd, sotn, sotg;
    while ( )
}

int main()
{
    int SoCon = 100, SoCo = 100;
    LN A;
    A.SoCapNghiem = 0;
}
