#define MAXLEN 256

struct Student
{
    char *Name = new char[256];
    int Age;
    char *Address = new char[256];
};

void Input(Student &a);

void StrOut(char *str);

void Print(Student a);
