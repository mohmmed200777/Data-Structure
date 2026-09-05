#include <iostream>
#include "ArrayStack.h"
using namespace std;
template<class s>
stack<s>::stack(int maxsize){
capacity=maxsize;
topStack=0;
arr=new s[capacity];
}

template<class s>
stack<s>::stack(stack<s> &deep){
arr=nullptr;
copy(deep);
}

template<class s>
stack<s> & stack<s>:: operator=(stack<s> &deep){
if (this != &deep)
copy(deep);
 return *this;
}

template<class s>
stack<s>::~stack(){
delete [] arr;
}

template<class s>
bool stack<s>:: isEmpty(){
return topStack==0;
}

template<class s>
bool stack<s>:: isFull(){
return topStack==capacity;
}

template<class s>
void stack<s>:: push(s argumant){
if (isFull())
return;
else
arr[topStack++]=argumant;
}

template<class s>
s stack<s>:: top(){
if (!isEmpty())
return arr[topStack-1];
else
return 0;
}

template<class s>
void stack<s>:: pop(){
if (!isEmpty())
topStack--;
else
return;
}

template<class s>
void stack<s>:: intialize(){
topStack=0;
}

template<class s>
void stack<s>:: copy(stack<s> &deep){
delete []arr;
capacity=deep.capacity;
topStack=deep.topStack;
arr=new s[capacity];
for (int i=0;i<topStack;i++)
arr[i]=deep.arr[i];
}

template<class s>
void stack<s>:: Bprint(){
stack<s> B;
while (!isEmpty())
{
B.push(top());
cout<<B.top();
pop();
}
while (!B.isEmpty()) {
push(B.top());
B.pop();
}
}

template<class s>
void stack<s>:: Fprint(){
stack<s> B;
while (!isEmpty())
{
B.push(top());
pop();
}
while (!B.isEmpty()) {
cout<<B.top();
push(B.top());
B.pop();
}
}