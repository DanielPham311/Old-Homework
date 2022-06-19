#define MAX 100

typedef int Array2D[MAX][MAX]; 

void ReadFromFile(Array2D A, int &rows, int &cols);

int Solve(Array2D A, Array2D f, int rows, int cols);

int Max(int a, int b, int c);

void Results(Array2D f, Array2D A, int rows, int cols);
