#include <stack>

#define MAX 100

struct Stack
{
    char array[MAX];
    int top;
    int size;
};

struct queue
{
    char array[MAX];
    int front;
    int rear;
};

void Innit(Stack &stack);

bool IsEmpty(Stack stack);

void Push(Stack &stack, char item);

char Top(Stack &stack);

void Pop(Stack &stack);

void Innit(queue &q);

bool IsEmpty(queue q);

void Enqueue(queue &q, char item);

void Dequeue(queue &q);

char Front(queue q);

void StringInp(std::string &exp);

int ArithLv(char ar);

bool IsNumber(char c);

bool IsOperator(char c);

void RPN(Stack &ar, queue &nums, std::string exp);

void PrintRPN(queue nums);

float CharToNum(char c);

float Operation(float a, float b, char op);

float Calculate(queue RPN);
