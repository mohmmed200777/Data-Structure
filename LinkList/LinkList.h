template<class y>
struct Node{
y data;
Node<y> *next;
};
template<class y>
class UnorderedLinkedList 
{
private :
int count;
Node<y> *first;
Node<y> *last;
public :
UnorderedLinkedList();
~UnorderedLinkedList();
bool isEmpty() const;
int length() const;
void display() const;
bool search(y item) const;
void insertFirst(y item);
void insertLast(y item);
void insertAt(int position, y item);
void deleteFirst();
void deleteLast();
void deleteNode(y item);
void clearList();
int countOccurrences(y item) const;
void copyList(const UnorderedLinkedList &List2);
void recesionBackprint(Node<y> *current);
};