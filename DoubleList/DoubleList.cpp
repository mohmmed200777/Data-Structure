#include <iostream>
#include "DoubleList.h"
using namespace std;
DoubleList::DoubleList(){
count=0;
first=last=nullptr;
}

DoubleList::~DoubleList(){
clearList();
}

bool DoubleList:: isEmpty() const{
return first==nullptr;
}

int DoubleList:: length() const{
return count;
}

void DoubleList:: display() const{
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

void DoubleList:: back_display() const{
if (isEmpty()) {
cout<<"The list is empty."<<endl;
}
else 
{
Node *current=last;
while (current !=nullptr) {
cout<<current->data<<" ";
current=current->back;
}
cout<<endl;
}
}

bool DoubleList:: search(int item) const{
Node *current=first;
while (current !=nullptr && current->data<=item) {
if (current->data==item)
return true;
current=current->next;
}
return false;
}

void DoubleList:: insert(int item){
Node *x=new Node;
x->data=item;
x->next=nullptr;
x->back=nullptr;
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
first->back=x;
first=x;
}
else {
x->next=current;
x->back=q;
q->next=x;
if (current==nullptr) {
last=x;
}
else {
current->back=x;
}
}
count++;
}
}

void DoubleList:: deleteNode(int item){
Node *current=first;
if (isEmpty()) 
{
cout<<"Cannot delete. The list is empty."<<endl;
}
else if (!search(item)) 
{
cout<<"Item not found."<<endl;
}
else
{
if (first==last)
{
delete first;
first=last=nullptr;
count=0;
}
else 
{
while (current->data!=item) {
current=current->next;
}
if (current==first)
{
first=first->next;
first->back=nullptr;
delete current;
count--;
}
else {
current->back->next=current->next;
if (current->next==nullptr) {
last=current->back;
}
else {
current->next->back=current->back;
}
delete current;
count--;
}
}
}
}

void DoubleList:: clearList(){
Node *current;
while (first!=nullptr) {
current=first;
first=first->next;
delete current;
}
last=nullptr;
count=0;
}

void DoubleList:: deleteGreaterThan(int value){
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