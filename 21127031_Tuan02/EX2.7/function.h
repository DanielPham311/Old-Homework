#define MAX 100 //kích thước tối đa của mảng

extern int size; //biến toàn cục lưu trữ dữ liệu của kích thước mảng

void ArrayInput(int a[], int &size);

bool ArraySplit(int a[]);

bool HelperFunc(int index, int a[], int gr1, int gr2);
