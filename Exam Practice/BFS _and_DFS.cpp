#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1];
    int a,b,wt;
    for(int i=0;i<m;i++){
        cin>>a>>b>>wt;
        adj[a].push_back({b,wt});
        adj[b].push_back({a,wt});
    }
    for(int i=0;i<n;i++){
        cout<<i;
        for(auto it :adj[i]){
            cout<<it.first<<","<<it.second;
        }
    }
    return 0;
}