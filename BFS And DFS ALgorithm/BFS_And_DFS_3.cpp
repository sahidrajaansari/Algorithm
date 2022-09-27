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
public:
    Node *head;
    Linked_l()
    {
        head = nullptr;
    }
    void Push(int val)
    {
        if (head == NULL)
        {
            head = new Node(val);
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
        while (temp != nullptr)
        {
            cout << temp->data;
            if (temp->next != nullptr)
            {
                cout << ",";
            }
            temp = temp->next;
        }
        cout << endl;
    }
    Node *Return_Head()
    {
        return head;
    }
};
class Queue
{
    Node *head;

public:
    Queue()
    {
        head = nullptr;
    }
    bool isempty()
    {
        if (head == nullptr)
        {
            return true;
        }
        return false;
    }
    void enque(int val)
    {
       if (head == NULL)
        {
            head = new Node(val);
            return;
        }
        Node *newNode = new Node(val);
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    int deque()
    {
        if (isempty())
        {
            return -1;
        }
        else
        {
            int n = head->data;
            head = head->next;
            return n;
        }
    }
    void display(){
        cout<<"Queue :";
        Node *n=head;
        if(n==nullptr){
            cout<<"NULL";
            return;
        }
        while(n!=NULL){
            cout<<n->data<<" ";
            n=n->next;
        }
    }
};
class Stack
{
    Node *head;

public:
    Stack()
    {
        head = nullptr;
    }
    bool isempty()
    {
        if (head == nullptr)
        {
            return true;
        }
        return false;
    }
    void Push(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    int pop()
    {
        if (isempty())
        {
            return -1;
        }
        else
        {
            Node *Del=head;
            int n = Del->data;
            head=head->next;
            delete(Del);
            return n;
        }
    }
    void display(){
        cout<<"Stack :";
        Node *n=head;
        if(n==nullptr){
            cout<<"NULL";
            return;
        }
        while(n!=NULL){
            cout<<n->data<<" ";
            n=n->next;
        }
    }
};
class graph
{
public:
    void addedge(int x, int y, Linked_l l[])
    {
        l[x].Push(y);
        // l[y].Push(x);
    }
    void display(Linked_l l[], int vertices)
    {
        for (int i = 0; i < vertices; i++)
        {
            cout << i << "->";
            l[i].display();
        }
    }
    void BFS(Linked_l l[], int src, int vertices)
    {
        cout << "\n\t\tBreadth First Search\n\n";
        bool visit[vertices];
        for (int i = 0; i < vertices; i++)
        {
            visit[i] = false;
        }
        Queue q;
        q.enque(src);
        visit[src] = true;
        Linked_l Lq;
        cout << "Source :" << src << endl<<"\n";
        for(int i=0 ; i< vertices ; i++)
        {
        while (q.isempty() == false)
        {
            q.display();
            cout<<"\n";
            int n = q.deque();
            Lq.Push(n);
            cout << "Selected Node :" << n << endl;
            Node *temp = NULL;
            temp = l[n].Return_Head();
            while (temp != NULL)
            {
                if (visit[temp->data] == false)
                {
                    q.enque(temp->data);
                    visit[temp->data] = true;
                }
                temp = temp->next;
            }
            cout << "Intermediate Result is...........................\n";
            cout<<"Traversed Elements Are :";
            Lq.display();
            cout<<endl;
            cout << "\n";
        }
        if(!visit[i])
        {
            q.enque(i);
            visit[i]=true;
        }
        }
        // for(int i=0;i<vertices;i++){
        //     if(visit[i]==false){
        //         // Lq.Push(i);
        //         BFS(l,i,vertices);
        //     }
        // }
        cout << "After BFS Traversal Result is \n";
        Lq.display();
    }
    void DFS(Linked_l l[], int src, int vertices)
    {
        cout << "\n\t\tDepth First Search\n\n";
        bool visit[vertices];
        for (int i = 0; i < vertices; i++)
        {
            visit[i] = false;
        }
        Stack S;
        visit[src] = true;
        Linked_l Ls;
        cout << "Source :" << src << endl;
        S.Push(src);
        while (S.isempty() == false)
        {
            S.display();
            cout<<"\n";
            int n = S.pop();
            Ls.Push(n);
            cout << "Selected Node :" << n << endl;
            Node *temp = NULL;
            temp = l[n].Return_Head();
            while (temp != NULL)
            {
                if (visit[temp->data] == false)
                {
                    S.Push(temp->data);
                    visit[temp->data] = true;
                }
                temp = temp->next;
            }
            cout << "Intermediate Result is...........................\n";
            cout<<"Traversed Elements Are :";
            Ls.display();
            cout << endl;
            cout<<"\n";
        }
        // for(int i=0;i<vertices;i++){
        //     if(visit[i]==false){
        //         // Ls.Push(i);
        //         DFS(l,i,vertices);
        //     }
        // }
        cout << "After DFS Traversal Result is \n";
        Ls.display();
    }
};
int main()
{
    int e, v;
    cout << "Enter Total Number Of Vertices In Graph \n-> ";
    cin >> v;
    cout << "Enter Total Number Of Edges In Graph \n->";
    cin >> e;
    graph g;
    Linked_l *l = new Linked_l[v];
    for (int i = 0; i < e; i++)
    {
        int v1, v2;
        cout << "\nEdge Number " << i + 1 << endl;
        cout << "Source Vertex :";
        cin >> v1;
        cout << "Destination Vertex :";
        cin >> v2;
        g.addedge(v1, v2, l);
    }
    cout << "\n\nAdjacency List is As Follows " << endl;
    g.display(l, v);
    cout << "Graph Searching.................\n\n";
    int source, choice;
    cout << "Enter Source Of The Graph\n->";
    cin >> source;
    cout << "1.Breadth First Search \n2.Depth First Search\n3.Both\n4.Exit\n->";
    cin >> choice;
    while (choice != 4)
    {
        switch (choice)
        {
        case 1:
        {
            g.BFS(l, source, v);
            cout << "\n1.Breadth First Search \n2.Depth First Search\n3.Both\n4.Exit\n->";
            cin >> choice;
        }
        break;
        case 2:
        {
            g.DFS(l, source, v);
            cout << "\n1.Breadth First Search \n2.Depth First Search\n3.Both\n4.Exit\n->";
            cin >> choice;
        }
        break;
        case 3:
        {
            g.BFS(l, source, v);
            g.DFS(l, source, v);
            cout << "\n1.Breadth First Search \n2.Depth First Search\n3.Both\n4.Exit\n->";
            cin >> choice;
            
        }
        break;
        default:
        {
            cout << "Wrong Choice................\n";
            cout << "\n1.Breadth First Search \n2.Depth First Search\n3.Both\n4.Exit\n->";
            cin >> choice;
        }
        break;
        }
    }
    cout<<"Thank You..........";
    return 0;
}