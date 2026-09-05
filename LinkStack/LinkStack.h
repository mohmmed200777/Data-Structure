template<class s>
struct Node{
s data;
Node *next;
};

template<class s>
class LinkStack{
private:
Node<s> *Topstack;
public:
LinkStack();
LinkStack(LinkStack<s> &deep);
LinkStack<s> &operator=(LinkStack<s> &deep);
~LinkStack();
bool isEmpty();
void push (s val);
void pop();
s top();
void intialaize();
void copy(LinkStack<s> &deep);
int postfex();
void Recprint();
void Findmax(int &max);
};