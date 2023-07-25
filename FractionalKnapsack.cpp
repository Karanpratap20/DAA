#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector<pair<int,pair<int,int>>> viii;

bool compare(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
    return a.first > b.first;
}

void knapsack(viii sack,int Size)
{
    sort(sack.begin(),sack.end(),compare);
    int profit=0;
    for(int i=0;i<sack.size();i++)
    {
        if(Size!=0)
        {
            if(Size>sack[i].second.second)
            {
                profit+=sack[i].second.first;
                Size-=sack[i].second.second;
            }
            else{
                profit+= Size*sack[i].first;
                Size=0;
                break;
            }
        }
    }
    cout<<profit<<endl;    
}

int main(){
    viii sack;
    int n,v,w,Size;
    cin>>n>>Size;
    for(int i=0;i<n;i++)
    {
        cin>>v>>w;
        int x=v/w;
        sack.push_back(make_pair(x,make_pair(v,w)));
    }
    knapsack(sack,Size);
    return 0;
}