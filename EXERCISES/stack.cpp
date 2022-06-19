#include <iostream>
#include <string>

using namespace std;

#define MAX 100

template <typename T>
struct Stack
{
    T array[MAX];
    int top;
    int size;
};

template <typename T>
void innit(Stack <T> &stack)
{
    stack.top = -1;
    stack.size = 0;
}

template <typename T>
bool IsEmpty(Stack <T> stack)
{
    return stack.top == -1;
}

template <typename T>
void push(Stack <T> &stack, T item)
{
    stack.top ++;
    stack.array[stack.top] = item;
}   

template <typename T>
T top (Stack <T> &stack)
{
    return stack.array[stack.top];
}

template <typename T>
void pop(Stack <T> &stack)
{
    stack.top--;
}

template <typename T>
string Convert(T decimal)
{
    Stack <char> bin;
    innit(bin);
    while (decimal>0)
    {
        if (decimal%2==0) push(bin,'0');
        else push(bin,'1');

        decimal/=2;
    }

    string ans= " ";
    while (!IsEmpty(bin))
    {
        ans += top(bin);
        pop(bin);
    }
    return ans;
}

string convertToHex(long long value)
{
    Stack <char> ans;
    innit(ans);
    long long tmp;
    char tam;
    while (value > 0)
    {
        tmp = value % 16;
        if (tmp < 10)
        {
            tam=(char)(tmp+48);
            push(ans, tam);
        }
        else
        {
            tam=(char)(tmp+55);
            push(ans, tam);
        }
        value /= 16;
    }

    string out = "";
    while (!IsEmpty(ans))
    {
        out += top(ans);
        pop(ans);
    }
    return out;
}

// bool Check(int Push[], int Pop[], int n)
// {
//     Stack <int> ans;
//     innit(ans);
//     int j = 0;
//     for(int i=0; i<n; ++i)
//     {
//         push(ans,Push[i]);
//         while (j<(n-1) && !IsEmpty(ans) && Pop[j] == top(ans))
//         {
//             pop(ans);
//             j++;
//         }
//     }
//     return ;
// }

double compute(string s)
{
    Stack <char> op;
    Stack <int> value;
    innit(value); innit(op);

    for (int i=0; i<s.length(); ++i)
    {
        if (s.at(i) == '+' || s.at(i) == '-' || s.at(i) == '*' || s.at(i) == '/')
            push(op,s.at(i));
        if (s.at(i) <= 57 && s.at(i) >= 48)
        {
            int temp;
            while (s.at(i+1) <= 57 && s.at(i+1) <= 48)
            {
                temp = s.at(i+1) + s.at(i);
                i++;
            }
            push(value,temp);
        }

        if (s.at(i) == ')')
        {
            pop(op);
        }
    }
    return 1;
}

int main()
{
    // long long n;
    // cout << "Input a decimal: ";
    // cin >> n;

    // cout << Convert(n);

    //cout << convertToHex(1567);

    string s = "((5+6) * 10)";
    cout << compute(s);
}