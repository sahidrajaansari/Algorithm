class Linked_list{
    static class Node{
        int data;
        Node next;
        public Node(int val){
            data=val;
            next=null;
        }
    }
    static class Linked_lost{
        Node head;
        public Linked_lost(){
            head=null;
        }
        public void Push(int val){
            Node temp=head;
            Node newNode=new Node(val);
            if(head==null){
                head=new Node(val);
                System.out.println("Hello");
                System.out.println(head.data);
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
                System.out.println("Value is :"+temp.data);
                temp=temp.next;
            }
        }
    }
    public static void main(String[] args) {
        Linked_lost l=new Linked_lost();
        l.isempty();
        l.Push(1);
        l.display();
        l.isempty();
        l.Push(2);
        l.Push(3);
        l.Push(4);
        l.Push(5);
        l.Push(6);
        l.display();
    }
}