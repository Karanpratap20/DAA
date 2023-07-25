#include<iostream>
#include<limits.h>
using namespace std;

int MCM(int* p, int n)
{
    int m[n][n];
    for(int i = 1; i < n; i++)
    {
        m[i][i] = 0;
    }
    for(int L = 2; L < n; L++)
    {
        for(int i = 1; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for(int k = i; k <= j - 1; k++)
            {
                int q = m[i][k] + m[k + 1][j] + (p[i - 1] * p[k] * p[j]);
                if(q < m[i][j])
                {
                    m[i][j] = q;
                }
            }
        }
    }
    return m[1][n - 1];
}

int main()
{
    int n = 5;
    int arr[n] = {2, 3, 4, 5, 3};
    cout << MCM(arr, n) << endl;
    return 0;
}
