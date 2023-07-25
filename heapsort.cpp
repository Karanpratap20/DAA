#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void heapify(int *arr,int n,int i)
{
    int c1=2*i+1,c2=2*i+2;
    int max=i;
    if(c1<n && arr[c1]>arr[max])
    {
        max=c1;
    }
    if(c2<n && arr[c2]>arr[max])
    {
        max=c2;
    }
    if(max!=i)
    {
        swap(arr[i],arr[max]);
        heapify(arr,n,max);
    }
}
void heapsort(int *arr,int n)
{
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(arr,n,i);
    }
    for(int i=n-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
int main(){
    int n;
    cin>>n;
    int* arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    heapsort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}