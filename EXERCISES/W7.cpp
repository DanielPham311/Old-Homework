// W7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
float* inputArray(int& n) {
    cin >> n;
    float* a = new float[n];
    for (int i = 0;i < n;i++)
        cin >> *(a + i);
    return a;
}
void outputArray(float* a, int n) {
    for (int i = 0;i < n;i++)
        cout << a[i] << "\t";
    cout << endl;
}
double fibo(int n) {
    double* a = new double[n + 1];
    if (a == nullptr)
        exit(1);
    if (n < 2)
        return 1;
    double r;
    if (a != NULL) {
        *a = *(a + 1) = 1;
        for (double* i = a + 2;i <= a + n;i++)
            *i = *(i - 1) + *(i - 2);
    }
    r = *(a + n);
    delete[]a;
    return r;
}
int main()
{
    
    /*int n;
    float* a;
    a = inputArray(n);
    if (a == nullptr) {
        cout << "Error!";
        exit(1);
    }
    outputArray(a, n);*/
    cout << fibo(6) << endl;
    return 0;
}


