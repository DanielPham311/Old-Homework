#include <iostream>
using namespace std;
struct node {
	int data;
	node* next;
};

struct List
{
	node *head;
	int size;
};

node* createnode(int x)
{
	node* p = new node;
	p->data = x;
	p->next = NULL;
	return p;
}
void PrintList(node* a)
{
	node* temp = a;
	while (temp != NULL)  
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
void PrintList2(node* a) //recursive
{
	if (a == NULL)
	{
		return;
	}
	PrintList2(a->next);
	cout << a->data << " ";
}
void addHead(node* &head, int x)
{
	node* oldhead = head;
	head = createnode(x);
	head->next = oldhead;
}
void removeHead(node* &head)
{
	if (head == nullptr)
		return;
	node* oldhead = head;
	head = head->next;
	delete oldhead;
}
void addEnd(node* &head, int n)
{
	node* newnode = createnode(n);
	if (head == NULL)
	{
		head = newnode;
	}
	else
	{
		node* nodeptr = head;
		while (nodeptr->next != NULL)
		{
			nodeptr = nodeptr->next;
		}
		nodeptr->next = newnode;
	}
}
node* addEnd1(node* head, int n)
{
	if (head == NULL)
	{
		head = createnode(n);
	}
	else
	{
		head->next = addEnd1(head->next, n);
	}
	return head;
}
void addEnd2(node*& head, int n)
{
	if (head == nullptr)
		head = createnode(n);
	else
		addEnd2(head->next, n);
}
void insert1(node*& head, int data) { //inserting in a sorted list
	node* newnode = createnode(data);
	if (head == nullptr) 
		head = newnode;
	else 
	{
		node* nodePtr = head;
		node* previousnode = nullptr;
		while (nodePtr != nullptr && nodePtr->data <= data) {
			previousnode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (previousnode == nullptr) {
			head = newnode;
			nodePtr = nodePtr->next;
		}
		else {
			previousnode->next = newnode;
			newnode->next = nodePtr;
		}
	}
}
void insert2(node*& head, int data) { //recursive call for inserting
	if (head == nullptr)
		head = createnode(data);
	else
	{
		if (head->data > data)
		{
			node* newnode = createnode(data);
			newnode->next = head;
			head = newnode;
		}
		else {
			insert2(head->next, data);
		}
	}
}

void InsertAfter(node *prevnode, int value)
{
	if (prevnode == nullptr) return;
	node *newnode = createnode(value);

	newnode->next = prevnode->next;
	prevnode->next = newnode;
}

void InsertAnywhere(node *head, int value, int pos)
{
	node *newnode = createnode(value);
	if (head == nullptr)
	{
		head = newnode;
		return;
	}

	else 
	{
		int k=1;
		node *temp = head;
		while (temp != nullptr && k!=pos)
		{
			temp = temp->next;
			++k;
		}

		if (k!=pos)
		{
			cout << "Unable to add node";
			return;
		}
		else 
		{
			newnode->next = temp->next;
			temp->next = newnode;
		}
	}
}

void RemoveEnd(node *head)
{
	while ((head->next)->next != nullptr)
	{
		head = head->next;
	}

	node *oldend = head->next;
	head->next = nullptr;
	delete oldend;
}

node* reverse(node* head)
{
	node* current = head;
	node* previous = NULL;
	node* next = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	head = previous;
	return head;
}

void Delete(node *head, int pos)
{
	if (pos == 0||head == nullptr||head->next == nullptr)
	{
		removeHead(head);
		return;
	}

	else 
	{
		int ind = 1;
		node *temp = head;

		while ((temp->next)->next != nullptr && ind != pos)
		{
			temp = temp->next;
			++ind;
		}	

		if (ind != pos)
		{
			cout << "Index exceeding list's length";
			return;
		}

		else 
		{
			temp->next = (temp->next)->next;
		}
	}
}

void ClearList(node *&head)
{
	node *cur = head;
	node *next = nullptr;
	
	while (cur != nullptr)
	{
		next = cur->next;
		delete cur;
		cur = next;
	}
	head = nullptr;
}

// node *merge(node *a, node* b)
// {
// 	node *tempa = a;
// 	node *tempb = b;

// 	while (tempa != nullptr || tempb != nullptr)
// 	{
// 		a->next = b;
// 		b->next = a->next;
// 	}
// 	return a;
// }

node* merge(node* head1, node* head2) {
	if (head2 == nullptr)
		return head1;
	if (head1 == nullptr) {
		return head2;
	}
	while (head2!=nullptr && head1->data >= head2->data )
	{
		node* tmp = head2->next;
		head2->next = head1;
		head1 = head2;
		head2 = tmp;
	}
	node* p1 = head1;
	node* p2 = head2;
	node* prep = new node;
	prep->next = p1;

	while (p2 != nullptr) {
		if (p1 == nullptr || p1->data >= p2->data) {
			prep->next = p2;
			node* tmp = p2->next;
			p2->next = p1;
			prep = p2;
	p2 = tmp;
		}
		else
		{
			p1 = p1->next;
			prep = prep->next;
		}
	}
	return head1;
}

node *Merge(node *p1, node *p2)
{
	if (p1 == nullptr) return p2;
	if (p2 == nullptr) return p1;

	if (p1 ->data < p2->data)
	{
		p1->next = Merge(p1->next,p2);
		return p1;
	}

	else 
	{
		p2->next = Merge(p1,p2->next);
		return p2;
	}
}

void listDivide(node *baseList, node *&midnode){
    node *slowMove = baseList;
    node *fastMove = slowMove ->next;
    while (fastMove != NULL){
        fastMove = fastMove -> next;
        if (fastMove != NULL){
            slowMove = slowMove -> next;
            fastMove = fastMove -> next;
        }
    }
    midnode = slowMove -> next;
    slowMove -> next = NULL;
}

void sortLL(node *&startnode){
    node *firstHalf = startnode;
    node *secondHalf = NULL;
    if (startnode == NULL || startnode-> next == NULL) return ;
    listDivide(startnode,secondHalf);

    sortLL(firstHalf);
    sortLL(secondHalf);

    startnode = Merge(firstHalf,secondHalf);
}

int main()
{
	node* a, *b, *head;
	a = NULL;
	b = nullptr;
	head = nullptr;
	addHead(a, 5);
	addHead(a, 3);
	addHead(a, 2);
	addHead(a, 7);
	addHead(a, 1);
	addHead(a, 6);
	addHead(a, 4);
	//insert2(b, 8);
	//addHead(a,11);
	// InsertAfter(a,12);
	// InsertAnywhere(a,9,4);
	// RemoveEnd(a);
	// Delete(a,2);
	// cout << "Deleting List" << endl;
	// ClearList(a);
	// cout << "list deleted";
	// reverse(a);
	sortLL(a);
	PrintList(a);
	//PrintList(b);
}
