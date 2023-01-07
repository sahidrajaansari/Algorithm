#include<bits/stdc++.h>
using namespace std;
const int n=5;
vector<pair<int,int>> a[n];
int dijisktra(int source){
    vector<int> visited(n,0);
    vector<int> distance(n,INFINITY);
    set <pair<int,int>> s;
    s.insert(0,source);
    distance[source]=0;
    while(s.size()>0){
        auto node =*s.begin();
        int v=node.second;
        int wt=node.first;
        s.erase(s.begin());
        if(visited[v==1]){
        visited[v]=1;
        for(auto X :a[v]){
            int v_des=X.first;
            int wt_des=X.second;
            if(distance[v]+wt_des<distance[v_des]){
                distance[v_des]=wt+wt_des;
            }
        }
        }
    }
}
int main()
{
    return 0;
}