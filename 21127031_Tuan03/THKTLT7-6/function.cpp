#include <iostream>
#include <fstream>
#include "function.h"

using namespace std;
/*
File INP.txt gồm:
- Dòng đầu tiên chứa lần lượt các số nguyên dương M và N
- Dòng tiếp theo là dãy số nguyên A[1..M]
- Dòng cuối cùng là dãy số nguyên B[1..N]

File OUT.txt gồm:
- Dòng đầu là n: độ dài của chuỗi con chung lớn nhất
- n dòng sau: các cặp (i,j) là phần tử của chuỗi con (A[i] == B[j])
*/

void ReadFromFile(int A[], int B[], int &M, int &N) //Hàm đọc và nhận input từ file INP.txt
{
    ifstream fin;
    fin.open("INP.txt");
    if (fin.is_open()) //kiểm tra tình trạng mở file
    {
        fin >> M >> N;
        for (int i=1; i<=M; ++i)
            fin >> A[i];
        for (int j=1; j<=N; ++j)
            fin >> B[j];
        
        fin.close();
    }
    else cout << "Unable to open file";
}

void Solve(Array2D f, int A[], int B[], int M, int N) //Hàm tính toán và lưu kết quả vào bảng
{
    for (int i=1; i<=M; ++i) f[i][0] = 0; 
    for (int j=1; j<=N; ++j) f[0][j] = 0; //Các trường hợp không tồn tại chuỗi con

    for (int i=2; i<=M; ++i)
        for (int j=2; j<=N; ++j)
        {
            if (A[i] == B[j]) f[i][j] = f[i-1][j-1] + 1; //nếu tìm được phần tử giống nhau
            else f[i][j] = max(f[i][j-1], f[i-1][j]);
        }
}

void Results(Array2D f, int A[], int B[], int M, int N) //Hàm truy vết kết quả và ghi vào file OUT.txt
{
    ofstream fout;
    fout.open("OUT.txt");
    if (fout.is_open())
    {
        fout << f[M][N] << endl; // Ghi độ dài của dãy chung lớn nhất của hai dãy
        while (M>0 && N>0)
        {
            if (A[M]==B[N]) //Nếu tìm được hai phần tử giống nhau của hai dãy
            {
                fout << "(" << M << "," << N << ")" << endl; //in ra vị trí (i,j)
                M--;
                N--;    
            }

            else //tiếp tục truy vấn
            {
                if (f[M][N] == f[M-1][N]) M--; 
                else if (f[M][N] == f[M][N-1]) N--;
            } 
        }
        fout.close();
    }
    else cout << "Unable to open file";
}