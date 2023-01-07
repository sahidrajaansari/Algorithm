import java.util.Scanner;
class Node {
    int vertices;
    int Capacity;
    Node next;

    public Node(int val, int w) {
        vertices = val;
        Capacity = w;
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
            System.out.print("(" + temp.vertices + "," + temp.Capacity + ")" + " ");
            temp = temp.next;
        }
        System.out.println();
    }
}

class QNode {
    int val;
    QNode next;

    public QNode(int val) {
        this.val = val;
        next = null;
    }
}
class Queue {
    QNode front;
    QNode tail;

    public Queue() {
        front = null;
        tail = null;
    }

    boolean isempty() {
        if (front == null) {
            return true;
        }
        return false;
    }

    public void enque(int val) {
        QNode temp = new QNode(val);
        if (front == null) {
            this.front = this.tail = temp;
            return;
        }
        this.tail.next = temp;
        this.tail = temp;
        return;
    }

    public int deque() {
        if (isempty()) {
            return -1;
        } else {
            int n = front.val;
            front = front.next;
            return n;
        }
    }
}

class graph {
    int vertices;
    int edges;
    int Result[];
    int count;
    int flow;
    Linked_l Adjacency_List[];
    Linked_l Residual_Graph[];
    int parent[];

    public graph(int v, int e) {
        vertices = v;
        count=0;
        edges = e;
        Adjacency_List = new Linked_l[vertices];
        for (int i = 0; i < vertices; i++) {
            Adjacency_List[i] = new Linked_l();
        }
        Residual_Graph = new Linked_l[vertices];
        for (int i = 0; i < vertices; i++) {
            Residual_Graph[i] = new Linked_l();
        }
        parent = new int[vertices];
        Result=new int[vertices];
    }

    void addedge(int m, int n, int w) {
        Adjacency_List[m].Push(n, w);
        Residual_Graph[m].Push(n, w);
    }

    void display() {
        for (int i = 0; i < vertices; i++) {
            System.out.print(i + "->");
            Adjacency_List[i].display();
        }
    }
    void displayResidual(){
        for (int i = 0; i < vertices; i++) {
            System.out.print(i + "->");
            Residual_Graph[i].display();
        }
    }

    public Boolean BFS(int src, int sink) {
        boolean[] visit = new boolean[vertices];
        for (int i = 0; i < vertices; i++) {
            visit[i] = false;
        }
        Queue q = new Queue();
        q.enque(src);
        visit[src] = true;
        parent[src] = -1;
        while (q.isempty() == false) {
            // System.out.println();
            int n = q.deque();
            Node temp = Residual_Graph[n].head;
            while (temp != null) {
                if (visit[temp.vertices] == false && temp.Capacity > 0) {
                    q.enque(temp.vertices);
                    visit[temp.vertices] = true;
                    parent[temp.vertices] = n;
                }
                temp = temp.next;
            }
        }
        if (visit[sink] == true) {
            return true;
        } else {
            return false;
        }
    }

    public void intermediate(){
        System.out.println();
        System.out.println("Bottleneck Capacity is : "+ flow);
        System.out.print("Augmented Path is :");
            for(int i=count-1;i>=0;--i){
                System.out.print(Result[i]+" ");
            }
        System.out.println();
        System.out.println("Residual Graph :");
        displayResidual();
            System.out.println();
    }
    
    public int FordFulkerson(int src, int sink) {
        int u = 0, v = 0;
        int maxflow = 0;
        while (BFS(src, sink)) {
            count=0;
            flow = Integer.MAX_VALUE;
            v = sink;
            while (v != src) {
                Result[count]=v;
                count++;
                u = parent[v];
                Node temp = Residual_Graph[u].head;
                while (temp.vertices != v) {
                    temp = temp.next;
                }
                flow = Math.min(flow, temp.Capacity);
                v = parent[v];
            }
            Result[count]=v;
            count++;
            v = sink;
            while (v != src) {
                u = parent[v];
                Node temp = Residual_Graph[u].head;
                while (temp.vertices != v) {
                    temp = temp.next;
                }
                temp.Capacity -= flow;
                temp = Residual_Graph[v].head;
                while (temp != null && temp.vertices != u) {
                    temp = temp.next;
                }
                if (temp == null) {
                    Residual_Graph[v].Push(u, 0);
                }
                temp = Residual_Graph[v].head;
                while (temp.vertices != u) {
                    temp = temp.next;
                }
                temp.Capacity += flow;
                v = parent[v];
            }
            
            maxflow += flow;
            intermediate();
        }
        return maxflow;
    }
}

public class Ford {
    public static void main(String[] args) {
        graph g=new graph(6, 10);
        g.addedge(0, 1, 16);
        g.addedge(0, 2, 13);
        g.addedge(1, 2, 10);
        g.addedge(1, 3, 12);
        g.addedge(2,1, 4);
        g.addedge(2,4, 14);
        g.addedge(3, 2, 9);
        g.addedge(3, 5, 20);
        g.addedge(4, 3, 7);
        g.addedge(4, 5, 4);
        g.display();
        // System.out.println("Done");
        System.out.println("Max Flow Is :"+g.FordFulkerson(0, 5));
        // int vertices;
        // int edges;
        // Scanner sc = new Scanner(System.in);
        // System.out.print("Enter number of vertices \n->");
        // vertices = sc.nextInt();
        // System.out.print("Enter number of edges \n->");
        // edges = sc.nextInt();
        // graph g = new graph(vertices, edges);
        // for (int i = 0; i < edges; i++) {
        // System.out.println("Enter edge number " + (i + 1));
        // System.out.print("Source :");
        // int source = sc.nextInt();
        // System.out.print("Destination :");
        // int destination = sc.nextInt();
        // System.out.print("Capacity :");
        // int weight = sc.nextInt();
        // g.addedge(source, destination, weight);
        // System.out.println();
        // }
        // System.out.println("Your Adjacency List is As Follows :");
        // g.display();
        // int s,t;
        // System.out.print("Source \n->");
        // s=sc.nextInt();
        // System.out.print("Sink \n->");
        // t=sc.nextInt();
        // System.out.println("Max Flow Is :"+g.FordFulkerson(s,t));
        // sc.close();
    }

}