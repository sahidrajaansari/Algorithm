import java.util.Scanner;
class Node{
    int vertex;
    int weight;
    Node next;
    public Node(int value,int wt)
    {
        vertex=value;
        weight=wt;
        next=null;
    }
}
    class Linked_list{
     Node head;
    public Linked_list()
     {
      head=null;
     }
     public void create(int value,int wt)
     {
       Node newNode = new Node(value, wt);
       if(head==null)
       {
       head=newNode;
       return;
       }
       newNode.next=head;
       head=newNode;
     }
     public void printList()
     {
        if(head==null)
        {
            System.out.println("List is Empty");
        }
        Node currNode = head;
        while(currNode!=null)
        {
            System.out.print("("+currNode.vertex+","+currNode.weight+")"+" ");
            currNode=currNode.next;
        }
        System.out.println();
        
     }
    } 
    class Edge{
        int weight;
        int source;
        int destination;
        public Edge(int src,int dst,int wt)
        {
          this.weight=wt;
          this.source=src;
          this.destination=dst;
        }
    }
    class priorityQueue{
        Edge priorityQueue[];
        int size;
        int current;
        public priorityQueue(int sz)
        {
         size=sz;
         current=-1;
         priorityQueue = new Edge[size];
        }
        boolean isEmpty()
        {
            if(current ==-1)
            {
            return true;
            }
        return false;
        }
        int parent(int i)
        {
            return ((i-1) /2);
        }
        int leftChild(int i)
        {
            return ((2*i)+1);
        }
        int rightChild(int i)
        {
            return ((2*i)+2);
        }
        void upHeapify(int i)
        {
         while(i>0 && priorityQueue[parent(i)].weight>priorityQueue[i].weight)
         {
            Edge temp = priorityQueue[parent(i)];
            priorityQueue[parent(i)] = priorityQueue[i];
            priorityQueue[i]=temp;
            i=parent(i);//ye q kiya
         }
        }
        void downHeapify()
        {
            int i = 0, lc = leftChild(i), rc = rightChild(i);
            while(i<current && lc<=current && rc<=current )
            while (i < current && lc <= current && rc <= current) {
                Edge left = priorityQueue[lc];
                Edge right = priorityQueue[rc];
                int smallerChild;
                if(left.weight<right.weight)
                {
                     smallerChild=((2*i)+1);
                }
                else{
                    smallerChild=((2*i+2));
                }
                //int smaller = (left.weight) < (right.weight) ? ((2 * i) + 1) : ((2 * i) + 2);
                if (priorityQueue[i].weight > priorityQueue[smallerChild].weight) {
                    Edge temp = priorityQueue[i];
                    priorityQueue[i] = priorityQueue[smallerChild];
                    priorityQueue[smallerChild] = temp;
                    i = smallerChild;
                    lc = leftChild(i);
                    rc = rightChild(i);
                } else {
                    return;
                }
            }
        }
        void Enqueue(Edge e)
        {
           current++;
           priorityQueue[current]=e;
           upHeapify(current);

        }
        Edge Dequeue()
        {
           Edge res = priorityQueue[0];
           priorityQueue[0]=priorityQueue[current];
           --current;
           downHeapify();
           return res;
        }
        
    void printQueue() {
        if(current==-1){
            System.out.println("Queue Is Empty");
        }
        for (int i = 0; i <= current; i++) {
            System.out.println("Source :"+priorityQueue[i].source+"|Destination :"+priorityQueue[i].destination+"|Weight :"+priorityQueue[i].weight);
        }
    }
    }
    class Graph{
        int vertices;
        int edges;
        Linked_list adjecancyList[];
        public Graph(int v,int e)
        {
            vertices=v;
            edges=2*e;
            adjecancyList=new Linked_list[vertices];
            for(int i=0;i<vertices;i++)
            {
                adjecancyList[i]=new Linked_list();
            }
        }
        void addEdge(int v1,int v2,int wt)
        {
            adjecancyList[v1].create(v2,wt);
            adjecancyList[v2].create(v1,wt);
        }
        void display()
        {
            for(int i=0;i<vertices;i++)
            {
                System.out.print(i+"-> ");
                adjecancyList[i].printList();
            }
        }
        void primsAlgo(int source)
        {
            Linked_list res = new Linked_list();
            Edge e = new Edge(source,source,0);
            boolean visited[]=new boolean[vertices];
            for(int i=0;i<vertices;i++)
                {
                    visited[i]=false;
                }
                priorityQueue pq = new priorityQueue(edges);
                pq.Enqueue(e);
                while(pq.isEmpty()==false)
                {
                    Edge temp = pq.Dequeue();
                    if(visited[temp.destination]==false)
                    {
                        System.out.println("Selected Vertex is :" +temp.destination);
                        res.create(temp.destination,temp.weight);
                        visited[temp.destination]=true;
                        Node trace = adjecancyList[temp.destination].head;
                        while(trace!=null)
                    {
                        int v=trace.vertex;
                        int w=trace.weight;
                        if(visited[v]==false)
                        {
                            Edge ed=new Edge(temp.destination,v,w);
                            pq.Enqueue(ed);
                        }
                        trace=trace.next;
                    }
                    System.out.print("Traced path :");
                    res.printList();
                    }
                    System.out.println("Current elements in priority queue");
                    pq.printQueue();
                    System.out.println();
                }
                System.out.println("Final Resul is ");
                res.printList();
        }
        
    }



public class primsAlgorithm {
    public static void main(String[] args)
    { 
    //   int v,e;
    //   Scanner sc = new Scanner(System.in);
    //   System.out.print("Enter number of vertices :");
    //   v=sc.nextInt();
    //   System.out.print("Enter number of edges :");
    //   e=sc.nextInt();
    //   Graph G = new Graph(v,e);
    //   for(int i=0;i<e;i++)
    //   { System.out.println("Edge "+(i+1));
    //     System.out.print("Source :");
    //     int s = sc.nextInt();
    //     System.out.print("Destination :");
    //     int d = sc.nextInt();
    //     System.out.print("Weight :");
    //     int w=sc.nextInt();
    //     G.addEdge(s,d,w); 
    //   }
    //   System.out.println("__The Adjacency List :__");
    //   G.display();
    //   System.out.println("Enter Source Vertex :");
    //   int src;
    //   src=sc.nextInt();
    //   G.primsAlgo(src);
    Graph G=new Graph(5,6);
    G.addEdge(0,1,4);
    G.addEdge(0,3,5);
    G.addEdge(3,2,6);
    G.addEdge(2,1,9);
    G.addEdge(2,4,7);
    G.addEdge(1,4,8);
    G.display();
    G.primsAlgo(0);    
    }
}