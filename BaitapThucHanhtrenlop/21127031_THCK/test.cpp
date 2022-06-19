#include<iostream>
#include<fstream>
using namespace std;

main()
{
    ifstream a("Danh sach hoc sinh.txt",ios::in);

    int b,i=0;

    a>>b;

    char c[b][10000];

    while(i<b && a.getline(c[i],10000,'\0'))
    {   
        cout<<c[i];
        i++;
    }

}   