#include <iostream>
#include <vector>

#define MAX 100

template <typename T>
struct queue
{
    T array[MAX];
    int front;
    int rear;
};

using namespace std;

template <typename T>
void Innit(queue <T> &q)
{
    q.front = 0;
    q.rear = 0;
}

template <typename T>
bool IsEmpty(queue <T> q)
{
    if (q.front = q.rear) return true;
    else return false;
}

template <typename T>
void enqueue(queue <T> &q, T item)
{
    if (q.rear == MAX) q.rear = 0;
    else 
    {
        q.array[q.rear] = item;
        q.rear++;
    }
}
template <typename T>
void dequeue(queue <T> &q)
{
    q.front++;
    if (q.front == MAX) q.front = 0;
}

template <typename T>
T front(queue <T> q)
{
    return q.array[q.front];
}

int main()
{
    queue <char> q;
    Innit(q);
    enqueue(q,'A');
    enqueue(q,'B');
    enqueue(q,'C');
    enqueue(q,'D');
    enqueue(q,'E');
    enqueue(q,'F');
    
    while (!IsEmpty(q))
    {
        cout << front(q) << endl;
        dequeue(q);
    }
}