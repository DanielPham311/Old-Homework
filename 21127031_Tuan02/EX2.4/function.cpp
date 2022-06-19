#include <iostream>
#include <string.h>
#include "function.h"

using namespace std;

void Input(char seq[]) //Hàm nhập chuỗi
{
    cout << "String input: ";
    cin.getline(seq,MAX,'\n');
}

void Output(char seq[], int end, int start) //Hàm xuất chuỗi từ vị trí start đến vị trí end
{
    cout << "New string that lies in parentheses: ";
    for (int i=start; i<end; ++i)
    {
        cout << seq[i];
    }
}

int ParenBit(char seq[], int n, int &i) //Hàm chính, sẽ trả về vị trí của ký tự '(' để ta truy xuất từ đó đến i (vị trí của ')')
{
    if (seq[n] == '(') return n;

    if (seq[n] == ')')
    {
        i = n; //lưu vị trí của ký tự ')'
        return ParenBit(seq,n-1, i);
    }
    
    else return ParenBit(seq,n-1, i);
}