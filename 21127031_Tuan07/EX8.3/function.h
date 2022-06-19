struct node 
{
    int value;
    node *next;
};

node *create(int value);

void Append(node *&head, int value);

void Delete(node *&head, int key);

void DestroyList(node *&head);

void Print(node *head);

node *Reverse(node *head);

int Search(node *head, int key);

void Insert(node *&head, int value, int pos);

void DeletePos(node *&head, int pos);
