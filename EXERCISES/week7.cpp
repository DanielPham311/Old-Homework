#include <iostream>
#include <string>
using namespace std;

double fibo(int n) {		double* dp = new double[n + 1];	if (dp == nullptr) exit(1);	if (n < 2) return 1;		double *fi1 = dp + 1;	double *fi2 = dp;	*fi1 = 1;	*fi2 = 1;	for (double *fi = dp + 2; fi <= dp + n; fi++) {		*fi = *fi1 + *fi2;		fi2 = fi1;		fi1 = fi;	}	double ans = *(dp + n);	delete[] dp;	return ans;}
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
void mySwap(int* & a, int *& b) {	int * c = b;	b = a;	a = c;}int computeBin(int n, int k) {	int * a = new int[n+1];	int * b = new int[n+1];	for (int i = 0; i <= n; ++i) {		for (int j = 0; j <= i; ++j) {			if (j == 0 || j == i) 				*(b + j) = 1;			else				*(b + j) = *(a + j - 1) + *(a + j);		}		mySwap(a, b);	}	int r = *(a + k);	delete[] a;	delete[] b;	return r;}

void main() {
	cout << computeBin(4, 2) << endl;

}