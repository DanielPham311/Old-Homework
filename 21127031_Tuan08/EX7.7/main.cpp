#include <iostream>
#include <map>
#include <set>
#include "function.h"

using namespace std;

int main()
{
    map <string, set<int>> words;
    Read(words);
    PrintMap(words);
}