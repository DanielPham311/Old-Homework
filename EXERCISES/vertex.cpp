#include <iostream>
#include <cmath>

using namespace std;

#define MAX 100

struct vertex
{
    double x,y;
};

double Vertex(vertex list[], int n)
{
    vertex *p = list;
    vertex *pn = list + 1;
    double ver = 0;
    for (int i =0; i<n-1; i++)
    {
        ver += (((p->x) * ((pn)->y)) - ((pn)->x * p->y));
        p = pn;
        pn++;
    }
    pn = list;
    ver += (((p->x) * ((pn) ->y)) - ((pn)->x * p->y));
    return abs(ver) / 2;
}

int main()
{
    vertex list[MAX] = 
    {
        {2,2},
        {5,2},
        {5,5},
        {2,5},
    };
    int n = 4;
    cout << Vertex(list,n);
}