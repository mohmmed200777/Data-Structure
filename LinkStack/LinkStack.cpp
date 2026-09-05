#include <iostream>
#include "LinkStack.h"
using namespace std;
template<class s>
LinkStack<s> ::LinkStack(){
Topstack=nullptr;
}

template<class s>
LinkStack<s> ::LinkStack(LinkStack<s> &deep){
Topstack=nullptr;
copy(deep);
}

template<class s>
LinkStack<s> & LinkStack<s>:: operator=(LinkStack<s> &deep){
if (this != &deep)
copy(deep);
return *this;
}

template<class s>
LinkStack<s> ::~LinkStack(){
intialaize();
}

template<class s>
bool LinkStack<s> :: isEmpty(){
return Topstack==nullptr;
}

template<class s>
void LinkStack<s> :: push (s val){
Node<s> *x=new Node<s>;
x->data=val;
x->next=Topstack;
Topstack=x;
}

template<class s>
void LinkStack<s> :: pop(){
if(isEmpty())
return;
Node<s> *current=Topstack;
Topstack=Topstack->next;
delete current;
}

template<class s>
s LinkStack<s> :: top(){
if (isEmpty())
return 0;
else
return Topstack->data ;
}

template<class s>
void LinkStack<s> :: intialaize(){
Node<s> *current=nullptr;
while (Topstack !=nullptr) {
current=Topstack;
Topstack=Topstack->next;
delete current;
}
}

template<class s>
void LinkStack<s> :: copy(LinkStack<s> &deep){
if (!isEmpty())
intialaize();
if (deep.isEmpty())
Topstack=nullptr;
else{
Node<s> *current,*last,*x;
current=deep.Topstack;
Topstack=new Node<s>;
Topstack->data=current->data;
Topstack->next=nullptr;
last=Topstack;
current=current->next;
while (current !=nullptr) {
x=new Node<s>;
x->data=current->data;
x->next=nullptr;
last->next=x;
last=x;
current=current->next;
}
}
}

template<class s>
int LinkStack<s> :: postfex(){
int x,y;
char i;
cin>>i;
while (i !='=') {
switch (i) {
case '+' :
x=top();
pop();
y=top();
pop();
push(x+y);
break;

case '*' :
x=top();
pop();
y=top();
pop();
push(x*y);
break;

case '-' :
x=top();
pop();
y=top();
pop();
push(y-x);
break;

case '/' :
x=top();
pop();
y=top();
pop();
push(y/x);
break;

default:
push(i-48);
}
cin>>i;
}
return top();
}

template<class s>
void LinkStack<s> ::  Recprint(){
if(!isEmpty()){
s x=top();
pop();
Recprint();
cout<<x<<" ";
push(x);
}
}


template<class s>
void LinkStack<s> :: Findmax(int &max){
if (!isEmpty()) {
s x=top();
pop();
Findmax(max);
if (x>max)
max=x;
push(x);
}
}
