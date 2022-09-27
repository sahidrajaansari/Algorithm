class edge {
    int weight;
    int source;
    int destination;

    edge(int source, int destination,int weight) {
        this.weight = weight;
        this.source = source;
        this.destination = destination;
    }
}

public class Min_Heap {
    edge Priority_Queue[];
    int size;
    int current;

    Min_Heap(int s) {
        this.size = s;
        this.current = -1;
        Priority_Queue = new edge[size];
    }

    int parent(int i) {
        return ((i-1)/ 2);
    }

    int left_child(int i) {
        return ((2 * i)+1);
    }

    int right_child(int i) {
        return ((2 * i) + 2);
    }

    void levelup(int i) {
        System.out.println("Your Current element is at :"+i+" Your Parent is at :"+parent(i));
        while (i > 0 && (Priority_Queue[parent(i)].weight > Priority_Queue[i].weight)) {
            // System.out.println("hello");
            System.out.println("parents weight is :"+Priority_Queue[parent(i)].weight+" current element weight "+Priority_Queue[i].weight);
            edge temp = Priority_Queue[parent(i)];
            Priority_Queue[parent(i)] = Priority_Queue[i];
            Priority_Queue[i] = temp;
            i=parent(i);
        }
    }
    void leveldown(){
        int i=0,lc=left_child(i),rc=right_child(i);
        System.out.println("Your Left Child is at "+lc+" Your right Child is At "+rc+" Your Current ELement is "+current);
        while(i<current && lc<=current && rc<=current){
            edge left=Priority_Queue[lc];
            System.out.println("Weight of Left Child is "+left.weight);
            edge right=Priority_Queue[rc];
            System.out.println("Weight of right Child is "+right.weight);
            int smaller=(left.weight)<(right.weight)?((2*i)+1):((2*i)+2);
            System.out.println("smaller value is "+smaller);
            if(Priority_Queue[i].weight>Priority_Queue[smaller].weight){
                edge temp=Priority_Queue[i];
                Priority_Queue[i]=Priority_Queue[smaller];
                Priority_Queue[smaller]=temp;
                i=smaller;
                lc=left_child(i);
                rc=right_child(i);
            }
            else{
                return;
            }
        }
    }

    void enqueue(edge e) {
        current++;
        Priority_Queue[current] = e;
        levelup(current);
    }
    edge dequeue(){
        edge result=Priority_Queue[0];
        Priority_Queue[0]=Priority_Queue[current];
        --current;
        leveldown();
        return result;
    }
    void print(){
        System.out.println("Your Total Elements are :"+(current+1));
        for(int i=0;i<=current;i++){
            System.out.println("Weight is "+Priority_Queue[i].weight+" Source Vertex "+Priority_Queue[i].source+" Destination Vertex is "+Priority_Queue[i].destination);
        }
    }
    public static void main(String[] args) {
        edge e1=new edge(0, 1, 1);
        edge e2=new edge(0, 2, 4);
        edge e3=new edge(1, 2, 2);
        edge e4=new edge(2, 3, 0);
        // edge e1=new edge(3, 1, 4);
        // g.display();
        Min_Heap m=new Min_Heap(4);
        m.print();
        System.out.println("----------------------------");
        m.enqueue(e1);
        m.print();
        System.out.println("----------------------------");
        m.enqueue(e2);
        m.print();
        System.out.println("----------------------------");
        m.enqueue(e3);
        m.print();
        System.out.println("----------------------------");
        m.enqueue(e4);
        m.print();
        System.out.println("----------------------------");
        edge a=m.dequeue();
        System.out.println(a.weight);
        m.print();
        System.out.println("----------------------------");
        edge a1=m.dequeue();
        System.out.println(a1.weight);
        m.print();
        // m.print();
    }
}
