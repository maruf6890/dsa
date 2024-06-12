#include <bits/stdc++.h>
using namespace std;
const int capacity=5;
int que[capacity];
int f=-1,r=-1;
void push(int x){
    if(r<capacity){
        if(f==-1 && r==-1) f++;
        que[++r]=x;
    }else{
        cout<<"stack is full"<<endl;
    }
    
}
bool isEmpty(){
    if(f==r) return true;
    return false;
}
void pop()
{
    if(isEmpty()){
       cout<<"Queue is empty";
    }else{
        f++;
        if(f==r){
            f=r=-1;
        }
    }
}
void top()
{
   if(!isEmpty())
   cout<<que[f]<<endl;
   else cout<<"empty";
}
int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(6);
    
    top();
    pop();
    top();
    pop();
    top();
    pop();
    top();
    pop();
    top();
    pop();
    top();



    return 0; 
}