#include <iostream>
#include "function.h"

using namespace std;

int size;

void ArrayInput(int a[], int &size) //Hàm nhập mảng
{
    cout << "Size of array: ";
    cin >> size;

    while (size<=0) //Xử lý các trường hợp nhập dữ liệu lỗi
    {
        cout << "Size can only be greater than 0, please try again" << endl;
        cout << "Size of array : ";
        cin >> size;
    }

    for (int i=0; i<size; ++i)
    {
        cout << "a[" << i+1 << "] : ";
        cin >> a[i];
    }
}

bool ArraySplit(int a[]) //Hàm chính
{
    int gr1 = 0; //nhóm 1
    int gr2 = 0; //nhóm 2
    int index = 0; //trị số của mảng
    return HelperFunc(index,a,gr1,gr2);
}

bool HelperFunc(int index, int a[], int gr1, int gr2) //Hàm helper thực hiện công việc chính
{
    if (size == 1) return false; //không chia nhóm được
    else if (size == 2) //TH mảng chỉ có 2 phần tử
    {
        if (a[0] != a[1]) return false;
        else return true;
    }

    if (index == size)//dừng lại khi duyệt hết mảng
    {
        if (gr1 == gr2) return true; 
        else return false;
    }

    if (HelperFunc(index + 1, a, gr1 + a[index], gr2)) return true; 
    if (HelperFunc(index + 1, a, gr1, gr2 + a[index])) return true; 

    return false;
}