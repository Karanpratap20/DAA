#include<bits/stdc++.h>
using namespace std;
#define INF 99999
#define V 4

void FW(int g[V][V])
{
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            for(int k=0;k<V;k++)
            {
                if(g[i][j]>g[i][k]+g[k][j])
                {
                    g[i][j]=g[i][k]+g[k][j];
                }
            }
        }
    }
}
int main()
{
    int graph[V][V]={ {0, 12, INF, 1},
                  {12, 0, 4, 7},
                  {INF, 4, 0, 3},
                  {1, 7, 3, 0}};
    FW(graph);

    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cout << graph[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}