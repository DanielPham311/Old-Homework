#define MAX 100
#define MAXW 10000

typedef int Array2D[MAX][MAX];

void ReadFromFile(int a[], int c[], int &n, int &W);

void Solve(int a[], int c[], int n, int W, Array2D f);

void Results(Array2D f, int n, int W, int a[]);