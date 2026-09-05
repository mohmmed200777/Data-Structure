template<class s>
class stack{
private:
s *arr;
int topStack;
int capacity;
public:
stack(int maxsize=100);
stack(stack<s> &deep);
stack<s> & operator=(stack<s> &deep);
~stack();
bool isEmpty();
bool isFull();
void push(s argumant);
s top();
void pop();
void intialize();
void copy(stack<s> &deep);
void Bprint();
void Fprint();
};