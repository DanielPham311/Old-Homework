#include <iostream>
#include <string.h>
#include "function.h"

using namespace std;

int main()
{
    char seq[MAX];
    Input(seq);
    int size = strlen(seq); 

    int i = 0; //biến i dùng để ghi lại vị trí của ký tự ')'

    int a = ParenBit(seq,size,i);
    Output(seq,i+1,a);
}