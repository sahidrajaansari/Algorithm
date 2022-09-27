#include <iostream>
#include <ctime>
#include <malloc.h>
using namespace std;
struct node{
    int info;
    struct node *next;
};

class stack{
    struct node *top;
    public:
        stack();
        void push(int);
        int pop();
        bool isEmpty();
        void display();
};

stack::stack(){
    top = NULL;
}

void stack::push(int data){
    node *p;
    if((p=(node*)malloc(sizeof(node)))==NULL){
        cout<<"Memory Exhausted";
        exit(0);
    }
    p = new node;
    p->info = data;
    p->next = NULL;
    if(top!=NULL){
        p->next = top;
    }
    top = p;
}

int stack::pop(){
    struct node *temp;
    int value;
    if(top==NULL){
        cout<<"\nThe stack is Empty"<<endl;
    }else{
        temp = top;
        top = top->next;
        value = temp->info;
        delete temp;
    }
    return value;
}

bool stack::isEmpty(){
    return (top == NULL);
}

void stack::display(){
    struct node *p = top;
    if(top==NULL){
        cout<<"\nNothing to Display\n";
    }else{
        cout<<"\nThe contents of Stack\n";
        while(p!=NULL){
            cout<<p->info<<endl;
            p = p->next;
        }
    }
}

class Graph {
    private:
        int n;
        int **A;
    public:
        Graph(int size = 2);
        ~Graph();
        bool isConnected(int, int);
        void addEdge(int x, int y);
        void DFS(int);
};

Graph::Graph(int size) {
    int i, j;
    if (size < 2) n = 2;
    else n = size;
    A = new int*[n];
    for (i = 0; i < n; ++i)
        A[i] = new int[n];
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            A[i][j] = 0;
}

Graph::~Graph() {
    for (int i = 0; i < n; ++i)
    delete [] A[i];
    delete [] A;
}

bool Graph::isConnected(int x, int y) {
    return (A[x-1][y-1] == 1);
}

void Graph::addEdge(int x, int y) {
    A[x][y] = A[y][x] = 1;
}

void Graph::DFS(int x){
    stack s;
    bool *visited = new bool[n];
    int i;
    for(i = 0; i <= n; i++)
        visited[i] = false;
    s.push(x);
    visited[x] = true;
    cout << "Depth first Search starting from vertex ";
    cout << x << " : " << endl;
    while(!s.isEmpty()){
        int k = s.pop();
        cout<<k<<" ";
        for (i = n; i >= 0 ; --i)
            if (isConnected(k, i) && !visited[i]) {
                s.push(i);
                visited[i] = true;
            }
    }
    cout<<endl;
    // delete [] visited;
}

int main(){
    int v,e,source;
    // cout<<"Enter Total Vertice's: ";
    // cin>>v;
    // cout<<"Enter Total Edges: ";
    // cin>>e;
    // Graph g(v);
    // for(int i=0;i<e;i++){
    //     int v1,v2;
    //     cout<<"V1:";
    //     cin>>v1;
    //     cout<<"V2:";
    //     cin>>v2;
    //     g.addEdge(v1,v2);
    // }
    cout<<"Enter Source:";
    cin>>source;
    Graph g(8);
    g.addEdge(0, 1); g.addEdge(0, 2); g.addEdge(0, 3);
    g.addEdge(1, 4); g.addEdge(1, 5); g.addEdge(3, 6);
    g.addEdge(3, 7);
    g.DFS(source);
    return 0;
}
