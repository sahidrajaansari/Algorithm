class Node {
    int vertices;
    int weight;
    Node next;

    public Node(int val, int w) {
        vertices = val;
        weight = w;
        next = null;
    }
}

class Linked_l {
    Node head;

    public Linked_l() {
        head = null;
    }

    public void Push(int val, int w) {
        Node temp = head;
        Node newNode = new Node(val, w);
        if (head == null) {
            head = new Node(val, w);
            return;
        }
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = newNode;
        return;
    }

    public void display() {
        Node temp = head;
        while (temp != null) {
            System.out.print("(" + temp.vertices + "," + temp.weight + ")" + " ");
            temp = temp.next;
        }
        System.out.println();
    }
}

class QNode{
    // int v1;
    // int v2;
    int val;
    QNode next;
    // public QNode(int v1,int v2,int weight){
    public QNode(int val){
        // this.v1=v1;
        // this.v2=v2;
        this.val=val;
        next=null;
    }
}
class Queue{
    QNode head;
    QNode tail;
    public Queue(){
        head=null;
        tail=null;
    }
    boolean isempty()
    {
        if(head==null && tail==null){
            return true;
        }
        return false;
    }
    public void enque(int val){
        QNode temp=new QNode(val);
        if(head==null){
            this.head=this.tail= temp;
            return;
        }
            System.out.println("Hello");
            this.tail.next= temp;
            this.tail=temp;
            return;
    }
    public int deque(){
        if(isempty()){
            return -1;
        }
        else{
            int n=head.val;
            head=head.next;
            return n;
        }
    }
    public void display(){
        QNode temp=head;
        while(temp!=null){
            System.out.print(temp.val+" ");
            temp=temp.next;
        }
    }
}
class graph
{
    int vertices;
    int edges;
    Linked_l Adjacency_List[];
    int parent[];

    public graph(int v, int e) {
        vertices = v; 
        edges = e;
        Adjacency_List = new Linked_l[vertices];
        for (int i = 0; i < vertices; i++) {
            Adjacency_List[i] = new Linked_l();
        }
        parent= new int[vertices];
    }

    void addedge(int m, int n, int w) {
        Adjacency_List[m].Push(n, w);
        // Adjacency_List[n].Push(m, w);
    }

    void display() {
        for (int i = 0; i < vertices; i++) {
            System.out.print(i + "->");
            Adjacency_List[i].display();
        }
    }
    public Boolean BFS(int src,int sink)
    {
        boolean[] visit = new boolean[vertices];
        for (int i = 0; i < vertices; i++) {
            visit[i] = false;
        }
        Queue q=new Queue();
        q.enque(src);
        visit[src] = true;
        parent[src]=-1;
        while (q.isempty() == false)
        {
            q.display();
            int n = q.deque();
            Node temp = Adjacency_List[n].head;
            while (temp != null)
            {
                if (visit[temp.vertices] == false && temp.weight>0)
                {
                    q.enque(temp.vertices);
                    visit[temp.vertices] = true;
                    parent[temp.vertices]=n;
                }
                temp = temp.next;
            }
        }
        if(visit[sink]==true){
            return true;
        }
        else{
            return false;
        }
    } 
}
public class Bfs {
    public static void main(String[] args) {
    graph g=new graph(5, 10);
    g.addedge(0, 1, 2);
    g.addedge(0, 2, 2);
    g.addedge(1, 2, 2);
    g.addedge(1, 3, 2);
    g.addedge(2, 3, 2);
    g.addedge(3, 4, 2);
    g.addedge(4, 1, 2);
    g.addedge(4, 0, 2);
    g.addedge(4, 5, 2);
    int source = 0;
    int sink = 0;
    g.BFS(source,sink);
    }
}
