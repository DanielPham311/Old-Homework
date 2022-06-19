    #include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Info{
    char name[33];
    int age;
    char address[41];
    char phone[11];
};

int main()
{
    // int m = 3;
    // Info persons[] = {
    //     {"Van", 20, "Nguyen Van Cu", "0907020202"},
    //     {"Khang", 20, "Nguyen Van Troi", "0907030303"},
    //     {"Hung", 20, "Dien Bien Phu", "0907040404"},
    // };
    
    fstream file;
    // file.open("d:/data/people.dat", ios::out | ios::binary); //unix-style file name
    // file.write((char *)&m, sizeof(m));
    // file.write((char *)&persons, sizeof(Info) * 3); //size of (persons) to write all, else sizeof(Info) * n where n is the number of people wanted to enter

    // file.close();

    int n;
    Info data[100];
    Info person;
    file.open("d:/data/people.dat", ios::in | ios::binary); //unix-style file name
    file.seekg(sizeof(int) + 1 * sizeof(Info), ios::beg);
    file.read((char *)&person, sizeof(person));
    cout << person.name << " " << person.age << " " << person.address << " " << person.phone << endl;
    file.seekg(0,ios::end);
    cout << file.tellg() << endl; //size of file
    // file.read((char *)&n, sizeof(int));
    // cout << n << endl;
    // file.read((char *)data, sizeof(Info) * n);
    // for (int i=0; i<n; ++i)
    // {
    //     cout << data[i].name << endl;
    //     cout << data[i].age << endl;
    // }
    file.close();
}