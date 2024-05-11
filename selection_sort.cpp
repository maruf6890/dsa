#include <iostream>
#include <stdlib.h>
using namespace std;
void sort(int a[],int n){
    for( int i=0;  i<n ; i++)
    {   int min=i;
        for( int j=i+1;  j<n ; j++)
        {
            if(a[j]<a[i]){
                min=j;

            }
        }
        swap(a[i],a[min]);
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