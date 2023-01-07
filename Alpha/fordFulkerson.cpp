#include<bits/stdc++.h>
using namespace std;

class FordFulkerson
{
    private:
    int v;
    vector<list<pair<int,int>>> graph;
    public:
    FordFulkerson(int v)
    {
        this->v=v;
    }
     void input()
    {
        for(int i=0;i<v;i++)
        {
            list<pair<int,int>> l1;
            while(true)
            {
                int p;
                int k;
                cout<<endl<<"Enter the node number ";
                cin>>p;
                if(p==-1)
                break;
                cout<<endl<<"Enter the weight ";
                cin>>k;
                l1.push_back({p,k});
            }
            graph.push_back(l1);
        }
    }
    bool bfs(int source,int sink,int *parent)
    {
        bool visited[v];
        memset(visited,false,v);
        queue <int> q;
        q.push(source);
        visited[source]=true;
        parent[source]=-1;
        while(!q.empty())
        {
            int index=q.front();
            q.pop();
            while(auto i:graph[index])
            {
                if(visited[i.first]==false && i.second>0)
                {
                    if(i.first==sink)
                    {
                        parent[i.first]=index;
                        return;
                    }
                    q.push(i.first);
                    parent[i.first]=index;
                    visited[i.first]=true;
                }
            }
        }
        return false;
    }
    int min(int x,list<pair<int,int>> l)
    {
        for(auto i:l)
        {
            if(i.second<x)
                x=i.second;
        }
        return x;
    }
    int fordfulkerson(int source,int sink)
    {
        int *parent=new int[v];
        int maxflow=0;
        int index;
        while(bfs(source,sink,parent))
        {
            int path_flow=INT_MAX;
            for(int i=sink;i!=source;i=parent[i])
            {
                index=parent[v];
                path_flow=min(path_flow,graph[index]);
            }
            for(int i=sink;i!=source;i=parent[i])
            {
                int k=parent[i];
                
            }
        }

    }
};