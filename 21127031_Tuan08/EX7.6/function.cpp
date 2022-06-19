#include <iostream>
#include <string.h>
#include <map>
#include <iterator>
#include <fstream>
#include <time.h>
#include <conio.h>
#include "function.h"

using namespace std;

void Input(map <string, string> &US) //Function: Adding the keys and values (states and capitals) from file into map
{
    ifstream fin;
    string temp1, temp2; //temporary string representing state,capital
    fin.open("States.txt");
    if (fin.is_open()) //checking if the file is opened successfully
    {
        while (fin >> temp1 && fin >> temp2)
        {
            US.insert(make_pair(temp1,temp2));
        }
        fin.close();
    }
    else cout << "Unable to open file";
}

void Quiz(map <string,string> US) //Function: Quiz
{
    srand(time(nullptr));
    char key;
    int cor = 0, incor = 0; // variables used to update the number of corresponding answers
    do
    {
        map <string,string> :: iterator itr;
        itr = US.begin();
        advance(itr, rand() % US.size()); //moving the iterator to a random key in the map

        string tmp = itr->first;
        string ans;
        cout << "What is the capital of the following state in the USA (please type _ between two words if there are more than two words): " << endl;
        cout << tmp << endl;

        cout << "Your answer: ";
        cin >> ans;

        //Updating the number of correct or incorrect answers corresponding to user's answer
        if (ans == itr->second)
        {
            cout << "You have " << ++cor << " correct answers" << endl;
            cout << "You have " << incor << " incorrect answers" << endl;
        }

        else 
        {
            cout << "You have " << cor << " correct answers" << endl;
            cout << "You have " << ++incor << " incorrect answers" << endl;
        }

        cout << "Would you like to stop playing? (Press Esc to exit)" << endl; //press Esc to quit game
        cin.ignore();
        key = getch();
    } 
    while (key != 27);
    
    cout << "\nThank you for playing" << endl;
}