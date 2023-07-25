#include<iostream>
using namespace std;

int fibo(int n)
{
    int arr[n];
    for(int i=0;i<=n;i++)
    {
        arr[i]=-1;
    }
    if(arr[n]==-1)
    {
        if(n<=1)
        {
            arr[n]=n;
        }
        else{
            arr[n]=fibo(n-1)+fibo(n-2);
        }
    }
    return arr[n];
}

int main()
{
    int n = 5;
    cout << fibo(n);
    return 0;
}