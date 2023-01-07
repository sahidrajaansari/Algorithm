#include<bits/stdc++.h>
using namespace std;
const int n=5;
vector<pair<int,int>> adj[n];
void prims(int s){
    int key[n],parent[n],visit[n];
    for(int i=0;i<n;i++){
        key[i]=-1;
        parent[i]=-1;
        visit[i]=0;
    }
    key[s]=0;
    parent[s]=-1;
    for(int i=0;i<n;i++){
        int mini=INT_MAX,u;
        for(int j=0;j<n;j++){
            if(visit[j]==0 && key[j]<mini){
                mini=key[j];
                u=j;
            }
        }
        visit[u]=true;


        for(auto X: adj[u]){
            int v=X.first;
            int wt=X.second;
            if(visit[v]==0 && key[v]>wt){
                parent[v]=u,key[v]=wt;
            }
        }


    }

}
int main()
{
    return 0;
}