#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    // int n = 10;
    // long long m = 17;
    // int a[] = {4,5,6,7,8,9,10,12};
    fstream file;
    // file.open("d:\\data\\numbers.dat", ios::out | ios::binary); //windows-style file name
    // //file.open("e:/data/numbers.dat", ios::out | ios::binary); //unix-style file name

    // file.write((char *)&n, sizeof(n));
    // file.write((char *)&m, sizeof(m));
    // file.write((char *)a, sizeof(a));
    // file.close();

    //read operations:
    file.open("d:/data/numbers.dat", ios::in | ios::binary); //windows-style file name
    int data;
    file.read((char *)&data, 4);
    cout << data << endl;
    long long data2;
    file.read((char *)&data2, 8);
    cout << data2 << endl;
    int data3[100];
    int n = 8;
    file.read((char *)data3, n*sizeof(int));
    for (int i=0; i<n; ++i)
        cout << data3[i] << " ";
    file.close();
}