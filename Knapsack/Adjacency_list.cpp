#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int val){
        data=val;
        next=nulptr;
    }
}
class linked_list{
    node *head;
    public:
    linked_list(){
        head=nulptr;
    }
    void add(int data){
        node *newNode= new Node(data);
        if(head==null){
            head=newNode;
        }
        node *temp=head;
        while(temp!=null){
            temp=temp->next;
        }
        temp=newNode;
    }
    void print(){
        node *temp=head;
        while(temp!=null){
            cout<<temp->data<<" ";
        }
    }
}
class graph{
    public:
    linked_list ll;
    int vertices;
    graph(int v;){
        vertices=v;
        ll=new linked_list[v];
    }
    void addedge(int a,int b){
        ll[a].add(b);
        ll[b].add(a);
    }
    void print(){
        for(int i=0;i<vertices;i++){
            ll[i].print();
            cout<<"\n";
        }
    }
}
int main()
{
    int v=4;
    graph g(4);
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(1,3);
    g.addedge(2,3);
    g.print();
    return 0;
}