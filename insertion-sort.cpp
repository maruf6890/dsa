#include <iostream>
using namespace std;


//sort
void sort(int a[],int n)
{   // 3 4 5 2 1 //k=3 j=1
    for( int i=1;  i<n ; i++)
    {
        int key=a[i];
        int j=i-1;//0
        while(key<a[j] && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;


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