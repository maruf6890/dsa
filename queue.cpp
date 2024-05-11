#include <bits/stdc++.h>
using namespace std;
const int capacity=5;
int que[capacity];
int index=-1;
void push(int x){
    if(index<capacity){
        index++;
        que[index]=x;
    }else{
        cout<<"stack is full"<<endl;
    }
    
}

void pop()
{
    if(index<capacity){
        for(int i=0; i<=index-1;  i++) que[i]=que[i+1];
    }
}
void top()
{
    cout<<que[0]<<endl;
}
int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    top();
    pop();
    top();


    return 0; 
}