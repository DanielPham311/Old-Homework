#include <iostream>
#include "function.h"

using namespace std;

int size;

void ArrayInput(int a[], int &size) //Hàm nhập mảng
{
    cout << "Size of array : ";
    cin >> size;

    while (size <=0) //Xử lý các trường hợp nhập dữ liệu lỗi
    {
        cout << "Size can only be greater than 0, please try again" <<endl;
        cout << "Size of array : ";
        cin >> size;
    }

    for (int i=0; i<size; ++i)
    {
        cout << "a[" << i+1 << "]: ";
        cin >> a[i];
    }
}

bool GroupSum(int start, int nums[], int target) //Hàm chính của bài
{
    if(target == 0) return true; //trường hợp target trừ về đúng bằng 0
    if(target < 0) return false; //trường hợp target trừ về <0 (không tính được)

    int remainder = target - nums[start];
    if (GroupSum(start, nums, remainder)) return true;
    else return GroupSum(start + 1, nums, remainder);
}