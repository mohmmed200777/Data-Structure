template<class q>
struct Node
{
q data;
Node<q> *next;
};


template<class q>
class queue{
Node<q> *front;
Node<q> *rear;
public:
queue();
~queue();
bool isEmpty();
void intialize();
void addQueue(q value);
void deletequeue();
q Front();
q Rear();
void reverseQueue();
};