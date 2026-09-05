#include <iostream>
#include "orderLink.h"
using namespace std;
OrderedLinkedList::OrderedLinkedList(){
count=0;
first=last=nullptr;
}

OrderedLinkedList::~OrderedLinkedList(){
clearList();
}

bool OrderedLinkedList:: isEmpty() const{
return first==nullptr;
}

int OrderedLinkedList:: length() const{
return count;
}

void OrderedLinkedList:: display() const{
if (isEmpty()) {
cout<<"The list is empty."<<endl;
}
else {
Node *current=first;
while (current !=nullptr) {
cout<<current->data<<" ";
current=current->next;
}
cout<<endl;
}
}

bool OrderedLinkedList:: search(int item) const{
Node *current=first;
while (current !=nullptr && current->data<=item) {
if (current->data==item)
return true;
current=current->next;
}
return false;
}

void OrderedLinkedList:: insert(int item){
Node *x=new Node;
x->data=item;
x->next=nullptr;
if (first==nullptr)
{
first=last=x;
count++;
}
else {
Node *current =first;
Node *q=nullptr;
while (current !=nullptr && current->data<item) {
q=current;
current=current->next;
}
if (current==first) {
x->next=first;
first=x;
}
else {
x->next=current;
q->next=x;
if (current==nullptr) {
last=x;
}
}
count++;
}
}

void OrderedLinkedList:: deleteNode(int item){
Node *current=first;
Node *q=nullptr;
if (isEmpty()) {
cout<<"Cannot delete. The list is empty."<<endl;
}
else if (!search(item)) {
cout<<"Item not found."<<endl;
}
else {
if (first==last)
{
delete first;
first=last=nullptr;
count=0;
}
else {
while (current->data!=item) {
q=current;
current=current->next;
}
if (current==first)
{
first=first->next;
delete current;
count--;
}
else {
q->next=current->next;
delete current;
if (q->next==nullptr) {
last=q;
}
count--;
}
}
}
}

void OrderedLinkedList:: clearList(){
Node *current;
while (first!=nullptr) {
current=first;
first=first->next;
delete current;
}
last=nullptr;
count=0;
}

void OrderedLinkedList:: deleteGreaterThan(int value){
Node *current=first;
Node *temp=nullptr;
Node *q=nullptr;
if (isEmpty())
return;
else if (first->data>value)
clearList();
else if (last->data<value)
return;
else
{
while (current!=nullptr && current->data<=value) {
q=current;
current=current->next;
}
while (current!=nullptr) {
temp=current;
current=current->next;
delete temp;
count--;
}
last=q;
q->next=nullptr;
}
}