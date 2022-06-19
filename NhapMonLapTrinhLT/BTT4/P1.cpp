#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cout << "Nhap vao so nguyen duong n: ";
	cin >> n;
	double sum1(0);
	long sum2(0);
	long bien(1);
	long sum3(0);
	//Tinh S = 1 + 1/2 + ... + 1/n
	for (int a = 1; a <= n; a++) {
		sum1 = sum1 + 1.0 / a;
	}
	//Tinh S = 1! + 2! + ... + n!
	for (int b = 1; b <= n; b++) {
		bien = bien * b;
		sum2 += bien;
	}
	//Tinh  S = pow(1,1) + pow(2,2) + pow(3,3) + ... + pow(n,n)
	for (int c = 1; c <= n; c++) {
		sum3 += pow(c, c);
	}
	cout << "Gia tri cua bieu thuc 1: " << sum1 << endl;
	cout << "Gia tri cua bieu thuc 2: " << sum2 << endl;
	cout << "Gia tri cua bieu thuc 3: " << sum3 << endl;
	system("pause");
	return 0;
}