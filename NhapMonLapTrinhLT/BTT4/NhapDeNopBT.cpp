#include<iostream>
using namespace std;
int main()
{
	int n(1);
	int tong(0);
	int tich(1);
    int temp = 0; //bien tam
	while (n != 0) {
		cout << "Nhap vao so nguyen duong n: ";
		cin >> n;
    temp = n;
		while (temp)
	  {
			tong += temp % 10;
			tich *= temp % 10;
			temp = temp / 10;

    }
    
		cout << tong << endl;
		cout << tich << endl;
		if (tong == tich) {
			cout << "Tong bang tich" << endl;
		}
		else
			cout << "Tong khong bang tich" << endl;
	}
  system ("pause");
	
}