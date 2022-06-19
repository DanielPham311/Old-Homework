#include <iostream>
#include "function.h"
#include <fstream>

using namespace std;
/*
File INP.txt gồm các dòng:
- Dòng thứ nhất chứa lần lượt số hàng và số cột của ma trận
- rows dòng và cols cột tiếp theo chứa ma trận rows x cols

File OUT.txt sẽ chứa tổng đường đi lớn nhất từ cột 1 sang cột n
*/

//rows: số hàng, cols: số cột
void ReadFromFile(Array2D A, int &rows, int &cols) // Hàm đọc dữ liệu input từ file INP.txt
{
    ifstream fin;
    fin.open("INP.txt");
    if (fin.is_open()) //kiểm tra tình trạng mở file
    {
        fin >> rows >> cols;
        for (int i=1; i<=rows; ++i)
            for (int j=1; j<=cols; ++j)
            {
                fin >> A[i][j];
            }
        fin.close();
    }
    else cout << "Unable to open file";
}

int Max(int a, int b, int c) //Hàm tìm ra số lớn nhất trong ba số
{
    if (a>b && a>c) return a;
    else if (b>a && b>c) return b;
    else return c;
}

int Solve(Array2D A, Array2D f, int rows, int cols) //Hàm giải và lưu trữ kết quả vào bảng
{
    for (int i = 1; i<=rows; ++i)
        for (int j=1; j<=cols; ++j)
        {
            f[i][j] = 0; //khởi tạo các giá trị trong bảng
        }

    for (int i = 1; i<=rows; ++i) f[i][1] = A[i][1]; // base case: cột đầu tiên của ma trận

    for (int j=2; j<=cols; ++j)
        for (int i=1; i<=rows; ++i)
        {
            f[i][j] = Max(f[i][j-1], f[i-1][j-1], f[i+1][j-1]) + A[i][j]; //có 3 hướng đi đến ô (i,j) nên ta lấy ô lớn nhất trước đó cộng với giá trị ô hiện tại
        }
    
    int results = 0;
    for (int i=1; i<=rows; ++i)
    {
        if (f[i][cols] > results) results = f[i][cols]; //tìm giá trị lớn nhất được lưu ở cột cuối cùng của bảng giá trị
    }
    return results;
}

void Results(Array2D f, Array2D A, int rows, int cols) //Hàm xuất kết quả vào file OUT.txt
{
    ofstream fout;
    fout.open("OUT.txt");
    if (fout.is_open()) //kiểm tra tình trạng mở file
    {
        fout << Solve(A,f,rows,cols); 
        fout.close();
    }
    else cout << "Unable to open file";
}