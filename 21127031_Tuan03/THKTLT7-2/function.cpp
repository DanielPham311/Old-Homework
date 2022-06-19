#include <iostream>
#include "function.h"
#include <fstream>

using namespace std;
/* File INP.txt gồm hai dòng:
- Dòng thứ nhất chứa hai số n, W
- Dòng thứ hai lần lượt chứa khối lượng của vật 1 đến vật n

File OUT.txt xuất ra vị trí của các vật sẽ được lấy
*/

// W: giới hạn khối lượng, n: số đồ vật, a[]: mảng để lưu khối lượng các vật
void ReadFromFile(int a[], int &n, int &W) //Hàm đọc các giá trị input từ file INP.txt
{
    ifstream myfile;
    myfile.open("INP.txt");
    if (myfile.is_open()) //kiểm tra tình trạng mở file
    {
        myfile >> n >> W;
        for (int i=0; i<n; ++i)
        {
            myfile >> a[i];
        }
        myfile.close();
    }
    else cout << "Unable to open file";
}

void Solve(int a[], int n, int W, Array2D f) //Hàm tính toán và lưu trữ bảng kết quả
{
    //base cases
    for(int i = 0; i <= n; ++i) f[i][0] = 0;
    f[0][0] = 1;

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j <= W; ++j)
        {
            f[i][j] = f[i-1][j]; //Nếu không lấy vật thứ i
            if(j - a[i-1] >= 0) f[i][j] = max(f[i-1][j],f[i-1][j-a[i-1]]); //Nếu chọn vật thứ i
        }
    }
}

void Results(Array2D f, int n, int W, int a[]) //Hàm truy vết các vật đã lấy và ghi vào file OUT.txt
{
    ofstream fileout;
    fileout.open("OUT.txt");
    if (fileout.is_open())
    {
        while (n>0) 
        {
            if (f[n][W] != f[n-1][W]) //nếu có lấy vật i
            {
                fileout << n << " "; //xuất vị trí của vật i
                W = W - a[n-1]; //giảm giới hạn khối lượng xuống
            }
            n--;
        } 
        fileout.close();
    }
    else cout << "Unable to open file";
}