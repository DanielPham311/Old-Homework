#include <iostream>
#include <string>
using namespace std;

double fibo(int n) {	
// rewrite bin function
int bin(int n, int k) {
	int B[100][100]; // table n + 1 x n + 1
	int(*p)[100];
	int *q = new int[(n + 1) * 100];
	p = (int(*)[100]) q;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= i; j++)
			if (j==0 || j==i)
				p[i][j] = 1;
			else
				p[i][j] = p[i - 1][j - 1] + p[i - 1][j];
	int r = p[n][k];
	delete[] q;
	return r;
}
void mySwap(int* & a, int *& b) {

void main() {
	cout << computeBin(4, 2) << endl;

}