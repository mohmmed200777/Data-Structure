struct Node
{
int data;
Node *next;
};

class OrderedLinkedList
{
private:
int count;
Node *first;
Node *last;

public:
OrderedLinkedList();
~OrderedLinkedList();
bool isEmpty() const;
int length() const;
void display() const;
bool search(int item) const;
void insert(int item);
void deleteNode(int item);
void clearList();
void deleteGreaterThan(int value);
};