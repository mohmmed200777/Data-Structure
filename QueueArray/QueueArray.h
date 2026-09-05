template<class q>
class queue{
private:
int maxsize;
int count;
q *list;
int front;
int rear;

public:
queue(int size=100);
~queue();
queue(queue<q> &deep);
queue<q> & operator=(queue<q> &deep);
bool isEmpty();
bool isFull();
void intialize();
void addQueue(q value);
void deletequeue();
q Front();
q Rear();
void copy(queue<q> &deep);
};