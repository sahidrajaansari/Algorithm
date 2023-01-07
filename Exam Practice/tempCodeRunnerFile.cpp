#include<bits/stdc++.h>
using namespace std;
void bfs(int node,vector<int> adj[],int vis[],vector<int> &ls){
    queue<int> q;
    q.push(node);
    vis[node]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        ls.push_back(node);
        for(auto it : adj[node]){
            if(vis[it]!=1){
                q.push(it);
                vis[it]=1;
            }
        }
    }
}
vector<int> traversal(int start,vector<int> adj[],int n){
    int vis[n+1];
    memset(vis,n+1,0);
    vector<int> ls;
    bfs(start,adj,vis,ls);
    for(int i=1;i<n+1;i++){
        if(vis[i]!=1){
            bfs(i,adj,vis,ls);
        }
    }
    cout<<"Path is";
    for(auto it :ls){
        cout<<it<<" ";
    }
    return ls;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    int a,b,wt;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<"Tree Is ";
    for(int i=0;i<n;i++){
        cout<<i<<"->";
        for(auto it :adj[i]){
            cout<<it<<",";
        }
        cout<<endl;
    }
    traversal(1,adj,n);
    return 0;
}