#define MAX 100

typedef int Array2D[MAX][MAX];

void ReadFromFile(int a[], int &n, int &W);

void Solve(int a[], int n, int W, Array2D f);

void Results(Array2D f, int n, int W, int a[]);