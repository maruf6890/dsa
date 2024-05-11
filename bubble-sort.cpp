#include <iostream>
#include <stdlib.h>
using namespace std;
void sort(int a[],int n){
    for( int i=0;  i<n-1 ; i++)
    {
        for( int j=0;  j<n-1-i ; j++)
        {
            if(a[j+1]<a[j]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }

        }
    }
}

int main()
{
   const int n=5;
   int a[n]={1,5,3,4,2};
   sort(a,n);
   for( int i=0;  i<n ; i++)
   {
    cout<<a[i]<<endl;
   }





}