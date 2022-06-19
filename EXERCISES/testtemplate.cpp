#include <iostream>
using namespace std;

template <typename T>
struct node {
	T data;
	node <T>* next;
};

template <typename T>
node <T>* createnode(T x)
{
	node <T>* p = new node<T>;
	p->data = x;
	p->next = NULL;
	return p;
}

template <typename T>
void PrintList(node <T>* a)
{
	node <T>* temp = a;
	while (temp != NULL)  
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

template <typename T>
void addHead(node <T>* &head, T x)
{
	node <T>* oldhead = head;
	head = createnode(x);
	head->next = oldhead;
}

int main()
{
    node<string> *headstring = nullptr;

    addHead(headstring, string("Kaka"));
    PrintList(headstring);
}