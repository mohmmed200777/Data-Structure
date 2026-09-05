#include <iostream>
#include "QueueArray.h"
using namespace std;
template<class q>
queue<q> ::queue(int size){
maxsize=size;
list=new q[maxsize];
count=0;
front=0;
rear=maxsize-1;
}

template<class q>
queue<q> ::~queue(){
delete []list;
}

template<class q>
queue<q> ::queue(queue<q> &deep){
list=nullptr;
count=0;
copy(deep);
}

template<class q>
queue<q> & queue<q> ::operator=(queue<q> &deep){
if (this != &deep)
copy(deep);
return *this;
}

template<class q>
bool queue<q> :: isEmpty(){
return count==0;
}

template<class q>
bool queue<q> :: isFull(){
return count==maxsize;
}

template<class q>
void queue<q> :: intialize(){
count=0;
front=0;
rear=maxsize-1;
}

template<class q>
void queue<q> :: addQueue(q value){
if (isFull())
return;
else {
rear=(rear+1)%maxsize;
list[rear]=value;
count++;
}
}

template<class q>
void queue<q> :: deletequeue(){
if (isEmpty())
return;
else
{
front=(front + 1)%maxsize;
count--;
}
}

template<class q>
q queue<q> :: Front(){
return list[front];
}

template<class q>
q queue<q> :: Rear(){
return list[rear];
}

template<class q>
void queue<q> :: copy(queue<q> &deep){
if (list != nullptr)
delete [] list;
maxsize=deep.maxsize;
count=deep.count;
list=new q[maxsize];
front=deep.front;
rear=deep.rear;
for (int i=0;i<maxsize;i++)
list[i]=deep.list[i];
}