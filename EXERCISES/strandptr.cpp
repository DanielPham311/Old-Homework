#include <iostream>

using namespace std;

#define MAXLEN 100

typedef struct Student
{
    char ID[MAXLEN];
    char Name[MAXLEN];
    int YOB;
    double Avg; 
}ST;

void Print(Student *list, int n)
{
    Student *temp = list;
    for (int i=0; i<n; ++i)
    {
        cout << (temp + i)->ID << "|";
        cout << (temp + i)->Name << "|";
        cout << (temp + i)->YOB << "|";
        cout << (temp + i)->Avg << "|";
        cout << endl;
    }
}

int main()
{
    ST list[MAXLEN] =
    {
        {"21127031", "Duy", 2003, 9.0},
        {"101", "Lmao", 2420, 6.9},
        {"102", "Dakwa", 2690, 4.2},
    };
    int n = 3;
    Print(list,3);
}