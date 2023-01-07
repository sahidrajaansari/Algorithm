#include<bits/stdc++.h>
using namespace std;
void prims(int n,vector<pair<int,int>> adj[],int start){
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    pq.push({0,start,-1});
    int sum=0;
    vector<int> vis(n,0);
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int distance=it[0];
        int node=it[1];
        int parent=it[2];
        if(vis[node]==1) continue;
        vis[node]=1;
        sum+=distance;
        for(auto it:adj[node]){
            int adjNode=it.first;
            int adjWeight=it.second;
            if(!vis[adjNode]){
                pq.push({adjWeight,adjNode,node});
            }
        }
    }
    cout<<"Sum is :"<<sum;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n];
    int a,b,wt;
    for(int i=0;i<m;i++){
        cin>>a>>b>>wt;
        adj[a].push_back({b,wt});
        adj[b].push_back({a,wt});
    }
    for(int i=0;i<n;i++){
        cout<<i<<"->";
        for(auto it :adj[i]){
            cout<<"("<<it.first<<","<<it.second<<")";
        }
        cout<<endl;
    }
    prims(n,adj,0);
    return 0;
}