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

void InputStr(std::string &s);

bool Is_PalindromeLv1(std::string s, Stack &stack);

bool Is_PalindromeLv2(std::string s, Stack &stack, queue &q);
