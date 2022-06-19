#include <iostream>
#include <string.h>
#include "function.h"

using namespace std;

int Recursive(char mainst[], char subst[])
{
    cout << "Enter main string: ";
    cin.getline(mainst,MAX,'\n');
    cout << "Enter sub string: ";
    cin.getline(subst,MAX,'\n');

    int mlength = strlen(mainst);
    int slength = strlen(subst);
    
    int left = -1, right = -1;
    strDist(mainst,subst,0,mlength,slength,left,right);
    if (left == -1 || right == -1) return slength;
    return right - left;
}

void strDist(char mainst[], char subst[], int index, int mlength, int slength, int &left, int &right)
{
    if (index >= mlength - slength + 1) return;
    if (strncmp(mainst,subst,slength) == 0)
    {
        if (left == -1) left = index;
        else right = index + slength;
    }
    index++;
    strDist(mainst,subst,index,mlength,slength,left,right);
}
