#include <iostream>
#include <cmath>
#include "ArrayList.h"
using namespace std ;

template <class data>
ArrayList<data>::ArrayList(int size){
capacity=size;
lenght=0;
p=new data[capacity];
}

template <class data>
ArrayList<data>::ArrayList(ArrayList & deep) {
capacity=deep.capacity;
lenght=deep.lenght;
p=new data[capacity];
for(int i=0;i<lenght;i++)
p[i]=deep.p[i];
}

template <class data>
ArrayList<data> &ArrayList<data>::operator=(ArrayList & deep) {
    if (this != &deep)
{
delete []p;
capacity=deep.capacity;
lenght=deep.lenght;
p=new data[capacity];
for(int i=0;i<lenght;i++)
p[i]=deep.p[i];
return *this;
}
else 
return *this;
}

template <class data>
ArrayList<data>::~ArrayList() {
delete []p;
}

template <class data>
bool ArrayList<data>:: isEmpty() {
    return lenght==0;
}

template <class data>
bool ArrayList<data>:: isFull() {
    return lenght==capacity;
}

template <class data>
int ArrayList<data>:: getSize() {
    return capacity;
}

template <class data>
int ArrayList<data>:: getLenght() {
    return lenght;
}

template <class data>
bool ArrayList<data>:: isItemEqual(int loc,data val) {
if (isEmpty())
{
cout<<"Is Empty "<<endl;
return false;
}
else if (loc<0 ||loc>=lenght)
{
cout<<"Out of range "<<endl;
return false;
}
else
return p[loc]==val;
}

template <class data>
void ArrayList<data>:: insertEnd(data val) {
if (isFull())
cout<<"Is Full "<<endl;
else
p[lenght++]=val;
}

template <class data>
void ArrayList<data>:: insertAt(int loc,data val) {
if (isFull())
cout<<"Is Full "<<endl;
else if (loc<0 ||loc>lenght)
cout<<"Out of range "<<endl;
else
{
 for (int i=lenght;i>loc;i--)
p[i]=p[i-1];
p[loc]=val;
lenght++;
}
}

template <class data>
void ArrayList<data>:: removeAt(int loc) {
if (isEmpty())
cout<<"Is Empty "<<endl;
else if (loc<0 ||loc>=lenght)
cout<<"Out of range "<<endl;
else{
for (int i=loc;i<lenght-1;i++)
p[i]=p[i+1];
lenght--;
}
}

template <class data>
int ArrayList<data>:: seqserch(data val) {
if (isEmpty()) 
{
cout<<"Is Empty "<<endl;
return -1;
}
else 
{
for (int i=0;i<lenght;i++)
{
if (p[i]==val)
return i;
}
return -1;
}

}

template <class data>
void ArrayList<data>:: removeItem(data val) {
if (isEmpty())
cout<<"Is Empty "<<endl;
else
{
int loc=seqserch(val);
if (loc==-1)
cout<<"Not found "<<endl;
else
removeAt(loc);
}
}

template <class data>
void ArrayList<data>:: removeAll(data val) {
if (isEmpty())
cout<<"Is Empty "<<endl;
else
{
int loc=seqserch(val);
while (loc !=-1 )
{
removeAt(loc);
loc=seqserch(val);
}
}
}

template <class data>
void ArrayList<data>:: retriveAt(int loc,data &val) {
if (isEmpty())
cout<<"Is Empty "<<endl;
else if (loc<0 ||loc>=lenght)
cout<<"Out of range "<<endl;
else
val=p[loc];
}

template <class data>
void ArrayList<data>:: replaceAt(int loc,data val) {
if (isEmpty())
cout<<"Is Empty "<<endl;
else if (loc<0 ||loc>=lenght)
cout<<"Out of range "<<endl;
else
p[loc]=val;
}

template <class data>
void ArrayList<data>:: clearlist() {
    lenght=0;
}



template <class data>
void ArrayList<data>:: reserve() {
    if(isEmpty())
    cout<<"Is Empty "<<endl;
else
 {
int start=0;
int end=lenght-1;
for (int i=0;i<(lenght/2);i++)
{
swap(p[start],p[end]);
start++;
end--;
}
}
}

template <class data>
void ArrayList<data>:: print(){
    if(isEmpty())
    cout<<"Is Empty "<<endl;
else
for (int i=0;i<lenght;i++)
cout<<p[i]<<"  ";
cout<<endl;
}