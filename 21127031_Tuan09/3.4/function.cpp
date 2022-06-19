#include <iostream>
#include <stack>
#include <string.h>
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

void StringInp(string &exp)
{
    cout << "Enter the mathematical expression: ";
    getline(cin,exp);
}

int ArithLv(char ar) //Function: returning the level priority of an operator
{
    if (ar == '*' || ar == '/') return 2;
    else if (ar == '+' || ar == '-') return 1;
}

bool IsNumber(char c) //Function: checking if a character is a number
{
    if (c >= 48 && c <= 57) return true;
    return false;
}

bool IsOperator(char c) //Function: checking if a character is an operator
{
    if (c == '+' || c == '-' || c == '*' || c == '/') return true;
    return false;
}

void RPN(Stack &ar, queue &nums, string exp) //Function: converting the mathematical expression to an RPN 
{
    for (int i=0; i<exp.length(); ++i)
    {
        if (IsNumber(exp.at(i))) //if the character is a number
        {
            Enqueue(nums,exp.at(i)); //add to the number queue
        }

        else if (IsOperator(exp.at(i))) //if the character is an operator
        {
            if (ArithLv(exp.at(i)) <= ArithLv(Top(ar)) && Top(ar) != '(') //if the level of the operator is lower or equal to the top of stack's level
            {
                Enqueue(nums,Top(ar)); //enqueue the top element of the stack 
                Pop(ar);
                Push(ar,exp.at(i)); //pushing the operator to the stack
            }

            else if (ArithLv(exp.at(i)) > ArithLv(Top(ar)) || Top(ar) == '(' || IsEmpty(ar)) //if the level of the operator is higher or the top element is a left parathesis or the stack is empty
            {
                Push(ar,exp.at(i)); //pushing the operator to the stack
            }
        }

        else if (exp.at(i) == ')') //if the element at the position is a right parathesis
        {
            do
            {
                Enqueue(nums,Top(ar));
                Pop(ar); //enqueuing the top of stack until we meet left parathesis
            } while (Top(ar) != '(');
            Pop(ar); //pop the left parathesis
        }

        else if (exp.at(i) == '(') Push(ar,exp.at(i)); //add the left parathesis to stack
    }
    Enqueue(nums,Top(ar));
    Pop(ar); //add the rest of the stack to the queue and pop it all out
}

void PrintRPN(queue nums)//Function: printing the RPN
{
    cout << "Mathematical expression to RPN: ";
    while (!IsEmpty(nums))
    {
        cout << Front(nums) << " ";
        Dequeue(nums);
    }
}

float CharToNum(char c) //Function: converting number characters to float
{
    float value;
    value = c;
    return (float)(value -'0');
}

float Operation(float a, float b, char op) //Function: Executing operations
{
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else if (op == '*') return a * b;
    else if (op == '/') return a / b;
    else return -1;
}

float Calculate(queue RPN) //Function: Calculate based on RPN and return the result
{
    stack <float> res; //result stack
    while (!IsEmpty(RPN))
    {
        if (IsNumber(Front(RPN))) 
        {
            float num = CharToNum(Front(RPN));
            res.push(num); //changing the character to number and push it back to result stack
        }

        if (IsOperator(Front(RPN))) //when we meet an operator
        {
            float num1 = res.top();
            res.pop();
            float num2 = res.top();
            res.pop(); 
            res.push(Operation(num2,num1,Front(RPN))); //popping the two numbers, swap their place and execute the corresponding operation
        }
        Dequeue(RPN);
    }
    return res.top(); //return the final result
}