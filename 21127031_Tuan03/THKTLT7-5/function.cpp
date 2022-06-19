#include <iostream>
#include <fstream>
#include "function.h"

using namespace std;
/*
File INP.txt gồm:
- Dòng thứ nhất chứa chỉ số h là chiều cao của tam giác
- h dòng tiếp theo là h tầng của tam giác với h giá trị ở mỗi tầng

File OUT.txt sẽ xuất ra:
- Dòng đầu tiên sẽ xuất ra giá trị lớn nhất của các ô trên đường đi
- h dòng tiếp theo là các tọa độ (i,j) của đường đi
*/

// h: chiều cao của tam giác, Array2D a: mảng 2 chiều để lưu tam giác sao cho A[i][j] là giá trị thứ j trong hàng i
void ReadFromFile(Array2D a, int &h) //Hàm đọc dữ liệu từ file INP.txt
{
    ifstream filein;
    filein.open("INP.txt");
    if (filein.is_open()) //kiểm tra tình trạng mở file
    {
        filein >> h;
        for (int i=1; i<=h; ++i)
            for (int j=1; j<=i; ++j)
            {
                filein >> a[i][j];
            }
        filein.close();
    }
    else cout << "Unable to open file";
}

int Solve(Array2D f, Array2D a, int h) //Hàm tính toán và lưu giá trị vào bảng 
{
    for (int i=1; i<=h; ++i) f[i][1] = f[i-1][1] + a[i][1]; //Các số nằm dọc theo cạnh trái của tam giác
    f[1][1] = a[1][1]; 
    
    for (int i=2; i<=h; ++i)
        for (int j=2; j<=i; ++j)
        {
            if (i==j) f[i][j] = f[i-1][j-1] + a[i][j]; //Các số nằm dọc theo cạnh phải của tam giác
            else f[i][j] = max(f[i-1][j-1], f[i-1][j]) + a[i][j]; //các số còn lại có 2 hướng đến nó
        }

    int results = 0;
    for (int j = 1; j<=h; ++j)
    {
        if (f[h][j] > results) results = f[h][j]; //tìm giá trị lớn nhất lưu ở hàng dưới cùng của bảng 
    }
    return results;
}

void Results(Array2D a, Array2D f, int h) //Hàm truy vết và xuất ra kết quả
{
    ofstream fout;
    fout.open("OUT.txt");
    if (fout.is_open()) //kiểm tra tình trạng mở file
    {
        int max = Solve(f,a,h);
        fout << max << endl;
        
        int j = 1; //biến đếm

        while (h>0)
        {
            if (max == f[h][j]) //nếu tìm được vị trí của giá trị max
            {
                fout << "(" << h << "," << j << ")" << endl; //Xuất vị trí 
                max -= a[h][j]; //cập nhật giá trị max (max = f[h-1][j] + a[h][j])
                j = 1; 
                h--; 
            }
            else j++;
        }
        fout.close();
    }
    else cout << "Unable to open file";
}