#include<iostream>
using namespace std;

int LCS(string x,string y,int m,int n)
{
    int sol[m+1][n+1];
    int i,j;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0 || j==0)
            {
                sol[i][j]=0;
            }
            else if(x[i-1]==y[j-1]){
                sol[i][j]=sol[i-1][j-1]+1;
            }
            else{
                int x1=sol[i][j-1];
                int x2=sol[i-1][j];
                sol[i][j]=max(x1,x2);
            }
        }
    }
    return sol[m][n];
}
int main()
{
    string s="qwertyu",s1="qwrtiu";
    cout<<LCS(s,s1,7,6);
    return 0;
}