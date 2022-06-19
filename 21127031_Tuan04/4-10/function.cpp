#include <iostream>
#include "function.h"

using namespace std;

void Input(Student &a)
{
    cout << "Full name of student: " << endl;
    cin.getline(a.Name, MAXLEN, '\n');
    cout << "Student's address: ";
    cin.getline(a.Address, MAXLEN, '\n');
    cout << "Student's age: ";
    cin >> a.Age;
}

void StrOut(char *str)
{
    while (*str != '\0')
    {
        cout << *str;
        str++;
    }
}

void Print(Student a)
{
    cout << "Student's full name: ";
    StrOut(a.Name);
    cout << endl;
    cout << "Student's age: " << a.Age << endl;
    cout << "Student's address: ";
    StrOut(a.Address);
    cout << endl;
}