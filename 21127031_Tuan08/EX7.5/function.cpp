#include <iostream>
#include <fstream>
#include <string.h>
#include <set>
#include <iterator>
#include "function.h"

using namespace std;

void Read(set<string> &s) //Function: Reading words from a text file into a set of string type
{
    ifstream fin;
    string temp;
    fin.open("INP.txt");
    if (fin.is_open()) //checking if the file is successfully opened
    {
        while (fin >> temp)
        {
            if (!s.count(temp)) //if the word is not found in the set (unique word)
            {
                s.insert(temp); //insert
            }
        }
    }
    else cout << "Unable to open file";
}

void Output(set<string> s)//Function: Printing values in the set
{
    set <string>::iterator itr;
    for (itr = s.begin(); itr != s.end(); ++itr)
    {
        cout << *itr << endl;
    }
}