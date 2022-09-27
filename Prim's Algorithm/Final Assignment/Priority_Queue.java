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

public class Priority_Queue {
    edge Priority_Queue[];
    int size;
    int current;

    Priority_Queue(int s) {
        this.size = s;
        this.current = -1;
        Priority_Queue = new edge[size];
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

    public static void main(String[] args) {
        Priority_Queue Q=new Priority_Queue(5);
        edge e1=new edge(0, 1, 4);
        edge e2=new edge(0, 3, 3);
        edge e3=new edge(1, 2,1);
        edge e4=new edge(2, 3, 5);
        edge e5=new edge(2, 5, 2);
        Q.enqueue(e1);
        Q.enqueue(e2);
        Q.enqueue(e3);
        Q.enqueue(e4);
        Q.enqueue(e5);
        Q.print();
        System.out.println(Q.dequeue().weight);
        Q.print();
        System.out.println(Q.dequeue().weight);
        Q.print();
        // edge e1=new edge(0, 1, 4);
    }
}
