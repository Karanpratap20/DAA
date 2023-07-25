#include<iostream>
using namespace std;

void merge(int arr[],int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];

    for(int i=0;i<n1;i++)
    {
        L[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        R[i]=arr[m+i+1];
    }

    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k++]=L[i++];
        }
        else{
            arr[k++]=R[j++];
        }
    }

    while(i<n1){
        arr[k++]=L[i++];
    }
    while(j<n2){
        arr[k++]=R[j++];
    }
}
void mergSort(int arr[],int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        mergSort(arr,l,m);
        mergSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main(){
    int arr[]={10,9,4,5,7,1,3,2,6,8};
    mergSort(arr,0,9);
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}