#include <iostream>
#include <string>
#include "function.h"

using namespace std;

int main()
{
    Stack stack;
    queue q;
    Innit(stack);
    Innit(q);

    string s;
    InputStr(s);

    // if (Is_PalindromeLv1(s, stack)) cout << "This is a palindrome" << endl;
    // else cout << "This is not a palindrome" << endl;

    if (Is_PalindromeLv2(s, stack, q)) cout << "This is a palindrome" << endl;
    else cout << "This is not a palindrome" << endl;
}
//Completed version of exercise 3.3(fixed function lv2 palindrome)