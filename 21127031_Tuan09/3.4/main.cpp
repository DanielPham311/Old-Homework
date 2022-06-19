#include <iostream>
#include <stack>
#include <string.h>
#include "function.h"

using namespace std;

int main()
{
    Stack ar;
    queue nums;
    Innit(nums);
    Innit(ar);

    string express;
    StringInp(express);

    RPN(ar,nums,express);
    PrintRPN(nums);

    cout << "\nThe result of the given mathematical expression is: " << Calculate(nums);
}