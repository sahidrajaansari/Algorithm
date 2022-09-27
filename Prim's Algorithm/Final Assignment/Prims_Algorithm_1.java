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

class Linked_lost {
    Node head;

    public Linked_lost() {
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
            System.out.print(temp.vertices + " ");
            temp = temp.next;
        }
        System.out.println();
    }
}

class edge {
    int weight;
    int source;
    int destination;

    edge(int source, int destination, int weight) {
        this.weight = weight;
        this.source = source;
        this.destination = destination;
    }
}

class Priority_Queue {
    edge Priority_Queue[];
    int size;
    int current;

    Priority_Queue(int s) {
        this.size = s;
        this.current = -1;
        Priority_Queue = new edge[size];
    }

    boolean isempty() {
        if (current == -1) {
            return true;
        }
        return false;
    }

    int parent(int i) {
        return ((i - 1) / 2);
    }

    int left_child(int i) {
        return ((2 * i) + 1);
    }

    int right_child(int i) {
        return ((2 * i) + 2);
    }

    void levelup(int i) {
        while (i > 0 && (Priority_Queue[parent(i)].weight > Priority_Queue[i].weight)) {
            edge temp = Priority_Queue[parent(i)];
            Priority_Queue[parent(i)] = Priority_Queue[i];
            Priority_Queue[i] = temp;
            i = parent(i);
        }
    }

    void leveldown() {
        int i = 0, lc = left_child(i), rc = right_child(i);
        while (i < current && lc <= current && rc <= current) {
            edge left = Priority_Queue[lc];
            edge right = Priority_Queue[rc];
            int smaller = (left.weight) < (right.weight) ? ((2 * i) + 1) : ((2 * i) + 2);
            if (Priority_Queue[i].weight > Priority_Queue[smaller].weight) {
                edge temp = Priority_Queue[i];
                Priority_Queue[i] = Priority_Queue[smaller];
                Priority_Queue[smaller] = temp;
                i = smaller;
                lc = left_child(i);
                rc = right_child(i);
            } else {
                return;
            }
        }
    }

    void enqueue(edge e) {
        current++;
        Priority_Queue[current] = e;
        levelup(current);
    }

    edge dequeue() {
        edge result = Priority_Queue[0];
        Priority_Queue[0] = Priority_Queue[current];
        --current;
        leveldown();
        return result;
    }

    void print() {
        System.out.println("Your Total Elements are :" + (current + 1));
        for (int i = 0; i <= current; i++) {
            System.out.println("Weight is " + Priority_Queue[i].weight + " Source Vertex " + Priority_Queue[i].source
                    + " Destination Vertex is " + Priority_Queue[i].destination);
        }
    }
}

class Graph {
    int vertices;
    int edges;
    Linked_lost Adjacency_List[];

    public Graph(int v, int e) {
        vertices = v;
        edges = 2*e;
        Adjacency_List = new Linked_lost[vertices];
        for (int i = 0; i < vertices; i++) {
            Adjacency_List[i] = new Linked_lost();
        }
    }

    void addedge(int m, int n, int w) {
        Adjacency_List[m].Push(n, w);
        Adjacency_List[n].Push(m, w);
    }

    void display() {
        for (int i = 0; i < vertices; i++) {
            System.out.print(i + "->");
            Adjacency_List[i].display();
        }
    }

    void prims(int source) {
        Linked_lost result=new Linked_lost();
        edge e = new edge(source, source, 0);
        boolean[] vis = new boolean[vertices];
        for (int i = 0; i < vertices; i++) {
            vis[i] = false;
        }
        Priority_Queue Q = new Priority_Queue(edges);
        Q.enqueue(e);
        while (Q.isempty() == false) {
            edge temp = Q.dequeue();
            result.Push(temp.source, temp.weight);
            if (vis[temp.source] == false) {
                vis[temp.source] = true;
                Node trace = Adjacency_List[temp.source].head;
                while (trace != null) {
                    int v = trace.vertices;
                    int w = trace.weight;
                    if (vis[v] == false) {
                        edge a = new edge(temp.source, v, w);
                        Q.enqueue(a);
                    }
                    trace = trace.next;
                }
            }
            System.out.println("Your Traced VAlues Are as Follows");
            result.display();
        }

    }
}

public class Prims_Algorithm_1 {
public static void main(String[] args) {
    Graph g=new Graph(9, 14);
    g.addedge(0, 1, 4);
    g.addedge(0, 7, 8);
    g.addedge(1, 7, 11);
    g.addedge(1, 2, 8);
    g.addedge(2, 8, 2);
    g.addedge(2, 3, 7);
    g.addedge(2, 5, 4);
    g.addedge(3, 5, 14);
    g.addedge(3, 4, 9);
    g.addedge(4, 5, 10);
    g.addedge(5,6, 2);
    g.addedge(6,8, 6);
    g.addedge(6,7, 1);
    g.addedge(7,8, 7);
    g.display();

}
}
