struct Node
{
int data;
Node *next;
Node *back;
};

class DoubleList
{
private:
int count;
Node *first;
Node *last;

public:
DoubleList();
~DoubleList();
bool isEmpty() const;
int length() const;
void display() const;
void back_display() const;
bool search(int item) const;
void insert(int item);
void deleteNode(int item);
void clearList();
void deleteGreaterThan(int value);
};