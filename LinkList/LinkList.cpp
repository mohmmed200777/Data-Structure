#include <iostream>
#include "LinkList.h"
using namespace std;
template<class y>
UnorderedLinkedList <y>::UnorderedLinkedList(){
count=0;
first=nullptr;
last=nullptr;
}
template<class y>
UnorderedLinkedList <y>::~UnorderedLinkedList(){
clearList();
}
template<class y>
bool UnorderedLinkedList <y>:: isEmpty() const{
return first==nullptr;
}
template<class y>
int  UnorderedLinkedList <y>:: length() const{
return count;
}
template<class y>
void UnorderedLinkedList <y>:: display() const{
if (isEmpty()) {
cout<<"The list is empty."<<endl;
return;
}
else {
Node<y> *current=first;
while (current != nullptr) {
cout<<current->data<<" "<<endl;
current=current->next;
}
cout<<endl;
}
}
template<class y>
bool UnorderedLinkedList <y>:: search(y item) const{
if (isEmpty()) {
cout<<"The list is empty."<<endl;
return false;
}
else {
Node<y> *current=first;
while (current != nullptr) {
if (current->data==item){
return true;
}
current=current->next;
}
return false;
}
}
template<class y>
void UnorderedLinkedList <y>:: insertFirst(y item){
Node<y> *x=new Node<y>;
x->data=item;
x->next=first;
first=x;
if (last==nullptr)
last=x;
count++;
}
template<class y>
void UnorderedLinkedList <y>:: insertLast(y item){
Node<y> *x=new Node<y>;
x->data=item;
x->next=nullptr;
if (isEmpty()) {
first=x;
last=x;
}
else {
last->next=x;
last=x;
}
count++;
}
template<class y>
void UnorderedLinkedList <y>:: insertAt(int position, y item){
if (position<0 || position>count){
cout<<"Cannot insert. Invalid position."<<endl;
return;
}
else if (position==0) {
insertFirst(item);
return;
}
else if (position==count) {
insertLast(item);
return;
}
else {
Node<y> *x=new Node<y>;
x->data=item;
x->next=nullptr;
Node<y> *current=first;
for (int i=0; i<position-1; i++) {
current=current->next;
}
x->next=current->next;
current->next=x;
count++;
}
}
template<class y>
void UnorderedLinkedList <y>:: deleteFirst(){
if (isEmpty()) {
cout<<"Cannot delete. The list is empty."<<endl;
return;
}
Node<y> *current=first;
first=first->next;
delete current;
if (isEmpty()){
last=nullptr;
}
count--;
}
template<class y>
void UnorderedLinkedList <y>:: deleteLast(){
if (isEmpty()) {
cout<<"Cannot delete. The list is empty."<<endl;
return;
}
Node<y> *current=first;
if (first==last) {
delete first;
first=nullptr;
last=nullptr;
}
else 
{
for (int i=1;i<count-1;i++)
current=current->next;
delete last;
last=current;
last->next=nullptr;
}
count--;
}
template<class y>
void UnorderedLinkedList <y>:: deleteNode(y item){
if (isEmpty()) {
cout<<"Cannot delete. The list is empty."<<endl;
return;
}
else if (!search(item)) {
cout<<"Item not found."<<endl;
return;
}
if (first->data==item){
deleteFirst();
return;
}
Node<y> *current=first->next;
Node<y> *q=first;
while (current!=nullptr) {
if (current->data==item)
{
if (current==last){
deleteLast();
return;
}
else {
q->next=current->next;
delete current;
count--;
return;
}
}
q=current;
current=current->next;
}
}
template<class y>
void UnorderedLinkedList <y>:: clearList(){
if (isEmpty()) {
cout<<"Cannot delete. The list is empty."<<endl;
return;
}
while (first!=nullptr) {
Node<y> *current=first;
first=first->next;
delete current;
}
count=0;
last=nullptr;
}
template<class y>
int UnorderedLinkedList <y>:: countOccurrences(y item) const{
if (isEmpty()) {
cout<<"The list is empty."<<endl;
return 0;
}
else {
int countOccurrences=0;
Node<y> *current=first;
while (current!=nullptr) {
if (current->data==item)
{
countOccurrences++;
}
current=current->next;
}
return countOccurrences;
}
}
template<class y>
void UnorderedLinkedList <y>::copyList(const UnorderedLinkedList &List2){
if (!isEmpty()){
clearList();
}
if (List2.isEmpty()){
first=nullptr;
last=nullptr;
count=0;
}
else {
Node<y> *current=List2.first;
Node<y> *x;
count=List2.count;
first=new Node<y>;
first->data=current->data;
first->next=nullptr;
last=first;
current=current->next;
while (current!=nullptr)
{
x=new Node<y>;
x->data=current->data;
x->next=nullptr;
last->next=x;
last=x;
current=current->next;
}
}
}
template<class y>
void UnorderedLinkedList<y>:: recesionBackprint(Node<y> *current){
if (current!=nullptr){
recesionBackprint(current->next);
cout<<current->data;
}
}