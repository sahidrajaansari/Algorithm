#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
class Linked_l
{
private:
    Node *head;

public:
    Linked_l()
    {
        head = nullptr;
    }
    void Push(int val)
    {
        if (head == NULL)
        {
            head=new Node(val);
            return;
        }
        Node *temp = head;
        Node *newNode = new Node(val);
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void display()
    {
        Node *temp = head;
        if(temp!=nullptr){
            cout <<temp->data << "->";
            temp=temp->next;
        }
        while (temp != nullptr)
        {
            cout << temp->data;
            if(temp->next!=nullptr){
                cout<<",";
            }
            temp = temp->next;
        }
        cout << endl;
    }
};
class graph
{
    public:
    void addedge(int x, int y,Linked_l l[])
    {
        l[x].Push(y);
        l[y].Push(x);
    }
    void display(Linked_l l[],int vertices)
    {
        for (int i = 0; i < vertices; i++)
        {
            l[i].display();
        }
    }
};
int main()
{
    int e,v;
    cout<<"Enter Total Number Of Vertices In Graph \n-> ";
    cin>>v;
    cout<<"Enter Total Number Of Edges In Graph \n->";
    cin>>e;
    graph g;
    Linked_l *l=new Linked_l[v];
    for(int i=0;i<v;i++){
        l[i].Push(i);
    }
    for(int i=0;i<e;i++){
        int v1,v2;
        cout<<"\nEdge Number "<<i+1<<endl;
        cout<<"Vertex :";
        cin>>v1;
        cout<<"Vertex :";
        cin>>v2;
        g.addedge(v1,v2,l);
    }
    cout<<"\n\nAdjacency List is As Follows "<<endl;
    g.display(l,v);
    return 0;
}