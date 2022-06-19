#include <iostream>
#include <string>
#include "function.h"

using namespace std;

void Innit(Stack &stack)
{
    stack.top = -1;
    stack.size = 0; 
}

bool IsEmpty(Stack stack)
{
    return stack.top == -1;
}

bool IsFull(Stack stack)
{
    if (stack.top > stack.size) return true;
    return false;
}

void Push(Stack &stack, char item)
{
    if (IsFull(stack)) return;
    stack.top++;
    stack.size++;
    stack.array[stack.top] = item;
}

char Top(Stack &stack)
{
    return stack.array[stack.top];
}

void Pop(Stack &stack)
{
    if (IsEmpty(stack)) return;
    stack.top--;
    stack.size--;
}

void Innit(queue &q)
{
    q.front = 0;
    q.rear = 0;
}

bool IsEmpty(queue q)
{
    if (q.front == q.rear) return true;
    else return false;
}

void Enqueue(queue &q, char item)
{
    if (q.rear == MAX) 
    {
        cout << "Overflow" << endl;
        return;
    }
    else
    {
        q.array[q.rear] = item;
        q.rear++;
    }
}

void Dequeue(queue &q)
{
    if (IsEmpty(q))
    {
        cout << "Underflow" << endl;
        return;
    }

    else 
    {
        q.array[q.front] = 0;
        q.front++;
    }
}

char Front(queue q)
{
    return q.array[q.front];
}

void InputStr(string &s)
{
    cout << "Enter the string wanted to check: ";
    getline(cin,s);
}

bool Is_PalindromeLv1(string s, Stack &stack) //Function: Palindrome checking at lv1(basic Palindrome)
{
    if (s.length() == 0 || s.length() == 1) return true; 

    else 
    {
        for (int i=0; i<s.length(); ++i)
        {
            Push(stack,s.at(i)); //pushing characters to the stack
        }

        string ans = "";
        while (!IsEmpty(stack))
        {
            ans += Top(stack); //add the characters to a temporary string
            Pop(stack); //popping the characters
        }

        if (ans == s) return true; //if the temporary string (reversed) is the same as the string
        else return false;
    }
}

bool Is_PalindromeLv2(string s, Stack &stack, queue &q) //Function: Palindrome checking at lv2 (loose Palindrome)
{
    if (s.length() == 0 || s.length() == 1) return true;

    else 
    {
        for (int i=0; i<s.length(); ++i)
        {
            if (isupper(s.at(i))) Enqueue(q,tolower(s.at(i))); //if the character is capital character
            else if (((s.at(i)) >= 32 && (s.at(i)) <= 46) || ((s.at(i)) >= 58 && (s.at(i)) <= 64) || ((s.at(i)) >= 91 && (s.at(i)) <= 96) || ((s.at(i)) >= 123 && (s.at(i)) <= 127))
                continue; //if a character is not a word
            else Enqueue(q,s.at(i)); //Enqueue the character
        }

        string temp = "";
        while (!IsEmpty(q))
        {
            temp += Front(q);
            Dequeue(q);
        } //transfering the processed characters into a temporary string

        for (int i=0; i<temp.length(); ++i)
        {
            Push(stack,temp.at(i)); //pushing the temporary string into a stack (reversing)
        }

        string ans = "";
        while (!IsEmpty(stack))
        {
            ans += Top(stack);
            Pop(stack); 
        } //reversing the string by popping the characters from the stack to the result string

        if (ans == temp) return true;
        else return false;
    }
}