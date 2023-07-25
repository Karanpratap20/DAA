#include<iostream>
using namespace std;

int knapsack(int* wt, int* val, int n, int W)
{
    int sol[n+1][W+1];
    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<W+1; j++)
        {
            if(i==0 || j==0)
                sol[i][j] = 0;
            else if(wt[i-1] > j)
                sol[i][j] = sol[i-1][j];
            else
            {
                int without_current_item = sol[i-1][j];
                int with_current_item = val[i-1] + sol[i-1][j-wt[i-1]];
                sol[i][j] = max(without_current_item, with_current_item);
            }
        }
    }
    return sol[n][W];
}

int main()
{
    int n = 5;
    int wt[n] = {5, 2, 10, 20, 8};
    int val[n] = {100, 60, 50, 100, 40};
    int W = 50;
    cout << knapsack(wt, val, n, W);
    return 0;
}
