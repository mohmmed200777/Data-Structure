#include <iostream>
#include "QueueLinked.h"
using namespace std;
template<class q>
queue<q> ::queue(){
front=nullptr;
rear=nullptr;
}

template<class q>
queue<q> ::~queue(){
intialize();
}

template<class q>
bool queue<q> :: isEmpty(){
return front==nullptr;
}

template<class q>
void queue<q> :: intialize(){
Node<q> *current;
while (front != nullptr)
{
current=front;
front=front->next;
delete current;
}
rear=nullptr;
}

template<class q>
void queue<q> :: addQueue(q value){
Node<q> *x=new Node<q>;
x->data=value;
x->next=nullptr;
if (isEmpty())
front=rear=x;
else {
{
rear->next=x;
rear=x;
}
}
}

template<class q>
void queue<q> :: deletequeue(){
if (isEmpty())
return;
Node<q> *current=front;
front=front->next;
delete current;
if (front==nullptr) {
rear=nullptr;
}
}

template<class q>
q queue<q> :: Front(){
return front->data;
}

template<class q>
q queue<q> :: Rear(){
return rear->data;
}
template<class q>
void  queue<q> :: reverseQueue(){
    if (!isEmpty()){
    q x=Front();
    deletequeue();
    reverseQueue();
    addQueue(x);
}
}