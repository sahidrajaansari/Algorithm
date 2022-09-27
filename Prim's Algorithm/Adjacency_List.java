public class Adjacency_List {
    static class Node{
        int vertices;
        int weight;
        Node next;
        public Node(int val,int w){
            vertices=val;
            weight=w;
            next=null;
        }
    }
    static class Linked_lost{
        Node head;
        public Linked_lost(){
            head=null;
        }
        public void Push(int val,int w){
            Node temp=head;
            Node newNode=new Node(val,w);
            if(head==null){
                head=new Node(val,w);
                System.out.println(head.vertices);
                return;
            }
            while(temp.next!=null){
                temp=temp.next;
            }
            temp.next=newNode;
            return;
        }
        public void isempty(){
            if(head==null){
                System.out.println("List Is empty ");
                return;
            }
        }
        public void display(){
            Node temp=head;
            while(temp!=null){
                System.out.print(temp.vertices+" ");
                temp=temp.next;
            }
            System.out.println();
        }
    }
    static class Graph{
        int vertices;
        Linked_lost l[];
        public Graph(int v){
            vertices=v;
            l=new Linked_lost[vertices];
            for(int i=0;i<vertices;i++){
                l[i]=new Linked_lost();
            }
        }
        void addedge(int m,int n,int w){
            l[m].Push(n,w);
            l[n].Push(m,w);
        }
        void display(){
            for(int i=0;i<vertices;i++){
                System.out.print(i+"->");
                l[i].display();
            }
        }
    }
    public static void main(String[] args) {
        Graph g=new Graph(4);
        g.addedge(0, 1, 1);
        g.addedge(0, 2, 4);
        g.addedge(1, 2, 2);
        g.addedge(2, 3, 3);
        g.addedge(3, 1, 4);
        g.display();
    }
}
