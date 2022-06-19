struct node 
{
    int value;
    node *next;
    node *prev;
};

node *create(int data);

void Insert(node *&current, int value);

void Print(node *current);

int Search(node *current, int key);

void Delete(node *&current, int pos);
