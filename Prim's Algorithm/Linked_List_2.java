public class Linked_List_2 {
        static class Node{
            int vertices;
            int weight;
            Node next;
            public Node(int val,int w){
                this.vertices=val;
                this.weight=w;
                this.next=null;
            }
        }
        static class Linked_lost{
            Node head;
            public Linked_lost(){
                this.head=null;
            }
            public void Push(int val,int w){
                Node temp=head;
                Node newNode=new Node(val,w);
                if(head==null){
                    head=newNode;
                    System.out.println("Hello");
                    System.out.println(head.vertices);
                    return;
                }
                newNode.next=temp;
                head=newNode;
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
                    System.out.println("Value is :"+temp.vertices);
                    System.out.println("Weight is :"+temp.weight);
                    temp=temp.next;
                }
            }
        }
        public static void main(String[] args) {
            Linked_lost l1[]=new Linked_lost[2];
            l1[0].isempty();
            l1[0].Push(1,2);
            l1[0].display();
            l1[0].isempty();
            l1[0].Push(2,3);
            l1[0].Push(3,4);
            l1[0].Push(4,5);
            l1[0].Push(5,6);
            l1[0].Push(6,7);
            l1[0].display();
        }
}
