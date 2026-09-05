#include <iostream>
using namespace std;


int findFact(int num){
if (num<0) {
return -1;
}
if (num==0)
return 1;
else
return num*findFact(num-1);
}

int largestArr(int list[],int lowIndex , int upIndex)
{
int max;
if (lowIndex==upIndex) {
return list[lowIndex];
}
else{
max=largestArr(list, lowIndex+1,upIndex);
if (list[lowIndex]>max)
return list[lowIndex];
else
return max;
}
}

int FibNum(int a,int b,int loc){
if (loc==0)
return a;
else if (loc==1)
return b;
else
return FibNum(a,b,loc-1)+FibNum(a,  b,  loc-2);
}


void decTobinary(int num){
if (num>1){
decTobinary(num/2);
}
cout<<num%2<<" ";
}