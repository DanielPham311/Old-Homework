struct node 
{
    int value;
    node *next;
};

node *create(int value);

void AddHead(node *&head, int value);

void Print(node *head);

void DestroyList(node *&head);
