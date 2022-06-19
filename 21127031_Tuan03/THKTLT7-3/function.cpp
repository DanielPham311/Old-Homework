#include <iostream>
#include "function.h"
#include <fstream>

using namespace std;
/*
File INP gồm có 3 dòng:
- Dòng thứ nhất lần lượt chứa n và W
- Dòng thứ hai gồm khối lượng từng vật từ 1 đến n
- Dòng thứ ba gồm giá trị của từng vật từ 1 đến n

File OUT gồm hai dòng:
- Dòng thứ nhất gồm giá trị lớn nhất có thể thu được của các vật
- Dòng thứ hai là vị trí của các vật được lấy
*/

//a[] : mảng lưu khối lượng các vật, c[]: mảng lưu giá trị của từng vật, n: số lượng vật, W: giới hạn khối lượng
void ReadFromFile(int a[], int c[], int &n, int &W) //Hàm đọc thông tin input tù file INP.txt
{
    ifstream myfile;
    myfile.open("INP.txt");
    if (myfile.is_open()) //kiểm tra tình trạng mở file thành công
    {
        myfile >> n >> W;
        for (int i=1; i<=n; ++i)
        {
            myfile >> a[i];
        }

        for (int j=1; j<=n; ++j)
        {
            myfile >> c[j];
        }
        myfile.close();
    }
    else cout << "Unable to open file";
}

void Solve(int a[], int c[], int n, int W, Array2D f) //Hàm tính toán và lưu trữ kết quả vào bảng
{
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= W; ++j)
        {
            if(a[i] <= j) f[i][j] = max(f[i-1][j],f[i-1][j-a[i]] + c[i]); //Nếu lấy vật i 
            else f[i][j] = f[i-1][j]; //Nếu không lấy vật i
        }
    }
}

void Results(Array2D f, int n, int W, int a[]) //Hàm truy vết kết quả và ghi vào file OUT.txt
{
    ofstream fileout;
    fileout.open("OUT.txt");
    if (fileout.is_open()) //kiểm tra tình trạng mở file
    {
        fileout << f[n][W] << endl; //Xuất ra giá trị lớn nhất lấy được
        while (n>0)
        {
            if (f[n][W] != f[n-1][W]) //nếu có lấy vật i
            {
                fileout << n << " "; //Xuất ra vị trí từng vật
                W = W - a[n]; //cập nhật giới hạn khối lượng
            }
            n--;
        }
        fileout.close();
    }
    else cout << "Unable to open file";
}