#include <iostream>
#include <string.h>
#include <set>
#include <map>
#include <fstream>
#include <iterator>
#include "function.h"

using namespace std;

void DetachWord(string s, map <string, set<int>> &words, int line) //Function: Detach each word in a line and mark them correspondingly with the line number
{
    int pos = 0;
    string tmp;

    while ((pos = s.find(" ")) != string::npos) //finding the position of " " (capture a word)
    {
        tmp = s.substr(0,pos);
        words[tmp].insert(line); //insert the word to the map
        s.erase(0,pos+1); //erase the word from the line

        if ((pos = s.find(" ")) == string::npos) //last word in a line
        {
            tmp = s.substr(0,pos); 
            words[tmp].insert(line); //add the last word
        }
    }
}

void Read(map <string, set<int>> &words) //Function: adding words from file to map
{
    ifstream fin;
    string temp;
    int line = 1; //line marker
    fin.open("Kennedy.txt");
    if (fin.is_open()) //checking if the file is successfully opened
    {
        while (getline(fin,temp))
        {
            DetachWord(temp,words,line);
            line++;
        }
        fin.close();
    }
    else cout << "Unable to open file";
}

void PrintMap(map <string, set<int>> words) //Function: Printing the map into index.txt
{
    map <string, set<int>> :: iterator itr1;
    ofstream fout;
    fout.open("index.txt");
    if (fout.is_open()) //checking if the file is opened successfully
    {
        for (itr1 = words.begin(); itr1 != words.end(); ++itr1)
        {   
            fout << (itr1->first) << ": "; //word
            set<int> :: iterator itr;
            for (itr = itr1->second.begin(); itr != itr1->second.end(); ++itr)
            {
                fout << *itr << " "; //lines that the word appear
            }
            fout << endl;
        }
        fout.close();
    }
    else cout << "Unable to open file";
}
