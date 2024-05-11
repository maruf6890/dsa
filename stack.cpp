#include <bits/stdc++.h>
using namespace std;
const int capacity=5;
int sta[capacity];
int index=-1;
void push(int x){
    if(index<capacity){
        index++;
        sta[index]=x;
    }else{
        cout<<"stack is full"<<endl;
    }
    
}

void pop()
{
    if(index<capacity){
        index--;
    }
}
void top()
{
    cout<<sta[index]<<endl;
}
int main(){
    push(1);
    push(2);
    push(3);
    top();
    pop();
    top();


    return 0; 
}